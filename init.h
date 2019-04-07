//
// Created by Yurii Tkachyshyn on 2019-03-30.
//
#ifndef ECG_INIT_H
#define ECG_INIT_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "defs.h"

//Starts up SDL and creates window
SDL_Window *init();
void close();

#endif //ECG_INIT_H
