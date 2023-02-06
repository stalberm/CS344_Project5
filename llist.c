#include "llist.h"
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {

    struct node *head=NULL;

    for (int i =1; i < argc; i++) {
        char *command = argv[i];
        printf("%s\n", command);
    }

}