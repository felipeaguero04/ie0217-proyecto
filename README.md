# IE0217 - Estructuras Absttractas de Datos y Algoritmos

## Proyecto Final: Sistema de Gestion Bancaria

### Universidad de Costa Rica, I - S - 2024
### Desarrolladores: Luis Felipe Aguero Peralta, Jorge Meneses Garro e Ismael Jimenez Carballo


Este repositorio es el designado para el desarrollo cooperativo del proyecto final del curso Estructuras Abstractas de Datos y Algoritmos para Ingeniería IE-0217 de la UCR. A continuacion se expone la investigacion y diseño previo a alto nivel del programa a desarrollar. De igual manera, se dan instrucciones de compilacion y ejecucion para simplificar el uso del mismo.

## Investigación
4. Las operaciones bancarias son actividades financieras que hacen los bancos y sus clientes. Ayudan a las personas a manejar su dinero, hacer pagos, obtener préstamos y usar servicios financieros. Hay tres tipos: activas, pasivas y de servicios. Este programa se enfocará en cuatro operaciones específicas: depósitos, retiros, transferencias y pagos de préstamos. Estas son las principales operaciones que permitirán a los usuarios usar el programa. A continuación, se explican las operaciones bancarias incluidas.

    | Operación                        | Descripción                                                                 |
    |----------------------------------|-----------------------------------------------------------------------------|
    | **Depósitos**                    | Se pueden ingresar fondos en las cuentas bancarias. Este dinero se añade al saldo de la cuenta y está disponible para futuros usos. |
    | **Retiros**                      | Se pueden extraer fondos de las cuentas bancarias. Esto reduce el saldo disponible en la cuenta. |
    | **Transferencias entre cuentas** | Es posible mover fondos de una cuenta a otra dentro del mismo banco. Esto incluye transferencias entre cuentas propias y transferencias a cuentas de otros clientes del mismo banco. |
    | **Abonos a préstamos**           | Se pueden hacer pagos a préstamos, propios o de otras personas. Estos pagos ayudan a reducir el monto adeudado del préstamo. |

5. El sistema a implementar debe registrar todas las transacciones de manera detallada. Esto permite seguir todas las operaciones como depósitos, retiros, transferencias y pagos. Ayuda a prevenir fraudes y detectar actividades no autorizadas. También ayuda a resolver conflictos al tener un historial claro. Además, incrementa la transparencia y la confianza de los clientes porque se les ofrecerle acceso a sus historiales de transacciones. La tabla siguiente muestra la información que se incluirá en el registro de transacciones para mantener el programa simple.

    ## Tabla para Depósitos y Retiros
    | Información de la Transacción | Descripción                                                                 |
    |-------------------------------|-----------------------------------------------------------------------------|
    | **Tipo de operación**         | Depósito o retiro.                                                          |
    | **Monto de la transacción**   | Cuánto dinero se movió.                                                     |
    | **Cuenta**                    | La cuenta desde donde se retiró o hacia donde se depositó el dinero.        |
    | **Descripción**               | Detalles adicionales sobre la transacción.                                  |
    | **Moneda**                    | Tipo de moneda con el que se hizo la transacción               |
    <!-- Esto ponerlo en caso de que se agregue en la tabla SQL
    | **Fecha de la transacción**      | Cuándo se realizó la operación.                                             |
    -->

    ## Tabla para Transferencias
    | Información de la Transacción | Descripción                                                                 |
    |-------------------------------|-----------------------------------------------------------------------------|
    | **Tipo de operación**         | Transferencia.                                                              |
    | **Monto de la transacción**   | Cuánto dinero se movió.                                                     |
    | **Cuenta de origen**          | La cuenta desde donde se transfirió el dinero.                              |
    | **Cuenta de destino**         | La cuenta hacia donde se transfirió el dinero.                              |
    | **Descripción**               | Detalles adicionales sobre la transacción.                                  |
    | **Moneda**                    | Tipo de moneda con el que se hizo la transacción               |
    <!-- Esto ponerlo en caso de que se agregue en la tabla SQL
    | **Fecha de la transacción**      | Cuándo se realizó la operación.                                             |
    -->                                           

    ## Tabla para Abonos a Préstamos
    | Información de la Transacción | Descripción                                                                 |
    |-------------------------------|-----------------------------------------------------------------------------|
    | **Tipo de operación**         | Abono a préstamo.                                                           |
    | **Monto de la transacción**   | Cuánto dinero se movió.                                                     |
    | **Cuenta**                    | La cuenta desde donde se realizó el abono.                                  |
    | **ID del préstamo**           | Identificador del préstamo al que se hizo el abono.                         |
    | **Descripción**               | Detalles adicionales sobre la transacción.                                  |
    | **Moneda**                    | Tipo de moneda con el que se hizo la transacción               |
    <!-- Esto ponerlo en caso de que se agregue en la tabla SQL
    | **Fecha de la transacción**      | Cuándo se realizó la operación.                                             |
    -->                                            


