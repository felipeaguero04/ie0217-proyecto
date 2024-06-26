#ifndef CLIENTMODE_HPP
#define CLIENTMODE_HPP
#include "DBManager.hpp"
void mostrarMenuAtencionClientes();
void realizarDeposito(DBManager& DBmanager);
void realizarRetiro(DBManager& DBmanager);
void realizarTransferencia();
void abonarPrestamo();
void mostrarReportePrestamos();

#endif // CLIENTMODE_HPP
