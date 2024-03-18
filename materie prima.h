//
// Created by stefy0-0 on 10.03.2024.
//

#ifndef COFETARIE_MATERIE_PRIMA_H
#define COFETARIE_MATERIE_PRIMA_H

typedef struct {
    char *name;
    char *producer;
    unsigned long quantity;
} materie_prima;

materie_prima *new_materie_prima (char *name, char *producer, unsigned long quantity);
void destroy_materie_prima (materie_prima *m);

char *get_name(materie_prima *m);
char *get_producer(materie_prima *m);
unsigned long get_quantity(materie_prima *m);

void set_producer(materie_prima *m, char *new_producer);
void set_quantity(materie_prima *m, unsigned long new_quantity);

#endif //COFETARIE_MATERIE_PRIMA_H
