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

int min(struct node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root->value;
}

int max(struct node *root)
{
    while (root->right != NULL)
        root = root->left;
    return root->value;
}

// Questo algoritmo permette di trova il nodo successore di un determinato nodo
// dato. Con nodo successore si intende il nodo con il valore più piccolo che sia
// però maggiore o uguale al node che diamo in input.
int successore(struct node *node)
{

    // Se il nodo ha un sottoalbero con radice il figlio sinistro
    // basterà trovare il nodo più piccolo del sottoalbero grazie a min
    // visto che per la proprietà degli algeri di ricerca nei sottoalberi destri
    // ci sono solo nodi più grandi della radice
    if (node->right != NULL)
    {
        return min(node->right);
    }

    // In caso non esista un sottoalbero destro si scorre a ritroso l'albero
    // guardando ogni volta se il nodo (node) si trovi a destra, in caso si trovi
    // a destra infatti è ancora più grande del parent, in caso contrario vuol dire che
    // è il primo caso in cui il parent è più grande del figlio quindi abbiamo il primo
    // nodo più grande a partire dal nodo dato in input.
    // Nel caso questa cosa non si verifichi mai arriviamo alla radice e ritorniamo quella.
    struct node *y = node->parent;
    while (y != NULL && node->value == y->right->value)
    {
        node = y;
        y = y->parent;
    }
    return y->value;
}

// L'algoritmo predecessore funziona in maniera uguale al successore solo che in questo
// caso andiamo a cercare l'elemento subito più piccolo del nodo dato in input, per questo
// guarderemo left invece che right
int predecessore(struct node *node)
{
    if (node->left != NULL)
    {
        return max(node->left);
    }
    struct node *y = node->parent;
    while (y != NULL && node->value == y->left->value)
    {
        node = y;
        y = y->parent;
    }
    return y->value;
}

// Entrambi questi algoritmi al caso pessimo hanno O(h) con
// h che è uguale all'altezza dell'albero.

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
    struct node *node = insert(&root, 13);
    insert(&root, 9);
    insert(&root, 17);
    insert(&root, 20);

    cout << successore(node) << endl;
    cout << predecessore(node) << endl;

    return 0;
}