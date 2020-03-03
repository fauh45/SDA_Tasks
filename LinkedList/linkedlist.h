#ifndef linekedlist_h
#define linekedlist_h

typedef struct
{
    char info;
    struct Node *next;
} Node;

Node *createNode(int info);
Node *tail(Node *head_node);
Node *nodeAt(Node *head_node, int pos);
int size(Node *head_node);
void changeInfoAt(Node *head_node, int info, int pos);
void push(Node **head_node, int info);
void append(Node **head_node, int info);
void appendAfter(Node *node_before, int info);
void appendAfterPosition(Node *head_node, int info, int pos);
void deleteNodeAtPosition(Node **head_node, int pos);
void printContent(Node *head_node);

#include "linkedlist.c"

#endif