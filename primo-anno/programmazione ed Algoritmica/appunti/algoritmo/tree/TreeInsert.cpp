#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct node
{
    int value;
    node *parent;
    node *left;
    node *right;
};

// Questo algoritmo permette di inserire un nuovo nodo in un albero
// di ricerca mantenedeno appunto la sua proprietà che dice:
// Ogni nodo ha l'elemtno alla sua destra maggioe e alla sua sinistra minore.
struct node *insert(struct node *root, int value)
{
    // Creo il nuovo nodo controllando se ci sia memoria
    struct node *node = (struct node *)malloc(sizeof(struct node));
    if (node != NULL)
    {
        // Inizializzo i valori del nodo
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;

        // Creo due nodi che serviranno per ter traccia del parent (y)
        // e della posizione attuale (x) per poi scorrere la lista spostandosi
        // a destra o a sinistra in base al valore del nuovo nodo rispetto ai valori
        // già presenti nell'albero
        struct node *y = NULL, *x = root;
        while (x != NULL)
        {
            y = x;
            if (node->value < x->value)
                x = x->left;
            else
                x = x->right;
        }

        // Una volta finito di scorrere setto come prima cosa il parent
        node->parent = y;

        // Asseconda di dove si è arrivatto inserisco il nuovo nodo
        if (y == NULL)
            root = node;
        else if (node->value < y->value)
            y->left = node;
        else
            y->right = node;
        return node;
    }
    else
    {
        cout << "Memoria esaurita!" << endl;
        return NULL;
    }
}

// Questo algoritmo ha una compessità do O(h) con h = altezza albero

int main()
{
    struct node root;
    root.value = 15, root.parent = NULL;
    root.left = NULL, root.right = NULL;
    insert(&root, 6);
    insert(&root, 18);
    insert(&root, 7);
    insert(&root, 3);
    insert(&root, 2);
    insert(&root, 4);
}