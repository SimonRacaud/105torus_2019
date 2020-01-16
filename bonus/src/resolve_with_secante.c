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

int resolve_with_secante(config_t *config, sfRenderWindow *window,
framebuffer_t *fb)
{
    double x0 = 0;
    double x1 = 1;
    double x2 = 0;
    double a;
    sfVector2u pos;

    if (check_first_values(config) != 2)
        return check_first_values(config);
    for (int i = 0; i < 100; i++) {
        x2 = compute_x2(config, x0, x1);
        display_x_value(x2, config);
        pos.x = i * 15 + 5;
        pos.y = 600 - 600 * x2 + 5;
        draw_disc(fb, pos, 5, sfGreen);
        if (x2 == 0) {
            write(2, "Division by zero\n", 17);
            exit(84);
        }
        a = ABS(x2 - x1);
        a /= ABS(x2);
        if (a < pow(10, -config->precision)) {
            if (x2 < 0 || x2 > 1) {
                write(2, "No solution found\n", 18);
                exit(84);
            }
            for(int j = i; j < 53; j++) {
                pos.x = j * 15 + 5;
                pos.y = 600 - 600 * x2 + 5;
                draw_disc(fb, pos, 5, sfGreen);
            }
            return x2;
        }
        update_values(&x0, &x1, x2);
    }
    write(2, "No solution found\n", 18);
    exit(84);
}
