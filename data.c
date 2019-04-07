//
// Created by Yurii Tkachyshyn on 2019-04-02.
//

#include "data.h"
#include <stdio.h>
#include <stdlib.h>

void read_ecg_simulation(void);
static FILE* open_file(char* path);
static void close_file(FILE* fp);
static int read_next(float* time, float* voltage, FILE* fp);
