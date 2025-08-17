#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    node *nextNode;
};

void push(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->nextNode = (*head_ref);
    (*head_ref) = new_node;
}

int pop(struct node **topNode)
{
    int val = (*topNode)->data;
    node *tempNode = (*topNode);
    (*topNode) = (*topNode)->nextNode;
    free(tempNode);
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
    push(&firstNode, 4);
    push(&firstNode, 2);
    push(&firstNode, 10);
    printList(firstNode);
    pop(&firstNode);
    printList(firstNode);
    return 0;
}
