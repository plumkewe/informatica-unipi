#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

/*
DESCRIZIONE GENERALE:

In questo esempio le liste che andiamo creare sono liste ordinate senza cicli
e singolarmente concatenata.
*/

// Questa struct rappresenta un elemento della lista
// è composto da il dato che contiene ed un puntatore
// al nodo successivo
struct node
{
    int data;
    node *nextNode;
};

// Questa funzione inserisce un nuvo elemento (val) all'interno
// di una lista dove il primo nodo viene passato come puntatore (firstNode)
node *insert(node *firstNode, int val)
{
    // creaiamo un nuovo controllando con il malloc che ci sia
    // spazio in memoria, in caso contrario si manda un messaggio
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode != NULL)
    {

        // Se c'è memoria inizializiamo il nuovo elemento con il valore dei dati
        // passati e come nextNode mettiamo null
        newNode->data = val;
        newNode->nextNode = NULL;

        // questi due nodi servono per scorrere la lista partendo da firstNode
        // finchè non troviamo un elemento più grande di quello che stiamo inserendo
        // ed appunto lo inserimo prima (la lista è ordinata in modo decrescente)
        node *preNode = NULL;
        node *currentNode = firstNode;

        // Con questo while scorriamo finchè o arriviamo alla fine oppure
        // troviamo un elemento maggiore di val
        while (currentNode != NULL && val > currentNode->data)
        {
            preNode = currentNode;
            currentNode = currentNode->nextNode;
        }

        // Se preNode è null vuol dire che siamo arrivati alla fine della lista
        // quindi inseriamo il nuovo elemento alla fine
        if (preNode == NULL)
        {
            newNode->nextNode = firstNode;
            firstNode = newNode;
        }
        else
        {
            // in caso contrario inseriamo il nuovo nodo fra preNode e currentNode
            preNode->nextNode = newNode;
            newNode->nextNode = currentNode;
        }
        return firstNode;
    }
    else
    {
        cout << "Memora Esaurita" << endl;
        return NULL;
    }
}

// Funzione che stampa tutta una lista scorrendola
// partendo dal primo elemento (firstNode)
void printList(node *firstNode)
{
    node *currentNode = firstNode;
    while (currentNode != NULL)
    {
        cout << currentNode->data << endl;
        currentNode = currentNode->nextNode;
    }
}

// Funzione che elimina il primo nodo con valore val
node *remove(node *firstNode, int val)
{
    // se firstNode è null vuol dire che non ci sono elementi
    // nella lista e quindi finice la funzione
    if (firstNode != NULL)
    {
        // con questo if controlliamo se l'elemento si trova come
        // primo e nel caso lo eliminamo utilizzando una variabile temp
        if (val == firstNode->data)
        {
            node *temp = firstNode;
            firstNode = firstNode->nextNode;
            // una volta utilizzata la variabile puntatore temp la puliamo
            // dalla memoria
            free(temp);
            return firstNode;
        }
        else
        {
            // in caso l'elemento che vogliamo eliminare non si trovi in prima
            // posizione scorriamo tutta la lista con preNode e currentNode finche
            // non lo troviamo
            node *preNode = NULL;
            node *currentNode = firstNode->nextNode;
            while (currentNode != NULL && val != currentNode->data)
            {
                preNode = currentNode;
                currentNode = currentNode->nextNode;
            }

            // Se currentNode non è NULL vuol dire che non siamo arrivati alla fine
            // e quindi esiste il nodo da eliminare e lo eliminamo anche in questo caso
            // usando temp e poi ripulendolo dalla memoria
            if (currentNode != NULL)
            {
                node *temp = currentNode;
                preNode->nextNode = currentNode->nextNode;
                free(temp);
            }
            return firstNode;
        }
    }
    return firstNode;
}

// questa funzione controlla se la lista è vuota
// e lo fa semplicemente controllando se il primo elemento è NULL
bool is_empty(node *firstNode)
{
    return firstNode == NULL;
}

int main(void)
{
    node firstNode;
    firstNode.data = 3;
    firstNode.nextNode = NULL;
    node *newHead;
    newHead = insert(&firstNode, 20);
    newHead = insert(newHead, 8);
    newHead = insert(newHead, 1);
    newHead = insert(newHead, 5);
    newHead = remove(newHead, 5);
    printList(newHead);
    return 0;
}
