#include <iostream>
#include "Menu.hpp"
using namespace std;

int main(){
    int mainOption;
    do{
        cout << "-------------------------------------------" << endl;
        cout << "--------SISTEMA DE GESTION BANCARIA--------" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "\nMenu principal" << endl;
        cout << "\t1. Informacion general de prestamos." << endl;
        cout << "\t2. Atencion al cliente." << endl;
        cout << "\t3. Salir del sistema." << endl;

        cout << "Ingrese su eleccion: ";
        cin >> mainOption;
        cout << endl;

        switch(mainOption){
            case LOANS:
                break;
            case CLIENTS:
                break;
            case EXIT:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                break;
        }
    }while(mainOption != EXIT);

    return 0;
}