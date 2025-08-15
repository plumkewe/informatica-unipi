#include <iostream>

using namespace std;

/*
PROBLEMA: Zaino 0-1 (intero)
Il problema consiste, dato in input un peso W che rappresenta il peso massimo che lo zaino può trasportare e un array composto da coppie di elementi (peso, valore), nel massimizzare il valore di oggetti messi nello zaino. Quindi dobbiamo trovare gli elementi che sommati rientrino nel peso dello zaino e che hanno il valore maggiore. (Si dice 0-1 perché un elemento o si prendo o no)

Possiamo optare per un approccio a forza bruta e quindi con n oggetti avremmo circa 2^n possibili combinazioni con un costo di O(2^n) quindi esponenziale.

In alternativa possiamo procedere con la programmazione dinamica. Poniamo di avere uno zaino di dimension W e k elementi da inserire. Facciamo che I_0, I_1, ..., I_{k-1} è la miglior combinazione da mettere nello zaino per k-1 elementi, una volta che aggiungiamo l'elemento I_k abbiamo che:
- I_k non entra => ottimo è I_0, ..., I_{k-1}
- I_k entra => Dobbiamo considerare l'ottimo per I_k + I_0, ..., I_{k-1} per uno zaino di dim W-w_k

Possiamo così definire una formula ricorsiva:

         { B(k-1, w)                            se w_k > w
B(k,w) = { max{ B(k-1,w), B(k-1, w-w_i) + v_k}  altrimenti

Il primo caso dice che se l'elemento non può entrare nello zaino, quindi non è parte della soluzione e quindi consideriamo il valore visto in k-1 con lo stesso peso raggiunto.
IL secondo caso considera se l'elemento sta nello zaino e quindi vediamo se aggiungendolo si ha una soluzione migliore rispetto al caso precedente.

Possiamo trasformare questa funzione in un'algoritmo che riempie una matrice n x W.
*/

int zaino_01(int value[], int weight[], int maxW, int dim)
{

    // Inizializziamo la matrice con n+1 righe e W+1 colonne (+1 per lo 0)
    // e mettiamo tutta la prima riga e la prima colonna a 0 perché
    // uno zaino di Wmax 0 non contiene nulla e senza elementi lo zaino rimane a 0
    int M[dim + 1][maxW + 1];
    for (int i = 0; i <= dim; i++)
        M[i][0] = 0;
    for (int i = 0; i <= maxW; i++)
        M[0][i] = 0;

    // Iniziamo il riempimento dal basso verso l'alto
    for (int i = 1; i <= dim; i++)
    {
        // E da sinistra verso destra
        for (int w = 1; w <= maxW; w++)
        {
            // Ad ogni casella controlliamo se il peso dell'elemento in quella
            // riga entra o meno
            if (weight[i - 1] <= w)
            {

                // Nel caso invece entri controlliamo quale è il massimo valore
                // fra prendere tutto quello già preso + il nuovo valore o
                // prendere semplicemnte la colonna prima
                if (value[i - 1] + M[i - 1][w - weight[i - 1]] > M[i - 1][w])
                    M[i][w] = value[i - 1] + M[i - 1][w - weight[i - 1]];
                else
                    M[i][w] = M[i - 1][w];

                // In caso non entri copiamo l'elemento sopra che sta ad indicare
                // la prima riga della formula sopra
            }
            else
                M[i][w] = M[i - 1][w];
        }
    }
    // Ritorniamo l'ultimo elemento in basso a destra
    return M[dim][maxW];
}

// Per salvare gli elementi che vanno inseriri basta marcare l'elemento quando
// M[i][w] != M[i-1][w], che è il caso in cui abbiamo aggiunto un nuovo elemento
// nello zaino e non abbiamo copiato quello nella riga sopra

/*
Questa funzione ha un costo di O(nW) che potrebbe sembrare polinomiale ma non lo è, questo
perché noi dobbiamo considerare il numero di passi da eseguire con l'aumento dell'input, in
caso dell'aumento di n si aumenta linearmente ma nel caso di W l'aumento si vede in base
al numero di bit che usiamo per contenere le colonne, quindi log_2 W che riportato nell'O grande
abbiamo che O(nW) = O(n2^{log_2 W}) quindi l'algorimo è pseudo-polinomiale
*/

int main()
{
    int value[4] = {3, 4, 5, 6};
    int weight[4] = {2, 3, 4, 5};

    cout << zaino_01(value, weight, 5, 4) << endl;
}