/**
 * @file DBManager.hpp
 * @author Jorge Meneses (j.menesesgarro@gmail.com), Ismael Jimenez () and Luis Felipe Aguero ()
 * @brief Clase encargada de manipular la base de datos bancaria
 * @version 1.0
 * @date 2024-07-1
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef DBMANAGER_HPP
#define DBMANAGER_HPP
#include <iostream>
#include <sqlite3.h>
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;

/**
 * @brief Clase cuya instanciacion crea y manipula la base datos por medio de operaciones CRUD.
 * 
 */
class DBManager{
    private:
        sqlite3 *db; /**<- Puntero de la base de datos SQLite3.*/
        char *errMsg; /**<- Cadena de chars con el mensaje de error.*/
        int rc; /**<- Return code de directivas SQL.*/
        const char *sql; /**<- Directiva SQL.*/
        const char* data = "Callback function called"; /**<- Cadena de chars para ejecucion SQL.*/
        /**
         * @brief Funcion a ejecutar sobre cada fila de los resultados.
         * 
         * Imprime los resultados de la directiva SQL en la terminal.
         * 
         * @param data Puntero a los datos, es decir, el database.
         * @param argc Cantidad de columnas en el set de resultados.
         * @param argv Valores de cada columna en formato text.
         * @param azColName Nombre d ela columna de la fila resultante.
         * @return int Represntante del rc (0 para bien, 1 para mal).
         */
        static int callback(void* data, int argc, char** argv, char** azColName);
        
        /**
         * @brief Funcion a ejecutar sobre cada fila de los resultados.
         * 
         * Se encarga de imprimir los resultados en el reporte.txt
         * 
         * @param data Puntero a los datos, es decir, el database.
         * @param argc Cantidad de columnas en el set de resultados.
         * @param argv Valores de cada columna en formato text.
         * @param azColName Nombre d ela columna de la fila resultante.
         * @return int Represntante del rc (0 para bien, 1 para mal).
         */
        static int getLoanReport(void* data, int argc, char** argv, char** azColName);

    public:
        /**
         * @brief Constructor de objetos tipo DBManager
         * 
         * Tareas:
         * -------
         * 1. Creacion de la base de datos 'banksys.db' si esta no existe.
         * 2. Creacion de las tablas 'CLIENTS', 'ACCOUNTS', 'LOANS' y 'TRANSACTIONS' con sus respectivas especificaciones, keys y constraints. 
         * 
         */
        DBManager();

        /**
         * @brief Destructor de objetos tipo DBManager
         * 
         * Cierra la base de datos 'banksys.db'.
         * 
         */
        ~DBManager();

        /**
         * @brief Revision de existencia de un cliente especifico.
         * 
         * @param ID ID del cliente que se desea revisar si existe en la base de datos del banco.
         */
        int checkClientID(int ID);

        /**
         * @brief Agregar un cliente a la base de datos.
         * 
         * Esta funcion no es incluida en las operaciones de atencion al cliente. ES usada para la creacion de cleintes default en el sistema.
         * 
         * @param idClient ID del nuevo cliente.
         * @param firsName Nombre del nuevo cliente.
         * @param lastName Apellido dle nuevo cliente.
         */
        void addClient(int idClient, std::string firsName, std::string lastName);

        /**
         * @brief Agregar una cuenta a la base de datos.
         * 
         * @param client ID del cliente que sera el dueno.
         * @param curr Tipo de moneda en el que desea la cuenta ($ o ₡).
         * @param rate Tasa de interes de la cuenta. Distinta de cero si es un CDP.
         */
        void addAccount(int client, int curr, float rate);

        /**
         * @brief Realizar un deposito a una cuenta especifica.
         * 
         * @param amount Monto que se desea depositar.
         * @param curr Tipo de moneda en el que se deposita.
         * @param acc_ID ID de cuenta a la que se desea depositar.
         */
        void deposit(int amount, int curr, int acc_ID);

        /**
         * @brief Realizar un retiro de una cuenta especifica.
         * 
         * @param amount Monto que se desea retirar.
         * @param acc_ID ID de la cuenta de la que se desea retirar.
         */
        void withdrawal(int amount, int acc_ID);

        /**
         * @brief Realizar transferencias entre cuentas especificas
         * 
         * @param amount Monto que se desea transferir.
         * @param acc_ID ID de la cuenta desde la que se desea transferir.
         * @param dest_acc_ID ID de la cuenta a la que se desea transferir.
         */
        void transference(int amount, int acc_ID, int dest_acc_ID);

        /**
         * @brief Realizar un pago a un prestamo.
         * 
         * @param amount Monto que se pagara.
         * @param acc_ID Cuenta desde la que se desea pagar.
         * @param loan_ID ID del prestamo hacia el que se abonara.
         */
        void loanPayment(int amount, int acc_ID, int loan_ID);

        /**
         * @brief Imprimir reporte de prestamos de un cliente especifico.
         * 
         * @param client_ID ID del cliente cuyo reporte se desea obtener.
         */
        void loanReport(int client_ID);

        /**
         * @brief Agregar una transaccion al registro de transacciones.
         * 
         * @param accountID2 ID de la cuenta destino, de haber una. De no haber, se ingresa la misma que la fuente.
         * @param accoutnID1 ID de la cuenta fuente.
         * @param amountTransaction Monto de la transaccion.
         * @param typeTransaction Tipo de transaccion => 1 para deposito, 2 para retiro, 3 para transferencia y 4 para abono a prestamo.
         * @param loanID ID del prestamo, de ser el caso.
         */
        void addTransaction(int accountID2, int accoutnID1, unsigned long int amountTransaction, int typeTransaction, int loanID);

        /**
         * @brief Agregar un prestamo a la base de datos.
         * 
         * @param client_ID ID del cleinte al que se le asociara el nuevo prestamo.
         * @param amount Monto inicial dle prestamo.
         * @param rate Tasa de interes del prestamo.
         * @param payments Cantidad de cuotas del prestamo.
         * @param type Tipo de prestamo => 1 para personal, 2 para prendario y 3 para hipotecario.
         * @param curr Tipo de moneda en el que se pide el prestamo => 1 para $ y 2 para ₡.
         */
        void addLoan(int client_ID, int amount, float rate, int payments, int type, int curr);
};
#endif // DBMANAGER_HPP