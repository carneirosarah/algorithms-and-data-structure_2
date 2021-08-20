#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

struct binary_tree {
    char info;
    struct binary_tree* right;
    struct binary_tree* left;
};

typedef struct binary_tree binary_tree;

binary_tree* new_binary_tree_empty();
binary_tree* new_binary_tree(char value, binary_tree* left, binary_tree* right);
int binary_tree_empty(binary_tree* tree);
binary_tree* free_binary_tree(binary_tree* tree);
int binary_tree_membership(binary_tree* tree, char value);
void print(binary_tree* tree);
int count_nodes (binary_tree* tree);
int count_leaves (binary_tree* tree);
int count_rigth_sons(binary_tree* tree);
int get_tree_height(binary_tree* tree);

#endif