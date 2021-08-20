#include "arvore_binaria.c"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    binary_tree* tree = new_binary_tree('a', 
        new_binary_tree('b', new_binary_tree_empty(), new_binary_tree_empty()),
        new_binary_tree('c', new_binary_tree('f', new_binary_tree_empty(), new_binary_tree_empty()), 
            new_binary_tree('d', 
                new_binary_tree('e', new_binary_tree_empty(), new_binary_tree_empty()), 
                new_binary_tree_empty()
            )
        )
    );
    print(tree);
    printf("\n");
    printf("Numero de nos = %d \n", count_nodes(tree));
    printf("Numero de folhas = %d \n", count_leaves(tree));
    printf("Numero de filhos a direita = %d \n", count_rigth_sons(tree));
    printf("Altura da árvore = %d \n", get_tree_height(tree));


}