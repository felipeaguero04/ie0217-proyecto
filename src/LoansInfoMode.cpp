#include "LoansInfoMode.hpp"
#include "InputValidator.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Función que muestra información sobre préstamos personales y establece una tasa de interés predeterminada.
void getPersonalLoanInfo(float* _rate) {
    cout << "\nPRÉSTAMOS PERSONALES" << endl;
    cout << "---------------------" << endl;
    cout << "1. Crédito no asegurado" << endl;  // El préstamo no requiere una garantía específica.
    cout << "2. Útil para gastos médicos, educación, consolidación de deudas, entre otros" << endl;  // Aplicable para diversos gastos.
    cout << "3. No requiere una garantía específica" << endl;  // Se reitera que no se necesita una garantía.
    cout << "4. Rango común de tasas de interés: 20% - 25%" << endl;  // Indica el rango típico de tasas de interés.
    *_rate = 0.23;  // Establece una tasa de interés predeterminada del 23%.
    cout << "\nTasa de interés predeterminada: " << (*_rate) * 100 << '%' << endl;  // Muestra la tasa de interés predeterminada.
}

// Función que muestra información sobre préstamos prendarios y establece una tasa de interés predeterminada.
void getPrendaryLoanInfo(float* _rate) {
    cout << "\nPRÉSTAMOS PRENDARIOS" << endl;
    cout << "---------------------" << endl;
    cout << "1. Crédito asegurado por un bien mueble" << endl;  // El préstamo está respaldado por un bien mueble.
    cout << "2. Bien mueble: Joyas, vehículos, equipos electrónicos, etc." << endl;  // Ejemplos de bienes muebles que pueden actuar como garantía.
    cout << "3. Bien mueble actúa como garantía" << endl;  // Se reitera el uso del bien mueble como garantía.
    cout << "4. En caso de incumplimiento, el prestamista puede vender el bien para recuperar el monto prestado" << endl;  // Consecuencia del incumplimiento del préstamo.
    cout << "5. Rango común de tasas de interés: 15% - 18%" << endl;  // Indica el rango típico de tasas de interés.
    *_rate = 0.17;  // Establece una tasa de interés predeterminada del 17%.
    cout << "\nTasa de interés predeterminada: " << (*_rate) * 100 << '%' << endl;  // Muestra la tasa de interés predeterminada.
}

// Función que muestra información sobre préstamos hipotecarios y establece una tasa de interés predeterminada.
void getMortgageInfo(float* _rate) {
    cout << "\nPRÉSTAMOS HIPOTECARIOS" << endl;
    cout << "-----------------------" << endl;
    cout << "1. Crédito asegurado por un bien inmueble" << endl;  // El préstamo está respaldado por un bien inmueble.
    cout << "2. Bien inmueble: Casas, terrenos, etc." << endl;  // Ejemplos de bienes inmuebles que pueden actuar como garantía.
    cout << "3. Normalmente usado para compra de bienes raíces" << endl;  // Uso común del préstamo hipotecario.
    cout << "4. En caso de incumplimiento, el prestamista tiene el derecho de ejecutar la hipoteca y vender la propiedad para recuperar el monto prestado" << endl;  // Consecuencia del incumplimiento del préstamo.
    cout << "5. Rango común de tasas de interés: 10% - 12%" << endl;  // Indica el rango típico de tasas de interés.
    *_rate = 0.11;  // Establece una tasa de interés predeterminada del 11%.
    cout << "\nTasa de interés predeterminada: " << (*_rate) * 100 << '%' << endl;  // Muestra la tasa de interés predeterminada.
}

// Función que calcula el pago mensual de un préstamo utilizando el monto, la tasa de interés y el número de pagos.
double calcularPagoMensual(unsigned long int monto, float tasaInteres, int numeroPagos) {
    return (monto * (tasaInteres / 12)) / (1 - pow(1 + (tasaInteres / 12), -numeroPagos));  // Fórmula de pago mensual.
}

