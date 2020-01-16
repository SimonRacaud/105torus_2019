/*
** EPITECH PROJECT, 2019
** CPool_Day13_2019
** File description:
** Display a rectangle
*/

#include "torus.h"

void put_pixel(framebuffer_t *framebuffer, int x,
int y, sfColor color)
{
    int pixel_nb = (framebuffer->width) * y * 4 + (x * 4);

    if (x < 800 && x >= 0 && y < 600 && y >= 0) {
        framebuffer->pixel[pixel_nb] = color.r;
        framebuffer->pixel[pixel_nb + 1] = color.g;
        framebuffer->pixel[pixel_nb + 2] = color.b;
        framebuffer->pixel[pixel_nb + 3] = color.a;
    }
}

void draw_rectangle(framebuffer_t *framebuffer, sfVector2u position,
unsigned int *size, sfColor color)
{
    for (unsigned int y = position.y; y < position.y + size[1]; y++)
        for (unsigned int x = position.x; x < position.x + size[0]; x++)
            put_pixel(framebuffer, x, y, color);
}
