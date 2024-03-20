//
// Created by stefy0-0 on 13.03.2024.
//

#include <assert.h>
#include <string.h>
#include <stddef.h>
#include "test.h"
#include "materie prima.h"
#include "repo.h"
#include "service.h"

void testCreateMaterie() {
    materie_prima *m = new_materie_prima("lapte", "napolact", 20);

    assert(strcmp(m->name, "lapte") == 0);
    assert(strcmp(m->producer, "napolact") == 0);
    assert(m->quantity == 20);

    destroy_materie_prima(m);
}

void testGetName() {
    materie_prima *m = new_materie_prima("lapte", "napolact", 20);

    assert(strcmp(get_name(m), "lapte") == 0);

    destroy_materie_prima(m);
}

void testGetProducer() {
    materie_prima *m = new_materie_prima("lapte", "napolact", 20);

    assert(strcmp(get_producer(m), "napolact") == 0);

    destroy_materie_prima(m);
}

void testGetQuantity() {
    materie_prima *m = new_materie_prima("lapte", "napolact", 20);

    assert(get_quantity(m) == 20);

    destroy_materie_prima(m);
}

void testSetProducer() {
    materie_prima *m = new_materie_prima("lapte", "napolact", 20);

    set_producer(m, "dorna");

    assert(strcmp(m->producer, "dorna") == 0);

    destroy_materie_prima(m);
}

void testSetQuantity() {
    materie_prima *m = new_materie_prima("lapte", "napolact", 20);

    set_quantity(m, 30);

    assert(m->quantity == 30);

    destroy_materie_prima(m);
}

void testDomain() {
    testCreateMaterie();
    testGetName();
    testGetProducer();
    testGetQuantity();
    testSetProducer();
    testSetQuantity();
}

void testNewContainer() {
    list *l = new_list();

    assert(l->size == 0);
    assert(l->capacity == 1);

    destroy_list(l);
}

void testAddMaterial() {
    list *l = new_list();
    TElem *e1 = new_materie_prima("lapte", "napolact", 20),
          *e2 = new_materie_prima("apa plata", "Dorna", 30);

    add_TElem(l, e1);
    add_TElem(l, e2);

    assert(l->element[0] == e1);
    assert(l->element[1] == e2);
    assert(l->capacity == 2);

    destroy_list(l);
}

void testDeleteMaterial() {
    list *l = new_list();
    TElem *e1 = new_materie_prima("lapte", "Napolact", 20),
          *e2 = new_materie_prima("apa plata", "Dorna", 30),
          *e3 = new_materie_prima("faina", "de la moara", 10);

    add_TElem(l, e1);
    add_TElem(l, e2);

    assert(delete_TElem(l, e3) == 1);

    add_TElem(l, e3);

    assert(delete_TElem(l, e2) == 0);
    assert(l->size == 2);
    assert(l->element[0] == e1);
    assert(l->element[1] == e3);

    destroy_list(l);
}

void testEmptyList() {
    list *l = new_list();
    TElem *e1 = new_materie_prima("lapte", "Napolact", 20),
            *e2 = new_materie_prima("apa plata", "Dorna", 30);

    add_TElem(l, e1);
    add_TElem(l, e2);

    empty_list(l);
    assert(l->size == 0);

    destroy_list(l);
    destroy_materie_prima(e1);
    destroy_materie_prima(e2);
}

void testGetSize() {
    list *l = new_list();
    TElem *e1 = new_materie_prima("lapte", "Napolact", 20),
            *e2 = new_materie_prima("apa plata", "Dorna", 30),
            *e3 = new_materie_prima("faina", "de la moara", 10);

    add_TElem(l, e1);
    add_TElem(l, e2);
    add_TElem(l, e3);

    assert(get_size(l) == 3);

    destroy_list(l);
}

void testGetCapacity() {
    list *l = new_list();
    TElem *e1 = new_materie_prima("lapte", "Napolact", 20),
            *e2 = new_materie_prima("apa plata", "Dorna", 30),
            *e3 = new_materie_prima("faina", "de la moara", 10);

    add_TElem(l, e1);
    add_TElem(l, e2);
    add_TElem(l, e3);

    assert(get_capacity(l) == 4);

    destroy_list(l);
}

void testFindByName() {
    list *l = new_list();
    TElem *e1 = new_materie_prima("lapte", "Napolact", 20),
          *e2 = new_materie_prima("apa plata", "Dorna", 30),
          *e3 = new_materie_prima("faina", "de la moara", 10),
          *e4;

    add_TElem(l, e1);
    add_TElem(l, e2);
    add_TElem(l, e3);

    e4 = find_by_name(l, "lapte");
    assert(e4 == e1);

    e4 = find_by_name(l, "biscuiti");
    assert(e4 == NULL);

    destroy_list(l);
}

void testFindByIndex() {
    list *l = new_list();
    TElem *e1 = new_materie_prima("lapte", "Napolact", 20),
          *e2 = new_materie_prima("apa plata", "Dorna", 30),
          *e3 = new_materie_prima("faina", "de la moara", 10),
          *e4;

    add_TElem(l, e1);
    add_TElem(l, e2);
    add_TElem(l, e3);

    e4 = find_by_index(l, 0);
    assert(e4 == e1);

    e4 = find_by_index(l, 1);
    assert(e4 == e2);

    e4 = find_by_index(l, 2);
    assert(e4 == e3);

    destroy_list(l);
}

