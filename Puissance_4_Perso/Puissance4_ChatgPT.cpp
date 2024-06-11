#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 6;
const int COLS = 7;

void afficherPlateau(const vector<vector<char>>& plateau) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << "| " << plateau[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << "-----------------------------\n";
}

bool estColonneValide(const vector<vector<char>>& plateau, int colonne) {
    return colonne >= 0 && colonne < COLS && plateau[0][colonne] == ' ';
}

void jouerCoup(vector<vector<char>>& plateau, int colonne, char joueur) {
    for (int i = ROWS - 1; i >= 0; --i) {
        if (plateau[i][colonne] == ' ') {
            plateau[i][colonne] = joueur;
            break;
        }
    }
}

bool estVictoire(const vector<vector<char>>& plateau, char joueur) {
    // Vérifier les victoires en ligne
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (plateau[i][j] == joueur && plateau[i][j + 1] == joueur &&
                plateau[i][j + 2] == joueur && plateau[i][j + 3] == joueur) {
                return true;
            }
        }
    }

    // Vérifier les victoires en colonne
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (plateau[i][j] == joueur && plateau[i + 1][j] == joueur &&
                plateau[i + 2][j] == joueur && plateau[i + 3][j] == joueur) {
                return true;
            }
        }
    }

    // Vérifier les victoires en diagonale (descendante)
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (plateau[i][j] == joueur && plateau[i + 1][j + 1] == joueur &&
                plateau[i + 2][j + 2] == joueur && plateau[i + 3][j + 3] == joueur) {
                return true;
            }
        }
    }

    // Vérifier les victoires en diagonale (ascendante)
    for (int i = 3; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (plateau[i][j] == joueur && plateau[i - 1][j + 1] == joueur &&
                plateau[i - 2][j + 2] == joueur && plateau[i - 3][j + 3] == joueur) {
                return true;
            }
        }
    }

    return false;
}

bool estMatchNul(const vector<vector<char>>& plateau) {
    for (int i = 0; i < COLS; ++i) {
        if (plateau[0][i] == ' ') {
            return false;
        }
    }
    return true;
}

int main1() {
    vector<vector<char>> plateau(ROWS, vector<char>(COLS, ' '));
    char joueurActuel = 'X';
    bool finPartie = false;

    while (!finPartie) {
        afficherPlateau(plateau);
        cout << "Joueur " << joueurActuel << ", entrez la colonne où vous voulez jouer (0-6): ";
        int colonne;
        cin >> colonne;

        if (estColonneValide(plateau, colonne)) {
            jouerCoup(plateau, colonne, joueurActuel);
            if (estVictoire(plateau, joueurActuel)) {
                afficherPlateau(plateau);
                cout << "Le joueur " << joueurActuel << " a gagné !" << endl;
                finPartie = true;
            }
            else if (estMatchNul(plateau)) {
                afficherPlateau(plateau);
                cout << "Match nul !" << endl;
                finPartie = true;
            }
            else {
                joueurActuel = (joueurActuel == 'X') ? 'O' : 'X';
            }
        }
        else {
            cout << "Colonne invalide. Réessayez." << endl;
        }
    }

    return 0;
}
