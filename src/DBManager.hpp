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
        // Constructor
        DBManager();
        // Destructor 
        ~DBManager();
};