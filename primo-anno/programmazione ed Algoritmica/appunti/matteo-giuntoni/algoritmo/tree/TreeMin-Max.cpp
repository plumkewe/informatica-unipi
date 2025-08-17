#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
};

void insert(struct node *root, int value)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    if (node != NULL)
    {
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        struct node *y = NULL, *x = root;
        while (x != NULL)
        {
            y = x;
            if (node->value < x->value)
                x = x->left;
            else
                x = x->right;
        }
        if (y == NULL)
            root = node;
        else if (node->value < y->value)
            y->left = node;
        else
            y->right = node;
    }
    else
        cout << "Memoria esaurita!" << endl;
}

// Algoritmi di ricerca del minim valore in un albero di ricerca
// struttando la proprietà degli alberi di ricerca di esserre ordinati
// con tutti i nodi più grandi della radice a destra e più piccoli a sinistra
int ricercaMIN_R(struct node *root)
{
    if (root->left == NULL)
        return root->value;
    else
        return ricercaMIN_R(root->left);
}

// Versione iterativa più efficente
int ricercaMIN_I(struct node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root->value;
}

// Algoritmi di ricerca del massimo valore in un albero di ricerca
// struttando la proprietà degli alberi di ricerca di esserre ordinati
// con tutti i nodi più grandi della radice a destra e più piccoli a sinistra
int ricercaMAX_R(struct node *root)
{
    if (root->right == NULL)
        return root->value;
    else
        return ricercaMAX_R(root->right);
}

// Versione iterativa più efficente
int ricercaMAX_I(struct node *root)
{
    while (root->right != NULL)
        root = root->left;
    return root->value;
}

// Il costo di tutti questi algoritmi è sempre O(h) al caso pessimo
// con h che è l'altezza dell'albero.

int main()
{
    struct node root;
    root.value = 15, root.left = NULL, root.right = NULL;
    insert(&root, 6);
    insert(&root, 18);
    insert(&root, 7);
    insert(&root, 3);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 13);
    insert(&root, 9);
    insert(&root, 17);
    insert(&root, 20);
    cout << "----- Ricerca minimo ricorsivo -----" << endl;
    cout << ricercaMIN_R(&root) << endl;

    cout << "----- Ricerca minimo iterativo -----" << endl;
    cout << ricercaMIN_I(&root) << endl;

    cout << "----- Ricerca massimo ricorsivo -----" << endl;
    cout << ricercaMAX_R(&root) << endl;

    cout << "----- Ricerca massimo iterativo -----" << endl;
    cout << ricercaMAX_R(&root) << endl;
}