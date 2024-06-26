#include <iostream>
#include "Clientmode.hpp"
using namespace std;

void mostrarMenuAtencionClientes() {
    DBManager DBManager;
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
        cin >> opcion;

        switch (opcion) {
            case 1:
                realizarDeposito(DBManager);
                break;
            case 2:
                realizarRetiro(DBManager);
                break;
            case 3:
                realizarTransferencia();
                break;
            case 4:
                abonarPrestamo();
                break;
            case 5:
                mostrarReportePrestamos();
                break;
            case 6:
                return;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 6);
}


void realizarDeposito(DBManager& DBManager) {
    int amount, curr, acc_ID;
    std::cout << "Ingrese el monto a depositar: ";
    std::cin >> amount;
    std::cout << "Ingrese la moneda (1 para USD, 2 para CRC): ";
    std::cin >> curr;
    std::cout << "Ingrese el ID de la cuenta: ";
    std::cin >> acc_ID;

    DBManager.deposit(amount, curr, acc_ID);
}
void realizarRetiro(DBManager& DBManager) {
    int amount, acc_ID;
    std::cout << "Ingrese el monto a retirar: ";
    std::cin >> amount;
    std::cout << "Ingrese el ID de la cuenta: ";
    std::cin >> acc_ID;

    DBManager.withdrawal(amount, acc_ID);
}

void realizarTransferencia() {
    cout << "Función para realizar transferencia.\n";
    // Implementación de la lógica de transferencia va aquí
}

void abonarPrestamo() {
    cout << "Función para abonar a préstamo.\n";
    // Implementación de la lógica de abono a préstamo va aquí
}

void mostrarReportePrestamos() {
    cout << "Función para mostrar reporte de préstamos.\n";
    // Implementación de la lógica de reporte de préstamos va aquí
}