// Función que imprime una línea divisoria en la tabla de pagos.
void imprimirLineaDivisoria(int anchos[], int numColumnas) {
    for (int i = 0; i < numColumnas; ++i) {
        cout << "+";  // Imprime el inicio de la columna.
        for (int j = 0; j < anchos[i]; ++j) {
            cout << "-";  // Imprime la longitud de la columna.
        }
    }
    cout << "+" << endl;  // Imprime el final de la línea.
}

// Función que imprime una fila de la tabla de pagos.
void imprimirFila(const vector<string>& fila, const vector<int>& anchos) {
    cout << left;  // Alinea el texto a la izquierda.
    for (size_t i = 0; i < fila.size(); ++i) {
        cout << "| " << setw(anchos[i] - 2) << fila[i];  // Imprime cada celda de la fila.
    }
    cout << "|" << endl;  // Finaliza la fila.
}

// Función que imprime la tabla de pagos completa.
void imprimirTablaPagos(unsigned long int monto, float tasaInteres, int numeroPagos) {
    vector<vector<string>> tabla;  // Almacena las filas de la tabla.

    tabla.push_back({"Cuota", "Monto Inicial", "Interés", "Capital", "Monto Final"});  // Cabecera de la tabla.

    double pagoMensual = calcularPagoMensual(monto, tasaInteres, numeroPagos);  // Calcula el pago mensual.
    double montoInicial = monto;  // Inicializa el monto inicial.
    double interes, capital;

    for (int i = 1; i <= numeroPagos; ++i) {
        interes = montoInicial * (tasaInteres / 12);  // Calcula el interés del mes.
        capital = pagoMensual - interes;  // Calcula el capital del mes.
        double montoFinal = montoInicial - capital;  // Calcula el monto final después del pago.

        stringstream ss;  // Utiliza stringstream para formatear los números.
        ss << fixed << setprecision(2);

        ss << i;
        string cuota = ss.str();
        ss.str("");

        ss << fixed << setprecision(2) << montoInicial;
        string montoInicialStr = ss.str();
        ss.str("");

        ss << fixed << setprecision(2) << interes;
        string interesStr = ss.str();
        ss.str("");

        ss << fixed << setprecision(2) << capital;
        string capitalStr = ss.str();
        ss.str("");

        ss << fixed << setprecision(2) << montoFinal;
        string montoFinalStr = ss.str();
        ss.str("");

        tabla.push_back({cuota, montoInicialStr, interesStr, capitalStr, montoFinalStr});  // Agrega la fila a la tabla.

        montoInicial = montoFinal;  // Actualiza el monto inicial para la siguiente iteración.
    }

    int anchos[] = {8, 15, 13, 13, 16};  // Define los anchos de las columnas.

    imprimirLineaDivisoria(anchos, 5);  // Imprime la línea divisoria superior.
    for (size_t i = 0; i < tabla.size(); ++i) {
        imprimirFila(tabla[i], vector<int>(begin(anchos), end(anchos)));  // Imprime cada fila de la tabla.
        imprimirLineaDivisoria(anchos, 5);  // Imprime la línea divisoria después de cada fila.
    }
}

