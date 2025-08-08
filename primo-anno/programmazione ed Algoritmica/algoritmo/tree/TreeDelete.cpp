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

struct node *insert(struct node *root, int value)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    if (node != NULL)
    {
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;
        struct node *y = NULL, *x = root;
        while (x != NULL)
        {
            y = x;
            if (node->value < x->value)
                x = x->left;
            else
                x = x->right;
        }
        node->parent = y;
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

// ------ FUNZIONI AUSILIARIE PER REMOVE -----
struct node *max(struct node *root)
{
    while (root->right != NULL)
        root = root->left;
    return root;
}

void stacca(struct node *node)
{
    struct node *parent = node->parent;
    if (parent->left->value == node->value)
        parent->left = NULL;
    else
        parent->right = NULL;
    free(node);
}

void scambia(struct node *node1, struct node *node2)
{
    struct node *app = node1;
    node2 = node1;
    node2 = app;
}
// ------ FUNZIONI AUSILIARIE PER REMOVE -----

// Questo algoritmo permette di rimuovere un nodo in un albero binario
// di ricerca mantenedo la proprietà per cui il sottoalvbero sinistro contiene tutti
// nodi minori della radice mentre il destro tuti maggiori.
// Questo algoritmo copre 3 casistiche:
// - 1: Eliminare un nodo senza figli
// - 2: Eliminare un nodo con 1 solo figlio
// - 3: Eliminare un nodo con 2 figli
void remove(struct node *node)
{

    // Questo è il caso in cui un nodo ha 2 figli
    if (node->left != NULL && node->right != NULL)
    {
        // andiamo a trovare il nodo massimo fra quelli più
        // piccolo del nodo che vogliamo eliminare e lo scambiamo con
        // il nodo da eliminare. Questo perchè il più grande nodo più piccolo
        // del nodo da elimiare è l'unico che può essere più grande di tutti i nodi a sinistra
        // ma più piccolo anche di quelli a destra
        struct node *pred = max(node->left);
        scambia(node, pred);
    }
    // Qui andiamo a coprire i casi con 0 o 1 figlio
    struct node *f = NULL;

    // In questo caso controlliamo se esiste o il figlio destro o sinistro
    if (node->left != NULL)
        f = node->left;
    else if (node->right != NULL)
        f = node->right;

    // Nel caso non abbiamo figli eliminamo il nodo e fine
    if (f == NULL)
        stacca(node);
    else
    {
        // In caso contrario scambiamo il nodo da eliminare con il suo unico figlio
        // e poi lo eliminamo. Questa casistica funziona anche con 2 figli perchè una volta avvenuto
        // lo scambio il nodo da eliminare sarà per forza messo in una posizione o senza figli o con solo
        // il nodo sinistro, visto che se ci fosse un destro sarebbe quello il max.
        scambia(node, f);
        stacca(node);
    }
}

// Questo algoritmo ha sempre un costo massimo di O(h) con h=altezza albero

void simmetrica(struct node *root)
{
    if (root != NULL)
    {
        simmetrica(root->left);
        cout << root->value << endl;
        simmetrica(root->right);
    }
}

int main()
{
    struct node root;
    root.value = 15, root.parent = NULL;
    root.left = NULL, root.right = NULL;
    insert(&root, 6);
    insert(&root, 18);
    struct node *node = insert(&root, 7);
    insert(&root, 3);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 13);
    insert(&root, 9);
    insert(&root, 17);
    insert(&root, 20);

    simmetrica(&root);

    remove(node);

    cout << "---- Post remove -----" << endl;
    simmetrica(&root);
}