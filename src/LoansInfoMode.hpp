/**
 * @file LoansInfoMode.hpp
 * @author Jorge Meneses (j.menesesgarro@gmail.com), Ismael Jimenez (ijime31@gmail.com) and Luis Felipe Aguero (felipe.aguero04@gmail.com)
 * @brief Modalidad de informacion general de prestamos
 * @version 1.0
 * @date 2024-07-1
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef LOANSINFOMODE_HPP
#define LOANSINFOMODE_HPP

#include <iostream>

/**
 * @brief Enum usado para identificar entre dolares y colones en los menus.
 * 
 */
enum Currencies {
    DOLLARS = 1,
    COLONES
};

/**
 * @brief Enum para las opciones de tipos de prestamos.
 * 
 */
enum LoanMenuOptions {
    PERSONAL = 1,
    PRENDARY,
    MORTGAGE,
    RETURN
};

/**
 * @brief Menu inicial de la modalidad de informacion de prestamos.
 * 
 */
void getGeneralLoanInfo();

/**
 * @brief Obtener la informacion sobre prestamos personales.
 * 
 * @param _rate Tasa de interes.
 */
void getPersonalLoanInfo(float* _rate);

/**
 * @brief Obtener la informacion sobre prestamos prendarios.
 * 
 * @param _rate Tasa de interes
 */
void getPrendaryLoanInfo(float* _rate);

/**
 * @brief Obtener la informacion sobre prestamos hipotecarios.
 * 
 * @param _rate Tasa de interes
 */
void getMortgageInfo(float* _rate);

/**
 * @brief Funcion que imprime la tabla de pagos para un prestamo establecido.
 * 
 * @param monto Monto por el que se pide el prestamo.
 * @param tasaInteres Tasa de interes del prestamo.
 * @param numeroPagos Cantidad de cuotas del prestamo.
 */
void imprimirTablaPagos(unsigned long int monto, float tasaInteres, int numeroPagos);

/**
 * @brief Calculo de la cuota mensual del prestamo.
 * 
 * @param monto Monto sobre el que se calcula.
 * @param tasaInteres Tasa de interes del prestamo.
 * @param numeroPagos Cantidad de cuotas del prestamo.
 * @return double Cuota.
 */
double calcularPagoMensual(unsigned long int monto, float tasaInteres, int numeroPagos);

#endif // LOANSINFOMODE_HPP