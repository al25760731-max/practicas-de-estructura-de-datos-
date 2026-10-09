#include <iostream>
#include <limits>
using namespace std;

// Función auxiliar para leer enteros de forma segura
int leerEntero() {
    int valor;
    while (!(cin >> valor)) {
        cout << "error de caracteres ( solo caracteres numericos)" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return valor;
}

// Función auxiliar para leer decimales (floats) de forma segura
float leerFloat() {
    float valor;
    while (!(cin >> valor)) {
        cout << "error de caracteres ( solo caracteres numericos)" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return valor;
}

int main() {
    int pin;
    int opcion;
    float saldo = 5000.00;
    float deposito;
    int retiro;
    float comision;
    float total;
    bool acceso = false;
    int seleccion;
    int montoRapido;

    // Todos los numeros se muestran con 2 decimales
    cout << fixed;
    cout.precision(2);

    // ================= PARTE 1: PIN =================
    // for: maximo 3 intentos
    cout << "=== CAJERO AUTOMATICO ===" << endl;
    for (int intento = 1; intento <= 3; intento++) {
        cout << "Ingresa tu PIN: ";
        pin = leerEntero();

        if (pin == 1234) {
            cout << "\nPIN correcto. Bienvenido.\n" << endl;
            acceso = true;
            break;
        } else {
            cout << "PIN incorrecto. Intentos restantes: " << 3 - intento << "\n" << endl;
        }
    }

    if (!acceso) {
        cout << "Tarjeta bloqueada." << endl;
        return 0;
    }

    // ================= PARTE 2: MENU =================
    // do-while: se repite hasta elegir la opcion 5
    do {
        cout << "=== MENU ===" << endl;
        cout << "1. Consultar saldo" << endl;
        cout << "2. Depositar" << endl;
        cout << "3. Retirar" << endl;
        cout << "4. Retiros rapidos" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        opcion = leerEntero();

        if (opcion < 1 || opcion > 5) {
            cout << "\nError: la opcion no existe. Intenta de nuevo.\n" << endl;
            continue;
        }

        switch (opcion) {

            // ---------- CONSULTAR SALDO ----------
            case 1:
                cout << "\nSaldo disponible: $" << saldo << "\n" << endl;
                break;

            // ---------- DEPOSITAR ----------
            case 2:
                cout << "\nMonto a depositar: $";
                deposito = leerFloat();

                if (deposito <= 0) {
                    cout << "Error: el deposito debe ser mayor a $0.00.\n" << endl;
                } else if (deposito > 10000) {
                    cout << "Error: el deposito no puede exceder $10000.00.\n" << endl;
                } else {
                    saldo += deposito;
                    cout << "Exito: deposito realizado. Nuevo saldo: $" << saldo << "\n" << endl;
                }
                break;

            // ---------- RETIRAR ----------
            case 3:
                cout << "\nMonto a retirar: $";
                retiro = leerEntero();

                if (retiro <= 0) {
                    cout << "Error: el retiro debe ser mayor a $0.00.\n" << endl;
                } else if (retiro % 100 != 0) {
                    cout << "Error: el retiro debe ser multiplo de $100.\n" << endl;
                } else {
                    // Comision de $15 si el retiro es menor a $1000
                    if (retiro < 1000) {
                        comision = 15;
                    } else {
                        comision = 0;
                    }
                    total = retiro + comision;

                    if (total > saldo) {
                        cout << "Error: saldo insuficiente. Se necesitan $" << total
                             << " (retiro + comision de $" << comision << ")\n" << endl;
                    } else {
                        saldo -= total;
                        cout << "Exito: retiro de $" << (float)retiro << " realizado." << endl;
                        cout << "Comision: $" << comision << endl;
                        cout << "Nuevo saldo: $" << saldo << "\n" << endl;
                    }
                }
                break;

            // ---------- RETIROS RAPIDOS ----------
            case 4:
                cout << "\n=== RETIROS RAPIDOS ===" << endl;
                cout << "Saldo actual: $" << saldo << "\n" << endl;
                cout << "Opc\tMonto\t\tComision\tTotal\t\tDisponible" << endl;

                // for: de 500 a 3000 en incrementos de 500
                for (int i = 1; i <= 6; i++) {
                    montoRapido = i * 500;
                    if (montoRapido < 1000) {
                        comision = 15;
                    } else {
                        comision = 0;
                    }
                    total = montoRapido + comision;

                    cout << i << "\t$" << (float)montoRapido << "\t$" << comision << "\t\t$" << total << "\t";
                    if (total <= saldo) {
                        cout << "Si" << endl;
                    } else {
                        cout << "No" << endl;
                    }
                }
                cout << "0\tCancelar\n" << endl;

                cout << "Selecciona una opcion: ";
                seleccion = leerEntero();

                if (seleccion == 0) {
                    cout << "\nRetiro cancelado.\n" << endl;
                } else if (seleccion < 1 || seleccion > 6) {
                    cout << "\nError: la opcion no existe.\n" << endl;
                } else {
                    montoRapido = seleccion * 500;
                    if (montoRapido < 1000) {
                        comision = 15;
                    } else {
                        comision = 0;
                    }
                    total = montoRapido + comision;

                    if (total > saldo) {
                        cout << "\nError: saldo insuficiente. Se necesitan $" << total
                             << " (retiro + comision de $" << comision << ")\n" << endl;
                    } else {
                        saldo -= total;
                        cout << "\nExito: retiro de $" << (float)montoRapido << " realizado." << endl;
                        cout << "Comision: $" << comision << endl;
                        cout << "Nuevo saldo: $" << saldo << "\n" << endl;
                    }
                }
                break;

            // ---------- SALIR ----------
            case 5:
                cout << "\nGracias por usar el cajero. Hasta pronto." << endl;
                break;
        }

    } while (opcion != 5);

    return 0;
}