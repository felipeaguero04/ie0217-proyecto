#include <iostream>
#include "MainMenu.hpp"
#include "LoansInfoMode.hpp"
#include "InputValidator.hpp"
#include <stdexcept>
#include <limits>
#include "DBManager.hpp"
#include "Clientmode.hpp"

using namespace std;

int main(){
    int mainOption;
    DBManager DBManager;
    do{
        cout << "-------------------------------------------" << endl;
        cout << "--------SISTEMA DE GESTION BANCARIA--------" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "\nMenu principal" << endl;
        cout << "\t1. Informacion general de prestamos." << endl;
        cout << "\t2. Atencion al cliente." << endl;
        cout << "\t3. Salir del sistema." << endl;

        cout << "Ingrese su eleccion: ";

        try {
            InputValidator::menusValidatedInput(mainOption);
        } 
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
            continue; 
        }

        switch(mainOption){
            case LOANS:
                getGeneralLoanInfo();
                break;
            case CLIENTS:
                mostrarMenuAtencionClientes();
                break;
            case EXIT:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción del 1 al 3. Inténtelo de nuevo." << endl;
                break;
        }
    } while(mainOption != EXIT);
    return 0;
}
