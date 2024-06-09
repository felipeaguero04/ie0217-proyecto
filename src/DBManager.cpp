#include "DBManager.hpp"

DBManager::DBManager(){
    // Crear y abrir la base de datos
    rc = sqlite3_open("banksys.db", &db);
    if (rc){
        cerr << "No se pudo abrir la base de datos: " << sqlite3_errmsg(db) << endl;
        exit (0);
    } else cout << "Base de datos abierta correctamente!" << endl;

    // Crear tabla clientes
    sql = "CREATE TABLE IF NOT EXISTS CLIENTS ("
        "client_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
        "first_name TEXT NOT NULL,"
        "last_name TEXT NOT NULL,"
        "CHECK(client_ID <= 999999999)";
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
        "loan_ID INT PRIMARY KEY NOT NULL,"
        "type TEXT NOT NULL,"
        "amount MONEY NOT NULL,"
        "payments INT NOT NULL,"
        "interest FLOAT NOT NULL,"
        "made_payments INT NOT NULL,"
        "paid_amount MONEY NOT NULL,"
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
        "transaction_ID INT NOT NULL,"
        "type TEXT NOT NULL,"
        "loan_ID INT NOT NULL,"
        "amount MONEY NOT NULL,"
        "source INT NOT NULL,"
        "destiny INT NOT NULL);";
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Tabla creada exitosamente!" << endl;
    }

    // Crear tabla de cuentas en dolares
    sql = "CREATE TABLE IF NOT EXISTS DOLLAR_ACCOUNTS("
        "owner INT NOT NULL,"
        "account_ID BIGINT PRIMARY KEY NOT NULL,"
        "balance MONEY NOT NULL,"
        "interest FLOAT NOT NULL,"
        "CHECK(account_ID % 2 = 0));" ;
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Tabla creada exitosamente!" << endl;
    }

    // Crear tabla de registro de transacciones
    sql = "CREATE TABLE IF NOT EXISTS COLONES_ACCOUNTS("
        "owner INT NOT NULL,"
        "account_ID BIGINT PRIMARY KEY NOT NULL,"
        "balance MONEY NOT NULL,"
        "interest FLOAT NOT NULL,"
        "CHECK(account_ID % 2 != 0));";
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg); 
    } else {
        cout << "Tabla creada exitosamente!" << endl;
    }
};

DBManager::~DBManager(){
    sqlite3_close(db);
    cout << "Base de datos cerrada correctamente!" << endl;
};

int DBManager::callback(void* data, int argc, char** argv, char** azColName){
    for(int i = 0; i < argc; i++){
        cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
    }
    return 0;
}

void DBManager::addAccount(int client, int curr, float rate){

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