7. Los clientes pueden tener préstamos en colones o en dólares. Cada préstamo tiene su propia tasa de interés, periodo en meses y cuota mensual, según valores ya definidos. Estos valores aseguran que cada tipo de préstamo tenga características específicas que se adapten a las necesidades y capacidades de los clientes. Hay tres tipos principales de préstamos con tasas de interés promedio,  en el contexto de préstamos, el interés es la cantidad adicional que se debe pagar junto con el capital prestado como compensación al prestamista por el uso de esos fondos. A continuación se presenta los intereses que se utilizaran para cada tipo de préstamo:

    | Tipo de Préstamo         | Tasa de Interés Anual |
    |--------------------------|-----------------------|
    | **Préstamos Hipotecarios** | 10% - 12%            |
    | **Préstamos Prendarios**   | 15% - 18%            |
    | **Préstamos Personales**   | 20% - 25%            |

    Pueden variar según el banco, el plazo del préstamo, el monto y la situación crediticia del cliente. Además, las tasas pueden cambiar un poco dependiendo de las condiciones económicas y del mercado financiero. Pero para este programa, se usarán tasas fijas basadas en pagos periódicos constantes y una tasa de interés constante.


    La cuota mensual (PMT) se calcula utilizando la siguiente fórmula:

    $$
    \text{PMT} = \frac{P \cdot r \cdot (1 + r)^n}{(1 + r)^n - 1}
    $$

    Donde:
    - \( P \) es el monto del préstamo.
    - \( r \) es la tasa de interés mensual (tasa anual dividida por 12).
    - \( n \) es el número total de pagos (meses).

    Para calcular \( r \):

    $$
    r = \frac{\text{Tasa Anual}}{12}
    $$

    Para calcular \( n \):

    $$
    n = \text{Años} \times 12
    $$

    Es muy importante saber que esta fórmula PMT solo funciona con tasas de interés constantes. Esta fórmula se usa principalmente en finanzas para calcular el pago periódico necesario para pagar un préstamo o una inversión en un tiempo específico. Ayuda a determinar cuánto se debe pagar regularmente para saldar la deuda en un plazo específico, considerando la tasa de interés y el número de períodos. Es una herramienta útil para planificar presupuestos, evaluar inversiones y tomar decisiones financieras informadas. Por lo tanto, se utilizará en la implementación del programa para calcular el pago mensual para un número determinado de períodos del pago de un préstamo.

