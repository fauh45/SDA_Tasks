#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Node *createNode(int info)
{
    Node *temp;
    temp = malloc(sizeof(Node));
    temp->info = info;
    temp->next = NULL;

    return temp;
}

void push(Node **head_node, int info)
{
    Node *newNode = createNode(info);
    newNode -> next = (*head_node);
    (*head_node) = newNode;
}

void append(Node **head_node, int info)
{   
    Node *newNode = createNode(info);
    Node *last = *head_node;

    if (*head_node == NULL)
    {
        *head_node = newNode;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;
}

void appendAfter(Node *node_before, int info)
{
    if (node_before == NULL)
    {
        return;
    }
    
    Node *newNode = createNode(info);

    newNode->next = node_before->next;
    node_before->next = newNode;
}

/* TODO */ 
void deleteNodeAtPosition(Node **head_node, int pos)
{
    if (*head_node == NULL)
    {
        return;
    }

    Node *temp = *head_node;
    
    if (temp->next == NULL)
    {
        free(temp);
        return;
    }
    
    if (pos == 0)
    {
        *head_node = temp->next;
        temp->next = NULL;
        free(temp);
        return;      
    }

    for (int i = 0; temp != NULL && i < pos-1; i++)
    {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL)
    {
        return;
    }

    Node *next = temp->next;
    next = next->next;

    free(temp->next);
    temp->next = next;
}

void printContent(Node *head_node)
{
    while (head_node != NULL)
    {
        printf("%d", head_node->info);
        head_node = head_node->next;
    }
}

