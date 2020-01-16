/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** Draw a circle
*/

#include "torus.h"

static void compute_distance(double *distance, unsigned int *x_y,
unsigned int size)
{
    distance[1] = my_compute_power_rec(x_y[0] - size / 2, 2);
    distance[2] = my_compute_power_rec(x_y[1] - size / 2, 2);
    distance[0] = sqrt(distance[1] + distance[2]);
}

void draw_disc(framebuffer_t *framebuffer, sfVector2u pos,
unsigned int size, sfColor color)
{
    unsigned int x_y[] = {0, 0};
    double distance[] = {0, 0, 0};

    for (int i = 0; i < my_compute_power_rec(size + 1, 2); i++) {
        compute_distance(distance, x_y, size);
        if (size - (distance[0] * 2) >= 0.1)
            put_pixel(framebuffer, x_y[0] + pos.x, x_y[1] + pos.y, color);
        if (x_y[0] >= size) {
            x_y[1]++;
            x_y[0] = -1;
        }
        x_y[0]++;
    }
}
