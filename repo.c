//
// Created by stefy0-0 on 13.03.2024.
//

#include "repo.h"
#include <string.h>
#include <stdlib.h>

list *new_list()
/// creates a new list
/// \return list
{
    list *l;

    l = malloc(sizeof(list));

    l->element = malloc(sizeof(TElem *));
    l->size = 0;
    l->capacity = 1;

    return l;
}

void destroy_list(list *l)
/// frees the memory used by l
/// \param l - list
{
    unsigned long i, size;
    size = l->size;

    for(i = 0; i < size; i++) {
        destroy_materie_prima(l->element[i]);
    }

    free(l->element);
    free(l);
}

int add_TElem(list *l, TElem *e)
/// adds a TElem to the list
/// \param l - list
/// \param e - TElem
/// \return 0 if it was added with success
///         1 if it failed
{
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

int delete_TElem(list *l, TElem *e)
/// eliminates the e from l and also frees the memory used by e
/// \param l - list
/// \param e - TElem
/// \return 0 if the element was eliminated
///         1 if the element was not found in the list
{
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

void set_size_0(list *l)
/// sets the size of l to 0
/// \param l - list
{
    l->size = 0;
}

unsigned long get_size(list *l)
/// gets the size of
/// \param l
/// \return
{
    return l->size;
}

unsigned long get_capacity(list *l)
/// gets the capacity of l
/// \param l - list
/// \return unsigned long
{
    return l->capacity;
}

TElem *find_by_name(list *l, char *name)
/// gets the TElem that has the name
/// \param l - list
/// \param name - char *
/// \return TElem
{
    unsigned long i, size;
    size = l->size;

    for(i = 0; i < size; i++) {
        if(strcmp(get_name(l->element[i]), name) == 0) {
            return l->element[i];
        }
    }

    return NULL;
}

TElem *find_by_index(list *l, unsigned long index)
/// gets the TElem that occupies the position index in l, starting from 0
/// \param l - list
/// \param index - unsigned long
/// \return - TElem
{
    if(index >= l->size)
        return NULL;

    return l->element[index];
}
