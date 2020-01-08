/*
** EPITECH PROJECT, 2020
** 105torus_2019
** File description:
** torus header
*/

#ifndef H_TORUS
#define H_TORUS

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

#define EXIT_ERROR 84

#define NB_ARG 8

#define BISECTION_MODE 1
#define NEWTON_MODE 2
#define SECANT_MODE 3

typedef struct config {
    int opt;
    int coef[5];
    int precision;
} config_t;

int torus(char **argv);
int get_arguments(config_t *config, char **argv);

double get_equation_result(config_t *config, double x);

#endif
