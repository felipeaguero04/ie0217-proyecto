# IE0217 - Estructuras Absttractas de Datos y Algoritmos

## Proyecto Final: Sistema de Gestion Bancaria

### Universidad de Costa Rica, I - S - 2024
### Desarrolladores: Luis Felipe Aguero Peralta, Jorge Meneses Garro e Ismael Jimenez Carballo


Este repositorio es el designado para el desarrollo cooperativo del proyecto final del curso Estructuras Abstractas de Datos y Algoritmos para Ingeniería IE-0217 de la UCR. A continuacion se expone la investigacion y diseño previo a alto nivel del programa a desarrollar. De igual manera, se dan instrucciones de compilacion y ejecucion para simplificar el uso del mismo.

## Investigación

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