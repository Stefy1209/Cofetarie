//
// Created by stefy0-0 on 13.03.2024.
//

#include "repo.h"
#include <string.h>
#include <stdlib.h>

list *new_list() {
    list *l;

    l = malloc(sizeof(list));

    l->element = malloc(sizeof(TElem *));
    l->size = 0;
    l->capacity = 1;

    return l;
}

void destroy_list(list *l) {
    unsigned long i, size;
    size = l->size;

    for(i = 0; i < size; i++) {
        destroy_materie_prima(l->element[i]);
    }

    free(l->element);
    free(l);
}

int add_TElem(list *l, TElem *e) {
    if(l->size == l->capacity) {
        TElem **aux;

        l->capacity <<= 1;
        aux = realloc(l->element, l->capacity * sizeof(TElem *));

        //if(aux == NULL) {
            //l->capacity >>= 1;
            //return 1;
        //}

        l->element = aux;
    }

    l->element[ l->size++ ] = e;

    return 0;
}

int delete_TElem(list *l, TElem *e) {
    unsigned long i, size;
    size = l->size;

    for(i = 0; i < size; i++) {
        if(l->element[i] == e) {
            unsigned long j;
            for(j = i; j < size - 1; j++)
                l->element[j] = l->element[j + 1];

            l->size--;
            destroy_materie_prima(e);

            return 0;
        }
    }

    return 1;
}

void empty_list(list *l) {
    l->size = 0;
}

unsigned long get_size(list *l) {
    return l->size;
}

unsigned long get_capacity(list *l) {
    return l->capacity;
}

TElem *find_by_name(list *l, char *name) {
    unsigned long i, size;
    size = l->size;

    for(i = 0; i < size; i++) {
        if(strcmp(get_name(l->element[i]), name) == 0) {
            return l->element[i];
        }
    }

    return NULL;
}

TElem *find_by_index(list *l, unsigned long index) {
    return l->element[index];
}
