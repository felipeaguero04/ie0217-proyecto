#include "DBManager.hpp"

int DBManager::callback(void* data, int argc, char** argv, char** azColName){
    for(int i = 0; i < argc; i++){
        cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
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
    sql = "CREATE TABLE IF NOT EXISTS CLIENTS ("
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

    // Crear tabla de cuentas en dolares
    sql = "CREATE TABLE IF NOT EXISTS ACCOUNTS("
        "owner INT NOT NULL,"
        "account_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
        "balance MONEY NOT NULL,"
        "rate FLOAT NOT NULL,"
        "currency CHAR NOT NULL);";
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Tabla creada exitosamente!" << endl;
    }

    // Crear tabla de registro de transacciones
    sql = "CREATE TABLE IF NOT EXISTS TRANSACTIONS("
        "transaction_ID INT PRIMARY KEY NOT NULL,"
        "type TEXT NOT NULL,"
        "loan_ID INT NOT NULL,"
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

void DBManager::addAccount(int client, int curr, float rate){
    if (curr == 1){
        // Crear un string con los parametros ingresados
        std::stringstream ss;
        ss << "INSERT INTO ACCOUNTS (owner, balance, rate, currency) VALUES(" << client << ", 0, " << rate << ", '$');";
        string aux = ss.str();
        char* extra = new char[aux.length() + 1];
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
        // Crear un string con los parametros ingresados
        std::stringstream ss;
        ss << "INSERT INTO ACCOUNTS (owner, balance, rate, currency) VALUES(" << client << ", 0, " << rate << ", '₡'); ";
        string aux = ss.str();
        char* extra = new char[aux.length() + 1];
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

};

void DBManager::addTransaction(){

};

void DBManager::addLoan(int amount, float rate, int payments, int type){
    
};