#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.c"

list** calc_hash (list** hash_table, int numb_elements, char** values) {

    int hash_value;

    for (int i = 0; i < 25; i++) {

        hash_value = 0;
        
        for (int j = 0; j < numb_elements; j++) {
            
            hash_value += values[i][j];
        }
        
       hash_value = hash_value % 10;
       printf("%d\n", hash_value);
    }

    return hash_table;
}
int main(void) {

    FILE *file = fopen("in_exec6.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    char** cities = (char**) calloc(25, sizeof(char*));
    
    for (int i = 0; i < 25; i++) {
        cities[i] = (char*) calloc(25, sizeof(char));
    }
    
    int index = 0;

    while (fscanf(file, "%s\n", cities[index]) != EOF) {
                
        printf("%s\n", cities[index]);
        index++;
    }
    
    list** hash_table = (list**) calloc(5, sizeof(list*));

    hash_table = calc_hash(hash_table, 5, cities);

    fclose(file);
    return 0;
}