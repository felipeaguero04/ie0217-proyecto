#include "DBManager.hpp"

int DBManager::callback(void* data, int argc, char** argv, char** azColName){
    for(int i = 0; i < argc; i++){
        cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
    }
    return 0;
}

int DBManager::getLoanReport(void* data, int argc, char** argv, char** azColName){
    // Crear archivo para el reporte
    std::ofstream output_file("reporte.txt");
    if(output_file){
        // Imprimir todos los outputs 
        for(int i = 0; i < argc; i++){
            output_file << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
        }
    }
    return 0;
}

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

void DBManager::checkClientID(){

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
        cout << "Cuenta creada exitosamente!" << endl;
        delete extra; // Liberar la memoria
    }
};

void DBManager::addAccount(int client, int curr, float rate){
    // Verificar si ya hay dos cuentas
    // Crear un string con los parametros ingresados
    std::stringstream ss;
    string aux;

    // Agregar cuenta a la DB
    if (curr == 1){
        // LImpiar sstream
        ss.str("");
        // Crear directiva con los parametros
        ss << "INSERT INTO ACCOUNTS (owner, balance, rate, currency) VALUES(" << client << ", 0, " << rate << ", '$');";
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
            cout << "Cuenta creada exitosamente!" << endl;
            delete extra; // Liberar la memoria
        }

    } else if (curr == 2){
        // LImpiar sstream
        ss.str("");
        // Crear directiva con los parametros
        ss << "INSERT INTO ACCOUNTS (owner, balance, rate, currency) VALUES(" << client << ", 0, " << rate << ", '₡'); ";
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
            cout << "Cuenta creada exitosamente!" << endl;
            delete extra; // Liberar la memoria
        }
    }
}

void DBManager::deposit(int amount, int curr, int acc_ID){

}

void DBManager::withdrawal(int amount, int acc_ID){

};

void DBManager::transference(int amount, int curr, int acc_ID){

};

void DBManager::loanPayment(int amount, int curr, int loan_ID){

};

void DBManager::loanReport(int client_ID){
    std::stringstream ss;
    string aux;
    ss << "SELECT * FROM LOANS WHERE client_ID = " << client_ID << ";";
    aux = ss.str();
    // Alocar memoria del nuevo char*
    char* extra = new char[aux.length() + 1];
    // EScribir en el nuevo char*
    strcpy(extra, aux.c_str());
    // Asignar el string creado a la directiva SQL
    sql = extra;
    rc = sqlite3_exec(db, sql, getLoanReport, (void*)data, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Operation done successfully" << endl;
    }
};

void DBManager::addTransaction(int accountID2, int accountID1, unsigned long int amountTransaction, int typeTransaction, int loanID){
    std::stringstream ss;
    string aux, typestr;
    ss.str("");

    // Convierte el argumento a un string que indica el tipo de transaccion
    if (typeTransaction == 1) typestr = "Realizar Depósito";
    else if (typeTransaction == 2) typestr = "Realizar Retiro";
    else if (typeTransaction == 3) typestr = "Transferir entre Cuentas";
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
        cout << "Cuenta creada exitosamente!" << endl;
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
        cout << "Records created successfully" << endl;
    }
};