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

    if (get_arguments(&config, argv))
        return EXIT_ERROR;
    debug_display(&config);
    resolve_with_bisection(&config);
    return EXIT_SUCCESS;
}