void testRepo() {
    testNewContainer();
    testAddMaterial();
    testDeleteMaterial();
    testEmptyList();
    testGetSize();
    testGetCapacity();
    testFindByName();
    testFindByIndex();
}

void testNewService() {
    service *s = new_service();

    assert(s != NULL);

    destroy_service(s);
}

void testAddMaterie() {
    service *s = new_service();
    char name[] = "lapte", producer[] = "napolact";
    unsigned long quantity = 20;

    add_materie_prima(s, name, producer, quantity);

    TElem *e = find_by_index(s->list, 0);

    assert(strcmp(get_name(e), "lapte") == 0);
    assert(strcmp(get_producer(e), "napolact") == 0);
    assert(get_quantity(e) == 20);

    destroy_service(s);
}

void testModifyMaterie() {
    service *s = new_service();
    char name[] = "lapte", producer[] = "napolact", *new_producer = "dorna";
    unsigned long quantity = 20, new_quantity = 30;

    add_materie_prima(s, name, producer, quantity);

    assert(modify_materie(s, "ceva", new_producer, new_quantity) == 1);
    assert(modify_materie(s, name, new_producer, new_quantity) == 0);

    TElem *e = find_by_name(s->list, name);

    assert(strcmp(get_name(e), name) == 0);
    assert(strcmp(get_producer(e), new_producer) == 0);
    assert(get_quantity(e) == new_quantity);

    destroy_service(s);
}

void testDeleteMaterie() {
    service *s = new_service();
    char name[] = "lapte", producer[] = "napolact";
    unsigned long quantity = 20;

    add_materie_prima(s, name, producer, quantity);

    assert(delete_materie(s, "bicuiti") == 1);
    assert(delete_materie(s, name) == 0);
    assert(get_size(s->list) == 0);

    destroy_service(s);
}

void testFilterByLetter() {
    service *s = new_service();
    char name[] = "lapte", producer[] = "napolact";
    unsigned long quantity = 20;

    add_materie_prima(s, name, producer, quantity);
    add_materie_prima(s, "biscuiti", "ceva", 10);
    add_materie_prima(s, "banane", "brazilia", 15);

    list *filtered = filter_by_the_first_letter(s, 'b');

    TElem *e;

    e = find_by_index(filtered, 0);
    assert(strcmp(get_name(e), "biscuiti") == 0);
    e = find_by_index(filtered, 1);
    assert(strcmp(get_name(e), "banane") == 0);

    destroy_service(s);
}

void testFilterByQuantity() {
    service *s = new_service();
    char name[] = "lapte", producer[] = "napolact";
    unsigned long quantity = 20;

    add_materie_prima(s, name, producer, quantity);
    add_materie_prima(s, "biscuiti", "ceva", 10);
    add_materie_prima(s, "banane", "brazilia", 15);

    list *filtered = filter_by_quantity(s, 16);

    TElem *e;

    e = find_by_index(filtered, 0);
    assert(strcmp(get_name(e), "biscuiti") == 0);
    e = find_by_index(filtered, 1);
    assert(strcmp(get_name(e), "banane") == 0);

    destroy_service(s);
}

void testSortByNameAscending() {
    service *s = new_service();
    char name[] = "lapte", producer[] = "napolact";
    unsigned long quantity = 20;

    add_materie_prima(s, name, producer, quantity);
    add_materie_prima(s, "biscuiti", "ceva", 10);
    add_materie_prima(s, "banane", "brazilia", 15);

    sort_down_name(s);

    destroy_service(s);
}

void testSortByNameDescending() {
    service *s = new_service();
    char name[] = "lapte", producer[] = "napolact";
    unsigned long quantity = 20;

    add_materie_prima(s, name, producer, quantity);
    add_materie_prima(s, "biscuiti", "ceva", 10);
    add_materie_prima(s, "banane", "brazilia", 15);

    sort_up_name(s);

    destroy_service(s);
}

void testSortByQuantityAscending() {
    service *s = new_service();
    char name[] = "lapte", producer[] = "napolact";
    unsigned long quantity = 20;

    add_materie_prima(s, name, producer, quantity);
    add_materie_prima(s, "biscuiti", "ceva", 10);
    add_materie_prima(s, "banane", "brazilia", 15);

    sort_up_quantity(s);

    destroy_service(s);
}

void testSortByQuantityDescending() {
    service *s = new_service();
    char name[] = "lapte", producer[] = "napolact";
    unsigned long quantity = 20;

    add_materie_prima(s, name, producer, quantity);
    add_materie_prima(s, "biscuiti", "ceva", 10);
    add_materie_prima(s, "banane", "brazilia", 15);

    sort_down_quantity(s);

    destroy_service(s);
}

void testService() {
    testNewService();
    testAddMaterie();
    testModifyMaterie();
    testDeleteMaterie();
    testFilterByLetter();
    testFilterByQuantity();
    testSortByNameAscending();
    testSortByNameDescending();
    testSortByQuantityAscending();
    testSortByQuantityDescending();
}

void testAll() {
    testDomain();
    testRepo();
    testService();
}