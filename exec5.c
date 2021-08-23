#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.c"

int main(void) {

    list** hash_table = (list**) calloc(5, sizeof(list*));

    for (int index = 0; index < 5; index++) {

        hash_table[index] = new_node();
        
        switch (index) {
            
            case 0:

                hash_table[index] = insert(hash_table[index], 'o');
                hash_table[index] = insert(hash_table[index], 't');
                hash_table[index] = insert(hash_table[index], 'o');
                
                break;

            case 1:
                
                hash_table[index] = insert(hash_table[index], 'a');
                hash_table[index] = insert(hash_table[index], 'a');
                hash_table[index] = insert(hash_table[index], 'u');
                hash_table[index] = insert(hash_table[index], 'p');

                break;

            case 3:

                hash_table[index] = insert(hash_table[index], 'm');
                hash_table[index] = insert(hash_table[index], 'c');

                break;
            
            default:
                break;
        }

        printf("\n\nIndice %d =>", index);
        print_as_char(hash_table[index]);
    }

    exit(0);
}