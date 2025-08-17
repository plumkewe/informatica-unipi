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

// Ricerca di un valore in un albro di ricerca in modo ricorsivo.
// Questo algoritmo sfrutta la proprietà che i nodi alla sinistra della
// radice sono minori e quelli alla destra sono maggiori per decidere in che
// ramo proseguire la ricerca.
bool ricercaABR_R(struct node *root, int value)
{
    if (root == NULL)
        return false;
    if (value == root->value)
        return true;
    if (root->value > value)
        return ricercaABR_R(root->left, value);
    else
        return ricercaABR_R(root->right, value);
}

// Questa è la variante ieterativa dell'algoritmo (da prefeire per evitare
// l'accumularsi di chiamata nello stack di attivazione)
bool ricercaABR_I(struct node *root, int value)
{
    while (root != NULL && value != root->value)
    {
        if (value < root->value)
            root = root->left;
        else
            root = root->right;
    }
    if (root == NULL)
        return false;
    else
        return true;
}

// L'algoritmo (sia quello iterativo che quello ricorsivo) ha un costo al
//  caso pessio di O(h) con h= altezza albero

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
    bool result = ricercaABR_R(&root, 123);
    cout << result << endl;
}