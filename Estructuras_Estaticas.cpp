#include <iostream>
using namespace std;

int main() {

    // Se creo el tablero de 3x3 con espacios vacios.
    char tablero [3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };


    int fila;
    int columna;
    char jugador = 'X';
    char jugadorActual;
    bool jugando = true;
    bool movimientoValido = false;
    
    //Mantiene el juego activo mientras no termine la jugada.
    while (jugando) {
        movimientoValido = false;
        cout << "Turno del jugador: " << jugador <<endl;
    
    //Valida que la fila sea un numero del 0-2.
    while (true) {    
    cout << "Ingresa la fila (0-2): ";
    cin >> fila;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Debes ingresar un numero." << endl;
        continue;
    }

    if (fila >= 0 && fila <= 2) {
        break;
    }

    cout << "Fila invalida. Ingresa un numero del 0 al 2." << endl;
    }
    
    ////Valida que la columna sea un numero del 0-2.
    while (true) {
    cout << "Ingresa la columna (0-2): ";
    cin >> columna;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Debes ingresar un numero." << endl;
        continue;
    }
    if (columna >= 0 && columna <= 2) {
        break;
    }
    cout << "Columna invalida. Ingresa un numero del 0 al 2." << endl;
}

    // Comprueba si la casilla esta libre y registra las jugadas.
    if (fila >= 0 && fila < 3 &&
        columna >= 0 && columna < 3) {

            cout << "Las posiciones son validas" << endl;
    if (tablero[fila][columna] == ' ') {
        tablero[fila][columna] = jugador;
        movimientoValido = true;
        jugadorActual = jugador;
        cout << "Ficha colocada" << endl;

        if (jugador == 'X') {
            jugador = 'O';
        }else {
            jugador = 'X';
        }

    }else {
        cout << "La casilla esta ocupada" << endl;
    }

        }else {
            cout << "Posicion fuera del tablero" << endl;
        }

        for (int fila = 0; fila < 3; fila++) {
        for (int columna = 0; columna < 3; columna++) {
            cout << tablero[fila][columna];

            if (columna < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (fila < 2) {
            cout << "___+___+___" << endl;
        }
    }

    // Revisa las combinaciones posible para ganar.
    if (movimientoValido) {
        if (tablero[1][0] == jugadorActual &&
        tablero[1][1] == jugadorActual &&
        tablero[1][2] == jugadorActual) {
            cout << "Gana el jugador: " << jugadorActual << endl;
            jugando = false; 
        }
    if (tablero[0][1] == jugadorActual &&
        tablero[1][1] == jugadorActual &&
        tablero[2][1] == jugadorActual) {
            cout << "Gana el jugador: " << jugadorActual << endl;
            jugando = false; 
        }

    if (tablero[0][0] == jugadorActual &&
        tablero[1][0] == jugadorActual &&
        tablero[2][0] == jugadorActual) {
            cout << "Gana el jugador: " << jugadorActual << endl;
            jugando = false; 
        }
    if (tablero[0][2] == jugadorActual &&
        tablero[1][2] == jugadorActual &&
        tablero[2][2] == jugadorActual) {
            cout << "Gana el jugador: " << jugadorActual << endl;
            jugando = false; 
        }
    if (tablero[0][0] == jugadorActual &&
        tablero[0][1] == jugadorActual &&
        tablero[0][2] == jugadorActual) {
            cout << "Gana el jugador: " << jugadorActual << endl;
            jugando = false; 
        }
    if (tablero[2][0] == jugadorActual &&
        tablero[2][1] == jugadorActual &&
        tablero[2][2] == jugadorActual) {
            cout << "Gana el jugador: " << jugadorActual << endl;
            jugando = false; 
        }
    if (tablero[0][0] == jugadorActual &&
        tablero[1][1] == jugadorActual &&
        tablero[2][2] == jugadorActual) {
            cout << "Gana el jugador: " << jugadorActual << endl;
            jugando = false; 
        }
    if (tablero[0][2] == jugadorActual &&
        tablero[1][1] == jugadorActual &&
        tablero[2][0] == jugadorActual) {
            cout << "Gana el jugador: " << jugadorActual << endl;
            jugando = false; 
        }
    }
        
        // Cuenta las casillas ocupadas para detectar un empate.
        int casillasOcupadas = 0;
        for (int fila = 0; fila < 3; fila++) {
            for (int columna = 0; columna < 3; columna++) {
                if (tablero[fila][columna] != ' ') {
                    casillasOcupadas++;
                }
            }
        }

        if (casillasOcupadas == 9 && jugando) {
            cout << "¡Empate!, El tablero esta lleno :)" << endl;
            jugando = false;
        }

        cout << "Casillas ocupadas: " << casillasOcupadas << endl;
    }    
    


    

    return 0;
}
