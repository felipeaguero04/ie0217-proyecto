#ifndef CLIENTMODE_HPP
#define CLIENTMODE_HPP
#include "DBManager.hpp"
void mostrarMenuAtencionClientes(DBManager* dbManager, const int& clientID);
void realizarDeposito(DBManager* dbManager);
void realizarRetiro(DBManager* dbManager);
void realizarTransferencia();
void abonarPrestamo();
void mostrarReportePrestamos(DBManager* dbManager, const int& clientID);

#endif // CLIENTMODE_HPP
