#include <stdio.h>
#include "linkedlist.h"

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    append(&head, 2);
    push(&head, 0);
    printf("Size, %d \n", size(head));
    printContent(head);
    printf("\n");
    deleteNodeAtPosition(&head, 1);
    changeInfoAt(head, 1, 0);
    printContent(head);
    printf("\nSize, %d \n", size(head));
    printContent(tail(head));
    return 0;
}
