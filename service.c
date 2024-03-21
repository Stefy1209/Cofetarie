//
// Created by stefy0-0 on 13.03.2024.
//

#include "service.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

service *new_service()
/// creates a service
/// \return service
{
    service *s = NULL;
    s = malloc(sizeof(service));
    s->list = new_list();
    s->filtered = new_list();

    return s;
}

void destroy_service(service *s)
/// frees the memory used by s
/// \param s - service
{
    set_size_0(s->filtered);
    destroy_list(s->list);
    destroy_list(s->filtered);
    free(s);
}

int add_materie_prima(service *s, char *name, char *producer, unsigned long quantity)
/// adds a raw material
/// \param s - service
/// \param name - char *
/// \param producer - char *
/// \param quantity - unsigned long
/// \return 0 - added with success
///         1 - it could not be added
{
    TElem *e = new_materie_prima(name, producer, quantity);

    return add_TElem(s->list, e);
}

int modify_materie(service *s, char *name, char *new_producer, unsigned long new_quantity)
/// modifies the raw material that has the name given
/// \param s - service
/// \param name - char *
/// \param new_producer - char *
/// \param new_quantity - unsigned long
/// \return 0 - modified with success
///         1 - it could not be modified
{
    TElem *e = find_by_name(s->list, name);

    if(e == NULL) {
        return 1;
    }

    set_producer(e, new_producer);
    set_quantity(e, new_quantity);

    return 0;
}

int delete_materie(service *s, char *name)
/// deletes the material
/// \param s - service
/// \param name - char *
/// \return 0 - deleted with success
///         1 - it could not be modified
{
    TElem *e = find_by_name(s->list, name);

    if(e == NULL) {
        return 1;
    }

    delete_TElem(s->list, e);

    return 0;
}

bool first_letter(TElem *e, char letter) {
    return get_name(e)[0] == letter;
}

bool less_quantity(TElem *e, unsigned long quantity) {
    return get_quantity(e) < quantity;
}

list *filter_by_the_first_letter(service *s, char letter)
///
/// \param s - service
/// \param letter - char
/// \return list
{
    TElem *e;
    unsigned long i, size;
    size = get_size(s->list);

    set_size_0(s->filtered);

    for(i = 0; i < size; i++) {
        e = find_by_index(s->list, i);
        if(first_letter(e, letter)) {
            add_TElem(s->filtered, e);
        }
    }

    return s->filtered;
}

list *filter_by_quantity(service *s, unsigned long quantity)
///
/// \param s - service
/// \param quantity - unsigned long
/// \return list
{
    TElem *e;
    unsigned long i, size;
    size = get_size(s->list);

    set_size_0(s->filtered);

    for(i = 0; i < size; i++) {
        e = find_by_index(s->list, i);
        if(less_quantity(e, quantity)) {
            add_TElem(s->filtered, e);
        }
    }

    return s->filtered;
}

bool up_name(TElem *e1, TElem *e2) {
    return strcmp(get_name(e1), get_name(e2)) > 0;
}

bool down_name(TElem *e1, TElem *e2) {
    return strcmp(get_name(e1), get_name(e2)) < 0;
}

bool up_quantity(TElem *e1, TElem *e2) {
    return get_quantity(e1) > get_quantity(e2);
}

bool down_quantity(TElem *e1, TElem *e2) {
    return get_quantity(e1) < get_quantity(e2);
}

list *sort(service *s, bool (*criteriu)(TElem *, TElem *)) {
    unsigned long i, j, size, position;
    TElem *aux;
    size = get_size(s->list);

    for(i = 0; i < size - 1; i++) {
        position = i;
        for(j = i+1; j < size; j++) {
            if(criteriu(s->list->element[i], s->list->element[j])) {
                position = j;
            }
        }
        aux = s->list->element[i];
        s->list->element[i] = s->list->element[position];
        s->list->element[position] = aux;
    }

    return s->list;
}

list *sort_up_name(service *s) {
    return sort(s, &up_name);
}

list *sort_down_name(service *s) {
    return sort(s, &down_name);
}

list *sort_up_quantity(service *s) {
    return sort(s, &up_quantity);
}

list *sort_down_quantity(service *s) {
    return sort(s, &down_quantity);
}