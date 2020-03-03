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

Node *tail(Node *head_node)
{
    Node *curr = head_node;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    
    return curr;
}

Node *nodeAt(Node *head_node, int pos)
{
    Node *curr = head_node;

    for (int i = 0; i < pos; i++)
    {
        curr = curr->next;
    }
    
    return curr;
}

int size(Node *head_node)
{
    int count = 0;
    Node *curr = head_node;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    
    return count;
}

void changeInfoAt(Node *head_node, int info, int pos)
{
    Node *curr = head_node;

    for (int i = 0; i < pos; i++)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        return;
    }
    
    curr->info = info;
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
        return;
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

void appendAfterPosition(Node *head_node, int info, int pos)
{
    if (pos == 0)
    {
        appendAfter(head_node, info);
        return;
    }
    
    appendAfter(nodeAt(head_node,pos), info);
}

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
        temp->next = NULL;
        *head_node = temp->next;
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
