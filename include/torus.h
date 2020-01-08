/*
** EPITECH PROJECT, 2020
** 105torus_2019
** File description:
** torus header
*/

#ifndef H_TORUS
#define H_TORUS

#include <math.h>
#include "my.h"

#define EXIT_ERROR 84

typedef struct config {
    int opt;
    int coef[5];
    int precision;
} config_t;

int torus(int argc, char **argv);

#endif
