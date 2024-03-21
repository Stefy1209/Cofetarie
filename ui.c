//
// Created by stefy0-0 on 13.03.2024.
//

#include "ui.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print(list *l) {
    unsigned long i, size = l->size, quantity;
    TElem *e;
    char *name, *producer;

    for(i = 0; i < size; i++) {
        e = l->element[i];
        name = get_name(e);
        producer = get_producer(e);
        quantity = get_quantity(e);

        printf("Name: %s\n", name);
        printf("Producer: %s\n", producer);
        printf("Quantity: %ld\n", quantity);
        printf("\n");
    }
}

void UIAdd(ui *UI) {
    char name[256], producer[256];
    char number[256], *ptr;
    unsigned long quantity;

    printf("\n");
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter producer: ");
    scanf("%s", producer);
    printf("Enter quantity: ");
    scanf("%s", number);
    quantity = strtoul(number, &ptr, 10);

    add_materie_prima(UI->service, name, producer, quantity);

    printf("\n");

    print(UI->service->list);
}

void UIModify(ui *UI) {
    char name[256], new_producer[256];
    char number[256], *ptr;
    unsigned long new_quantity;

    printf("\n");
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter producer: ");
    scanf("%s", new_producer);
    printf("Enter quantity: ");
    scanf("%s", number);
    new_quantity = strtoul(number, &ptr, 10);

    modify_materie(UI->service, name, new_producer, new_quantity);

    printf("\n");

    print(UI->service->list);
}

void UIDelete(ui *UI) {
    char name[256];

    printf("\n");
    printf("Enter name: ");
    scanf("%s", name);

    delete_materie(UI->service, name);

    printf("\n");

    print(UI->service->list);
}

void UIFilterLetter(ui *UI) {
    char letter;

    printf("\n");
    printf("Enter a letter: ");
    scanf(" %c", &letter);

    filter_by_the_first_letter(UI->service, letter);

    printf("\n");

    print(UI->service->filtered);
}

void UIFilterQuan(ui *UI) {
    unsigned long quantity;
    char number[256], *ptr;

    printf("\n");
    printf("Enter a quantity: ");
    scanf("%s", number);
    quantity = strtoul(number, &ptr, 10);

    filter_by_quantity(UI->service, quantity);

    printf("\n");

    print(UI->service->filtered);
}

void print_help() {

}

void runUI(ui *UI) {
    bool finished = false;
    char command[257];

    while (finished == false) {
        printf(">>> ");
        fscanf(stdin,"%s", command);

        switch (command[0]) {
            case 'a':
                if(strcmp(command, "add") == 0)
                    UIAdd(UI);
                else printf("\nInvalid command!\n\n");
                break;

            case 'm':
                if(strcmp(command, "modify") == 0)
                    UIModify(UI);
                else printf("\nInvalid command!\n\n");
                break;

            case 's':
                if(strcmp(command, "sort_asc_by_name") == 0) {
                    sort_up_name(UI->service);
                    printf("\n");
                    print(UI->service->list);
                }

                else if(strcmp(command, "sort_des_by_name") == 0) {
                    sort_down_name(UI->service);
                    printf("\n");
                    print(UI->service->list);
                }

                else if(strcmp(command, "sort_asc_by_q") == 0) {
                    sort_up_quantity(UI->service);
                    printf("\n");
                    print(UI->service->list);
                }

                else if(strcmp(command, "sort_des_by_q") == 0) {
                    sort_down_quantity(UI->service);
                    printf("\n");
                    print(UI->service->list);
                }

                else printf("\nInvalid command!\n\n");

                break;

            case 'f':
                if(strcmp(command, "filter_by_letter") == 0)
                    UIFilterLetter(UI);

                else if(strcmp(command, "filter_by_q") == 0)
                    UIFilterQuan(UI);

                else printf("\nInvalid command!\n\n");

                break;

            case 'd':
                if(strcmp(command, "delete") == 0)
                    UIDelete(UI);

                else printf("\nInvalid command!\n\n");

                break;

            case 'e':
                if(strcmp(command, "exit") == 0)
                    finished = true;

                else printf("\nInvalid command!\n\n");

                break;

            case 'h':
                if(strcmp(command, "help") == 0)
                    print_help();

                else printf("\nInvalid command!\n\n");

                break;

            default:
                printf("\nInvalid command!\n\n");
                break;
        }
    }
}