#include <iostream>
#include <algorithm>

using namespace std;
/*
PROBLEMA TAGLIO DELLA CORDA:
Il probelama consiste, dato in input un valore intero che corrispone alla lunghezza della corda, e dato un array contentente per ogni lunghezza della corda il valore, di ottenere in output il taglio della corda che massimizza il guadagno.
Esempio: corda di lungezza n=4, (lunghezza,valore): (1, 3), (2, 4), (3, 10), (4, 12)
In questo caso la divisione che massimizza il guadagno è 3 + 1 perchè 3 vale 10 e 1 vale 3 quindi
3 + 10 = 13 > tutte le altre combinazioni.
*/

/*
Il primo approccio per risolvere questo problmea è quello top-down.
Esso si basa su fissare un primo pezzo di lunghezza compresa fra 1 ed n, e poi prendere la miglior suddivisione possibile per il pezzo della corda rimanente, che verrà a sua volta calcolato ricorsivamente con lo stesso principio. Quindi:
r_n = max{p_i + r_n-1, 1<= i <= n} dove p_i è il pezzo fissato di lunghezza i e r_n-1 è la miglior suddivisione per un pezzo di lunghezza n-1
*/
int taglio_top_down(int p[], int n)
{
    // Controllo se arriviamo a lunghezza 0 non sarà possibile dividere nulla
    if (n == 0)
        return 0;
    // Fisso una variaible che mi segnerà il massimo valore per i vari p_i.
    int q = -1;
    // Provo un pezzo iniziale di varie misure partendo dalla 1 fino a prendere tutto n
    for (int i = 1; i <= n; i++)
    {
        // Per ogni pezzo calcolo se è miglire addizionando taglio_top_down(p, n-i) che
        // calcola a sua volta il prezzo migliore per un pezzo n-1
        q = max(q, p[i - 1] + taglio_top_down(p, n - i));
    }
    // Ritorno il miglior valore
    return q;
}

/*
Questo algoritmo è uguale a T(n) = 1 + T(1) + T(2) + ... + T(n-1)
che fa si che T(n) = O(2^n) quindi ha un costo esponenziale
*/

/*
Questo approccio crea un albero andando a calcoalre tutte le possibili combinazioni.
Prendiamo per esempio il caso di una corda di lunghezza 4:
                              4
                    /      /    \    \
                  3        2      1    0
            /    |   \    / \     |
          2      1    0  1   0    0
        /  \     |       |
      1    0     0       0
      |
      0
Come possiamo vedere in questo albero ci sono varie seguenze che si ripetono, possiamo dunque utilizzare la
programmazione dinamica per salvare queste sequenze, partendo dalle più piccole (quelle in fondo all'alebero) e risalendo
con la tecnica bottom-up.
*/

int taglio_bottom_up(int p[], int n)
{
    // Dichiariamo un array per salvare il miglior valore per ogni
    // lunghezza e inizializiamo la lunghezza 0 a 0
    int r[n];
    r[0] = 0;

    // Questo array invece serve a salvare i tagli da fare
    int s[n];
    // Riempiamo l'array partendo dal fondo
    for (int j = 1; j <= n; j++)
    {
        // Per riempire ogni posizione con l'elemento migliore
        // calcoliamo con un for la migior combinazione per la parte
        // rimanente, e lo facciamo prendedo gli elementi dall'array
        // che essendo riempito dal fondo avrà già salvato
        int q = -1;
        for (int i = 1; i <= j; i++)
        {
            if (q < p[i - 1] + r[j - i - 1])
            {
                q = p[i - 1] + r[j - i - 1];

                // Salviamo la posizione dei tagli da fare
                s[j] = i;
            }
        }
        // Alla fine salviamo il miglrio valore trovato
        r[j - 1] = q;
    }
    // restituisco l'ultimo elemento che è il miglior valore
    // trovato per tutto la corda
    return r[n - 1];
}

// Questo algoritmo ha un costo di O(n^2) perché è uguale a:
// Sommatoria di O(j) con j da 1 a n = n(n+1)/2 = semplificando per la
// notazione O grande = n^2 = O(n^2)

int main()
{
    int value[4] = {1, 5, 8, 9};
    cout << taglio_top_down(value, 4) << endl;
    cout << taglio_bottom_up(value, 4) << endl;
}