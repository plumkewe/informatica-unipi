#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    node *nextNode;
};

// Funzione che aggiunge un elemento in testa alla coda
void enqueue(struct node **head, struct node **tail, int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode != NULL)
    {
        newNode->data = val;
        newNode->nextNode = NULL;
        if ((*head) == NULL)
        {
            (*head) = newNode;
            (*tail) = newNode;
        }
        else
        {
            (*tail)->nextNode = newNode;
            (*tail) = newNode;
        }
    }
    else
    {
        puts("Memoria esaurita");
    }
}

// Funzione che rimuove il primo elemento della coda
int dequeue(struct node **head, struct node **tail)
{
    int val = (*head)->data;
    node *temp = (*head);
    (*head) = (*head)->nextNode;
    if (head == NULL)
    {
        tail = NULL;
    }
    free(temp);
    return val;
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

int main(void)
{
    struct node *firstNode = NULL;
    struct node *tail = NULL;
    enqueue(&firstNode, &tail, 5);
    enqueue(&firstNode, &tail, 10);
    enqueue(&firstNode, &tail, 1);
    printList(firstNode);
    dequeue(&firstNode, &tail);
    printList(firstNode);
    return 0;
}
