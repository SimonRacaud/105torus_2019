/*
** EPITECH PROJECT, 2020
** 105torus_2019
** File description:
** get arguments
*/

#include "torus.h"

static int str_is_number(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] == '-' && i != 0) {
            return 0;
        } else if ((str[i] > '9' || str[i] < 0) && str[i] != '-') {
            return 0;
        }
    }
    return 1;
}

static int check_arguments(config_t *config)
{
    if (config->opt < 1 && config->opt > 3) {
        perror("ERROR: opt must be between 1 and 3\n");
        return EXIT_ERROR;
    } else if (config->precision < 0) {
        perror("ERROR: negative precision\n");
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

int get_arguments(config_t *config, char **argv)
{
    for (int i = 1; i < NB_ARG; i++) {
        if (!str_is_number(argv[i])) {
            perror("ERROR: an argument is not a number\n");
            return EXIT_ERROR;
        }
    }
    config->opt = my_getnbr(argv[1]);
    for (int i = 2; i < NB_ARG - 1; i++) {
        config->coef[i - 2] = my_getnbr(argv[i]);
    }
    config->precision = my_getnbr(argv[NB_ARG - 1]);
    if (check_arguments(config))
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
