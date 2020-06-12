/*
    Program         : tree.c
    Deskripsi       : Implemention of Dynamic Binary Tree
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 11 June 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include "tree.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*
    Constructor
*/
Tree createTree()
{
    Tree t;
    t.root = NULL;

    return t;
}

TNaddress createNode(char data)
{
    TNaddress n = (TNaddress)malloc(sizeof(TreeNode));

    n->data = data;
    n->parent = NULL;
    n->right = NULL;
    n->left = NULL;

    return n;
}

/*
    Mutators
*/
// pos -> 'r' for right, and 'l' for left
void insertChild(TNaddress node, char pos, char data)
{
    if (node == NULL)
    {
        return;
    }

    TNaddress temp = createNode(data);
    temp->parent = node;

    if (pos == 'r')
    {
        node->right = temp;
    }
    else if (pos == 'l')
    {
        node->left = temp;
    }
}

/*
    Accessor
*/
void printNode(TNaddress node)
{
    printf((node->data == 0 ? "empty " : "%c "), node->data);
}

void inorder(TNaddress node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printNode(node);
        inorder(node->right);
    }
}

TNaddress searchData(TNaddress node, char data)
{
    if (node == NULL)
    {
        return node;
    }

    if (node->data == toupper(data))
    {
        return node;
    }

    TNaddress tempResult = searchData(node->left, data);

    if (tempResult != NULL)
    {
        return tempResult;
    }

    tempResult = searchData(node->right, data);
    return tempResult;
}

/*
    Validator
*/
bool isNodeEmpty(TNaddress node)
{
    return node->data == 0;
}

bool isNodeLeaf(TNaddress node)
{
    if (node == NULL)
    {
        return false;
    }

    return (node->right == NULL && node->left == NULL);
}

bool isNodeRoot(TNaddress node)
{
    return node->parent == NULL;
}

/*
    Others
*/
int treeHeight(TNaddress root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = treeHeight(root->left);
    int right = treeHeight(root->right);

    return left > right ? (left + 1) : (right + 1);
}

void createMorseTree(Tree *tree)
{
    // Creates morse tree with . as the left child
    //  and - as the right child

    // Add root
    tree->root = createNode(0);

    // Add level 1
    insertChild(tree->root, LEFT, 'E');
    insertChild(tree->root, RIGHT, 'T');

    // Add level 2
    insertChild(tree->root->left, LEFT, 'I');
    insertChild(tree->root->left, RIGHT, 'A');

    insertChild(tree->root->right, LEFT, 'N');
    insertChild(tree->root->right, RIGHT, 'M');

    // Add level 3
    insertChild(tree->root->left->left, LEFT, 'S');
    insertChild(tree->root->left->left, RIGHT, 'U');

    insertChild(tree->root->left->right, LEFT, 'R');
    insertChild(tree->root->left->right, RIGHT, 'W');

    insertChild(tree->root->right->left, LEFT, 'D');
    insertChild(tree->root->right->left, RIGHT, 'K');

    insertChild(tree->root->right->right, LEFT, 'G');
    insertChild(tree->root->right->right, RIGHT, 'O');

    // Add level 4
    insertChild(tree->root->left->left->left, LEFT, 'H');
    insertChild(tree->root->left->left->left, RIGHT, 'V');

    insertChild(tree->root->left->left->right, LEFT, 'F');
    insertChild(tree->root->left->left->right, RIGHT, 0);

    insertChild(tree->root->left->right->left, LEFT, 'L');
    insertChild(tree->root->left->right->left, RIGHT, 0);

    insertChild(tree->root->left->right->right, LEFT, 'P');
    insertChild(tree->root->left->right->right, RIGHT, 'J');

    insertChild(tree->root->right->left->left, LEFT, 'B');
    insertChild(tree->root->right->left->left, RIGHT, 'X');

    insertChild(tree->root->right->right->left, LEFT, 'Z');
    insertChild(tree->root->right->right->left, RIGHT, 'Q');

    insertChild(tree->root->right->left->right, LEFT, 'C');
    insertChild(tree->root->right->left->right, RIGHT, 'Y');

    insertChild(tree->root->right->right->right, LEFT, '0');
    insertChild(tree->root->right->right->right, RIGHT, 0);

    // Add level 5
    insertChild(tree->root->left->left->left->left, LEFT, '5');
    insertChild(tree->root->left->left->left->left, RIGHT, '4');

    insertChild(tree->root->left->left->left->right, RIGHT, '3');

    insertChild(tree->root->left->left->right->right, RIGHT, '2');

    insertChild(tree->root->left->right->left->left, RIGHT, 0);

    insertChild(tree->root->left->right->right->right, RIGHT, '1');

    insertChild(tree->root->right->left->left->left, LEFT, '6');

    insertChild(tree->root->right->right->left->left, LEFT, '7');

    insertChild(tree->root->right->right->right->left, LEFT, '8');

    insertChild(tree->root->right->right->right->right, LEFT, '9');

    // Add level 6
    insertChild(tree->root->left->right->left->left->right, LEFT, ' ');
}

