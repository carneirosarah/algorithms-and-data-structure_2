#include "lista_encadeada.h"
#include <stdio.h>
#include <stdlib.h>


list* new_node (void) {
    
    return NULL;
}

list* insert(list* node, int value) {
    
    list* new_node = (list*) malloc(sizeof(list));

    new_node -> info = value;
    new_node -> next = node;

    return new_node;
}

list* search (list* data, int value) {
    
    list* p;

    for (p = data; p != NULL; p = p -> next) {
        if (p -> info == value) {

            return p;
        }
    }

    return NULL;
}

list* delete_node (list* data, int value) {

    list* prev = NULL;
    list* p = data;

    while (p != NULL && p -> info != value) {
        
        prev = p;
        p = p -> next;
    }

    if (p == NULL) {

        return data;
    }

    if (prev == NULL) {
        
        data = p -> next;
    } else {

        prev -> next = p -> next;
    }

    free(p);
    return data;
}

void free_list (list* data) {

    list* p = data;
    
    while (p != NULL) {
        
        list* aux = p -> next;
        free(p);
        p = aux;
    }
}

void print(list* data) {

    list* p;

    for(p = data; p!=NULL; p = p -> next) {
        printf(" %d", p->info);
    }

    printf("\n");
}

void print_as_char(list* data) {

    list* p;

    for(p = data; p!=NULL; p = p -> next) {
        printf(" %c", p->info);
    }

    printf("\n");
}

int is_empty(list* data) {
    
    return (data == NULL);
}

list* reverse (list* a) {

    list* prev = NULL;
    list* p = a;
    list* aux = NULL;

    while (p != NULL) {
        
        aux = p -> next;
        p -> next = prev;
        prev = p;
        p = aux;
    }
    
    a = prev;
    return a;
}