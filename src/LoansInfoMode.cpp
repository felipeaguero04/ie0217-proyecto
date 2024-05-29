#include "LoansInfoMode.hpp"

const void getGeneralLoanInfo(){
    int loanType, currency;
    do{
        cout << "------------------------------------------------" << endl;
        cout << "--------INFORMACIÓN GENERAL DE PRÉSTAMOS--------" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "En cuál tipo de moneda desea cotizar el préstamo?" << endl;
        cout << "\t1. Dólares ($)" << endl;
        cout << "\t2. Colones (₡)" << endl;
        cout << "Ingrese su eleccion: ";
        cin >> currency;
        cout << endl;
        cout << "\nTipos de préstamo:" << endl;
        cout << "\t1. Préstamo personal." << endl;
        cout << "\t2. Préstamo prendario." << endl;
        cout << "\t3. Préstamo hipotecario." << endl;
        cout << "\t4. Volver." << endl;
        cout << "Ingrese su eleccion: ";
        cin >> loanType;
        cout << endl;
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
    }while(loanType != RETURN);
    
}