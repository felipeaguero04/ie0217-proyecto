/**
 * @file Clientmode.hpp
 * @author Jorge Meneses (j.menesesgarro@gmail.com), Ismael Jimenez (ijime31@gmail.com) and Luis Felipe Aguero (felipe.aguero04@gmail.com)
 * @brief Header file para el modo de atencion al cliente.
 * @version 1.0
 * @date 2024-07-1
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef CLIENTMODE_HPP
#define CLIENTMODE_HPP

#include "DBManager.hpp"

/**
 * @brief Muestra el menú de atención a clientes.
 * 
 * @param dbManager Puntero al administrador de la base de datos.
 * @param clientID ID del cliente.
 */
void mostrarMenuAtencionClientes(DBManager* dbManager, const int& clientID);

/**
 * @brief Realiza un depósito en una cuenta.
 * 
 * @param dbManager Puntero al administrador de la base de datos.
 */
void realizarDeposito(DBManager* dbManager);

/**
 * @brief Realiza un retiro de una cuenta.
 * 
 * @param dbManager Puntero al administrador de la base de datos.
 */
void realizarRetiro(DBManager* dbManager);

/**
 * @brief Realiza una transferencia entre cuentas.
 * 
 * @param dbManager Puntero al administrador de la base de datos.
 */
void realizarTransferencia(DBManager* dbManager);

/**
 * @brief Abona un pago a un préstamo.
 * 
 * @param dbManager Puntero al administrador de la base de datos.
 */
void abonarPrestamo(DBManager* dbManager);

/**
 * @brief Muestra un reporte de los préstamos de un cliente.
 * 
 * @param dbManager Puntero al administrador de la base de datos.
 * @param clientID ID del cliente.
 */
void mostrarReportePrestamos(DBManager* dbManager, const int& clientID);


/**
 * @brief Pide un préstamo.
 * 
 * @param dbManager Puntero al administrador de la base de datos.
 */
void PedirPrestamos(DBManager* dbManager);
#endif // CLIENTMODE_HPP
