#ifndef linekedlist_h
#define linekedlist_h

typedef struct
{
    char info;
    struct Node *next;
} Node;

Node *createNode(int info);
void push(Node **head_node, int info);
void append(Node **head_node, int info);
void appendAfter(Node *node_before, int info);
void deleteNodeAtPosition(Node **head_node, int pos);
void printContent(Node *head_node);

#endif