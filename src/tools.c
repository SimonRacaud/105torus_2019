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
