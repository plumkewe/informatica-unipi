#include <iostream>

using namespace std;

void controllo(int A[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << A[i];
    }
    cout << "" << endl;
}

// Funzione che genera tutte le configurazioni possibili
// dato un determinato array e le passa a la procedura configurazione.
// Con tutte le configuraizoni si intende
// tutte i casi in cui elemeni ci sono (1) o non ci sono (0)
void configurazioni(int A[], int k, int n)
{
    for (int i = 0; i <= 1; i++)
    {
        // Per ogni elemento metto una volta 0 ed una volta 1
        A[k] = i;

        // Se sono arrivato alla fine chiamo controllo
        if (k == n - 1)
            controllo(A, n);

        // In caso controario chiamo la chiamata ricorsiva per mettere
        // una volta 0 e una volta 1 negli elementi k+1
        else
            configurazioni(A, k + 1, n);
    }
}

// Funzione che genera tutte le permutazioni di un array
// dato in input e per ognuna chiama la procedura controllo
void permutazioni(int P[], int k, int n)
{
    // Controllo per dire che se si è arrivati alla fine
    // di chiamare controllo
    if (k == n - 1)
        controllo(P, n);
    else
    {
        for (int i = k; i < n; i++)
        {
            // Operazioni di scambio
            int app = P[k];
            P[k] = P[i];
            P[i] = app;

            // Chiamata ricorsiva per generare le permutazioni
            // degli elementi da k+1
            permutazioni(P, k + 1, n);

            // Operazioni di scambio
            app = P[k];
            P[k] = P[i];
            P[i] = app;
        }
    }
}

int main()
{
    int A[5];
    // configurazioni(A, 0, 5);
    int B[5] = {1, 2, 3, 4, 5};
    permutazioni(B, 0, 5);
}