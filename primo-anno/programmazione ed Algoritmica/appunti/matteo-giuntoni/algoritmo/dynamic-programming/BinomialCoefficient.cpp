#include <iostream>
#include <utility>

using namespace std;

/*
PROBLEMA: Calcolo coefficente binomiale.
Il coefficente binomiale si esprime con la formula C(n,k) = n! / k!(n-k)!
Questa formula però non viene utilizzata per i calcoli effettivi visto che il costo di n! è molto elevato
si usa invece la seguente variante:
          { 1                         con k = 0
C(n,k) =  { 1                         con k = n
          { C(n-1, k-1) + C(n-1, k)   tutti gli altri
*/

int rec_coef_bin(int n, int k)
{
    if ((k == 0) || (k == n))
    {
        return 1;
    }
    else
    {
        return rec_coef_bin(n - 1, k - 1) + rec_coef_bin(n - 1, k);
    }
}

/*
Questa funzione ricorsiva genera un alebero dove avvengo delle operazioni ripetute, queste operazioni possono essere eliminare andandole a salvare in una matrice formate da n+1 righe e k+1 colonne (+1 perché si aggiunge lo 0), dove appunti si salva il risultato di C(n,k). Andremo a riempire questa matrice dall'alto verso il basso e da sinistra verso destra in modo che ogni operazione successiva avrà sempre le precedenti già risolte.

    _ _ _ _ _ k colonne
  | 1 0 0 0 0
  | 1 1
  | 1   1
  | 1 Y Z 1
  |     X   1
n righe

Tutta la prima colonna è inizializzata ad uno per la condizione della funzione (C(i,0) = 1), inoltre il calcolo del fattoriale impone che se k=n si abbia 1 quindi anche tutta la diagonale che va dall'alto vero il basso e da sinistra verso destra si inizializza ad 1. Inoltre la prima riga ha tutti i valori a 0 perché il binoliame C(0,k) = 0, questo fa di che la matrice vada riempita solo per la parte a sinistra dalla bisetricce visto che i valori a destra sarebbero tutti 0.
Possiamo vedere che per calcolare X abbiamo bisogno di Y e Z. Quindi le righe precedenti a quelle contenti questi due valori non ci servono, possiamo così semplificare la matrice in due array un contente i valori dove si trova X ed uno per i valori dove si trova Y e Z; così facendo risparmiamo di memoria passando da O(n^2) a O(2n) = O(n)
*/

int it_coef_bin(int n, int k)
{
    // Definiamo i due array che conterranno gli elementi da 0...n per le prime due colonne
    int result1[n + 1];
    int result2[n + 1];
    // Inizializzimo il primo array ad 1 per la definizione della funzione binomiale, e lo facciamo in modo
    // che si possa fare il calcolo per l'elemento in result2
    result1[0] = 1;
    result1[1] = 1;

    // Partiamo dalla posizione 2 per escudere le prime due che abbiamo già inizializzato e scorriamo tutte
    // le colonne della matrice riempiendole
    for (int i = 2; i <= n; i++)
    {

        // Valore inizializzato ad 1 per propreità binomiale (essendo prima colonna)
        result2[0] = 1;

        // Ciclo che si termina a i perché non è necessario calcolare tutti gli elementi
        // ma solo quelli prima di i (matrice inferiore) perché i valori a sinistra sarebbero sempre 0
        for (int j = 1; j < i; j++)
        {
            result2[j] = result1[j - 1] + result1[j];
        }
        // Per la proprietà del binomiale si mette il valore finale a 1 (il valore con n=k)
        result2[i] = 1;
        // Scambio delle due righe per ricominicare il riempimento
        // salvando la riga result2 come result1 e riempendo nuovamente result2
        int app;
        for (int i = 0; i < n + 1; i++)
        {
            app = result1[i];
            result1[i] = result2[i];
            result2[i] = app;
        }
    }
    // Ritorniamo il valore finale di result1 che conterrà il risultato finale
    return result1[k];
}

// A livello di tempo dobbiamo andare semplicemente a riempire una matrice nk quini il costo sarà appunto O(nk).
// A livello di memoria, come scritto prima, grazie alla semplificazione in cui andiamo a salvare soltato le due
// righe in cui siamo lavorando abbiamo un costo di O(n).

int main()
{
    cout << rec_coef_bin(5, 2) << endl;
    cout << it_coef_bin(5, 2) << endl;
}
