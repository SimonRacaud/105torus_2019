/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** Create, display and  destroy
*/

#include "torus.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode video_mode;

    video_mode.width = 800;
    video_mode.height = 600;
    video_mode.bitsPerPixel = 32;
    return sfRenderWindow_create(video_mode, "", sfDefaultStyle, NULL);
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(*framebuffer));

    framebuffer->pixel = malloc(width * height * 32 / 8);
    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->texture = sfTexture_create(800, 600);
    framebuffer->sprite = sfSprite_create();
    return framebuffer;
}

void display(sfTexture *texture, framebuffer_t *fb, sfSprite *sprite,
sfRenderWindow *window)
{
    sfTexture_updateFromPixels(texture, fb->pixel, 800, 600, 0, 0);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
}

int is_event(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    return 0;
}

void destroy(framebuffer_t *fb, sfTexture *texture, sfSprite *sprite)
{
    free(fb->pixel);
    free(fb);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}
