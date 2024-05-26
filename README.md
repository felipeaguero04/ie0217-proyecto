# IE0217 - Estructuras Absttractas de Datos y Algoritmos

## Proyecto Final: Sistema de Gestion Bancaria

### Universidad de Costa Rica, I - S - 2024
### Desarrolladores: Luis Felipe Aguero Peralta - C10089, Jorge Meneses Garro - C14742 e Ismael Jimenez Carballo - B94009


Este repositorio es el designado para el desarrollo cooperativo del proyecto final del curso Estructuras Abstractas de Datos y Algoritmos para Ingeniería IE-0217 de la UCR. A continuacion se expone la investigacion y diseño previo a alto nivel del programa a desarrollar. De igual manera, se dan instrucciones de compilacion y ejecucion para simplificar el uso del mismo.

## Investigación
1. El sistema a implementar será utilizado por agentes que atienden a clientes a través de ventanillas en una entidad bancaria y es importante entender los modos de operación disponibles
que tienen los agentes. 
- **Consulta Inicial**: El sistema inicia preguntando al inicio si se va a utilizar en modalidad de atención a clientes o para obtener información general sobre préstamos bancarios.
- **Operaciones Disponibles en Modo Atención a Clientes**:
  - Depósitos
  - Retiros
  - Transferencias entre cuentas dirigidas a otros clientes
  - Abonos a préstamos (propios y de otras personas)
- **Operaciones Disponibles en Modo Información General**:
  - Información sobre tipos de préstamos
  - Tasas de interés
  - Requisitos para préstamos
- Según la respuesta, el sistema procede a mostrar el menú de operaciones correspondiente o finaliza.
#### Menú de Operaciones básico:
- Si el usuario selecciona "Atención a Clientes", se muestra un menú con las siguientes opciones:
  1. Realizar Depósito
  2. Realizar Retiro
  3. Transferir entre Cuentas
  4. Abonar a Préstamo
  5. Salir
- Si el usuario selecciona "Información General", se muestra la información sobre préstamos bancarios.
#### Descripción de la interacción por Operación en Modo Atención a Clientes
- **Realizar Depósito**:
  - Pedir número de cuenta.
  - Pedir monto a depositar.
  - Confirmar depósito y actualizar la base de datos.
- **Realizar Retiro**:
  - Pedir número de cuenta.
  - Pedir monto a retirar.
  - Confirmar saldo suficiente y actualizar la base de datos.
- **Transferir entre Cuentas**:
  - Pedir número de cuenta origen y destino.
  - Pedir monto a transferir.
  - Confirmar transferencia y actualizar la base de datos.
- **Abonar a Préstamo**:
  - Pedir número de préstamo.
  - Pedir monto a abonar.
  - Confirmar abono y actualizar la base de datos.

#### Descripción de la interacción de la interacción en Modo Información General
- **Obtener Información sobre Préstamos**:
  - Muestra información sobre tipos de préstamos, tasas de interés, requisitos, etc.

2. Al sistema implementar varios conceptos financieros, es importante detallarlos a continuación:
### 1. Tipos de Préstamos Bancarios
#### 1.1 Préstamo Personal
Un préstamo personal es un tipo de crédito no asegurado que se otorga a individuos para cubrir diversas necesidades personales, como gastos médicos, educación, consolidación de deudas, entre otros. No requiere una garantía específica, lo que significa que se basa en la solvencia crediticia del solicitante.

#### 1.2 Préstamo Prendario
Un préstamo prendario es un tipo de crédito asegurado por un bien mueble, como joyas, vehículos o equipos electrónicos. El bien mueble actúa como garantía y, en caso de incumplimiento, el prestamista puede vender el bien para recuperar el monto prestado.

#### 1.3 Préstamo Hipotecario
Un préstamo hipotecario es un crédito asegurado por una propiedad inmueble, como una casa o un terreno. Este tipo de préstamo generalmente se utiliza para comprar bienes raíces. En caso de incumplimiento, el prestamista tiene el derecho de ejecutar la hipoteca y vender la propiedad para recuperar el monto prestado.

### 2. Conceptos Clave de los Préstamos
#### 2.1 Monto del Préstamo
El monto del préstamo es la cantidad de dinero que se presta al solicitante. Este monto debe ser devuelto al prestamista junto con los intereses acordados.

#### 2.2 Tasa de Interés
La tasa de interés es el porcentaje que se aplica sobre el monto del préstamo como costo del crédito. Puede ser fija o variable:
- **Tasa Fija**: Permanece constante durante toda la vida del préstamo.
- **Tasa Variable**: Puede cambiar en función de índices de referencia o condiciones del mercado.

