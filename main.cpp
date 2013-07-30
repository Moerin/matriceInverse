#include <iostream>
#include <string.h>

using namespace std;

void afficheMatrice(float matrice[3][3]);

//void copyMatrice(int matrice1[3][3], int matrice2[3][3]);

// Constant
#define N 3

int main()
{
    float mdep[N][N] = {{1,2,3},{2,3,1},{0,1,1}};
    float mid[N][N] = {{1},{0,1},{0,0,1}};
    float mtrans[N][N] = {{0},{0}};
    float minv[N][N] = {{0},{0}};

    int i,j,k;

    cout << "Saisissez les valeurs de la matrice de depart " << endl;
    for (i = 0; i < N; i++) {
        cout << "Valeur de la case " << i+1 << endl;
        for (j = 0; j < N; j++) {
            cout << "et de la colonne " << j+1 << endl;
            cin >> mdep[i][j];
        }

    }

    cout << "Matrice depart ";
    afficheMatrice(mdep);

//    cout << endl << "Matrice identite ";
//    afficheMatrice(mid);
//
//    cout << endl << "Matrice transition " ;
//    afficheMatrice(mtrans);

    // copy mdep to mtrans
    memcpy(mtrans, mdep, sizeof mdep);

    // copy mid to minv
    memcpy(minv, mid, sizeof mid);


    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            //  check if the diagonal slot is != null
            if (mdep[i][i] == 0) {
                cout << endl << "Exit : case diagonale = null";
                return 0;
            }
            // copy mdep to mtrans with value of mdep / mdep
            mtrans[i][j] = mdep[i][j] / mdep[i][i];

            // copy minv to mid with value of minv / minv
            mid[i][j] = minv[i][j] / mdep[i][i];
        }

        // copy mtrans to mdep
        memcpy(mdep, mtrans, sizeof mdep);

        // copy mid to minv
        memcpy(minv, mid, sizeof minv);

        for (k = 0; k < N; k++) {
            if(k != i) {
                for (j = 0; j < N; j++) {
                    // copy mdep to mtrans with value of mdep - (mdep * mdep)
                    mtrans[k][j] = mdep[k][j] - (mdep[i][j] * mdep[k][i]);
                    // copy minv to mid with value of mdep - (minv * mdep)
                    mid[k][j] = minv[k][j] - (minv[i][j] * mdep[k][i]);
                }
            }
        }

        // copy mtrans to mdep
        memcpy(mdep, mtrans, sizeof mdep);

        // copy mid to minv
        memcpy(minv, mid, sizeof minv);
    }

    cout << endl << "Matrice inverse apres calcul ";
    afficheMatrice(minv);

    return 0;
}

void afficheMatrice(float matrice[N][N]){
    int i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << matrice[i][j] << " ";
        }
    }
}

