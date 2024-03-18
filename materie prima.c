//
// Created by stefy0-0 on 10.03.2024.
//

#include "materie prima.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#define nullptr NULL

materie_prima *new_materie_prima (char *name, char *producer, unsigned long quantity) {
    materie_prima *m;
    m = malloc(sizeof( materie_prima ));

    if(m == nullptr) {
        return nullptr;
    }

    m->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(m->name, name);

    m->producer = malloc((strlen(producer) + 1) * sizeof(char));
    strcpy(m->producer, producer);

    m->quantity = quantity;

    return m;
}

void destroy_materie_prima(materie_prima *m) {
    free(m->name);
    free(m->producer);
    free(m);
}

char *get_name(materie_prima *m) {
    return m->name;
}

char *get_producer(materie_prima *m) {
    return m->producer;
}

unsigned long get_quantity(materie_prima *m) {
    return m->quantity;
}

void set_producer(materie_prima *m, char *new_producer) {
    free(m->producer);
    m->producer = malloc((strlen(new_producer) + 1) * sizeof(char));
    strcpy(m->producer, new_producer);
}

void set_quantity(materie_prima *m, unsigned long new_quantity) {
    m->quantity = new_quantity;
}