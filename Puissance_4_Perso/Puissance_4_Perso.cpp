#include <iostream>
//#include <random>

using namespace std;

bool checkVictory(int tab[6][7], int line, int column, int joueur) {

    //CHECK HORIZONTAL
    int cpt = 0;
    for (int i = -3; i <= 3; i++) {
        if (column + i >= 0 && column + i < 7) {
            if (tab[line][column + i] == joueur) cpt++;
            else cpt = 0;
            if (cpt == 4) return true;
        }
    }

    //CHECK VERTICAL
    cpt = 0;
    for (int i = 0; i <= 3; i++) {
        if (line + i >= 0 && line + i < 6) {
            if (tab[line + i][column] == joueur) cpt++;
            else cpt = 0;
            if (cpt == 4) return true;
        }
    }

    //CHECK DIAGONAL1
    cpt = 0;
    for (int i = -3; i <= 3; i++) {
        if (line + i >= 0 && line + i < 6 && column + i >= 0 && column + i < 7) {
            if (tab[line + i][column + i] == joueur) cpt++;
            else cpt = 0;
            if (cpt == 4) return true;
        }
    }

    //CHECK DIAGONAL2
    cpt = 0;
    for (int i = -3; i <= 3; i++) {
        if (line + i >= 0 && line + i < 6 && column + i >= 0 && column + i < 7) {
            if (tab[line + i][column - i] == joueur) cpt++;
            else cpt = 0;
            if (cpt == 4) return true;
        }
    }
    return false;
}

void showTab(int t[6][7]) {
    for (int i = 0; i < 7; i++) {
        cout << i + 1 << " ";
    }

    cout << endl << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            switch (t[i][j]) {
            case 0:
                cout << (char)254;
                break;
            case 1:
                cout << "X";
                break;
            case 2:
                cout << "O";
                break;
            default:
                cout << "?";
            }
            cout << " ";
        }
        cout << endl;
    }
}

int main() {
    while (1) {
        int tab[6][7] = { 0 };
        int cptTour = 1;
        int joueur;
        while (cptTour < 42) {
            system("cls");
            joueur = (cptTour % 2 == 1) ? 1 : 2;
            cout << "TOUR " << cptTour << endl;
            cout << "A TON TOUR JOUEUR " << joueur << endl;
            showTab(tab);

            bool hasPlayed = false;
            int line;
            int column;
            while (!hasPlayed) {
                column = -1;
                while (!(column > 0 && column <= 7)) {
                    cout << "Choisis ta colonne (1-7) : ";
                    cin >> column; cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                }
                column--;
                for (int i = 5; i >= 0; i--) {
                    if (tab[i][column] == 0) {
                        tab[i][column] = joueur;
                        line = i;
                        hasPlayed = true;
                        break;
                    }
                }
                if (!hasPlayed)
                    cout << "colonne pleine, rejoue !" << endl;
            }
            if (checkVictory(tab, line, column, joueur)) {
                break;
            }
            cptTour++;
        }

        if (cptTour != 42) {
            cout << "JOUEUR " << joueur << " A GAGNE" << endl;
        }
        else {
            cout << "EGALITE" << endl;
        }
        char replay = false;
        cout << "Voulez vous rejouer ? (Y/N) : ";
        cin >> replay;
        if (replay != 'Y') break;
    }
    return 0;
}