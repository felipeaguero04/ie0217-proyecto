#include <iostream>
#include <sqlite3.h>

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
    public:
        DBManager();
        ~DBManager();
        void addAccount(int client, int curr, float rate);
        void deposit(int amount, int curr, int acc_ID);
        void withdrawal(int amount, int acc_ID);
        void transference(int amount, int curr, int acc_ID);
        void loanPayment(int amount, int curr, int loan_ID);
        void loanReport(int client_ID);
        void addTransaction();
        void addLoan(int amount, float rate, int payments, int type);
};
};