// Función principal que gestiona la información general de los préstamos y permite personalizar las tablas de pagos.
void getGeneralLoanInfo() {
    int loanType = 0, currency = 0;
    char customTable;
    float rate = 0.0f;
    int payments = 240;
    unsigned long int amount = 0;

    while (true) {
        cout << "------------------------------------------------" << endl;
        cout << "--------INFORMACIÓN GENERAL DE PRÉSTAMOS--------" << endl;
        cout << "------------------------------------------------" << endl;

        cout << "¿En cuál tipo de moneda desea cotizar el préstamo?" << endl;
        cout << "\t1. Dólares ($)" << endl;
        cout << "\t2. Colones (₡)" << endl;
        cout << "\t3. Volver" << endl;
        cout << "Ingrese su elección: ";

        // Solicita al usuario seleccionar el tipo de moneda.
        try {
            InputValidator::menusValidatedInput(currency);
        } 
        // El catch agarra el error 
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
            // Para que vuelva al menu a peir la opcion al usuario
            continue; 
        }


        if (currency == 1) {  // Verifica si se seleccionaron dólares.
            cout << "Ha seleccionado dólares estadounidenses ($)" << endl;
        } else if (currency == 2) {  // Verifica si se seleccionaron colones.
            cout << "Ha seleccionado colones costarricenses (₡)" << endl;
        } else if(currency == 3){
            cout << "Regresando al menú principal..." << endl;
            return;
        }else {
            cout << "Opción no válida. Por favor, seleccione una opción del 1 al 2. Inténtelo de nuevo." << endl;  // Maneja la selección de moneda inválida.
            continue;
        }

        cout << "\nTipos de préstamo:" << endl;
        cout << "\t1. Préstamo personal." << endl;
        cout << "\t2. Préstamo prendario." << endl;
        cout << "\t3. Préstamo hipotecario." << endl;
        cout << "\t4. Volver." << endl;
        cout << "Ingrese su elección: ";
    
        // Solicita al usuario seleccionar el tipo de préstamo.
        try {
            InputValidator::menusValidatedInput(loanType);
        } 
        // El catch agarra el error 
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
            // Para que vuelva al menu a peir la opcion al usuario
            continue; 
        }

        switch (loanType) {
            case 1:
                getPersonalLoanInfo(&rate);  // Muestra información sobre préstamos personales.
                break;
            case 2:
                getPrendaryLoanInfo(&rate);  // Muestra información sobre préstamos prendarios.
                break;
            case 3:
                getMortgageInfo(&rate);  // Muestra información sobre préstamos hipotecarios.
                break;
            case 4:
                cout << "Regresando al menú principal..." << endl;
                return;  // Regresa al menú principal.
            default:
                cout << "Opción no válida. Por favor, seleccione una opción del 1 al 4. Inténtelo de nuevo." << endl;  // Maneja la selección de préstamo inválida.
                continue;
        }

        cout << "\nTABLA DE PAGOS" << endl;
        cout << "---------------" << endl;
        cout << "La tabla de pagos se mostrará usando los parámetros predeterminados para el tipo de préstamo seleccionado." << endl;
        cout << "Cantidad de cuotas: " << payments << endl;
        cout << "Tasa de interés: " << rate * 100 << "%" << endl;
        cout << "Ingrese el monto del préstamo: ";

        // Solicita al usuario ingresar el monto del préstamo.                
        try {
            InputValidator::amountValidatedInput(amount);
        } 
        // El catch agarra el error 
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
            // Para que vuelva al menu a peir la opcion al usuario
            continue; 
        }


        cout << "¿Desea personalizar la tasa de interés y la cantidad de cuotas? (Y/N) ";
        // Solicita al usuario si desea personalizar la tabla de pagos.                
        try {
            InputValidator::ynValidationInput(customTable);
        } 
        // El catch agarra el error 
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
            // Para que vuelva al menu a peir la opcion al usuario
            continue; 
        }

        if (customTable == 'Y' || customTable == 'y') {
            cout << "Ingrese la cantidad de cuotas: ";
            // Solicita al usuario ingresar la cantidad de cuotas.
            try {
            InputValidator::paymentsValidatedInput(payments);
            } 
            // El catch agarra el error 
            catch (const invalid_argument& e) {
                cout << e.what() << endl;
                // Para que vuelva al menu a peir la opcion al usuario
                continue; 
            }
            
            cout << "Ingrese la tasa de interés (0 - 100): ";
            // Solicita al usuario ingresar la tasa de interés.
            try {
            InputValidator::rateValidatedInput(rate, loanType);
            } 
            // El catch agarra el error 
            catch (const invalid_argument& e) {
                cout << e.what() << endl;
                // Para que vuelva al menu a peir la opcion al usuario
                continue; 
            }
        }

        imprimirTablaPagos(amount, rate, payments);  // Imprime la tabla de pagos personalizada.
    }
}
