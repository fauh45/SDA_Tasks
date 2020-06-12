/*
    Program         : tree.h
    Deskripsi       : Header of Dynamic Binary Tree implementation
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 11 June 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#pragma once

#include <stdbool.h>

#define RIGHT 'r'
#define LEFT 'l'

typedef struct TreeNode *TNaddress;
typedef struct TreeNode
{
    char data;
    TNaddress parent;
    TNaddress left, right;
} TreeNode;

typedef struct Tree
{
    TNaddress root;
} Tree;

/*
    Constructor
*/
Tree createTree();
TNaddress createNode(char data);

/*
    Mutators
*/
// pos -> 'r' for right, and 'l' for left
void insertChild(TNaddress node, char pos, char data);

/*
    Accessor
*/
void printNode(TNaddress node);
void inorder(TNaddress node);
TNaddress searchData(TNaddress node, char data);

/*
    Validator
*/
bool isNodeEmpty(TNaddress node);
bool isNodeLeaf(TNaddress node);
bool isNodeRoot(TNaddress node);

/*
    Others
*/
int treeHeight(TNaddress root);
void createMorseTree(Tree *tree);
char *createCodeChar(Tree morseTree, char code);
void createCodeString(Tree morseTree, char *codes);
char convertMorse(Tree morseTree, char *morse);
void convertMorseString(Tree morseTree, char *morses);
void convertFileToMorse(Tree morseTree, char *src, char *dest);