#include <iostream>
#include <sqlite3.h>
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;

class DBManager{
    private:
        // Puntero a la base de datos SQLite3
        sqlite3 *db;
        // Mensaje de error
        char *errMsg;
        // Return code
        int rc;
        // Directiva SQL
        const char *sql;
        // ??
        const char* data = "Callback function called";
        // Callback function
        static int callback(void* data, int argc, char** argv, char** azColName);
        static int getLoanReport(void* data, int argc, char** argv, char** azColName);
    public:
        DBManager();
        ~DBManager();
        void checkClientID(int ID);
        void addClient(int idClient, std::string firsName, std::string lastName);
        void addAccount(int client, int curr, float rate);
        void deposit(int amount, int curr, int acc_ID);
        void withdrawal(int amount, int acc_ID);
        void transference(int amount, int curr, int acc_ID, int dest_acc_ID);
        void loanPayment(int amount, int curr, int loan_ID);
        void loanReport(int client_ID);
        void addTransaction(int accountID2, int accoutnID1, unsigned long int amountTransaction, int typeTransaction, int loanID);
        void addLoan(int client_ID, int amount, float rate, int payments, int type, int curr);
};