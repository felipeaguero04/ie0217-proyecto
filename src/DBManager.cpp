#include "DBManager.hpp"

int DBManager::callback(void* data, int argc, char** argv, char** azColName){
    for(int i = 0; i < argc; i++){
        cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
    }
    return 0;
}


int DBManager::getLoanReport(void* data, int argc, char** argv, char** azColName) {
    std::ofstream* output_file = static_cast<std::ofstream*>(data);

   if (output_file->is_open()) {
        *output_file << "Reporte de Préstamo\n";
        *output_file << "===================\n";
        for (int i = 0; i < argc; i++) {
            if (std::string(azColName[i]) == "client_ID") {
                *output_file << "ID del Cliente: " << (argv[i] ? argv[i] : "NULL") << "\n";
            } else if (std::string(azColName[i]) == "first_name") {
                *output_file << "Nombre: " << (argv[i] ? argv[i] : "NULL") << "\n";
            } else if (std::string(azColName[i]) == "last_name") {
                *output_file << "Apellido: " << (argv[i] ? argv[i] : "NULL") << "\n";
            } else if (std::string(azColName[i]) == "loan_ID") {
                *output_file << "Préstamo ID: " << (argv[i] ? argv[i] : "NULL") << "\n";
            } else if (std::string(azColName[i]) == "amount") {
                *output_file << "Monto del Préstamo: " << (argv[i] ? argv[i] : "NULL") << "\n";
            } else if (std::string(azColName[i]) == "interest") {
                *output_file << "Intereses: " << (argv[i] ? argv[i] : "NULL") << "\n";
            } else if (std::string(azColName[i]) == "made_payments") {
                *output_file << "Cuotas Realizadas: " << (argv[i] ? argv[i] : "NULL") << "\n";
            } else if (std::string(azColName[i]) == "paid_amount") {
                *output_file << "Monto Pagado: " << (argv[i] ? argv[i] : "NULL") << "\n";
            }
        }
        *output_file << "------------------------\n"; // Separador entre registros
    } else {
        std::cerr << "Error al escribir en el archivo." << std::endl;
    }
    return 0;
};

DBManager::DBManager(){
    // Crear y abrir la base de datos
    rc = sqlite3_open("banksys.db", &db);
    if (rc){
        cerr << "No se pudo abrir la base de datos: " << sqlite3_errmsg(db) << endl;
        exit (0);
    } else cout << "Base de datos abierta correctamente!" << endl;

    // Crear tabla clientes
    sql = "PRAGMA foreign_keys = ON;"
        "CREATE TABLE IF NOT EXISTS CLIENTS ("
        "client_ID INT PRIMARY KEY NOT NULL,"
        "first_name TEXT NOT NULL,"
        "last_name TEXT NOT NULL,"
        "CHECK(client_ID <= 999999999));";

    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Tabla creada exitosamente!" << endl;
    }

    // Crear tabla loans
    sql = "CREATE TABLE IF NOT EXISTS LOANS ("
        "client_ID INT NOT NULL,"
        "loan_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
        "type TEXT NOT NULL,"
        "amount MONEY NOT NULL,"
        "payments INT NOT NULL,"
        "interest FLOAT NOT NULL,"
        "made_payments INT NOT NULL,"
        "paid_amount MONEY NOT NULL,"
        "currency CHAR NOT NULL,"
        "FOREIGN KEY (client_ID) REFERENCES CLIENTS (client_ID));";

    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Tabla creada exitosamente!" << endl;
    }

    // Crear tabla de cuentas
    sql = "CREATE TABLE IF NOT EXISTS ACCOUNTS("
        "owner INT NOT NULL,"
        "account_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
        "balance MONEY NOT NULL,"
        "rate FLOAT NOT NULL,"
        "currency CHAR NOT NULL,"
        "FOREIGN KEY (owner) REFERENCES CLIENTS (client_ID));";

    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Tabla creada exitosamente!" << endl;
    }

    // Crear tabla de registro de transacciones
    sql = "CREATE TABLE IF NOT EXISTS TRANSACTIONS("
        "transaction_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
        "type TEXT NOT NULL,"
        "loan_ID INT,"
        "amount MONEY NOT NULL,"
        "source INT NOT NULL,"
        "destiny INT NOT NULL,"
        "FOREIGN KEY (source) REFERENCES ACCOUNTS (account_ID),"
        "FOREIGN KEY (destiny) REFERENCES ACCOUNTS (account_ID));";
        
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Tabla creada exitosamente!" << endl;
    }
};

