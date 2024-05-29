#include "LoansInfoMode.hpp"

const void getPersonalLoanInfo(float* _rate){
    // Imprimir intormacion de los préstamos personales
    cout << "\nPRÉSTAMOS PERSONALES" << endl;
    cout << "---------------------" << endl;
    cout << "1. Crédito no asegurado" << endl;
    cout << "2. Útil para gastos médicos, educación, consolidación de deudas, entre otros" << endl;
    cout << "3. No requiere una garantía específica" << endl;
    cout << "4. Rango común de tasas de interés: 20%" << " - 25%" << endl;
    // Cambiar en memoria el interés predeterminado
    *_rate = 0.23;
    cout << "\nTasa de interés predeterminada: " << (*_rate)*100 << '%' << endl;
};

const void getPrendaryLoanInfo(float* _rate){
    // Imprimir intormacion de los préstamos prendarios
    cout << "\nPRÉSTAMOS PRENDARIOS" << endl;
    cout << "---------------------" << endl;
    cout << "1. Crédito asegurado por un bien mueble" << endl;
    cout << "2. Bien mueble: Joyas, vehículos, equipos electrónicos, etc." << endl;
    cout << "3. Bien mueble actúa como garantía" << endl;
    cout << "4. En caso de incumplimiento, el prestamista puede vender el bien para recuperar el monto prestado" << endl;
    cout << "5. Rango común de tasas de interés: 15%" << " - 18%" << endl;
    // Cambiar en memoria el interés predeterminado
    *_rate = 0.17;
    cout << "\nTasa de interés predeterminada: " << (*_rate)*100 << '%' << endl;
};

const void getMortgageInfo(float* _rate){
    // Imprimir intormacion de los préstamos hipotecarios
    cout << "\nPRÉSTAMOS HIPOTECARIOS" << endl;
    cout << "-----------------------" << endl;
    cout << "1. Crédito asegurado por un bien inmueble" << endl;
    cout << "2. Bien inmueble: Casas, terrenos, etc." << endl;
    cout << "3. Normalmente usaod para compra de bienes raíces" << endl;
    cout << "4. En caso de incumplimiento, el prestamista tiene el derecho de ejecutar la hipoteca y vender la propiedad para recuperar el monto prestado" << endl;
    cout << "5. Rango común de tasas de interés: 10%" << " - 12%" << endl;
    // Cambiar en memoria el interés predeterminado
    *_rate = 0.11;
    cout << "\nTasa de interés predeterminada: " << (*_rate)*100 << '%' << endl;
};

const void getGeneralLoanInfo(){
    // Opciones del menú
    int loanType, currency;

    // Char que indica si se personalzia la tabla de pagos
    char customTable; 

    // Variables para parámetros de la tabla de pagos
    float rate; // Tasa de interes
    int payments = 240; // Cantidad de cuotas
    unsigned long int amount; // Monto

    do{
        // Encabezado del menu
        cout << "------------------------------------------------" << endl;
        cout << "--------INFORMACIÓN GENERAL DE PRÉSTAMOS--------" << endl;
        cout << "------------------------------------------------" << endl;

        // Preguntar tipo de moneda
        cout << "¿En cuál tipo de moneda desea cotizar el préstamo?" << endl;
        cout << "\t1. Dólares ($)" << endl;
        cout << "\t2. Colones (₡)" << endl;
        cout << "Ingrese su eleccion: ";
        cin >> currency;
        cout << endl;

        // Sentencia switch-case para el tipo de moneda
        switch (currency){
            case DOLLARS:
                cout << "Ha seleccionado dólares estadounidenses ($)" << endl;
                break;

            case COLONES:
                cout << "Ha seleccionado colones costarricenses (₡)" << endl;
                break;

            default:
                cout << "Seleccione un tipo de moneda válido." << endl;
                goto check;
                break;
        }

        // Preguntar tipo de prestamo
        cout << "\nTipos de préstamo:" << endl;
        cout << "\t1. Préstamo personal." << endl;
        cout << "\t2. Préstamo prendario." << endl;
        cout << "\t3. Préstamo hipotecario." << endl;
        cout << "\t4. Volver." << endl;
        cout << "Ingrese su eleccion: ";
        cin >> loanType;
        cout << endl;

        // Sentencia switch-case para el tipo de préstamo
        switch (loanType){
            case PERSONAL:
                getPersonalLoanInfo(&rate);
                break;

            case PRENDARY:
                getPrendaryLoanInfo(&rate);
                break;

            case MORTGAGE:
                getMortgageInfo(&rate);
                break;

            case RETURN:
                cout << "Regresando al menú principal..." << endl;
                goto goback; // Saltar al final
                break;

            default:
                cout << "Seleccione un tipo de préstamo válido." << endl;
                goto check;
                break;
        }

        // TABLA DE PAGOS
        // --------------
        cout << "\nTABLA DE PAGOS" << endl;
        cout << "---------------" << endl;
        cout << "La tabla de pagos se mostrará usando los parámetros predeterminados para el tipo de préstamo seleccionado." << endl;
        cout << "Cantidad de cuotas: "<< payments << endl;
        cout << "Tasa de interés: "<< rate*100 << "%" << endl;
        cout << "Ingrese el monto del préstamo: ";
        cin >> amount;
        cout << endl;
        // Pregunta si desea personalizar
        cout << "¿Desea personalizar la tasa de interés y la cantidad de cuotas? (Y/N) ";
        cin >> customTable;
        cout << endl;

        if (customTable == 'Y' || customTable == 'y'){
            // Pedir nueva cantidad de cuotas
            cout << "Ingrese la cantidad de cuotas: ";
            cin >> payments;
            cout << endl;

            // Pedir nueva tasa de interes
            cout << "Ingrese la tasa de interés (0 - 1): ";
            cin >> rate;
            cout << endl;
        }

        // AQUI VA LA IMPRESION DE LA TABLA DE PAGOS

        check:
            cout << endl;
    }while(loanType != RETURN);

    goback:
        return;
}