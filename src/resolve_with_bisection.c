/*
** EPITECH PROJECT, 2020
** 105torus_2019
** File description:
** Resolve the equation with the bisection method
*/

#include "torus.h"

double get_equation_result(config_t *config, double x)
{
    double result = 0;

    for (int i = 4; i >= 0; i--) {
        result += config->coef[i];
        if (i != 0)
            result *= x;
    }
    return result;
}

static void check_first_values(config_t *config)
{
    if (get_equation_result(config, 0) < pow(10, -config->precision)) {
        my_printf("x = 0\n");
        exit(0);
    }
    if (get_equation_result(config, 1) < pow(10, -config->precision)) {
        my_printf("x = 1\n");
        exit(0);
    }
}

static void update_values(double *x0, double *x1, double xm, config_t *config)
{
    double result = 0;

    result += get_equation_result(config, *x0);
    result *= get_equation_result(config, xm);
    if (result < 0)
        *x1 = xm;
    else
        *x0 = xm;
}

void resolve_with_bisection(config_t *config)
{
    double x0 = 0;
    double x1 = 1;
    double xm = 0;

    check_first_values(config);
    for (int i = 0; i < 50; i++) {
        xm = abs(x1 - x0) / 2;
        my_printf("x = ");
        my_put_double(xm, config->precision);
        if (xm == 0) {
            write(2, "Division by zero\n", 17);
            exit(84);
        }
        if (abs(x0 - x1) / (2 * xm) < pow(10, -config->precision))
            exit(0);
        update_values(&x0, &x1, xm, config);
    }
    write(2, "No solution found\n", 18);
    exit(84);
}
