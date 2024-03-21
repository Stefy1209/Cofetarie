//
// Created by stefy0-0 on 10.03.2024.
//

#include "materie prima.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

materie_prima *new_materie_prima (char *name, char *producer, unsigned long quantity)
/// creates a new 'materie_prima'
/// \param name - char *
/// \param producer - char *
/// \param quantity - unsigned long
/// \return pointer to 'materie_prima'
{
    materie_prima *m;
    m = malloc(sizeof( materie_prima ));

    //if(m == NULL) {
      //  return NULL;
    //}

    m->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(m->name, name);

    m->producer = malloc((strlen(producer) + 1) * sizeof(char));
    strcpy(m->producer, producer);

    m->quantity = quantity;

    return m;
}

void destroy_materie_prima(materie_prima *m)
/// frees memory used by m
/// \param m - materie_prima
{
    free(m->name);
    free(m->producer);
    free(m);
}

char *get_name(materie_prima *m)
/// gets the name of m
/// \param m - materie_prima
/// \return char *
{
    return m->name;
}

char *get_producer(materie_prima *m)
/// gets the producer of m
/// \param m - materie_prima
/// \return char *
{
    return m->producer;
}

unsigned long get_quantity(materie_prima *m)
/// gets the quantity of m
/// \param m - materie_prima
/// \return unsigned long
{
    return m->quantity;
}

void set_producer(materie_prima *m, char *new_producer)
/// changes the producer of m
/// \param m - materie_prima
/// \param new_producer - char *
{
    free(m->producer);
    m->producer = malloc((strlen(new_producer) + 1) * sizeof(char));
    strcpy(m->producer, new_producer);
}

void set_quantity(materie_prima *m, unsigned long new_quantity)
/// changes the quantity of m
/// \param m - materie_prima
/// \param new_quantity - unsigned long
{
    m->quantity = new_quantity;
}