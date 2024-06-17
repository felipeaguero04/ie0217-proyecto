#include <iostream>
#include "Clientmode.hpp"

using namespace std;

void mostrarMenuAtencionClientes() {
    int opcion;
    do {
        cout << "\n--- Operaciones Bancarias disponibles ---\n";
        cout << "1. Realizar Depósito\n";
        cout << "2. Realizar Retiro\n";
        cout << "3. Transferencia entre Cuentas\n";
        cout << "4. Abonar a Préstamo\n";
        cout << "5. Mostrar Reporte de Préstamos\n";
        cout << "6. Volver al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                realizarDeposito();
                break;
            case 2:
                realizarRetiro();
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

void realizarDeposito() {
    cout << "Función para realizar depósito.\n";
    // Implementación de la lógica de depósito va aquí
}

void realizarRetiro() {
    cout << "Función para realizar retiro.\n";
    // Implementación de la lógica de retiro va aquí
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