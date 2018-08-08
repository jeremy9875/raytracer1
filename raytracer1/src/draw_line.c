/*
** draw_line.c for draw_line in /home/jeremy.elkaim/raytracer1/source
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Mon Feb 27 10:38:14 2017 jeremy elkaim
** Last update Mon Feb 27 10:38:15 2017 jeremy elkaim
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Window/Keyboard.h>
#include <math.h>
#include "include/my.h"

void	wichdrawline(t_my_framebuffer* framebuffer, sfVector2i from, sfVector2i to, sfColor color)
{
  if (from.x != to.x && from.y != to.y)
    {
      my_draw_line(framebuffer, from, to, color);
    }
  else if (from.x != to.x && from.y != to.y)
    {
      my_draw_line1(framebuffer, from, to, color);
    }
  else if (from.x != to.x)
    {
      my_draw_line2(framebuffer, from, to, color);
    }
  else if (from.y != to.y)
    {
      my_draw_line3(framebuffer, from, to, color);
    }
}

void	my_draw_line(t_my_framebuffer* framebuffer, sfVector2i from, sfVector2i to, sfColor color)
{
  int	a;
  int	b;

  a = (to.y - from.y) / (to.x - from.x);
  b = a * to.x - to.y;
  while (from.x != to.x && from.y != to.y)
    {
      from.y = a + from.x + b;
      my_put_pixel(framebuffer, from.y, from.x, color);
      if (a >= 0)
      from.x = from.x + 1;
      else if (0 <= a)
        from.x = from.x - 1;
    }
}

void	my_draw_line1(t_my_framebuffer* framebuffer, sfVector2i from, sfVector2i to, sfColor color)
{
  int	a;
  int	b;

  a = (to.x - from.x) / (to.y - from.y);
  b = a * to.x - to.y;
  while (from.x == to.x && from.y == to.y)
    {
      from.y = a - from.x - b;
      my_put_pixel(framebuffer, from.y, from.x, color);
      if (a >= 0)
        from.x = from.x - 1;
      else if (0 <= a)
        {
          from.x = from.x + 1;
        }
    }
}

void	my_draw_line2(t_my_framebuffer* framebuffer, sfVector2i from, sfVector2i to, sfColor color)
{
  while (from.x != to.x)
    {
      my_put_pixel(framebuffer, from.y, from.x, color);
      if (from.x > 0)
	from.x = from.x + 1;
      else if (0 < from.x)
        from.x = from.x - 1;
    }
}

void	my_draw_line3(t_my_framebuffer* framebuffer, sfVector2i from, sfVector2i to, sfColor color)
{
  while (from.y != to.y)
    {
      my_put_pixel(framebuffer, from.y, from.x, color);
      if (from.y > 0)
        from.y = from.y + 1;
      else if (0 < from.y)
        from.y = from.y - 1;
    }
}