DBManager::~DBManager(){
    // Desconectar de la base de datos
    sqlite3_close(db);
    cout << "Base de datos cerrada correctamente!" << endl;
};

int DBManager::checkClientID(int ID){
    stringstream ss;
    string aux;
    // Consulta SELECT para obtener el balance actual
    ss << "SELECT COUNT(client_ID) FROM CLIENTS WHERE client_ID = " << ID << ";";
    aux = ss.str();
    sql= aux.c_str();

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error en sqlite3_prepare_v2 (SELECT): " << sqlite3_errmsg(db) << std::endl;
        return -1; //Retorna algo no valido para un caso de error
    }

    // Ejecutar consulta SELECT
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        int quant = sqlite3_column_int(stmt, 0);
        if (quant == 1) {
        cout << "El cliente existe!" << endl;
        return 1; //Retorna 1 si el cliente existe
        }
        else if (quant == 0) {
        cout << "El cliente no existe!" << endl;
        return 0; //Retorna 0 si el cliente no existe
        }
    }

    sqlite3_finalize(stmt); // Finaliza el sqlite para cualquier caso
    return -1;
};

void DBManager::getAccountsInfo(int clientID){
    cout << "Cuentas del cliente: " << clientID << endl;
    std::stringstream ss;
    std::string aux;
    ss << "SELECT * FROM ACCOUNTS WHERE owner = " << clientID << ";";
    aux = ss.str();
    sql = aux.c_str();

    rc = sqlite3_exec(db, sql, callback, (void*)data, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
};

void DBManager::addClient(int idClient, std::string firstName, std::string lastName){
    std::stringstream ss;
    string aux;

    ss.str("");
    // Crear directiva con los parametros
    ss << "INSERT INTO CLIENTS (client_ID, first_name, last_name) VALUES("<< idClient << ", '" << firstName << "', '" << lastName << "');";
    aux = ss.str();
    // Alocar memoria del nuevo char*
    char* extra = new char[aux.length() + 1];
    // EScribir en el nuevo char*
    strcpy(extra, aux.c_str());
    // Asignar el string creado a la directiva SQL
    sql = extra;

    // Ejecutar la directiva
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Cliente creado exitosamente!" << endl;
        delete extra; // Liberar la memoria
    }
};


void DBManager::addAccount(int client, int curr, float rate) {
    std::stringstream ss;
    std::string aux;
    std::string mon;

    // Determinar el carácter de la moneda
    if (curr == 1) mon = "$";
    else if (curr == 2) mon = "₡";
    else {
        cerr << "Moneda no válida. Usa 1 para USD y 2 para CRC." << endl;
        return;
    }

    // Limpiar stringstream
    ss.str("");
    ss.clear();

    // Crear directiva con los parámetros
    ss << "INSERT INTO ACCOUNTS (owner, balance, rate, currency) VALUES(" << client << ", 0, " << rate << ", '" << mon << "');";
    aux = ss.str();
    sql = aux.c_str();

    // Ejecutar la directiva
    rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Cuenta creada exitosamente!" << std::endl;
    }
};

