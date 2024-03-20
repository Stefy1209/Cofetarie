//
// Created by stefy0-0 on 13.03.2024.
//

#ifndef COFETARIE_UI_H
#define COFETARIE_UI_H

#include "service.h"

typedef struct {
    service *service;
} ui;

void runUI(ui *UI);

#endif //COFETARIE_UI_H
