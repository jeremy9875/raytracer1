/*
** my.h for my in /home/jeremy.elkaim/raytracer1/include
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Mon Feb 27 10:34:00 2017 jeremy elkaim
** Last update Fri Mar 17 11:17:41 2017 jeremy elkaim
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

#ifndef RAYTRACER1_
#define RAYTRACER1_

typedef struct		s_my_framebuffer
{
  sfUint8*		pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

sfUint8*       	create_pixel_buffer(int	width, int height);
sfRenderWindow*	create_window(char* name, int width, int height);
void		my_put_pixel(t_my_framebuffer* framebuffer, int x, int y, sfColor color);
sfVector3f	calc_dir_vector(float dist_to_place,
				sfVector2i screen_size, sfVector2i screen_pos);
float		intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector);
float		get_normal_cylinder(sfVector3f intersection_point);
float		intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector);
float		get_normal_plane(int upward);
float		intersect_sphere(sfVector3f eye_pos,
				 sfVector3f dir_vector, float radius);
float		get_normal_sphere(sfVector3f
				  intersection_point);
float		intersection_cone(sfVector3f eye_pos,
				  sfVector3f dir_vector, float semiangle);
sfVector3f	get_normal_cone(sfVector3f intersection_point, float semiangle);
sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles);
sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles);
sfVector3f	translate(sfVector3f to_translate, sfVector3f translations);
sfVector2i	move_forward(sfVector2f pos,
			     float direction, float distance);
void		movedirectory();
void		wichdrawline(t_my_framebuffer* framebuffer,
			     sfVector2i from, sfVector2i to, sfColor color);
void		my_draw_line(t_my_framebuffer* framebuffer,
			     sfVector2i from, sfVector2i to, sfColor color);
void		my_draw_line1(t_my_framebuffer* framebuffer,
			      sfVector2i from, sfVector2i to, sfColor color);
void		my_draw_line2(t_my_framebuffer* framebuffer,
			      sfVector2i from, sfVector2i to, sfColor color);
void		my_draw_line3(t_my_framebuffer* framebuffer,
			      sfVector2i from, sfVector2i to, sfColor color);
int		main();
float		get_light_coef(sfVector3f light_vector, sfVector3f normal_vector);
int		main2(sfRenderWindow* window, sfSprite* sprite);

#endif /* !RAYTRACER_ */