#### 2.3 Cantidad de Cuotas
La cantidad de cuotas es el número de pagos periódicos que el prestatario debe realizar para amortizar el préstamo. Las cuotas pueden ser mensuales, trimestrales, anuales, etc.

### 3. Funcionamiento de un Préstamo
#### 3.1 Pago de Cuotas
El préstamo se paga en cuotas periódicas que incluyen una parte del capital y una parte de los intereses. La cuota se calcula de manera que, al final del período de préstamo, todo el capital y los intereses hayan sido pagados.

#### 3.2 Cálculo del Pago Mensual
El pago mensual de un préstamo se puede calcular usando la fórmula de amortización:

$$ \text{Pago Mensual} = P \times \frac{r(1+r)^n}{(1+r)^n - 1} $$

donde:
- \( P \) es el monto del préstamo.
- \( r \) es la tasa de interés mensual.
- \( n \) es la cantidad de cuotas.


#### 3.3 Ejemplo de Cálculo para clarificar nuestro proyecto
Si se realiza un préstamo de 10,000 unidades monetarias con una tasa de interés anual del 6% a ser pagado en 3 años (36 meses).
- Monto del Préstamo (\( P \)): 10,000
- Tasa de Interés Mensual (\( r \)): 0.06 / 12 = 0.005
- Cantidad de Cuotas (\( n \)): 36

$$ \text{Pago Mensual} = 10,000 \times \frac{0.005(1+0.005)^{36}}{(1+0.005)^{36} - 1} \approx 304.17 $$

### 4. Opciones del Sistema
#### 4.1 Préstamos Predefinidos
El sistema ofrecerá opciones predefinidas para diferentes tipos de préstamos con valores típicos para el monto, la tasa de interés y la cantidad de cuotas:
- **Préstamo Personal**
- **Préstamo Prendario**
- **Préstamo Hipotecario**

### 5. Realización de de la Tabla de Pagos
#### 5.1 Tabla de Pagos Esperados
La tabla de pagos muestra cómo se distribuyen los pagos entre el capital e intereses a lo largo del tiempo. Incluye información sobre:
- Pago Mensual
- Intereses Pagados
- Capital Pagado
- Saldo Restante

#### 5.2 Ejemplo de Tabla de Pagos para clarificar el proyecto
Para un préstamo de 10,000 unidades a una tasa de interés del 6% anual en 36 meses, la tabla de pagos podría verse así:

| Mes | Pago Mensual | Intereses Pagados | Capital Pagado | Saldo Restante |
|-----|---------------|-------------------|----------------|----------------|
| 1   | 304.17        | 50.00             | 254.17         | 9,745.83       |
| 2   | 304.17        | 48.73             | 255.44         | 9,490.39       |
| ... | ...           | ...               | ...            | ...            |
| 36  | 304.17        | 1.52              | 302.65         | 0.00           |
3. 
### 1. Cuentas Bancarias
Una cuenta bancaria es un servicio financiero ofrecido por entidades bancarias que permite a los clientes gestionar su dinero de forma segura. Las cuentas pueden ser de diversos tipos, pero aquí nos centraremos en las cuentas de ahorro en dos monedas: colones y dólares.

#### 1.1 Cuentas en Colones y Dólares
- **Cuenta en Colones**: Es una cuenta bancaria donde el saldo y las transacciones se manejan en la moneda local de Costa Rica, el colón (CRC).
- **Cuenta en Dólares**: Es una cuenta bancaria donde el saldo y las transacciones se manejan en dólares estadounidenses (USD).

#### 1.2 Propósito de las Cuentas
- **Gestión de Ahorros**: Los clientes utilizan estas cuentas para depositar, retirar y transferir dinero. Las cuentas de ahorro pueden generar intereses, proporcionando un incentivo para que los clientes mantengan su dinero en el banco.
- **Diversificación de Moneda**: Tener cuentas en diferentes monedas permite a los clientes gestionar el riesgo cambiario y aprovechar oportunidades de inversión en distintas monedas.

### 2. Certificados de Depósito a Plazo (CDP)
Un Certificado de Depósito a Plazo (CDP) es un tipo de inversión ofrecido por los bancos que permite a los clientes depositar una cantidad de dinero por un período de tiempo específico a cambio de una tasa de interés fija.

#### 2.1 Características de los CDP
- **Monto de Inversión**: Los clientes depositan una cantidad fija de dinero en el CDP.
- **Plazo**: El período durante el cual el dinero debe permanecer en el CDP. Los plazos pueden variar desde unos pocos meses hasta varios años.
- **Tasa de Interés**: El banco paga una tasa de interés fija sobre el monto depositado, que se acuerda al inicio del plazo.
- **Retiro al Vencimiento**: Al final del plazo, el cliente puede retirar el monto inicial más los intereses generados. Retirar el dinero antes del vencimiento puede resultar en penalizaciones.

