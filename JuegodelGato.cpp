#include <iostream>

using namespace std;

int main() {
    char jugarDeNuevo;

    do {
        // Inicializar o reiniciar el tablero con los números del 1 al 9
        char tablero[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
        int jugador = 1; // Empieza el jugador 1
        int estadoJuego = -1;

        // Elegir símbolo antes de empezar
        char simboloJ1;
        system("cls"); // Usa "clear" en lugar de "cls" si estás en Linux o Mac
        cout << "\n--- JUEGO DEL GATO (TIC-TAC-TOE) ---\n\n";
        
        do {
            cout << "Jugador 1, elije tu simbolo (X o O): ";
            cin >> simboloJ1;
            // Convertir a mayúscula por si acaso
            simboloJ1 = toupper(simboloJ1);
            
            if (simboloJ1 != 'X' && simboloJ1 != 'O') {
                cout << "[ERROR] Simbolo invalido. Intenta de nuevo.\n";
            }
        } while (simboloJ1 != 'X' && simboloJ1 != 'O');

        // Asignar símbolos correspondientes
        char simboloJ2 = (simboloJ1 == 'X') ? 'O' : 'X';
        cout << "\n¡Perfecto! Jugador 1 sera '" << simboloJ1 << "' y Jugador 2 sera '" << simboloJ2 << "'.\n";
        cout << "Presiona Enter para comenzar...";
        cin.ignore(10000, '\n');
        cin.get();

        // Bucle principal de la partida
        do {
            // Función para mostrar el tablero en pantalla
            system("cls"); 
            cout << "\n--- JUEGO DEL GATO (TIC-TAC-TOE) ---\n\n";
            cout << " Jugador 1 (" << simboloJ1 << ")  -  Jugador 2 (" << simboloJ2 << ")\n\n";
            
            cout << "     |     |     \n";
            cout << "  " << tablero[0][0] << "  |  " << tablero[0][1] << "  |  " << tablero[0][2] << "  \n";
            cout << "_____|_____|_____\n";
            cout << "     |     |     \n";
            cout << "  " << tablero[1][0] << "  |  " << tablero[1][1] << "  |  " << tablero[1][2] << "  \n";
            cout << "_____|_____|_____\n";
            cout << "     |     |     \n";
            cout << "  " << tablero[2][0] << "  |  " << tablero[2][1] << "  |  " << tablero[2][2] << "  \n";
            cout << "     |     |     \n\n";
            
            // Definir qué turno le toca a cada jugador
            jugador = (jugador % 2 == 1) ? 1 : 2;
            char marca = (jugador == 1) ? simboloJ1 : simboloJ2;

            int eleccion;
            cout << "Jugador " << jugador << " (" << marca << "), elige una casilla (1-9): ";
            
            // VALIDACIÓN 1: Si el usuario ingresa una letra o símbolo
            if (!(cin >> eleccion)) {
                cout << "\n[ERROR] Caracter no valido. Presiona Enter para intentar de nuevo.";
                cin.clear();           
                cin.ignore(10000, '\n'); 
                cin.get();
                continue;              
            }

            int fila = (eleccion - 1) / 3;
            int columna = (eleccion - 1) % 3;

            // VALIDACIÓN 2: Si el número está fuera del rango o la casilla ya está ocupada
            if (eleccion >= 1 && eleccion <= 9 && tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O') {
                tablero[fila][columna] = marca;
                jugador++;
            } else {
                cout << "\n[ERROR] Casilla invalida o ya ocupada. Presiona Enter para intentar de nuevo.";
                cin.ignore(10000, '\n');
                cin.get();
                continue; 
            }

            // Verificar si alguien ganó
            int ganadorEncontrado = 0;
            for (int i = 0; i < 3; i++) {
                if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) ganadorEncontrado = 1;
                if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) ganadorEncontrado = 1;
            }
            // Revisar diagonales
            if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) ganadorEncontrado = 1;
            if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) ganadorEncontrado = 1;

            if (ganadorEncontrado == 1) {
                estadoJuego = 1;
            } else {
                // Revisar empate
                int vacias = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (tablero[i][j] != 'X' && tablero[i][j] != 'O') vacias++;
                    }
                }
                if (vacias == 0) estadoJuego = 0; // Empate
            }

        } while (estadoJuego == -1);

        // Mostrar tablero final
        system("cls");
        cout << "\n--- JUEGO DEL GATO (TIC-TAC-TOE) ---\n\n";
        cout << " Jugador 1 (" << simboloJ1 << ")  -  Jugador 2 (" << simboloJ2 << ")\n\n";
        cout << "     |     |     \n";
        cout << "  " << tablero[0][0] << "  |  " << tablero[0][1] << "  |  " << tablero[0][2] << "  \n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << tablero[1][0] << "  |  " << tablero[1][1] << "  |  " << tablero[1][2] << "  \n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << tablero[2][0] << "  |  " << tablero[2][1] << "  |  " << tablero[2][2] << "  \n";
        cout << "     |     |     \n\n";

        if (estadoJuego == 1) {
            int ganador = (jugador % 2 == 1) ? 2 : 1;
            char marcaGanadora = (ganador == 1) ? simboloJ1 : simboloJ2;
            cout << "¡Felicidades! ¡Jugador " << ganador << " (" << marcaGanadora << ") ha ganado!\n\n";
        } else {
            cout << "¡Empate! ¡El juego ha terminado sin ganador!\n\n";
        }

        // Preguntar si desea reiniciar
        cout << "¿Quieres jugar de nuevo? (s/n): ";
        cin >> jugarDeNuevo;
        cin.ignore(10000, '\n'); // Limpiar buffer después de leer el char

    } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');

    cout << "\n¡Gracias por jugar! Hasta luego.\n";
    return 0;
}