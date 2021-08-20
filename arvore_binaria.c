#include "arvore_binaria.h"
#include <stdlib.h>
#include <stdio.h>

binary_tree* new_binary_tree_empty() {
    
    return NULL;
}

binary_tree* new_binary_tree(char value, binary_tree* left, binary_tree* right) {

    binary_tree* node = (binary_tree*) malloc(sizeof(binary_tree));
    node -> info = value;
    node -> left = left;
    node -> right = right;

    return node;
}

int binary_tree_empty(binary_tree* tree) {

    return tree == NULL;
}

binary_tree* free_binary_tree(binary_tree* tree) {
    
    if (binary_tree_empty(tree)) {
        
        return NULL;
    }

    free_binary_tree(tree -> left);
    free_binary_tree(tree -> right);
    free_binary_tree(tree);
}

int binary_tree_membership(binary_tree* tree, char value) {

    if (binary_tree_empty(tree)) {
        return 0;
    }
    
    return tree -> info == value || binary_tree_membership(tree->right, value) || binary_tree_membership(tree->left, value);
}

void print(binary_tree* tree) {

    if (binary_tree_empty(tree)) {
        
        return;
    }
    
    printf("%c ", tree -> info);
    print(tree -> left);
    print(tree -> right);
}

int count_nodes (binary_tree* tree) {

    int count = 0;

    if (binary_tree_empty(tree)) {
        
        return count;
    }

    count += 1;
    count += count_nodes(tree->right);
    count += count_nodes(tree -> left);

    return count;
}

int count_leaves (binary_tree* tree) {

    int count = 0;
    
    if (binary_tree_empty(tree)) {
        
        return count;
    }

    if (binary_tree_empty(tree -> left) && binary_tree_empty(tree -> right)) {
        
        count += 1;
        return count;
    }

    count += count_leaves(tree->right);
    count += count_leaves(tree -> left);

    return count;
}

int count_rigth_sons(binary_tree* tree) {
    
    return count_nodes (tree -> right);
}

int get_tree_height (binary_tree* tree) {

    int heigth_left = 0;
    int heigth_right = 0;

    if (binary_tree_empty(tree)) {
        
        return -1;
    }

    heigth_left = get_tree_height(tree -> left);
    heigth_right = get_tree_height(tree -> right);

    return heigth_left > heigth_right ? heigth_left + 1 : heigth_right + 1;
}