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
#define nullptr NULL

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

/*void testNewContainer() {
    container container1 = new_container();

    assert(container1.size == 0);
    assert(container1.capacity == 256);
}

void testDestroyContainer() {
    container container1 = new_container();
    materie materie1 = new_materie("lapte", "napolact", 20);

    add_material(&container1, materie1);
    destroy_container(&container1);

    assert(container1.size == 0);
    assert(container1.capacity == 0);
}

void testAddMaterial() {
    container container1 = new_container();
    materie materie1 = new_materie("lapte", "napolact", 20);

    add_material(&container1, materie1);

    assert(strcmp(container1.material[0].name, materie1.name) == 0);
    assert(strcmp(container1.material[0].producer, materie1.producer) == 0);
    assert(container1.material[0].quantity == materie1.quantity);

    container1.size = 256;

    add_material(&container1, new_materie("a", "a", 3));

    materie materie2 = new_materie("lapte", "napolact", 10);

    assert(strcmp(container1.material[0].name, materie1.name) == 0);
    assert(strcmp(container1.material[0].producer, materie1.producer) == 0);
    assert(container1.material[0].quantity == materie1.quantity);
}

void testDeleteMaterial() {
    container container1 = new_container();
    materie materie1 = new_materie("lapte", "napolact", 20);
    add_material(&container1, materie1);
    delete_material(&container1, materie1);

    assert(container1.size == 0);
    assert(container1.capacity == 256);

    add_material(&container1, materie1);
    delete_material(&container1, new_materie("a", "a", 2));

    assert(container1.size == 1);
    assert(container1.capacity == 256);
}

void testGetSize() {
    container container1 = new_container();
    materie materie1 = new_materie("lapte", "napolact", 20);
    add_material(&container1, materie1);

    assert(get_size(container1) == 1);
}

void testGetCapacity() {
    container container1 = new_container();
    assert(get_capacity(container1) == 256);
}

void testFindByName() {
    container container1 = new_container();
    materie materie2 = find_by_name(container1,"lapte");

    assert(strcmp(materie2.name, "") == 0);
    assert(strcmp(materie2.producer, "") == 0);
    assert(materie2.quantity == 0);

    materie materie1 = new_materie("lapte", "napolact", 20);
    add_material(&container1, materie1);

    materie2 = find_by_name(container1, "lapte");

    assert(strcmp(materie2.name, "lapte") == 0);
    assert(strcmp(materie2.producer, "napolact") == 0);
    assert(materie2.quantity == 20);
}

void testFindByIndex() {
    container container1 = new_container();
    materie materie1 = new_materie("lapte", "napolact", 20);
    add_material(&container1, materie1);

    materie materie2 = find_by_index(container1, 0);

    assert(strcmp(materie2.name, "lapte") == 0);
    assert(strcmp(materie2.producer, "napolact") == 0);
    assert(materie2.quantity == 20);
}

void testRepo() {
    testNewContainer();
    testDestroyContainer();
    testAddMaterial();
    testDestoryMaterie();
    testDeleteMaterial();
    testGetSize();
    testGetCapacity();
    testFindByName();
    testFindByIndex();
}

void testAddMaterie() {
    container container1 = new_container();

    add_materie(&container1, "", "a", 2);
    add_materie(&container1, "a", "", 2);
    add_materie(&container1, "a", "a", 0);

    add_materie(&container1, "lapte", "napolact", 20);
    assert(strcmp(container1.material[0].name, "lapte") == 0);
    assert(strcmp(container1.material[0].producer, "napolact") == 0);
    assert(container1.material[0].quantity == 20);

    add_materie(&container1, "lapte", "napolact", 10);
    assert(strcmp(container1.material[0].name, "lapte") == 0);
    assert(strcmp(container1.material[0].producer, "napolact") == 0);
    assert(container1.material[0].quantity == 30);
}

void testModifyMaterie() {
    container container1 = new_container();
    modify_materie(&container1, "lapte", "a", 20);

    modify_materie(&container1, "", "a", 2);
    modify_materie(&container1, "a", "", 2);
    modify_materie(&container1, "a", "a", 0);

    add_materie(&container1, "lapte", "a", 20);
    modify_materie(&container1, "lapte", "b", 30);

    assert(strcmp(container1.material[0].name, "lapte") == 0);
    assert(strcmp(container1.material[0].producer, "b") == 0);
    assert(container1.material[0].quantity == 30);
}

void testDeleteMaterie() {
    container container1 = new_container();
    add_materie(&container1, "lapte", "a", 20);
    delete_materie(&container1, "lapte");

    assert(container1.size == 0);
}

void testFilterByLetter() {
    container container1 = new_container(), container2;
    add_materie(&container1, "lapte", "a", 20);

    container2 = filter_by_first_letter(&container1, 'a');
    assert(container2.size == 0);

    container2 = filter_by_first_letter(&container1, 'l');
    assert(strcmp(container2.material[0].name, "lapte") == 0);
    assert(strcmp(container2.material[0].producer, "a") == 0);
    assert(container2.material[0].quantity == 20);
}

void testFilterBuQuantity() {
    container container1 = new_container(), container2;
    add_materie(&container1, "lapte", "a", 20);

    container2 = filter_by_quantity(&container1, 10);
    assert(container2.size == 0);

    container2 = filter_by_quantity(&container1, 40);
    assert(strcmp(container2.material[0].name, "lapte") == 0);
    assert(strcmp(container2.material[0].producer, "a") == 0);
    assert(container2.material[0].quantity == 20);
}

void testSortByNameAscending() {
    container container1 = new_container(), container2 = new_container();
    materie materie1 = new_materie("lapte", "napolact", 20),
            materie2 = new_materie("a", "b", 10);

    add_material(&container1, materie1);
    add_material(&container1, materie2);

    container2 = sort_by_name_ascending(&container1);

    assert(strcmp(container2.material[0].name, "a") == 0);
    assert(strcmp(container2.material[0].producer, "b") == 0);
    assert(container2.material[0].quantity == 10);

    assert(strcmp(container2.material[1].name, "lapte") == 0);
    assert(strcmp(container2.material[1].producer, "napolact") == 0);
    assert(container2.material[1].quantity == 20);
}

void testSortByNameDescending() {
    container container1 = new_container(), container2 = new_container();
    materie materie1 = new_materie("lapte", "napolact", 20),
            materie2 = new_materie("a", "b", 10);

    add_material(&container1, materie2);
    add_material(&container1, materie1);

    container2 = sort_by_name_descending(&container1);

    assert(strcmp(container2.material[1].name, "a") == 0);
    assert(strcmp(container2.material[1].producer, "b") == 0);
    assert(container2.material[1].quantity == 10);

    assert(strcmp(container2.material[0].name, "lapte") == 0);
    assert(strcmp(container2.material[0].producer, "napolact") == 0);
    assert(container2.material[0].quantity == 20);
}

void testSortByQuantityAscending() {
    container container1 = new_container(), container2 = new_container();
    materie materie1 = new_materie("lapte", "napolact", 20),
            materie2 = new_materie("a", "b", 10);

    add_material(&container1, materie1);
    add_material(&container1, materie2);

    container2 = sort_by_quantity_ascending(&container1);

    assert(strcmp(container2.material[0].name, "a") == 0);
    assert(strcmp(container2.material[0].producer, "b") == 0);
    assert(container2.material[0].quantity == 10);

    assert(strcmp(container2.material[1].name, "lapte") == 0);
    assert(strcmp(container2.material[1].producer, "napolact") == 0);
    assert(container2.material[1].quantity == 20);
}

void testSortByQuantityDescending() {
    container container1 = new_container(), container2 = new_container();
    materie materie1 = new_materie("lapte", "napolact", 20),
            materie2 = new_materie("a", "b", 10);

    add_material(&container1, materie2);
    add_material(&container1, materie1);

    container2 = sort_by_quantity_descending(&container1);

    assert(strcmp(container2.material[1].name, "a") == 0);
    assert(strcmp(container2.material[1].producer, "b") == 0);
    assert(container2.material[1].quantity == 10);

    assert(strcmp(container2.material[0].name, "lapte") == 0);
    assert(strcmp(container2.material[0].producer, "napolact") == 0);
    assert(container2.material[0].quantity == 20);
}

void testService() {
    testAddMaterie();
    testModifyMaterie();
    testDeleteMaterie();
    testFilterByLetter();
    testFilterBuQuantity();
    testSortByNameAscending();
    testSortByNameDescending();
    testSortByQuantityAscending();
    testSortByQuantityDescending();
}*/

void testAll() {
    testDomain();
    //testRepo();
    //testService();
}