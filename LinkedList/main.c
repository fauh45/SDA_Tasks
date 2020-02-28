#include <stdio.h>
#include "linkedlist.h"

int main(int argc, char const *argv[])
{
    Node *head = createNode(1);
    append(&head, 2);
    push(&head, 0);
    printContent(head);
    return 0;
}
