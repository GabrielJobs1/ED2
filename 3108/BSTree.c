#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BSTree.h"

typedef struct _no {
    int key;
    struct _no *left;
    struct _no *right;
    struct _no *parent;
} TNo;

struct _bstree {
    TNo *root;
};

static TNo* TNo_create(int key) {
    TNo *novo = (TNo*) malloc(sizeof(TNo));
    if (novo != NULL) {
        novo->key = key;
        novo->left = NULL;
        novo->right = NULL;
        novo->parent = NULL;
    }
    return novo;
}

static void Transplant(BSTree *T, TNo *u, TNo *v) {
    if (u->parent == NULL) {
        T->root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }

    if (v != NULL) {
        v->parent = u->parent;
    }
}

static TNo* Tree_Minimum(TNo *x) {
    while (x != NULL && x->left != NULL) {
        x = x->left;
    }
    return x;
}

static TNo* TNo_search(TNo *x, int k) {
    if (x == NULL || k == x->key) {
        return x;
    }
    if (k < x->key) {
        return TNo_search(x->left, k);
    } else {
        return TNo_search(x->right, k);
    }
}

static void TNo_preorder(TNo *x) {
    if (x != NULL) {
        printf("%d ", x->key);
        TNo_preorder(x->left);
        TNo_preorder(x->right);
    }
}

static void TNo_inorder(TNo *x) {
    if (x != NULL) {
        TNo_inorder(x->left);
        printf("%d ", x->key);
        TNo_inorder(x->right);
    }
}

static void TNo_posorder(TNo *x) {
    if (x != NULL) {
        TNo_posorder(x->left);
        TNo_posorder(x->right);
        printf("%d ", x->key);
    }
}


BSTree* BSTree_create(void) {
    BSTree *tree = (BSTree*) malloc(sizeof(BSTree));
    if (tree != NULL) {
        tree->root = NULL;
    }
    return tree;
}

TNo* BSTree_search(const BSTree *T, int key) {
    if (T == NULL) return NULL;
    return TNo_search(T->root, key);
}

bool BSTree_insert(BSTree *T, int z) {
    if (T == NULL) return false;

    TNo *y = NULL;
    TNo *x = T->root;

    while (x != NULL) {
        y = x;
        if (z < x->key) {
            x = x->left;
        } else if (z > x->key) {
            x = x->right;
        } else {
            return false; 
        }
    }

    TNo *novo = TNo_create(z);
    if (novo == NULL) return false;

    novo->parent = y;

    if (y == NULL) {
        T->root = novo;
    } else if (novo->key < y->key) {
        y->left = novo;
    } else {
        y->right = novo;
    }

    return true;
}

bool BSTree_delete(BSTree *T, int z) {
    if (T == NULL) return false;

    TNo *del = BSTree_search(T, z);
    if (del == NULL) return false;

    if (del->left == NULL) {
        Transplant(T, del, del->right);
    } else if (del->right == NULL) {
        Transplant(T, del, del->left);
    } else {
        TNo *y = Tree_Minimum(del->right);

        if (y->parent != del) {
            Transplant(T, y, y->right);
            y->right = del->right;
            y->right->parent = y;
        }

        Transplant(T, del, y);
        y->left = del->left;
        y->left->parent = y;
    }

    free(del);
    return true;
}

void BSTree_preorder(const BSTree *T) {
    if (T != NULL) {
        TNo_preorder(T->root);
    }
}

void BSTree_inorder(const BSTree *T) {
    if (T != NULL) {
        TNo_inorder(T->root);
    }
}

void BSTree_posorder(const BSTree *T) {
    if (T != NULL) {
        TNo_posorder(T->root);
    }
}