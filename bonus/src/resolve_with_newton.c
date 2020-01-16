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

    printf("x = 0.5\n");
    if (nbr < pow(10, -config->precision)) {
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

static double get_out_equation(double x1, double x0)
{
    double b = ABS(x1 - x0);
    double a = ABS(x1);

    return b / a;
}

int resolve_with_newton(config_t *config, sfRenderWindow *window,
framebuffer_t *fb)
{
    double x0 = 0.5;
    double x1;
    double derive;
    sfVector2u pos;

    if (check_first_values(config) != 2)
        return check_first_values(config);
    for (int i = 0; i < 100; i++) {
        derive = get_derive_result(config, x0);
        if (derive == 0)
            display_division_zero();
        x1 = x0 - (get_equation_result(config, x0) / derive);
        display_x_value(x1, config);
        pos.x = i * 15 + 2;
        pos.y = 600 - 600 * x1 + 2;
        draw_disc(fb, pos, 10, sfRed);
        if (x1 == 0)
            return 0;
        if (get_out_equation(x1, x0) < pow(10, -config->precision)) {
            if (x1 < 0 || x1 > 1) {
                write(2, "No solution found\n", 18);
                exit(84);
            }
            for(int j = i; j < 53; j++) {
                pos.x = j * 15 + 2;
                pos.y = 600 - 600 * x1 + 2;
                draw_disc(fb, pos, 10, sfRed);
            }
            return x1;
        }
        x0 = x1;
    }
    write(2, "No solution found\n", 18);
    exit(84);
}
