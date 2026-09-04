#ifndef BSTREE_H
#define BSTREE_H

#include <stdbool.h>

typedef struct _bstree BSTree;
typedef struct _no TNo;

// Criação da Árvore
BSTree* BSTree_create(void);

// Inserção e Remoção
bool BSTree_insert(BSTree *T, int key);
bool BSTree_delete(BSTree *T, int key);

// Busca
TNo* BSTree_search(const BSTree *T, int key);

// Percursos
void BSTree_preorder(const BSTree *T);
void BSTree_inorder(const BSTree *T);
void BSTree_posorder(const BSTree *T);

#endif