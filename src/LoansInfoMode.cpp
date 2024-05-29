#include "LoansInfoMode.hpp"

const void getGeneralLoanInfo(){
    // Opciones del menú
    int loanType, currency;

    // Char que indica si se personalzia la tabla de pagos
    char customTable; 

    // Variables para parámetros de la tabla de pagos
    float rate; // Tasa de interes
    int payments = 240, amount; // Cantidad de cuotas y monto

    do{
        // Encabezado del menu
        cout << "------------------------------------------------" << endl;
        cout << "--------INFORMACIÓN GENERAL DE PRÉSTAMOS--------" << endl;
        cout << "------------------------------------------------" << endl;

        // Preguntar tipo de moneda
        cout << "¿En cuál tipo de moneda desea cotizar el préstamo?" << endl;
        cout << "\t1. Dólares ($)" << endl;
        cout << "\t2. Colones (₡)" << endl;
        cout << "Ingrese su eleccion: ";
        cin >> currency;
        cout << endl;

        // Preguntar tipo de prestamo
        cout << "\nTipos de préstamo:" << endl;
        cout << "\t1. Préstamo personal." << endl;
        cout << "\t2. Préstamo prendario." << endl;
        cout << "\t3. Préstamo hipotecario." << endl;
        cout << "\t4. Volver." << endl;
        cout << "Ingrese su eleccion: ";
        cin >> loanType;
        cout << endl;

        // Sentencia switch-case para el tipo de préstamo
        switch (loanType){
            case PERSONAL:
                break;

            case PRENDARY:
                break;

            case MORTGAGE:
                break;

            case RETURN:
                cout << "Regresando al menú principal..." << endl;
                break;

            default:
                cout << "Seleccione un tipo de préstamo válido." << endl;
                break;
        }

        // TABLA DE PAGOS
        // --------------
        cout << "\nTABLA DE PAGOS" << endl;
        cout << "----------------" << endl;
        cout << "La tabla de pagos se mostrará usando los parámetros predeterminados para el tipo de préstamo seleccionado." << endl;
        cout << "Cantidad de cuotas: "<< payments << endl;
        cout << "Tasa de interés: "<< rate << "%" << endl;
        cout << "Ingrese el monto del préstamo: ";
        cin >> amount;
        cout << endl;
        // Pregunta si desea personalizar
        cout << "¿Desea personalizar la tasa de interés y la cantidad de cuotas? (Y/N)" << endl;
        cin >> customTable;
        cout << endl;

        if (customTable == 'Y' || customTable == 'y'){
            // Pedir nueva cantidad de cuotas
            cout << "Ingrese la cantidad de cuotas: ";
            cin >> payments;
            cout << endl;

            // Pedir nueva tasa de interes
            cout << "Ingrese la tasa de interés (0 - 1): ";
            cin >> rate;
            cout << endl;
        }

    }while(loanType != RETURN);
    
}