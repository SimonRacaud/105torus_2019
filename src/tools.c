/*
** EPITECH PROJECT, 2020
** 105torus_2019
** File description:
** tools
*/

#include "torus.h"

int get_nb_decimal(double nbr, int precision_max)
{
    int precision = 0;

    nbr -= (int)nbr;
    while (nbr != 0 && precision < precision_max) {
        nbr *= 10;
        nbr -= (int)nbr;
        precision++;
    }
    return precision;
}

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

void display_division_zero(void)
{
    write(2, "Division by zero\n", 17);
    exit(84);
}

void display_x_value(double x, config_t *config)
{
    double x2 = x * pow(10, config->precision) - (int)x;

    x2 = x2 - (int)x2;
    x2 *= pow(10, 5);
    x2 = floor(x2);
    if (x2 != 0) {
        printf("x = %.*f\n", get_nb_decimal(x, config->precision), x);
    } else {
        printf("x = %.*g\n", get_nb_decimal(x, config->precision), x);
    }
}

void check_first_values(config_t *config)
{
    if (abs(get_equation_result(config, 0)) < pow(10, -config->precision)) {
        printf("x = 0\n");
        exit(0);
    }
    if (abs(get_equation_result(config, 1)) < pow(10, -config->precision)) {
        printf("x = 1\n");
        exit(0);
    }
}
