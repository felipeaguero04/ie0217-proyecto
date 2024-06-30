/**
 * @file InputValidator.hpp
 * @brief Este archivo contiene la clase InputValidator con métodos estáticos para validar entradas del usuario.
 */
#ifndef INPUT_VALIDATOR_HPP
#define INPUT_VALIDATOR_HPP

#include <iostream>
#include <stdexcept>
#include <limits>

/**
 * @class InputValidator
 * @brief Clase que valida diferentes tipos de entradas del usuario.
 */
class InputValidator {
public:
     /**
     * Valida la entrada del usuario para selecciones de menú.
     * @param input Referencia al número entero de entrada del usuario.
     * @return Verdadero si la entrada es válida, de lo contrario, lanza una excepción.
     * @throws std::invalid_argument si la entrada no es un número entero válido.
     */
    static bool menusValidatedInput(int& input);

    /**
     * Valida la entrada del usuario para enteros sin signo largos.
     * @param input Referencia al entero sin signo largo de entrada del usuario.
     * @return Verdadero si la entrada es válida, de lo contrario, lanza una excepción.
     * @throws std::invalid_argument si la entrada no es un entero sin signo largo válido.
     * @throws std::out_of_range si la entrada excede el rango de unsigned long int.
     */
    static bool amountValidatedInput(unsigned long int& input);
    
    /**
     * Valida la entrada del usuario para caracteres 'Y' o 'N'.
     * @param input Referencia al carácter de entrada del usuario.
     * @return Verdadero si la entrada es válida, de lo contrario, lanza una excepción.
     * @throws std::invalid_argument si la entrada no es 'Y', 'y', 'N' o 'n'.
     */
    static bool ynValidationInput(char& input);

    /**
     * Valida la entrada del usuario para pagos como enteros positivos.
     * @param input Referencia al entero de entrada del usuario.
     * @return Verdadero si la entrada es válida, de lo contrario, lanza una excepción.
     * @throws std::invalid_argument si la entrada no es un entero positivo válido.
     */
    static bool paymentsValidatedInput(int& input);

    /**
     * Valida la entrada del usuario para tasas de interés dentro de un rango específico según el tipo de préstamo.
     * @param input Referencia al número decimal de entrada del usuario.
     * @param loanType Entero que representa el tipo de préstamo.
     * @return Verdadero si la entrada es válida, de lo contrario, lanza una excepción.
     * @throws std::invalid_argument si la entrada no es un número decimal positivo válido o si loanType no es válido.
     */
    static bool rateValidatedInput(float& input, int loanType);

    /**
     * Valida la entrada del usuario para seleccionar un tipo de moneda.
     * @param input Referencia al entero de entrada del usuario.
     * @return Verdadero si la entrada es válida, de lo contrario, lanza una excepción.
     * @throws std::invalid_argument si la entrada no es 1 o 2.
     */
    static bool typeMoneyInput(int& input);
    
    /**
     * Valida la entrada del usuario para asegurarse de que sea un entero positivo.
     * @param input Referencia al entero de entrada del usuario.
     * @return Verdadero si la entrada es válida, de lo contrario, lanza una excepción.
     * @throws std::invalid_argument si la entrada no es un entero positivo o si hay un error en la entrada.
     */
    static bool intInput(int& input);
};

#endif // INPUT_VALIDATOR_HPP
