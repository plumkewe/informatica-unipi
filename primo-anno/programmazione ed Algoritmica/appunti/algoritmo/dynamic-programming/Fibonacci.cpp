#include <iostream>

using namespace std;

// Funzione classica di fibonacci rappresentata matematicamente come:
// { F_0 = 0
// { F_1 = 1
// { F_n = F_{n-1} + F_{n-2} per n >= 2
int classic_fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return classic_fib(n - 1) + classic_fib(n - 2);
    }
}

/*
Questa funzione si dice che usa un approccio top-down, cioé crea un albero così
rappresentato che viene visitato dall'alto al basso.

                  F_n
                /  +  \
          F_{n-1}     F_{n-2}
        /     \        /     \
  F_{n-2}  F_{n-3}  F_{n-3}  F_{n-4}
          /     \      /    \
    F_{n-4} F_{n-5} F_{n-4}  F_{n-5}

Possiamo vedere che a diversi livelli vengono richiamate le stesse funzioni
che restituiscono lo stesso valore.
*/

/*
Questa è una variante della funzione fibonacci che utilizza la programmazione dinamica.
Questa variante si basa sul concetto che salvare il risultato delle funzioni precedenti ad n, per
riuscire a calcolare tutte le funzioni infatti si parte dalle più piccole e si risale fino a F(n),
questo è definito approccio bottom-up visto che è come se si ripercoresse l'albero dal basso verso l'alto:
F(0), F(1), F(2) = F(0) + (1), F(3) = F(2) + F(1) .... F(n) = F(n-1) + F(n-2)
I valori si salvano in un array di dimension n e si prende l'ultimo
*/
int dynamic_fib(int n)
{
    // Questa variante utilizza due variaibli al posto di un array
    // per l'imitare il consumo di memoria, visto che i valori prima di
    // F(n-1) e F(n-2) non servono più una volta usati
    int val1 = 0, val2 = 1;
    int app;
    for (int k = 2; k <= n; k++)
    {
        app = val2;
        val2 = val1 + val2;
        val1 = app;
    }
    return val2;
}
// Questa funzione ha costo in tempo O(n), visto che si bassa su riempire un array
// di n dimensioni, e in memoria, con quest avariante, O(1), visto che un manteniamo l'array
// ma solo gli ultimi due elementi

int main()
{

    cout << classic_fib(10) << endl;
    cout << dynamic_fib(10) << endl;
}