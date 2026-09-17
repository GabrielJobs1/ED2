#ifndef BSTREE_H
#define BSTREE_H

typedef struct _no TNo;

TNo* TNo_Create(int);

TNo* parse_tree(const char **str);

void preorder(TNo*);

void inorder(TNo*);

void free_tree(TNo*);

#endif