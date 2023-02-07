#include "llist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    struct node *head=NULL;

    for (int i =1; i < argc; i++) {
        char *command = argv[i];
        if (strcmp(command, "ih") == 0) {
            int val = atoi(argv[i+1]);
            struct node *ih = node_alloc(val);
            llist_insert_head(&head, ih);
        } else if (strcmp(command, "dh") == 0) {
            llist_delete_head(&head);
        }
        if (head != NULL) {printf("Head value after command %d\n", head->value);}
    }
    return 0;
}

struct node *node_alloc(int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void node_free(struct node *n) {
    free(n);
}

void llist_insert_head(struct node **head, struct node *n) {
    struct node *prev_head = *head;
    *head = n;
    n->next = prev_head;
}

struct node *llist_delete_head(struct node **head) {
    if (*head == NULL) {
        return NULL;
    }
    struct node *prev_head = *head;
    struct node *new_head = prev_head->next;
    *head = new_head;
    return prev_head;
}

