#include <iostream>
#include "Clientmode.hpp"
#include "InputValidator.hpp"
using namespace std;

void mostrarMenuAtencionClientes(DBManager* dbManager, const int& clientID) {
    int opcion;
    do {
        cout << "------------------------------------------------" << endl;
        cout << "-------OPERACIONES BANCARIAS DISPONIBLES--------" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "¿Cuál operación disponible desea realizar?" << endl;
        cout << "\t1. Realizar Depósito\n";
        cout << "\t2. Realizar Retiro\n";
        cout << "\t3. Transferencia entre Cuentas\n";
        cout << "\t4. Abonar a Préstamo\n";
        cout << "\t5. Mostrar Reporte de Préstamos\n";
        cout << "\t6. Volver al Menú Principal\n";
        cout << "Seleccione una opción: ";

        try {
            InputValidator::menusValidatedInput(opcion);
        } 
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
            continue; 
        }

        switch (opcion) {
            case 1:
                realizarDeposito(dbManager);
                break;
            case 2:
                realizarRetiro(dbManager);
                break;
            case 3:
                realizarTransferencia(dbManager);
                break;
            case 4:
                abonarPrestamo(dbManager);
                break;
            case 5:
                mostrarReportePrestamos(dbManager, clientID);
                break;
            case 6:
                return;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción del 1 al 6. Inténtelo de nuevo." << endl;
                break;
        }
    } while (opcion != 6);
}


void realizarDeposito(DBManager* dbManager) {
    int curr, acc_ID;
    unsigned long int amount;
    while (true){
        std::cout << "Ingrese el monto a depositar: ";
        // Solicita al usuario ingresar el monto del préstamo.                
        try {
            InputValidator::amountValidatedInput(amount);
        } 
        // El catch agarra el error 
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
            continue;
        }
        break;
    }

    while (true){
        std::cout << "Ingrese la moneda (1 para USD, 2 para CRC): ";
        // Solicita al usuario seleccionar el tipo de moneda.
        try {
            InputValidator::typeMoneyInput(curr);
        } 
        // El catch agarra el error 
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
            // Para que vuelva al menu a peir la opcion al usuario
            continue;
        }
        break;
    }

    std::cout << "Ingrese el ID de la cuenta: ";
    std::cin >> acc_ID;

    dbManager->deposit(amount, curr, acc_ID);
}

void realizarRetiro(DBManager* dbManager) {
    int acc_ID;
    unsigned long int amount;
    while (true){
        std::cout << "Ingrese el monto a retirar: ";
        // Solicita al usuario ingresar el monto del préstamo.                
        try {
            InputValidator::amountValidatedInput(amount);
        } 
        // El catch agarra el error 
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
            continue;
        }
        break;
    }

    std::cout << "Ingrese el ID de la cuenta: ";
    std::cin >> acc_ID;

    dbManager->withdrawal(amount, acc_ID);
}

void realizarTransferencia(DBManager* dbManager) {
    int amount, acc_ID, dest_acc_ID;
    std::cout << "Ingrese el monto a transferir: ";
    std::cin >> amount;
    std::cout << "Ingrese el ID de la cuenta origen: ";
    std::cin >> acc_ID;
    std::cout << "Ingrese el ID de la cuenta destino: ";
    std::cin >> dest_acc_ID;

    dbManager->transference(amount, acc_ID, dest_acc_ID);
};

void abonarPrestamo(DBManager* dbManager) {
    int amount, acc_ID, loan_ID;
    std::cout << "Ingrese el monto a abonar: ";
    std::cin >> amount;
    std::cout << "Ingrese el ID de la cuenta: ";
    std::cin >> acc_ID;
    std::cout << "Ingrese el ID del préstamo: ";
    std::cin >> loan_ID;

    dbManager->loanPayment(amount, acc_ID, loan_ID);
};
void mostrarReportePrestamos(DBManager* dbManager, const int& clientID) {
    dbManager->loanReport(clientID);
}
