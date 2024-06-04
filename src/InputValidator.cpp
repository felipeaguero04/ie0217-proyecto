#include "InputValidator.hpp"

bool InputValidator::menusValidatedInput(int& input) {
    std::cin >> input;
    // Revisa si hay errores, esto sucede si cin.good es false, es una flag de error
    if (!std::cin.good()) {
        // Se resetea el flag de error
        std::cin.clear(); 
        // Descartamos los caracteres que haya en el buffer de entrada  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        // Envia el error al catch
        throw std::invalid_argument("Error: Entrada no válida. Por favor, ingrese un número como se solicita en el menú.");
    }
    return true;
}


bool InputValidator::amountValidatedInput(unsigned long int& input) {
    std::cin >> input;
    // Revisa si hay errores, esto sucede si cin.good es false, es una flag de error
    if (!std::cin.good() || input < 0) {
        // Se resetea el flag de error
        std::cin.clear(); 
        // Descartamos los caracteres que haya en el buffer de entrada  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Envia el error al catch
        throw std::invalid_argument("Error: Entrada no válida. Por favor, ingrese un número que este en el rango de 0 a 4.294.967.295");
    }
    return true;
}

bool InputValidator::ynValidationInput(char& input) {
    std::cin >> input;
    // Revisa si hay errores, esto sucede si cin.good es false, es una flag de error
    if (!std::cin.good()) {
        // Se resetea el flag de error
        std::cin.clear(); 
        // Descartamos los caracteres que haya en el buffer de entrada  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Envia el error al catch
        throw std::invalid_argument("Error: Entrada no válida. Por favor, ingrese un caracter");
    } else if (input != 'y' && input != 'Y' && input != 'n' && input != 'N') {
        // Descartamos los caracteres que haya en el buffer de entrada 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Error: Entrada no válida. Por favor, ingrese 'Y', 'y', 'N' o 'n'.");
    }
    return true;
}

bool InputValidator::paymentsValidatedInput(int& input) {
    std::cin >> input;
    // Revisa si hay errores, esto sucede si cin.good es false, es una flag de error
    if (!std::cin.good() || input < 0) {
        // Se resetea el flag de error
        std::cin.clear(); 
        // Descartamos los caracteres que haya en el buffer de entrada  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        // Envia el error al catch
        throw std::invalid_argument("Error: Entrada no válida. Por favor, ingrese un número entero positivo.");
    }
    return true;
}

bool InputValidator::rateValidatedInput(float& input, int loanType) {
    std::cin >> input;
    // Revisa si hay errores, esto sucede si cin.good es false, es una flag de error
    if (!std::cin.good() || input < 0) {
        // Se resetea el flag de error
        std::cin.clear(); 
        // Descartamos los caracteres que haya en el buffer de entrada  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        throw std::invalid_argument("Error: Entrada no válida. Por favor, ingrese un número decimal positivo.");
    }

    // Revisa el rango sea el adecuado segun el tipo de prestamo
    bool validRange = false;
    // switch que depende de la entrada loanType que es el tipo de prestamo para sanber el rango 
    switch (loanType) {
        case 1:
            if (input >= 0.20 && input <= 0.25) {
                validRange = true;
            }
            break;
        case 2:
            if (input >= 0.15 && input <= 0.18) {
                validRange = true;
            }
            break;
        case 3:
            if (input >= 0.10 && input <= 0.12) {
                validRange = true;
            }
            break;
        default:
            throw std::invalid_argument("Error: Tipo de préstamo no válido.");
    }

    // Si entra a un case y es true significa que el rango es correcto para el tipo de prestamo
    if (!validRange) {
        throw std::invalid_argument("Error: Tasa de interés fuera del rango permitido.");
    }

    return true;
}