#### 2.2 Ventajas de los CDP
- **Seguridad**: Los CDP suelen ser inversiones seguras con un riesgo bajo, ya que están respaldados por el banco.
- **Tasa de Interés Fija**: Los clientes conocen la tasa de interés desde el principio, lo que proporciona certeza sobre los rendimientos de la inversión.
- **Diversificación**: Los CDP pueden ser parte de una estrategia de diversificación para equilibrar riesgos en la cartera de inversiones del cliente.

### 3. Aplicación en el Sistema Bancario
El sistema bancario que estamos investigando debe permitir a los clientes gestionar sus cuentas en colones y dólares, así como invertir en CDP. Aquí hay algunas funcionalidades específicas que podrían implementarse:

#### 3.1 Funcionalidades del Sistema
- **Gestión de Cuentas**:
  - Crear y administrar cuentas en colones y dólares.
  - Ver saldos y transacciones en ambas monedas.
  - Transferencias entre cuentas de un mismo cliente y hacia otros clientes.
- **Inversión en CDP**:
  - Información sobre CDP disponibles (montos mínimos, plazos, tasas de interés).
  - Apertura de nuevos CDP.
  - Visualización de los CDP activos y su rendimiento.
  - Gestión de vencimientos y reinversiones.
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
# Cronograma de Actividades del Proyecto

## Período: 27 de mayo de 2024 al 2 de julio de 2024

- **Reuniones semanales**: Todos los lunes a las 4 pm.
  - **Participantes**: Luis Aguero, Ismael Carballo, Jorge Meneses.

## Actividades y Responsables

| Fecha                | Actividad                                                 | Responsables       |
|----------------------|-----------------------------------------------------------|--------------------|
| 27 de mayo (lunes)   | Reunión de Inicio del Proyecto Programación               | Todos              |
| 28 de mayo (martes)  | Definir Requisitos del Sistema                            | Luis Aguero        |
| 29 de mayo (miércoles)| Análisis de Usuarios y Casos de Uso                      | Ismael Carballo    |
| 30 de mayo (jueves)  | Diseño de la Arquitectura del Sistema                     | Jorge Meneses      |
| 31 de mayo (viernes) | Revisión y Ajustes                                        | Todos              |
| 3 de junio (lunes)   | Reunión de Seguimiento                                    | Todos              |
| 4 de junio (martes)  | Implementación de la Base de Datos                        | Jorge Meneses      |
| 5 de junio (miércoles)| Desarrollo de Funciones de Autenticación y Autorización  | Luis Aguero        |
| 6 de junio (jueves)  | Desarrollo de Funciones para Depósitos y Retiros          | Ismael Carballo    |
| 7 de junio (viernes) | Revisión y Pruebas Iniciales                              | Todos              |
| 10 de junio (lunes)  | Reunión de Seguimiento                                    | Todos              |
| 11 de junio (martes) | Desarrollo de Funciones para Transferencias entre Cuentas | Luis Aguero        |
| 12 de junio (miércoles)| Desarrollo de Funciones para Abonos a Préstamos         | Ismael Carballo    |
| 13 de junio (jueves) | Desarrollo de Funciones para Información General sobre Préstamos | Jorge Meneses  |
| 14 de junio (viernes)| Revisión y Pruebas de Integración                         | Todos              |
| 17 de junio (lunes)  | Reunión de Seguimiento                                    | Todos              |
| 18 de junio (martes) | Desarrollo de la Interfaz de Usuario                      | Luis Aguero        |
| 19 de junio (miércoles)| Implementación de CDP (Certificados de Depósito a Plazo)| Jorge Meneses      |
| 20 de junio (jueves) | Desarrollo de Reportes y Generación de Tablas de Pagos    | Ismael Carballo    |
| 21 de junio (viernes)| Revisión y Pruebas Finales                                | Todos              |
| 24 de junio (lunes)  | Reunión de Seguimiento                                    | Todos              |
| 25 de junio (martes) | Documentación del Sistema                                 | Luis Aguero        |
| 26 de junio (miércoles)| Preparación para la Presentación Final                  | Ismael Carballo    |
| 27 de junio (jueves) | Ensayo de la Presentación                                 | Todos              |
| 28 de junio (viernes)| Revisión Final y Ajustes                                  | Todos              |
| 1 de julio (lunes)   | Reunión de Últimos Detalles                               | Todos              |
| 4 de julio (martes)  | Presentación Final del Proyecto                           | Todos              |
