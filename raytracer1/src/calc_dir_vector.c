/*
** calc_dir_vector.c for calc_dir_vector in /home/jeremy.elkaim/raytracer1/src
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Mon Mar  6 15:15:37 2017 jeremy elkaim
** Last update Wed Mar  8 14:15:51 2017 jeremy elkaim
*/
#include <SFML/Graphics.h>

sfVector3f	calc_dir_vector(float dist_to_plane, sfVector2i screen_size,  sfVector2i screen_pos)
{
  sfVector3f	qwerty;

  qwerty.x = dist_to_plane;
  qwerty.y = (screen_size.x / 2) - screen_pos.x;
  qwerty.z = (screen_size.y / 2) - screen_pos.y;
  return (qwerty);
}
