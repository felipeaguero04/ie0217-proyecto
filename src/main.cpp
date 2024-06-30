/**
 * @file main.cpp
 * @author Jorge Meneses (j.menesesgarro@gmail.com), Ismael Jimenez (ijime31@gmail.com) and Luis Felipe Aguero (felipe.aguero04@gmail.com)
 * @brief Implementacion principal del sistema de gestion bancaria.
 * @version 1.0
 * @date 2024-07-1
 * 
 * @copyright Copyright (c) 2024
 * 
 */

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
    int clientChek;
    DBManager DBManager;
    DBManager.addClient(305510245, "Luis", "F");
    DBManager.addClient(208190783, "Ismael", "Jimenez");
    DBManager.addAccount(208190783, 2, 0);
    DBManager.addAccount(305510245, 2, 0);
    DBManager.addLoan(305510245, 400000, 0.02, 20, 1, 2);
    DBManager.addLoan(208190783, 400000, 0.02, 20, 2, 2);

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
                while (true){
                    cout << "Ingrese el ID del cliente: " << endl;
                    // Solicita al usuario ingresar el monto del préstamo.                
                    try {
                        InputValidator::intInput(clientChek);
                    } 
                    // El catch agarra el error 
                    catch (const invalid_argument& e) {
                        cout << e.what() << endl;
                        continue;
                    }
                    break;
                }
                if (DBManager.checkClientID(clientChek) == 1){
                    DBManager.getAccountsInfo(clientChek);
                    mostrarMenuAtencionClientes(&DBManager, clientChek);
                } else {
                    continue;
                }
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
