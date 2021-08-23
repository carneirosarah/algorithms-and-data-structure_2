#include "arvore_binaria_busca.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


binary_tree* new_binary_tree() {

    return NULL;
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

int binary_tree_membership(binary_tree* tree, char* value) {

    if (binary_tree_empty(tree)) {
        return 0;
    }
    
    return tree -> info == value || binary_tree_membership(tree->right, value) || binary_tree_membership(tree->left, value);
}

void print_tree(binary_tree* tree) {

    if (binary_tree_empty(tree)) {
        
        return;
    }
    
    print_tree(tree -> left);
    printf("%s\n", tree -> info);
    print(tree -> lines);
    print_tree(tree -> right);
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

binary_tree* search_tree (binary_tree* tree, char* value) {
   
   if (binary_tree_empty(tree)) {
        
        return NULL;
    }

    if (strcmp(tree->info, value) > 0) {
        
        search_tree(tree -> left, value);

    } else if (strcmp(tree->info, value) < 0) {

        search_tree(tree -> right, value);
    }

    return tree;
}

binary_tree* insert_tree (binary_tree* tree, char* value, int line) {
    
    if (binary_tree_empty(tree)) {
        
        tree = (binary_tree*) malloc(sizeof(binary_tree));
        tree -> info = (char*) calloc(255, sizeof(char));
        strcpy(tree -> info, value);
        tree -> lines = insert(new_node(), line);
        tree -> left = NULL;
        tree -> right = NULL;
    
    } else if (strcmp(tree->info, value) > 0) {
        
        tree -> left = insert_tree(tree -> left, value, line);

    } else if (strcmp(tree->info, value) < 0) {

        tree -> right = insert_tree(tree -> right, value, line);
    
    } else {

        if (search(tree -> lines, line) == NULL) {

            tree -> lines = insert(tree -> lines, line);
        }
    }

    return tree;
}
