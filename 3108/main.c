#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BSTree.h"

int main(void) {

    BSTree *arvore = BSTree_create();

   int v[5] = {10,5,37,28,156};

    for(int i = 0; i < 5; i++){
        BSTree_insert(arvore,v[i]);
    }

    BSTree_inorder(arvore);
    
    BSTree_delete(arvore, 37);

    printf("\n");

    BSTree_inorder(arvore);
    
    printf("\n");


    BSTree_posorder(arvore);

    printf("\n");
    
    BSTree_delete(arvore, 10);  

    BSTree_posorder(arvore);

    printf("\n");

    BSTree_preorder(arvore);

    BSTree_delete(arvore, 5);
    
    printf("\n");
    
    BSTree_preorder(arvore);

    printf("\n");

    return 0;

}