//
// Created by stefy0-0 on 13.03.2024.
//

#ifndef COFETARIE_REPO_H
#define COFETARIE_REPO_H

#include "materie prima.h"

typedef materie_prima TElem;

typedef struct {
    TElem **element;
    unsigned long size;
    unsigned long capacity;
} list;

list *new_list();
void destroy_list(list *l);

int add_TElem(list *l, TElem *e);
int delete_TElem(list *l, TElem *e);
void set_size_0(list *l);

unsigned long get_size(list *l);
unsigned long get_capacity(list *l);

TElem *find_by_name(list *l, char *name);
TElem *find_by_index(list *l, unsigned long index);

#endif //COFETARIE_REPO_H
