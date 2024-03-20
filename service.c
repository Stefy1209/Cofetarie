//
// Created by stefy0-0 on 13.03.2024.
//

#include "service.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

service *new_service() {
    service *s = NULL;
    s = malloc(sizeof(service));
    s->list = new_list();
    s->filtered = new_list();

    return s;
}

void destroy_service(service *s) {
    empty_list(s->filtered);
    destroy_list(s->list);
    destroy_list(s->filtered);
    free(s);
}

int add_materie_prima(service *s, char *name, char *producer, unsigned long quantity) {
    TElem *e = new_materie_prima(name, producer, quantity);

    return add_TElem(s->list, e);
}

int modify_materie(service *s, char *name, char *new_producer, unsigned long new_quantity) {
    TElem *e = find_by_name(s->list, name);

    if(e == NULL) {
        return 1;
    }

    set_producer(e, new_producer);
    set_quantity(e, new_quantity);

    return 0;
}

int delete_materie(service *s, char *name) {
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

list *filter_by_the_first_letter(service *s, char letter) {
    TElem *e;
    char *name;
    unsigned long i, size;
    size = get_size(s->list);

    empty_list(s->filtered);

    for(i = 0; i < size; i++) {
        e = find_by_index(s->list, i);
        if(first_letter(e, letter)) {
            add_TElem(s->filtered, e);
        }
    }

    return s->filtered;
}

list *filter_by_quantity(service *s, unsigned long quantity) {
    TElem *e;
    char *name;
    unsigned long i, size;
    size = get_size(s->list);

    empty_list(s->filtered);

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
    unsigned long i, j, size, pmin;
    TElem *aux;
    size = get_size(s->list);

    for(i = 0; i < size - 1; i++) {
        pmin = i;
        for(j = i+1; j < size; j++) {
            if(criteriu(s->list->element[i], s->list->element[j])) {
                pmin = j;
            }
        }
        aux = s->list->element[i];
        s->list->element[i] = s->list->element[pmin];
        s->list->element[pmin] = aux;
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