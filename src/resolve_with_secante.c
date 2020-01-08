/*
** EPITECH PROJECT, 2020
** 105torus_2019
** File description:
** Resolve the equation with the secante method
*/

#include "torus.h"

static double compute_x2(config_t *config, double x0, double x1)
{
    double x2 = 0;

    x2 += get_equation_result(config, x1) * (x1 - x0);
    if (get_equation_result(config, x1) - get_equation_result(config, x0) == 0) {
        write(2, "Division by zero\n", 17);
        exit(84);
    }
    x2 /= get_equation_result(config, x1) - get_equation_result(config, x0);
    x2 *= -1;
    x2 += x1;
    return x2;
}

static void update_values(double *x0, double *x1, double x2)
{
    *x0 = *x1;
    *x1 = x2;
}

static void print_x_value(double x, int precision)
{
    my_printf("x = ");
    my_put_double(x, get_nb_decimal(x, precision));
    my_printf("\n");
}

void resolve_with_secante(config_t *config)
{
    double x0 = 0;
    double x1 = 1;
    double x2 = 0;
    double a;

    check_first_values(config);
    for (int i = 0; i < 50; i++) {
        x2 = compute_x2(config, x0, x1);
        print_x_value(x2, config->precision);
        if (x2 == 0) {
            write(2, "Division by zero\n", 17);
            exit(84);
        }
        a = ABS(x2 - x1);
        a /= ABS(x2);
        if (a < pow(10, -config->precision))
            exit(0);
        update_values(&x0, &x1, x2);
    }
    write(2, "No solution found\n", 18);
    exit(84);
}
