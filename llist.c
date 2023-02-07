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
        } else if (strcmp(command, "it") == 0) {
            int val = atoi(argv[i+1]);
            struct node *it = node_alloc(val);
            llist_insert_tail(&head, it);
        } else if (strcmp(command, "p") == 0) {
            llist_print(head);
        } else if (strcmp(command, "f") == 0) {
            llist_free(&head);
        }
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

void llist_insert_tail(struct node **head, struct node *n) {

    struct node *curr_node = *head;

    if (*head == NULL) {
        *head = n;
    } else {
        while (curr_node->next != NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = n;
    }
}

void llist_print(struct node *head) {
    struct node *curr_node = head;
    if (curr_node == NULL) {
        printf("[empty]");
    } else {
        while (curr_node != NULL) {
            printf("%d",curr_node->value);
            curr_node = curr_node->next;
            if (curr_node != NULL) {
                printf(" -> ");
            }
        }
    }
    printf("\n");
}

void llist_free(struct node **head) {
    struct node *curr_node = *head;
    if (curr_node == NULL) {
        return;
    } else {
        while (curr_node->next !=NULL) {
            struct node *next_node = curr_node->next;
            node_free(curr_node);
            curr_node = next_node;
        }
        node_free(curr_node);
        *head = NULL;
    }
}