void DBManager::deposit(int amount, int curr, int acc_ID) {
    stringstream ss;
    string aux;
    string mon;
    string colones = "₡";
    const unsigned char* acccurr;
    // Determinar el símbolo de la moneda
    if (curr == 1) mon = "$";
    else if (curr == 2) mon = "₡";
    else {
        std::cerr << "Moneda no válida. Usa 1 para USD y 2 para CRC." << std::endl;
        return;
    }

    // Consulta SELECT para obtener el balance actual
    ss.str("");
    ss.clear();
    ss << "SELECT balance, currency FROM ACCOUNTS WHERE account_ID = " << acc_ID << ";";
    aux = ss.str();
    sql = aux.c_str();

    // Preparar statement SELECT
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL Error: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    // Ejecutar consulta SELECT
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        double bal = sqlite3_column_double(stmt, 0);
        acccurr = sqlite3_column_text(stmt, 1);
        if (*((const char*) acccurr) == '$' && curr == 2) {
            // Formar y ejecutar consulta UPDATE
            ss.str(""); // Limpiar stringstream
            ss << "UPDATE ACCOUNTS SET balance = " << (bal + amount/EXCHANGE)
               << " WHERE account_ID = " << acc_ID << ";";
            aux = ss.str();
            sql = aux.c_str();
        } else if (*((const char*)acccurr) == *(colones.c_str()) && curr == 1) {
            // Formar y ejecutar consulta UPDATE
            ss.str(""); // Limpiar stringstream
            ss << "UPDATE ACCOUNTS SET balance = " << (bal + amount*EXCHANGE)
               << " WHERE account_ID = " << acc_ID << ";";
            aux = ss.str();
            sql = aux.c_str();
        } else {
            // Formar y ejecutar consulta UPDATE
            ss.str(""); // Limpiar stringstream
            ss << "UPDATE ACCOUNTS SET balance = " << (bal + amount)
               << " WHERE account_ID = " << acc_ID << ";";
            aux = ss.str();
            sql = aux.c_str();
        }

        // Ejecutar consulta UPDATE
        rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);
        if (rc != SQLITE_OK) {
            cerr << "SQL Error: " << errMsg << endl;
            sqlite3_free(errMsg);
            sqlite3_finalize(stmt);
            return;
        } else {
            cout << "Balance actualizado exitosamente!" << endl;
        }

        sqlite3_finalize(stmt);
    }
    // REgistrar transaccion
    addTransaction(acc_ID, acc_ID, amount, 1, -1);
};

void DBManager::withdrawal(int amount, int acc_ID){
    stringstream ss;
    string aux;

    // Consulta SELECT para obtener el balance actual
    ss << "SELECT balance FROM ACCOUNTS WHERE account_ID = " << acc_ID << ";";
    aux = ss.str();
    sql= aux.c_str();

    // Preparar statement SELECT
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "SQL Error: " << errMsg << endl;
        return;
    }

    // Ejecutar consulta SELECT
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        double bal = sqlite3_column_double(stmt, 0);
        cout << "Balance actual: " << bal << endl;

        // Verificar si el balance es suficiente para el retiro
        if (bal < amount) {
            cerr << "Error: Fondos insuficientes para realizar el retiro." << endl;
            sqlite3_finalize(stmt); // Finalizar statement SELECT
            return;
        }

        // Formar y ejecutar consulta UPDATE
        ss.str(""); // Limpiar stringstream
        ss << "UPDATE ACCOUNTS SET balance = " << (bal - amount)
           << " WHERE account_ID = " << acc_ID << ";";
        aux = ss.str();
        sql = aux.c_str();

        // Ejecutar consulta UPDATE
        rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);
        if (rc != SQLITE_OK) {
            cerr << "SQL Error: " << errMsg << endl;
            sqlite3_free(errMsg);
            sqlite3_finalize(stmt); // Finalizar statement SELECT
            return;
        } else {
            cout << "Balance actualizado exitosamente!" << endl;
        }

        // Finalizar statement SELECT
        sqlite3_finalize(stmt);
    }
    // Registrar transaccion
    addTransaction(acc_ID, acc_ID, amount, 2, -1);
};

