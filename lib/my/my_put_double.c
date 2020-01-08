/*
** EPITECH PROJECT, 2019
** ###
** File description:
** Print a double
*/

#include "../../include/my.h"

static long long int round_dec_part(long long int dec_part, double nb,
long long int precision)
{
    int int_part = nb;

    nb -= int_part;
    nb *= precision;
    nb = round(nb);
    if (nb < 0)
        nb *= -1;
    if (nb > dec_part)
        dec_part++;
    if (nb < dec_part)
        dec_part--;
    return dec_part;
}

static void arrange_and_put_the_dec_part(long long int dec_part, int pow_precision,
long long int precision, double nb)
{
    int int_len = 1;

    if (dec_part < 0)
        dec_part *= -1;
    dec_part = round_dec_part(dec_part, nb, precision);
    if (dec_part > 0) {
        for (long long int i = dec_part; i > 0 ; i /= 10)
            int_len++;
        for (int i = pow_precision - int_len; i >= 0 ; i--)
            my_putchar('0');
    }
    if (dec_part == 0)
        for (int i = 0; i < pow_precision - 1; i++)
            my_putchar('0');
    my_put_nbr(dec_part);
}

void my_put_double(double nb, int pow_precision)
{
    long int int_part = nb;
    long long int dec_part = 0;
    long double gap = 0;
    long long int precision = pow(10, pow_precision);

    if (nb < 0 && nb > -1)
        my_putchar('-');
    dec_part = nb * precision - (int_part * precision);
    gap = dec_part - (nb * precision - (int_part * precision));
    if ((gap > 0.001 || gap < -0.001) && dec_part >= 0)
        dec_part++;
    if (dec_part == precision) {
        dec_part = 0;
        int_part++;
    }
    my_put_nbr(int_part);
    my_putchar('.');
    arrange_and_put_the_dec_part(dec_part, pow_precision, precision, nb);
}
