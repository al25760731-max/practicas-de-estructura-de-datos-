#include <iostream>
#include <string>

using namespace std;


void mostrarMenu();
int leerEntero(string mensaje, int min, int max);
float leerCalificacion(int numero);
float calcularPromedio(float suma, int n);
string obtenerEstado(float promedio);
void registrarEstudiante();


int main() {
    int opcion;

    do {
        mostrarMenu();
        opcion = leerEntero("opcion: ", 1, 3);

        switch (opcion) {
            case 1:
                registrarEstudiante();
                break;
            case 2:
                cout << "\nSistema de Calificaciones v1.0" << endl;
                break;
            case 3:
                cout << "\nCerrando programa..." << endl;
                break;
        }
        cout << endl;
    } while (opcion != 3);

    return 0;
}


// Imprime el menú principal
void mostrarMenu() {
    cout << "== SISTEMA DE CALIFICACIONES ==" << endl;
    cout << "1. Registrar estudiante" << endl;
    cout << "2. Ver informacion del programa" << endl;
    cout << "3. Salir" << endl;
}

// Pide un entero al usuario y valida que esté dentro del rango [min, max]
int leerEntero(string mensaje, int min, int max) {
    int valor;
    cout << mensaje;
    cin >> valor;

    while (cin.fail() || valor < min || valor > max) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada invalida. Ingrese un numero entre " << min << " y " << max << ": ";
        cin >> valor;
    }

    return valor;
}

// Pide y valida una calificación entre 0 y 10
float leerCalificacion(int numero) {
    float calificacion;
    cout << "Calificacion " << numero << ": ";
    cin >> calificacion;

    while (cin.fail() || calificacion < 0 || calificacion > 10) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Calificacion invalida. Ingrese un numero del 0 al 10: ";
        cin >> calificacion;
    }

    return calificacion;
}

// Calcula y retorna el promedio
float calcularPromedio(float suma, int n) {
    if (n <= 0) return 0;
    return suma / n;
}

// Retorna la categoría según el promedio obtenido
string obtenerEstado(float promedio) {
    if (promedio >= 9.0) {
        return "EXCELENTE";
    } else if (promedio >= 7.0) {
        return "APROBADO";
    } else if (promedio >= 6.0) {
        return "REGULAR (aprobado con lo minimo)";
    } else {
        return "REPROBADO";
    }
}

// Flujo completo de la opción 1
void registrarEstudiante() {
    string nombre;
    int edad;
    int numCalificaciones;
    float suma = 0;
    int aprobadas = 0, reprobadas = 0;
    float masAlta = -1;
    float masBaja = 11;

    cout << "\n--- REGISTRO DE ESTUDIANTE ---" << endl;
    cout << "Nombre: ";
    cin >> nombre;

    // Reutilizamos la función leerEntero para validar la edad
    edad = leerEntero("Edad: ", 0, 120);

    // Reutilizamos la función leerEntero para la cantidad de calificaciones
    numCalificaciones = leerEntero("¿Cuantas calificaciones deseas registrar?: ", 1, 100);

    for (int i = 1; i <= numCalificaciones; i++) {
        // Leemos cada calificación con la función correspondiente
        float calificacion = leerCalificacion(i);
        suma += calificacion;

        // Conteo de aprobadas y reprobadas
        if (calificacion >= 6) {
            aprobadas++;
        } else {
            reprobadas++;
        }

        // Determinar nota más alta y más baja
        if (calificacion > masAlta) {
            masAlta = calificacion;
        }
        if (calificacion < masBaja) {
            masBaja = calificacion;
        }
    }

    float promedio = calcularPromedio(suma, numCalificaciones);
    string estado = obtenerEstado(promedio);

    // Imprimir resumen final
    cout << "\n--- RESUMEN ---" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Estado: " << estado << endl;
    cout << "Calificaciones aprobatorias: " << aprobadas << endl;
    cout << "Calificaciones reprobatorias: " << reprobadas << endl;
    cout << "Calificacion mas alta: " << masAlta << endl;
    cout << "Calificacion mas baja: " << masBaja << endl;
}