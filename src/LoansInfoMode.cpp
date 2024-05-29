#include "LoansInfoMode.hpp"

const void getGeneralLoanInfo(){
    int loanType, currency;
    do{
        cout << "------------------------------------------------" << endl;
        cout << "--------INFORMACIÓN GENERAL DE PRÉSTAMOS--------" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "\nMenu:" << endl;
        cout << "\t1. Préstamo personal." << endl;
        cout << "\t2. Préstamo prendario." << endl;
        cout << "\t3. Préstamo hipotecario." << endl;
        cout << "\t4. Volver." << endl;
        cout << "Ingrese su eleccion: ";
        cin >> loanType;
        cout << endl;
    }while(loanType != RETURN);
    
}