/*
** wolf3d.c for wolf3d in /home/jeremy.elkaim/raytracer1/source
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Mon Feb 27 10:36:40 2017 jeremy elkaim
** Last update Fri Mar 31 10:06:17 2017 jeremy elkaim
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <stdlib.h>
#include <SFML/Window/Keyboard.h>
#include <math.h>
#include <stdio.h>
#include "include/my.h"

int			main2(sfRenderWindow* window, sfSprite* sprite)
{
  while (sfRenderWindow_isOpen(window))
    {
      if (sfKeyboard_isKeyPressed(sfKeyEscape))
        {
          sfRenderWindow_destroy(window);
          return (EXIT_FAILURE);
        }
      sfRenderWindow_clear(window, sfBlack);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
    }
  sfRenderWindow_destroy(window);
  return (EXIT_SUCCESS);
}

int			main()
{
  sfRenderWindow*	window;
  sfTexture*		texture;
  sfSprite*		sprite;
  t_my_framebuffer*	framebuffer;
  int			a;
  int			b;
  float			plane;
  sfVector2i		screen_size;
  sfVector2i		position_screen;
  sfVector3f		eye;
  sfVector3f		vector;
  float			operation;

  a = 1680;
  b = 1050;
  screen_size.x = a;
  screen_size.y = b;
  position_screen.x = 0;
  position_screen.y = 0;
  eye.x = -200;
  eye.y = 0;
  eye.z = -10;
  framebuffer = malloc(sizeof(t_my_framebuffer *));
  framebuffer->width = a;
  framebuffer->height = b;
  window = create_window("Raytracer1", framebuffer->width, framebuffer->height);
  sprite = sfSprite_create();
  texture = sfTexture_create(framebuffer->width, framebuffer->height);
  framebuffer->pixels = create_pixel_buffer(framebuffer->width, framebuffer->height);
  sfSprite_setTexture(sprite, texture, sfTrue);
  while (position_screen.x != a)
    {
      position_screen.y = 0;
      while (position_screen.y != b)
	{
	  vector = calc_dir_vector(200, screen_size, position_screen);
	  operation = intersect_sphere(eye, vector, 100);
	  plane = intersect_plane(eye, vector);
	  if ((operation != -1 && operation < plane) || (operation != -1 && plane == -1) || (operation != -1 && operation > plane))
	    my_put_pixel(framebuffer, position_screen.x, position_screen.y, sfColor_fromRGB(0,0,255));
	  else if ((plane != -1 && plane < operation) || (plane != -1 && operation == -1))
	    my_put_pixel(framebuffer, position_screen.x, position_screen.y, sfColor_fromRGB(255,0,0));
	  position_screen.y = position_screen.y + 1;
	}
      position_screen.x = position_screen.x + 1;
    }
  sfTexture_updateFromPixels(texture, framebuffer->pixels, framebuffer->width, framebuffer->height, 0, 0);
  main2(window, sprite);
}
