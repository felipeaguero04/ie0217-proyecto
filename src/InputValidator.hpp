#ifndef INPUT_VALIDATOR_HPP
#define INPUT_VALIDATOR_HPP

#include <iostream>
#include <stdexcept>
#include <limits>

class InputValidator {
public:
    // Excepcion para que el usuario solo pueda meter numero enteros segun el menu
    static bool menusValidatedInput(int& input);
    // Excepcion para que el usuario ingrese un unsifned long int y que no se encicle el cin
    static bool amountValidatedInput(unsigned long int& input);
    // Excepcion para que el usuario ingrese un char Y, y o N, n
    static bool ynValidationInput(char& input);
    // Excepcion para que se ingrese entero para la cantidad de cuotas
    static bool paymentsValidatedInput(int& input);
    // Excepcion para que se ingrese un rango permitido segun el tipo de prestamo
    static bool rateValidatedInput(float& input, int loanType);
    
};

#endif // INPUT_VALIDATOR_HPP
