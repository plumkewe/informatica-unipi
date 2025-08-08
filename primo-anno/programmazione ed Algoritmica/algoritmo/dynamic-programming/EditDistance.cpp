#include <iostream>
#include <algorithm>

using namespace std;

/*
PROBLEMA: Edit distance
Il problema richiede di misurare la similarità fra due sequenze, e cioé la disanza di edit. In particolare noi volgimao trovare l'allineamto ottimo fra queste due sequene cioé quello che minimizza la distanza fra di esse.

La distanza di calcola vedendo le coppie di caratteri allineati, se uguali +0 se diversi o carraterri allineati con vuoto +1

ESEMPIO: con S1 = APE, S2 = ARPA possiamo avere
A _ P E        A _ P _ E
A R P A        A R P A _
0+1+0+1 = 2    0+1+0+1+1 = 3

Per risolvere questo problema consideriamo l'ultimo elemento di enrenamve le sequenze, quell'elemento può trovarsi o con uno spazio vuoto oppure con un altro elemnto che a sua volta può essere uguale o meno, abbiamo quindi 4 casi:
- elemento in S1 con _ in S2 (+1)
- elemento in S2 con _ in S1 (+1)
- elemnto in S1 != elemento in S2 (+1)
- elemento in S1 == elemento in S2 (+0)

Possiamo quindi definirire una funzione come:
ED(i, j) = min{
                1 + ED(i-1, j),
                1 + ED(i,j-1),
                P(i,j) + ED(i-1, j-1)
              }
Dove P(i,j) restituisce 0 se i==j e 1 se i!=j.
Si crea dunque un albero con calcoli ripetuto che grazie alla programmazione dinamica possiamo semplificare riempendo una matrice M[i,j], il riempimento si fa dall'alto verso il basso e da sinistra verso destra seguento questa logica:

   0  1  2     n
  _______________
0| 0  1  2 ... n
1| 1  Z  Y
2| 2  W  X
 |...
m| m

Ininzitutto i valori della prima colonna e della prima riga sono inizializzati a 1...n e 1...m perché l'edint distance fra una stringa vuota ed un'altra non vuota è la lunghezza di quella non vuota perché si aggiungono tutti caratteri vuoti, mentre stringa vuota e stringa vuota = 0.
Il valore X sarà uguale al minimo fra W+1, Y+1, Z+P(i,j) che è esattamente quello che è riportato nella formula. Alla fine del riempimento avremo il risultato in M[n,m].
*/

// Funzione di appoggio per calcolare P(i,j)
int P(int val1, int val2)
{
    if (val1 == val2)
        return 0;
    else
        return 1;
}

int edit_distance(char s1[], char s2[], int dim1, int dim2)
{

    // Dichiaro la matrice M[n,m] inizializzando la prima riga
    // e la prima colonna con i valori corrispondenti all'indice
    // per il motivo scritto sopra
    int M[dim1 + 1][dim2 + 1]; // Si fa +1 perché si considera anche lo 0
    for (int i = 0; i <= dim1; i++)
        M[i][0] = i;
    for (int i = 0; i <= dim2; i++)
        M[0][i] = i;

    // Faccio un semplice doppio ciclo per riempire la matrice, faccio partire
    // entrambi i cicli da 1 perché prima riga e prima colonna sono già inizializzati
    for (int i = 1; i < dim1 + 1; i++)
    {
        for (int j = 1; j < dim2 + 1; j++)
        {
            // Riempio vedendo il minimo fra i 3 valori scritti sopra
            M[i][j] = min(min(M[i - 1][j] + 1, M[i][j - 1] + 1), M[i - 1][j - 1] + P(s1[i - 1], s2[j - 1]));
        }
    }
    // Ritorno l'ulto valore in basso a destra
    return M[dim1][dim2];
}

// Il costo di questo algoritmo è O(nm) sia in tempo che in spazio, perché
// andiamo a fare un doppio ciclo per riempire la matrice che teniamo interamente
// in memoria (quindi anche spazio O(nm)).
int main()
{
    char s1[6] = {'A', 'L', 'B', 'E', 'R', 'O'};
    char s2[6] = {'L', 'A', 'B', 'B', 'R', 'O'};
    cout << edit_distance(s1, s2, 6, 6) << endl;
}