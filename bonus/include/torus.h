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
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>

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

typedef struct framebuffer
{
    sfUint8 *pixel;
    unsigned int width;
    unsigned int height;
    sfTexture *texture;
    sfSprite *sprite;
} framebuffer_t;

int torus(char **argv);
int get_arguments(config_t *config, char **argv);

int resolve_with_bisection(config_t *config, sfRenderWindow *window,
framebuffer_t *fb);
int resolve_with_newton(config_t *config, sfRenderWindow *window,
framebuffer_t *fb);
int resolve_with_secante(config_t *config, sfRenderWindow *window,
framebuffer_t *fb);

double get_equation_result(config_t *config, double x);

int get_nb_decimal(double nbr, int precision_max);
void display_division_zero(void);
void display_x_value(double x, config_t *config);
int check_first_values(config_t *config);

#define X3_VALUE 1.0647926521787425
#define X3_VALUE_DISP 1.064792652178748

sfRenderWindow *create_window(void);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void display(sfTexture *texture, framebuffer_t *fb, sfSprite *sprite,
sfRenderWindow *window);
int is_event(sfRenderWindow *window, sfEvent event);
void destroy(framebuffer_t *fb, sfTexture *texture, sfSprite *sprite);

void draw_rectangle(framebuffer_t *framebuffer, sfVector2u position,
unsigned int *size, sfColor color);

void draw_disc(framebuffer_t *framebuffer, sfVector2u pos,
unsigned int size, sfColor color);

void put_pixel(framebuffer_t *framebuffer, int x,
int y, sfColor color);

#endif