void DBManager::transference(int amount, int acc_ID, int dest_acc_ID){
    stringstream ss;
    string aux;
    int bal;
    ss << "SELECT balance FROM ACCOUNTS WHERE account_ID = " << acc_ID << ";";
    aux = ss.str();
    sql = aux.c_str();

    // Preparar statement SELECT
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "SQL Error: " << sqlite3_errmsg(db) << endl;
        return;
    }

    // Ejecutar consulta SELECT
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        bal = sqlite3_column_double(stmt, 0);

        // Verificar si el balance es suficiente para la transferencia
        if (bal < amount) {
            cerr << "Error: Fondos insuficientes para realizar la transferencia." << endl;
            sqlite3_finalize(stmt); // Finalizar statement SELECT
            return;
        }
        
        ss.str(""); // Limpiar stringstream
        ss << "UPDATE ACCOUNTS SET balance = " << (bal - amount)
           << " WHERE account_ID = " << acc_ID << ";";
        aux = ss.str();
        sql = aux.c_str();

        // Ejecutar consulta UPDATE
        rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);
        if (rc != SQLITE_OK) {
            std::cerr << "SQL Error: " << errMsg << std::endl;
            sqlite3_free(errMsg);
            sqlite3_finalize(stmt); // Finalizar statement SELECT
            return;
        }

        // Finalizar statement SELECT
        sqlite3_finalize(stmt);
    }

    ss.str("");
    ss << "SELECT balance FROM ACCOUNTS WHERE account_ID = " << dest_acc_ID << ";";
    aux = ss.str();
    sql = aux.c_str();
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "SQL Error: " << sqlite3_errmsg(db) << endl;
        return;
    }

    // Ejecutar consulta SELECT
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        bal = sqlite3_column_double(stmt, 0);
        
        ss.str(""); // Limpiar stringstream
        ss << "UPDATE ACCOUNTS SET balance = " << (bal + amount)
           << " WHERE account_ID = " << dest_acc_ID << ";";
        aux = ss.str();
        sql = aux.c_str();

        // Ejecutar consulta UPDATE
        rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);
        if (rc != SQLITE_OK) {
            cerr << "SQL Error: " << errMsg << endl;
            sqlite3_free(errMsg);
            sqlite3_finalize(stmt); // Finalizar statement SELECT
            return;
        } else {
            cout << "Transferencia realizada exitosamente!" << endl;
        }

        // Finalizar statement SELECT
        sqlite3_finalize(stmt);
    }

    // Registrar la transaccion
    addTransaction(dest_acc_ID, acc_ID, amount, 3, -1);
};

void DBManager::loanPayment(int amount, int acc_ID, int loan_ID){
    stringstream ss;
    string aux;
    double bal;
    int made_payments, paid_amount;

    ss << "SELECT made_payments, paid_amount FROM LOANS WHERE loan_ID = " << loan_ID << ";";
    aux = ss.str();
    sql = aux.c_str();

    // Preparar statement SELECT
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "SQL Error: " << sqlite3_errmsg(db) << endl;
        return;
    }

    // Ejecutar consulta SELECT
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        made_payments = sqlite3_column_int(stmt, 0);
        paid_amount = sqlite3_column_int(stmt, 1);
        
        ss.str(""); // Limpiar stringstream
        ss << "UPDATE LOANS SET made_payments = " << (made_payments + 1)
           << ", paid_amount = " << (paid_amount + amount)
           << " WHERE loan_ID = " << loan_ID << ";";
        aux = ss.str();
        sql = aux.c_str();

        // Ejecutar consulta UPDATE
        rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);
        if (rc != SQLITE_OK) {
            std::cerr << "SQL Error: " << errMsg << std::endl;
            sqlite3_free(errMsg);
            sqlite3_finalize(stmt); // Finalizar statement SELECT
            return;
        } else {
            std::cout << "Abono realizado exitosamente!" << std::endl;
        }

        // Finalizar statement SELECT
        sqlite3_finalize(stmt);
    }

    ss.str(""); // Limpiar stringstream
    ss << "SELECT balance FROM ACCOUNTS WHERE account_ID = " << acc_ID << ";";
    aux = ss.str();
    sql = aux.c_str();

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "SQL Error: " << sqlite3_errmsg(db) << endl;
        return;
    }

    if (rc == SQLITE_ROW) {
        bal = sqlite3_column_double(stmt, 0);
        
        ss.str(""); // Limpiar stringstream
        ss << "UPDATE ACCOUNTS SET balance = " << (bal - amount)
           << " WHERE account_ID = " << acc_ID << ";";
        aux = ss.str();
        sql = aux.c_str();

        // Ejecutar consulta UPDATE
        rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);
        if (rc != SQLITE_OK) {
            std::cerr << "SQL Error: " << errMsg << std::endl;
            sqlite3_free(errMsg);
            sqlite3_finalize(stmt); // Finalizar statement SELECT
            return;
        }

        // Finalizar statement SELECT
        sqlite3_finalize(stmt);
    }

    // Registrar el abono
    addTransaction(acc_ID, acc_ID, amount, 4, loan_ID);
};