char *createCodeChar(Tree morseTree, char code)
{
    TNaddress searchResult = searchData(morseTree.root, code);
    TNaddress temp = NULL;
    int height = treeHeight(morseTree.root);
    char *storage = (char *)malloc(sizeof(char) * height);
    int i = 0;

    while (searchResult != NULL)
    {
        temp = searchResult->parent;

        if (temp == NULL)
        {
            break;
        }

        if (searchResult == temp->left)
        {
            storage[i] = '.';
        }
        else
        {
            storage[i] = '-';
        }

        searchResult = temp;
        i++;
    }

    height = i - 1;
    char *reversed = (char *)malloc(sizeof(char) * i);
    for (i = height; i >= 0; i--)
    {
        reversed[height - i] = storage[i];
    }

    return reversed;
}

void createCodeString(Tree morseTree, char *codes)
{
    int length = strlen(codes);
    int i;

    printf("%s : ", codes);
    for (i = 0; i < length; i++)
    {
        printf("%s ", createCodeChar(morseTree, codes[i]));
    }
    printf("\n");
}

char convertMorse(Tree morseTree, char *morse)
{
    TNaddress temp = morseTree.root;
    int length = strlen(morse);
    int i;

    for (i = 0; i < length; i++)
    {
        if (morse[i] == '.')
        {
            temp = temp->left;
        }
        else if (morse[i] == '-')
        {
            temp = temp->right;
        }
    }

    return temp->data;
}

void convertMorseString(Tree morseTree, char *morses)
{
    char temp[6];
    int length = strlen(morses);
    int i, j = 0;

    for (i = 0; i < length; i++)
    {
        if (morses[i] == ' ')
        {
            printf("%c", convertMorse(morseTree, temp));
            j = 0;

            memset(temp, 0, sizeof(temp));
        }
        else if (morses[i] != ' ')
        {
            temp[j] = morses[i];
            j++;

            if (i == length - 1)
            {
                printf("%c", convertMorse(morseTree, temp));
            }
        }
    }
}

void convertFileToMorse(Tree morseTree, char *src, char *dest)
{
    FILE *fp_src, *fp_dest;
    char lineBuf[100];
    int i, length;

    fp_src = fopen(src, "r");
    fp_dest = fopen(dest, "w");
    if (fp_src == NULL || fp_dest == NULL)
    {
        return;
    }

    while (fgets(lineBuf, 100, fp_src) != NULL)
    {
        length = strlen(lineBuf);

        for (i = 0; i < length; i++)
        {
            fprintf(fp_dest, "%s ", createCodeChar(morseTree, lineBuf[i]));
        }

        fprintf(fp_dest, "\n");
    }

    fclose(fp_src);
    fclose(fp_dest);
}
