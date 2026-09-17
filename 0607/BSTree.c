#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct _no{
    int key;
    struct _no *left;
    struct _no *right;
}TNo;

TNo* TNo_Create(int key){
    TNo *novo = malloc(sizeof(TNo));
    if(novo != NULL){
        novo->key = key;
        novo->left = NULL;
        novo->right = NULL;
    }
    return novo;
}

TNo* parse_tree(const char **str){
    if(**str != '('){
        return NULL;
    }
    
    (*str)++;
    
    if(**str == ')'){
        (*str)++;
        return NULL;
    }
    
    char *endptr;
    int val = (int) strtol(*str,&endptr, 10);
    *str = endptr;
    
    TNo *node = TNo_Create(val);
    
    node->left = parse_tree(str);
    node->right = parse_tree(str);
    
    if(**str == ')'){
        (*str)++;
    }
    
    return node;
}

void preorder(TNo *root){
    if(root != NULL){
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TNo *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}

void free_tree(TNo *root){
    if(root != NULL){
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}