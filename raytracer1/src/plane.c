/*
** plane.c for plane in /home/jeremy.elkaim/raytracer1/src
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Mon Mar  6 15:36:00 2017 jeremy elkaim
** Last update Thu Mar  9 16:27:26 2017 jeremy elkaim
*/

#include <SFML/Graphics.h>
# include <stdio.h>

float	intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float	plane;

  if (dir_vector.z == 0)
    return (-1);
  plane = (eye_pos.z / dir_vector.z);
  if (plane <= 0)
    return (-1);
  else
    return (plane);
  return (0);
}
