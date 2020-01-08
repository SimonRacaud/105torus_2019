/*
** EPITECH PROJECT, 2020
** 105torus_2019
** File description:
** Resolve the equation with the newton method
*/

#include "torus.h"

static void check_first_value(config_t *config)
{
    double nbr = ABS(get_equation_result(config, 0.5));

    if (nbr < pow(10, -config->precision)) {
        my_printf("x = 0.5\n");
        exit(0);
    }
}

static double get_derive_result(config_t *config, double x)
{
    double result = 0;

    for (int i = 4; i > 0; i--) {
        result += i * config->coef[i] * pow(x, (i - 1));
    }
    return result;
}

void resolve_with_newton(config_t *config)
{
    double x0 = 0.5;
    double x1;
    double derive;

    check_first_value(config);
    for (int i = 0; i < 50; i++) {
        derive = get_derive_result(config, x0);
        if (derive == 0)
            display_division_zero();
        x1 = x0 - (get_equation_result(config, x0) / derive);
        display_x_value(x1, config);
        if (x1 == 0)
            display_division_zero();
        if (ABS(x1 - x0) / ABS(x1) < pow(10, -config->precision))
            exit(0);
        x0 = x1;
    }
    write(2, "No solution found\n", 18);
    exit(84);
}
