/*
** EPITECH PROJECT, 2020
** 105torus_2019
** File description:
** 105torus function
*/

#include "torus.h"

void debug_display(config_t *config)
{
    printf("-------------------\n");
    printf("opt %d \n", config->opt);
    for (int i = 0; i < 5; i++) {
        printf("\tcoef (%d) %d \n", i, config->coef[i]);
    }
    printf("precision %d \n", config->precision);
    printf("-------------------\n");
}

int torus(char **argv)
{
    config_t config;
    sfRenderWindow *window = create_window();
    sfEvent event;
    framebuffer_t *fb = framebuffer_create(800, 600);
    sfVector2u pos;
    unsigned int size[] = {800, 600};

    pos.x = 0;
    pos.y = 0;
    if (get_arguments(&config, argv)) {
        return EXIT_ERROR;
    }
    my_putstr("\033[34m");
    draw_rectangle(fb, pos, size, sfWhite);
    my_putstr("BISECTION : \n");
    resolve_with_bisection(&config, window, fb);
    my_putstr("\033[31m");
    my_putstr("\nNEWTON : \n");
    resolve_with_newton(&config, window, fb);
    my_putstr("\033[32m");
    my_putstr("\nSECANTE : \n");
    resolve_with_secante(&config, window, fb);
    my_putstr("\033[0m");
    while(sfRenderWindow_isOpen(window)) {
        display(fb->texture, fb, fb->sprite, window);
        is_event(window, event);
    }
    return EXIT_SUCCESS;
}
