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

#define ABS(x) (x < 0) ? (x * (-1)) : (x)

typedef struct config {
    int opt;
    int coef[5];
    int precision;
} config_t;

int torus(char **argv);
int get_arguments(config_t *config, char **argv);

void resolve_with_bisection(config_t *config);
void resolve_with_newton(config_t *config);
void resolve_with_secante(config_t *config);

double get_equation_result(config_t *config, double x);

int get_nb_decimal(double nbr, int precision_max);
void display_division_zero(void);
void display_x_value(double x, config_t *config);
void check_first_values(config_t *config);

#endif
