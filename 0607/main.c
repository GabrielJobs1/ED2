#include <stdio.h>
#include "BSTree.h"
int main(void) {
    char entrada[4097];

    if (scanf("%4096s", entrada) == 1) {
        const char *ptr = entrada;
        
        TNo *root = parse_tree(&ptr);

        printf("PREORDER: ");
        preorder(root);
        printf("\n");

        printf("INORDER: ");
        inorder(root);
        printf("\n");

        free_tree(root);
    }

    return 0;
}