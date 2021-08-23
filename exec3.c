#include "arvore_binaria_busca.c"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    FILE *file = fopen("in_exec3.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    char* line = (char*) calloc(255, sizeof(char));
    char * word;
    int line_count = 1;
    binary_tree* tree = new_binary_tree();

    while (fscanf(file, "%[^\n] ", line) != EOF) {
                
        word = strtok(line, " ");

        while (word != NULL) {
            tree = insert_tree(tree, word, line_count);
            word = strtok(NULL, " ");
        }

        line_count++;
    }

    print_tree(tree);

    fclose(file);
    return 0;
}