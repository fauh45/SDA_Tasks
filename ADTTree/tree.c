/*
    Program         : tree.c
    Deskripsi       : Body ADT Tree
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 22 April 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include "tree.h"
#include <stdio.h>

// Constructor
void initNode(Node *n)
{
    n->name = None;
    n->brother = None;
    n->child = None;
    n->parent = None;
}

void initTree(Tree *t)
{
    Node emptyNode;
    int i;

    initNode(&emptyNode);
    t->root = None;

    for (i = 0; i < MAX; i++)
    {
        t->nodes[i] = emptyNode;
    }
}

Node createNode(char name, int parentIndex, int brotherIndex, int childIndex)
{
    Node temp;
    temp.name = name;
    temp.parent = parentIndex;
    temp.child = childIndex;
    temp.brother = brotherIndex;

    return temp;
}

// Mutator
void setNodeChild(Node *n, int childIndex)
{
    n->child = childIndex;
}

void setNodeBro(Node *n, int broIndex)
{
    n->brother = broIndex;
}

void setNodeParent(Node *n, int parentIndex)
{
    n->parent = parentIndex;
}

// Accessor
int getLastBroIndex(Tree t, int broIndex)
{
    if (!isIndexNode(t, broIndex))
    {
        return None;
    }

    Node bro = t.nodes[broIndex];
    int currIndex = broIndex;
    while (bro.brother != None)
    {
        currIndex = bro.brother;
        bro = t.nodes[currIndex];
    }
    
    return currIndex;
}

// Validator
bool isIndexNode(Tree t, int index)
{
    if (index < 0)
    {
        return false;
    }

    return (t.nodes[index].name != None);
}

bool isLeaf(Tree t, int index)
{
    return (isIndexNode(t, index) && t.nodes[index].child == None);
}

bool isRoot(Tree t, int index)
{
    return (isIndexNode(t, index) && t.nodes[index].brother == None && t.nodes[index].parent == None);
}

// I/O
int insertNode(Tree *t, char name, int parentIndex)
{
    if (parentIndex == None && t->root != None)
    {
        return None;
    }

    if (parentIndex == None && t->root == None)
    {
        Node root = createNode(name, None, None, None);
        t->root = insertToTree(root, t);
        return t->root;
    }

    if (!isIndexNode(*t, parentIndex))
    {
        return None;
    }

    Node temp = createNode(name, parentIndex, None, None);
    int index = None;

    if (t->nodes[parentIndex].child == None)
    {
        index = insertToTree(temp, t);
        if (index == None)
        {
            return index;
        }

        setNodeChild(&(t->nodes[parentIndex]), index);
    }
    else
    {
        index = insertToTree(temp, t);
        if (index == None)
        {
            return index;
        }

        int broIndex = getLastBroIndex(*t, t->nodes[parentIndex].child);
        setNodeBro(&(t->nodes[broIndex]), index);
    }

    return index;
}

int insertToTree(Node n, Tree *t)
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        if (isRoot(*t, i))
        {
            continue;
        }
        else if (!isIndexNode(*t, i))
        {
            t->nodes[i] = n;

            return i;
        }
    }

    return None;
}

void deleteNode(Tree *t, int index)
{
    if (!isIndexNode(*t, index))
    {
        return;
    }

    if (t->nodes[index].brother != None)
    {
        deleteNode(t, t->nodes[index].brother);
    }

    if (t->nodes[index].child != None)
    {
        deleteNode(t, t->nodes[index].child);
    }

    if (t->nodes[t->nodes[index].parent].child == index)
    {
        t->nodes[t->nodes[index].parent].child = None;
    }
    else
    {
        int bro = t->nodes[t->nodes[index].parent].child;

        while (bro != None)
        {
            if (t->nodes[bro].brother == index)
            {
                t->nodes[bro].brother = None;
                break;
            }
            else
            {
                bro = t->nodes[bro].brother;
            }
        }
    }

    dealocateNode(t, index);
}

void dealocateNode(Tree *t, int index)
{
    Node nullNode;
    initNode(&nullNode);

    if (isRoot(*t, index))
    {
        t->root = None;
    }

    t->nodes[index] = nullNode;
}

// Other
int depth(Tree t, int index)
{
    if (!isIndexNode(t, index))
    {
        return 0;
    }

    if (isLeaf(t, index))
    {
        return 1;
    }
    else
    {
        int bro = t.nodes[index].child;
        int max = 0;
        int tempDepth;
        while (bro != None)
        {
            tempDepth = depth(t, bro);
            if (tempDepth > max)
            {
                max = tempDepth;
            }

            bro = t.nodes[bro].brother;
        }

        return max + 1;
    }
}

int order(Tree t, int index)
{
    if (!isIndexNode(t, index))
    {
        return None;
    }

    if (isLeaf(t, index))
    {
        return 0;
    }
    else
    {
        int child = t.nodes[index].child;
        int max = 0;
        int tempOrder;
        while (child != None)
        {
            tempOrder = order(t, child);
            if (tempOrder > max)
            {
                max = tempOrder;
            }

            child = t.nodes[child].brother;
        }

        return max + 1;
    }
}

int level(Tree t, int index)
{
    if (!isIndexNode(t, index))
    {
        return None;
    }

    int parent = t.nodes[index].parent;
    int level = 0;
    while (parent != None)
    {
        parent = t.nodes[parent].parent;
        level += 1;
    }

    return level;
}

int degree(Tree t, int index)
{
    if (!isIndexNode(t, index))
    {
        return 0;
    }

    if (isLeaf(t, index))
    {
        return 0;
    }

    int child = t.nodes[index].child;
    int currDegree = 0;
    while (child != None)
    {
        child = t.nodes[child].brother;
        currDegree++;
    }

    child = t.nodes[index].child;
    int degreeTemp;
    while (child != None)
    {
        degreeTemp = degree(t, child);
        if (degreeTemp > currDegree)
        {
            currDegree = degreeTemp;
        }

        child = t.nodes[child].brother;
    }

    return currDegree;
}

void printInOrder(Tree t, int index)
{
    if (!isIndexNode(t, index))
    {
        return;
    }

    if (isLeaf(t, index))
    {
        printf("%c ", t.nodes[index].name);
    }
    else
    {
        int cld = t.nodes[index].child;
        while (cld != None)
        {
            printInOrder(t, cld);

            if (cld == t.nodes[index].child)
            {
                printf("%c ", t.nodes[index].name);
            }

            cld = t.nodes[cld].brother;
        }
    }
}

void printPreOrder(Tree t, int index)
{
    if (!isIndexNode(t, index))
    {
        return;
    }

    if (isLeaf(t, index))
    {
        printf("%c ", t.nodes[index].name);
    }
    else
    {
        printf("%c ", t.nodes[index].name);

        int cld = t.nodes[index].child;
        while (cld != None)
        {
            printPreOrder(t, cld);

            cld = t.nodes[cld].brother;
        }
    }
}

void printPostOrder(Tree t, int index)
{
    if (!isIndexNode(t, index))
    {
        return;
    }

    if (isLeaf(t, index))
    {
        printf("%c ", t.nodes[index].name);
    }
    else
    {
        int cld = t.nodes[index].child;
        while (cld != None)
        {
            printPostOrder(t, cld);

            cld = t.nodes[cld].brother;
        }

        printf("%c ", t.nodes[index].name);
    }
}
