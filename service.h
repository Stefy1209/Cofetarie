//
// Created by stefy0-0 on 13.03.2024.
//

#ifndef COFETARIE_SERVICE_H
#define COFETARIE_SERVICE_H

#include "repo.h"

typedef struct {
    list *list;
    list *filtered;
} service;

service *new_service();
void destroy_service(service *s);

int add_materie_prima(service *s, char *name, char *producer, unsigned long quantity);
int modify_materie(service *s, char *name, char *new_producer, unsigned long new_quantity);
int delete_materie(service *s, char *name);

list *filter_by_the_first_letter(service *s, char letter);
list *filter_by_quantity(service *s, unsigned long quantity);

list *sort_up_name(service *s);
list *sort_down_name(service *s);
list *sort_up_quantity(service *s);
list *sort_down_quantity(service *s);

#endif //COFETARIE_SERVICE_H
