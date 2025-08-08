#include <iostream>

using namespace std;

/*
PROBLEMA: LCS (Longon Common Subsequence)
Inanzitutto definiamo cos'è una sequenza che è sotto sequenza:
Una sequenza S di lunghezza k è sotto-sequenza di una sequenza A di
lunghezza n se esistono delle posizioni

0 ≤ i_0 < i_1 < .... < i_{k-1} ≤ n-1 in A tali che
S[j] = A[i_j] per j = 0, 1, ..., k-1

S è sotto-sequenza comune ad A e B, se è sotto-sequenza comune sia
di A che di B. Vediamo un esempio:

            _ _     _ _         _   _ _ _
Dati A = (A,B,C,B,D,A,B) e B = (B,D,C,A,B,A)
una sotto-sequenza comune è B, C, A, B.
Il problema di chiede di calcolare la sotto-seguenza comune più lunga
(longest common subsequence)
*/

/*
Una prima soluzione sarebbe quella di provare tutte le possibili sotto-sequenze
ma questo porterebbe ad un costo di O(n2^m) dove 2^m sono le sotto-sequenze di A e n serve per vedere se esiste in B.

Una soluzione miglire può essere fatta analizzando il prefisso di A e B

A = _ _ _ _ c con c = i ed il resto = i-1
B = _ _ _ _ c' con c' = j ed il resto = j-1

Abbiamo due possibilità a questo punto, che c==c' o c!=c' nel primo caso eliminiamo entrabi ed aggiungiamo 1 perché il prefisso massimo è lungo +1, mentre nel secondo caso richiamiamo la funzione due volte, una volta eliminado c' e una volta c, e teniamo "la strada" che da il valore maggiore. Si ottiene la seguente funzione:

           { 0                               se i = 0 o j=0
LCS(i,j) = { LCS(i-1, j-1) + 1               se i,j > 0 e x_i = x_y
           { max(LCS(i, j-1), LCS(i-1, j))   se i,j > 0 e x_i != x_y

Una volta definita questa funzione si potrebbe procedere sia con il metodo top-down applicando una semplice ricorsione oppure con il metodo bottom-up andandoa a momorizzare le operazioni che si ripetono. Creiamo una matrice di grandezza nxm (ogni riga/colonna corrispone alla lunghezza della stringa da conisderare ess: n=2 con MELA di guarda ME) e la compiliamo da sinistra verso destra e dall'alto verso il basso scrivendo per ogni punto quanto è lunga l'LCS.

   0  1  2     n
  _______________
0| 0  0  0  0  0
1| 0  Z  Y1
2| 0 Y2  X
 | 0
m| 0

Prendiamo il caso sopra rappresentato, se colonna 2 e riga 2 hanno lo stesso valore siamo nel secondo caso della funzione quindi X = Z + 1, in caso controario si prende il massimo fra Y1 e Y2. Tutta la prima riga e la prima colonna sono a 0 perché se si cerca LCS fra una stringa normale ed una vuota si ha sempre 0.
*/

int LCS(char a[], char b[], int m, int n)
{
    // Inizializzazione di una matrice di dimensione n+1 X m+1 (+1 perché
    // consideriamo lo 0) andando a insierire in prima riga e colonna tutti 0
    int lunghezza[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
        lunghezza[i][0] = 0;
    for (int i = 0; i <= n; i++)
        lunghezza[0][i] = 0;

    // Iniziamo il riempimento scorrendo tutte le righe e tutte le colonne
    // della matrice create a riempiendola volta volta
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // Caso in cui abbiamo due valori uguali
            if (a[i - 1] == b[j - 1])
            {
                lunghezza[i][j] = lunghezza[i - 1][j - 1] + 1;

                // Casi in cui sono diversi i due valori
            }
            else if (lunghezza[i][j - 1] > lunghezza[i - 1][j])
            {
                lunghezza[i][j] = lunghezza[i][j - 1];
            }
            else
            {
                lunghezza[i][j] = lunghezza[i - 1][j];
            }
        }
    }
    // Ritorniamo l'ultimo elemento in basso a destra perché
    // esso è il risultato di tutta la matrice riempita quindi è
    // LCS delle due stringhe complete
    return lunghezza[m][n];
}

// Essendo che andiamo a riempire una matrice di dimensione N x M abbiamo che
// il tempo è appunto O(nm) mentre lo spazio è ugualemente O(nm) perché la matrice
// la manteniamo tutta in memoria

/*
NOTA:
Per salvare anche come è composta la LCS basta per ogni valore della matrice salvare
anche la posizione da cui è stata ricavato, le opzioni sono "diagonale", "alto", "sinistra", e poi stampare seguendo il percorso dalla posizione lunghezza[m][n] i casi
in cui si ha "diagonale", perché sono i casi in cui si cambia lettera e non si riprende una già vista.
*/

int main()
{
    char A[4] = {'M', 'E', 'L', 'A'};
    char B[5] = {'M', 'E', 'R', 'A', 'A'};
    cout << LCS(A, B, 4, 5) << endl;
}