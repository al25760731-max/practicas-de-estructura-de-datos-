#include <iostream>
#include <string>

using namespace std;

int main() {
    string nombre;
    int edad;
    float calificacion1, calificacion2, calificacion3, promedio;

    // Pedir datos
    cout << "Nombre: ";
    cin >> nombre;

    cout << "Edad: ";
    cin >> edad;

    // Validar edad
    if (edad < 0 || edad > 120) {
        cout << "Edad invalida" << endl;
        return 1;
    }

    cout << "Calificacion 1: ";
    cin >> calificacion1;

    cout << "Calificacion 2: ";
    cin >> calificacion2;

    cout << "Calificacion 3: ";
    cin >> calificacion3;

    // Validar calificaciones
    if (calificacion1 < 0 || calificacion1 > 10 || 
        calificacion2 < 0 || calificacion2 > 10 || 
        calificacion3 < 0 || calificacion3 > 10) {
        cout << "Calificacion invalida" << endl;
        return 1;
    }

    // Calcular promedio
    promedio = (calificacion1 + calificacion2 + calificacion3) / 3;

    // Imprimir resumen
    cout << "\n--- RESUMEN ---" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Promedio: " << promedio << endl;

    // Estado del estudiante
    if (promedio >= 9) {
        cout << "Estado: EXCELENTE" << endl;
    } else if (promedio >= 7) {
        cout << "Estado: APROBADO" << endl;
    } else if (promedio >= 6) {
        cout << "Estado: REGULAR (aprobado con lo minimo)" << endl;
    } else {
        cout << "Estado: REPROBADO" << endl;
    }

    return 0;
}