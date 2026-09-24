#include <iostream>
#include <string>

using namespace std;

int main()
{
    string nombre;
    int edad;
    int opcion;
    int numCalificaciones;
    float calificaciones;
    float suma = 0; 
    int aprobadas = 0, reprobadas = 0;
    float masAltas = -1;
    float masBajas = 11;
    float promedio;
   do { 
    cout << "== SISTEMA DE CALIFICACIONES ==" <<endl;
    cout << "1. registrar estudiante" <<endl;
    cout << "2. ver informacion del programa" <<endl;
    cout << "3. salir" <<endl;
    cout << "opcion: ";
    cin >>opcion;  
    if (cin.fail()){
        cin.clear();
        cin.ignore(10000, '\n');
    opcion = 0;
    }
   switch (opcion){
    case 1:{ 
       // Pedir datos
        cout << "Nombre: ";
        cin >> nombre;

        cout << "Edad: ";
        cin >> edad;

        // Validar edad
       while (cin.fail() || edad < 0 || edad > 120) {
        cin.clear();
        cin.ignore(10000, '\n'); 
        cout << "Edad invalida. solo se puede ingresar del 0 al 120" << endl;
        cin >> edad; 
    }
    cout << "cuantas calificaciones deseas registrar?: ";
    cin >> numCalificaciones;

   while (cin.fail() || numCalificaciones <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Cantidad invalida de calificaciones, ingresa un numero mayor a 0 ";
        cin >> numCalificaciones;
    }

    for (int i = 1; i <= numCalificaciones; i++) {
        cout << "calificacion " << i << ": ";
        cin >> calificaciones;

    // Validar calificaciones
    while(cin.fail() || calificaciones < 0 || calificaciones > 10 ){
        cin.clear();
        cin.ignore(10000, '\n');
        cout <<"calificacion invalida.  ingrese un numero del 0 al 10";
        cin >> calificaciones; 
    }
    suma += calificaciones;

     // Conteo de aprobadas y reprobadas
      if (calificaciones >= 6){
           aprobadas++;
    } else {
        reprobadas++;
     }

    // Obtener nota más alta y más baja
    if (calificaciones > masAltas) {
     masAltas = calificaciones;
    }
    if (calificaciones < masBajas) {
         masBajas = calificaciones;  
    }
}

    promedio = suma / numCalificaciones;
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

    cout << "Calificaciones aprobatorias: " << aprobadas << endl;
     cout << "Calificaciones reprobatorias: " << reprobadas << endl;
    cout << "Calificacion mas alta: " << masAltas << endl;
    cout << "Calificacion mas baja: " << masBajas << endl;

    break;
    }
    case 2:{
    cout << "sistema de calificaciones " <<endl;
        break; 
    }  
    case 3:{
       cout << "cerrando programa" <<endl;
     break;
    }
    default:
    cout << "Opcion invalida. Intente de nuevo." << endl;
    break;
  }
  } while (opcion != 3);
  return 0;
   }