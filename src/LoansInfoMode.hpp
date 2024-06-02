#ifndef LOANSINFOMODE_HPP
#define LOANSINFOMODE_HPP

#include <iostream>

enum Currencies {
    DOLLARS = 1,
    COLONES
};

enum LoanMenuOptions {
    PERSONAL = 1,
    PRENDARY,
    MORTGAGE,
    RETURN
};

// Function declarations for loan information retrieval
void getGeneralLoanInfo();
void getPersonalLoanInfo(float* _rate);
void getPrendaryLoanInfo(float* _rate);
void getMortgageInfo(float* _rate);

// Function declaration for payment table printing
void imprimirTablaPagos(unsigned long int monto, float tasaInteres, int numeroPagos);
double calcularPagoMensual(unsigned long int monto, float tasaInteres, int numeroPagos);

#endif // LOANSINFOMODE_HPP