void DBManager::loanReport(int client_ID) {
    std::stringstream ss;
    std::string aux;
    ss << "SELECT C.client_ID, C.first_name, C.last_name, L.loan_ID, L.amount, L.interest, L.made_payments, L.paid_amount "
       << "FROM CLIENTS C "
       << "JOIN LOANS L ON C.client_ID = L.client_ID "
       << "WHERE C.client_ID = " << client_ID << ";";
    aux = ss.str();
    sql = aux.c_str();

    std::ofstream output_file("reporte.txt", std::ios::out); // Abrir archivo para escritura

    if (!output_file.is_open()) {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
        return;
    }

    int rc = sqlite3_exec(db, sql, getLoanReport, &output_file, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Reporte generado exitosamente! Revisar archivo reporte.txt en este directorio." << std::endl;
    }

    output_file.close(); // Cerrar el archivo
};
void DBManager::addTransaction(int accountID2, int accountID1, unsigned long int amountTransaction, int typeTransaction, int loanID){
    std::stringstream ss;
    string aux, typestr;
    ss.str("");

    // Convierte el argumento a un string que indica el tipo de transaccion
    if (typeTransaction == 1) typestr = "Depósito";
    else if (typeTransaction == 2) typestr = "Retiro";
    else if (typeTransaction == 3) typestr = "Transferencia";
    else if (typeTransaction == 4) typestr = "Abono a prestamo";
    // Crear directiva con los parametros
    ss << "INSERT INTO TRANSACTIONS (type, loan_ID, amount, source, destiny) VALUES('"
       << typestr << "' , " 
       << loanID << ","
       << amountTransaction << ", "
       << accountID1 << ", "
       << accountID2 << ");";
    aux = ss.str();
    // Alocar memoria del nuevo char*
    char* extra = new char[aux.length() + 1];
    // EScribir en el nuevo char*
    strcpy(extra, aux.c_str());
    // Asignar el string creado a la directiva SQL
    sql = extra;

    // Ejecutar la directiva
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Transaccion registrada exitosamente!" << endl;
        delete extra; // Liberar la memoria
    }
};

void DBManager::addLoan(int client_ID, int amount, float rate, int payments, int type, int curr){
    // String para crear directiva SQL
    std::stringstream ss;
    // Variables necesarias para la directiva
    string aux, typestr, currchar;

    // Asignar strings de tipo de prestamo y tipo de moneda basado en parametros
    if (type == 1) typestr = "Personal";
    else if (type == 2) typestr = "Prendario";
    else if (type == 3) typestr = "Hipotecario";

    if (curr == 1) currchar = "$";
    else if (curr == 2) currchar = "₡";

    // Directiva SQL
    ss << "INSERT INTO LOANS (client_ID, type, amount, payments, interest, made_payments, paid_amount, currency) "
        << "VALUES (" << client_ID << ", '" << typestr << "', " << amount << ", " << payments << ", " << rate << ", "
        << "0, 0, '" << currchar << "');";
    aux = ss.str();
    // Alocar memoria del nuevo char*
    char* extra = new char[aux.length() + 1];
    // EScribir en el nuevo char*
    strcpy(extra, aux.c_str());
    // Asignar el string creado a la directiva SQL
    sql = extra;
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Prestamo creado exitosamente!" << endl;
    }
};
