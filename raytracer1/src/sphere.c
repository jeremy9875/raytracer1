/*
** sphere.c for sphere in /home/jeremy.elkaim/raytracer1/src
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Mon Mar  6 15:25:44 2017 jeremy elkaim
** Last update Thu Mar  9 16:18:28 2017 jeremy elkaim
*/

#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>

float	my_calc_delta(float a, float b, float c)
{
  float	delta;
  float	x;
  float	y;

  delta = pow(b,2) - (4 * a * c);
  if (delta < 0)
    return (-1);
  else if (delta > 0)
    {
      x = (-b+sqrt(delta)) / 2 * a;
      y = (-b-sqrt(delta)) / 2 * a;
      if (x > 0 && y < 0)
	return (x);
      else if (y > 0 && x < 0)
	return (y);
      else if (x > 0 && y > 0 && x > y)
	return (y);
      else if (x > 0 && y > 0 && y > x)
	return (x);
      else
	return (-1);
    }
  else if (delta == 0)
    {
      x = -b/(2*a);
      if (x <= 0)
	return (-1);
      else
	return (x);
    }
  return (0);
}

float	intersect_sphere(sfVector3f eye_pos,
			 sfVector3f dir_vector, float radius)
{
  float	delta;
  float	a;
  float	b;
  float	c;

  a = pow(dir_vector.x, 2) + pow(dir_vector.y, 2)
    + pow(dir_vector.z, 2);
  b = 2 * (eye_pos.x * dir_vector.x + eye_pos.y
	   * dir_vector.y + eye_pos.z * dir_vector.z);
  c = pow(eye_pos.x, 2) + pow(eye_pos.y, 2)
    + pow(eye_pos.z, 2) - pow(radius, 2);
  delta = my_calc_delta(a, b, c);
  return (delta);
}
