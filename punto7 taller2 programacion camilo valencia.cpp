#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

char tablero[3][3]; 
void inicializar() {
    char c = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = c++;
        }
    }
}

void mostrar() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << tablero[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool ganador(char p) {
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == p && tablero[i][1] == p && tablero[i][2] == p) return true;
        if (tablero[0][i] == p && tablero[1][i] == p && tablero[2][i] == p) return true;
    }
    if (tablero[0][0] == p && tablero[1][1] == p && tablero[2][2] == p) return true;
    if (tablero[0][2] == p && tablero[1][1] == p && tablero[2][0] == p) return true;
    return false;
}

bool empate() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tablero[i][j] != 'X' && tablero[i][j] != 'O')
                return false;
    return true;
}

int main() {
    inicializar();
    char jugador = 'X';
    int casilla;
    bool terminado = false;

    cout << "=== triki ===\n";
    mostrar();

    while (!terminado) {
        cout << "turno del jugador " << jugador << ". elige casilla (1-9): ";
        cin >> casilla;

        if (casilla < 1 || casilla > 9) {
            cout << "movimiento inválido. Intenta de nuevo.\n";
            continue;
        }

        int fila = (casilla - 1) / 3;
        int col  = (casilla - 1) % 3;

        if (tablero[fila][col] == 'X' || tablero[fila][col] == 'O') {
            cout << "casilla ocupada intenta otra.\n";
            continue;
        }

        tablero[fila][col] = jugador;
        mostrar();

        if (ganador(jugador)) {
            cout << "jugador " << jugador << " gana!\n";
            terminado = true;
        } else if (empate()) {
            cout << "empate.\n";
            terminado = true;
        } else {
            jugador = (jugador == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