8. Ahora bien, se tiene dentro de los requisitos de programa que el cliente debe estar en la potestad de solicitar un reporte de sus préstamos, sean pasados, activos, en dólares o en colones y que este sea impreso en un archivo de texto para la lectura del cliente. Esto puede ser visto como una versión de un informe de crédito filtrada a solo los préstamos del cliente y con sólo cierta información del solicitante. Esto dado que los informes de crédito incluyen mucha más información de interés público. En el caso de Costa Rica, los informes crediticios son regulados por la SUGEF y el CIC brinda los reportes crediticios a los usuarios y estos reportes traen información sobre los saldos de deudas actuales, clasificación de riesgo de la persona como deudor, historial de crédito de los últimos cuatro años del solicitante y cuáles entidades han consultado por el reporte en cuestión. Estos reportes son por lo general vendidos a los bancos por empresas terceras que se encargan de recolectar la información necesaria para armar un perfil crediticio sumamente detallado de cada persona y así poder analizar su viabilidad y confiabilidad como cliente de un banco. Sin embargo, esto es a niveles de empresas con grandes servidores y los recursos necesarios para manejar bases de datos de tales magnitudes donde hay información de toda la población habitante o más. Entonces para una aplicación reducida como este proyecto, se reduce el reporte crediticio a únicamente información actualizada de los saldos de los préstamos y cierta información personal del cliente.

9. Por último, pero no menos importante, está lo que son las bases de datos SQL. La importancia de estas dentro de este proyecto es que se hará uso de una base de datos para el elmacenamiento de la información del banco para el que se estaría realizando el sistema, ya sea la información de cleintes, balances de cuentas, préstamos, etc. Entonces, las bases de datos SQL (_Standard Query Language_) son sistemas de almacenamiento relacionales que permiten acceder, modificar y filtrar grandes cantidades de datos de manera rápida y eficiente. Estas bases de datos son un solo gran archivo digital que se subdivide en tablas y estas es donde se almacena la información. En dichas tablas, cada columna representa un atributo, o comúnmente llamado _field_; al igual que cada fila es conocido como registro o _record_ y cada registro tiene todos los atributos presentes en las columnas. Asimismo, cada registro es identificable en cada tabla por medio de los llamados _primary keys_, que la diferencian del resto de registros y también existen las _foreign keys_, que son las que relacionan dos tablas distintas por medio de un dato. A su vez, es importante destacar conceptos como clave única, que es similar a la _primary_ pero admite valores _NULL_; o el concepto de clave candidata, que hace alusión a todas las que podrían ser _primary_ y las que no sean seleccionadas, se conocerán como llaves alternas. Entonces, en la siguiente sección se expondrá el esuqema de base de datos y tablas que se aplicará para el desarrollo de este programa, al igual que indicando la interrelación entre las mismas.

    Por último, pero no menos importante, es esencial destacar el tipo de datos que admiten las tablas SQL para tenerlo presente en el ingreso de datos y cómo tratar con las mismas tablas a la hora de manipularlas y analizarlas. Los tipos de datos se dividen en tres sub-categorías principales: Numéricos, strings y temporales o de fecha. Si bien existen otras sub-categorías y tipos como XML, array, espaciales y demás, se exponen a continuación los más comunes y los que se emplearán en el presente proyecto.
    
    |***Sub-categoría***|***Tipos***|
    |---|---|
    |**Numéricos**|BigInt, Int, smallint, tinyint, bit, decimal, numeric, money, smallmoney, float|
    |**String**|char, varchar, text, nchar, Nvarchar|
    |**Date-Time**|DATE, TIME, DATETIME|
    |**Bool**|TRUE, FALSE|


## Diseño
### Flujo de programación
![Imgur](https://i.imgur.com/fJAjost.png)
![Imgur](https://i.imgur.com/hglk73Q.png)
![Imgur](https://i.imgur.com/YGRtrF5.png)

### Base de datos SQL
![Imgur](https://i.imgur.com/31YZ2P0.png)

<!--
## Imagen 1
<img src="https://i.imgur.com/fJAjost.png" alt="Imagen 1" width="700" height="500">
-->

<!--
## Imagen 2
<img src="https://i.imgur.com/hglk73Q.png" alt="Imagen 2" width="900" height="1100">
-->

<!--
## Imagen 3
<img src="https://i.imgur.com/YGRtrF5.png" alt="Imagen 3" width="11000" height="1500">
-->

<!--
## Base de datos SQL
<img src="https://i.imgur.com/31YZ2P0.png" alt="Base de datos SQL" width="900" height="700">
-->
