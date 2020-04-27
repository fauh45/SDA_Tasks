/*
    Program         : tree.h
    Deskripsi       : Header ADT Tree
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 22 April 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#pragma once

#include <stdbool.h>

#define None -1
#define MAX 15

typedef struct
{
    char name;
    int parent;
    int brother;
    int child;
} Node;

typedef struct
{
    Node nodes[MAX];
    int root;
} Tree;

// Constructor
void initNode(Node *n);
void initTree(Tree *t);
Node createNode(char name, int parentIndex, int brotherIndex, int childIndex);

// Mutator
void setNodeChild(Node *n, int childIndex);
void setNodeBro(Node *n, int broIndex);
void setNodeParent(Node *n, int parentIndex);

// Accessor
int getLastBroIndex(Tree t, int broIndex);

// Validator
bool isIndexNode(Tree t, int index);
bool isLeaf(Tree t, int index);
bool isRoot(Tree t, int index);

// I/O
int insertNode(Tree *t, char name, int parentIndex);
int insertToTree(Node n, Tree *t);
void deleteNode(Tree *t, int index);
void dealocateNode(Tree *t, int index);

// Other
int depth(Tree t, int index);
int order(Tree t, int index);
int level(Tree t, int index);
int degree(Tree t, int index);
void printInOrder(Tree t, int index);
void printPreOrder(Tree t, int index);
void printPostOrder(Tree t, int index);