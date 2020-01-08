/*
** EPITECH PROJECT, 2020
** 105torus_2019
** File description:
** main
*/

#include "torus.h"

int usage(int status)
{
    my_putstr("USAGE\n\t./105torus opt a0 a1 a2 a3 a4 n\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\topt\tmethod option:\n");
    my_putstr("\t\t\t1 for the bisection method\n");
    my_putstr("\t\t\t2 for Newton’s method\n");
    my_putstr("\t\t\t3 for the secant method\n");
    my_putstr("\ta[0-4]\tcoefficients of the equation\n");
    my_putstr("\tn\tprecision (the application of the polynomial");
    my_putstr(" to the solution should\n");
    my_putstr("\t\tbe smaller than 10ˆ-n)\n");
    return EXIT_ERROR;
}

int main(int argc, char **argv)
{
    if (argc == 8) {
        return torus(argc, argv);
    } else if (argc == 2 && my_strcmp(argv[1], "-h")) {
        return usage(EXIT_SUCCESS);
    } else {
        return usage(EXIT_ERROR);
    }
}
