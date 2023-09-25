/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:37:49 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/25 14:50:02 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
*	Macros de gestion d'erreur
*/

# define CHAR_ERROR "Unrecognized characters"
# define MAP_LAYOUT_ERROR "Bad map layout"
# define ARGUMENT_ERROR "Invalid argument"
# define FILE_DESRIPTOR_ERROR "Bad file descriptor"
# define BAD_PLAYER_ERROR "Not enough or too many players present on the map"
# define BAD_FILE "Bad file arrangement"

/*
*	Macros de gestion des visuels
*/

# define SCREEN_HEIGHT 700
# define SCREEN_HEIGHT_1 SCREEN_HEIGHT / 2
# define SCREEN_WIDTH 1200
# define TITLE_SCREEN "Cub3D"
# define MINIMAP_X 170
# define MINIMAP_Y 170
# define BITS_PER_BYTE 8

# define TILE_SIZE 20

# define FOV M_2_SQRTPI
# define NUM_RAYS SCREEN_WIDTH

/*
*	Macros de gestion mathematique
*/

# define COLLISION_MARGIN 0.00000f

# define PI 3.141592
# define CASTED_RAYS 1400
# define STEP_ANGLE FOV / CASTED_RAYS
# define SCALE (SCREEN_WIDTH / 2) / CASTED_RAYS

# define SPRITE_WIDTH 64
# define SPRITE_HEIGHT 64

# define NUM_FRAMES_TO_MEASURE 10

/*
*	Includes
*/

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include "mlx.h"
# include "libft.h"
# include <time.h>
# include <sys/time.h>
# include <stdbool.h>

typedef enum e_directions
{
	// SOUTH = 1,
	// NORTH = 13,
	// EAST = 2,
	// WEST = 0,
	// ESC = 53,
	NORTH = 119,
	WEST = 97,
	SOUTH = 115,
	EAST = 100,
	ESC = 65307,
}	t_directions;

/*
*	structure de gestion de ben
*/

typedef struct s_sprite
{
	float	x;
	float	y;
	float	distance;
}	t_sprite;

/*
*	structure de gestion des event clavier
*/

typedef struct s_key_states
{
	bool	east;
	bool	west;
	bool	north;
	bool	south;
}	t_key_states;

/*
*	structure de gestion du raycasting
*/

typedef struct s_ray
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	max_distance;
}	t_ray;

/*
*	structure de gestion du joueur
*/

typedef struct s_player
{
	float	delta_x;
	float	delta_y;
	float	player_angle;
	float	x;
	float	y;
}	t_player;

/*
*	structure de gestion de la mlx
*/

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	int		color;
}	t_mlx;

/*
*	structure de gestion des textures
*/

typedef struct s_xpm
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_xpm;

/*
*	structure de gestion de l'image génerale imprimée
*/

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/*
*	Structure de gestion des infos contenue dans le fichier
*/

typedef struct s_map
{
	int		def_x;
	int		def_y;
	char	def_angle;
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int		floor_color;
	int		ceiling_color;
	int		map_lenght;
	int		map_len;
	int		map_max;
	char	*map_line;
	char	**map;
}	t_map;

/*
*	Structure de verification de la map
*/

typedef struct s_verif
{
	char	**map;
	char	*line;
	char	**tmp;
	int		instruct;
	int		line_pos;
	int		map_pos;
	int		indic;
	int		i;
	int		j;
}	t_verif;

/*
*	structure de gestion des autres structures
*/

typedef struct s_s
{
	t_data			*img;
	t_map			*map;
	t_mlx			*p;
	t_player		*player;
	t_key_states	key_states;
	t_xpm			*xpm;
	long long		start_time;
	float			delta_time;
	float			rotation_speed;
}	t_s;

/*
*	structure de gestion du path_finding
*/

typedef struct s_map_verif
{
	int		error;
	char	*map_path;
	int		map_x;
	int		map_y;
	int		x;
	int		y;
	int		out_x;
	int		out_y;
	int		dist;
	int		map_mapleng;
	int		lower_cost;
	int		**map_dist;
	char	**map_compl;
}	t_map_verif;

/*
*	liste chainée du path_finding
*/

typedef struct s_map_corr
{
	int					x;
	int					y;
	struct s_map_corr	*next;
}	t_map_corr;

/*
*	structure de return du path_finding
*/

typedef struct s_path_return
{
	int	moves;
	int	*x;
	int	*y;
}	t_path_return;

/*
*	structure de gestion des vecteurs du raycasting
*/

typedef struct s_vec2{
	float	x;
	float	y;
}	t_vec2;

/*
*	structure de gestion de la camera dans le raycating
*/

typedef struct s_camera{
	t_vec2	pos;
	t_vec2	dir;
}	t_camera;

/*
*	structure de gestion génerale du raycating
*/

typedef struct s_ray_wall{
	float	distance;
	t_vec2	wall_hit;
	char	wall_type;
	char	wall_face;
}	t_ray_wall;

typedef struct s_minimap
{
	t_map		*map;
	t_data		*img;
	t_mlx		*p;
	t_player	*player;
	float		x_tile_size;
	float		y_tile_size;
}	t_minimap;

typedef struct s_minimap_data
{
	int	x;
	int	y;
	int	size_x;
	int	size_y;
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	thick;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	int	coordinate_x;
	int	coordinate_y;
}	t_minimap_data;

/*
*	structure de gestion de la fonction render
*/

typedef struct s_render {
	float		inv_num_rays;
	float		half_screen_height;
	float		fov_offset;
	float		fov_times_inv_num_rays;
	float		ray_angle;
	t_ray_wall	ray;
	int			map_x;
	int			map_y;
	float		eye_x;
	float		eye_y;
	float		delta_dist_x;
	float		delta_dist_y;
	float		side_dist_x;
	float		side_dist_y;
	int			step_x;
	int			step_y;
	int			hit;
	float		perp_wall_dist;
	int			wall_height;
	int			half_wall_height;
	int			draw_start;
	int			draw_end;
	int			line_height;
	float		wall_x;
	int			tex_num;
	int			tex_x;
	float		step;
	float		tex_pos;
	int			tex_y;
}	t_render;

/*
*	Parsing_map.c
*/

int				ft_put_file_table(int fd, t_map *map_struct);

/*
*	Verif_shape.c
*/

int				ft_verif_map_shape(t_map *map);

/*
*	Verif_map.c
*/

void			ft_verif_char_map(t_map *map);
void			ft_print_map(t_map *map);

/*
*	Error.c
*/

void			ft_error(char *str);

/*
*	Utils.c
*/

void			free_tab(char **tmp);
int				is_wall(char **map, float y, float x);
char			*concatenate_string_array(char **map, int len);
long long		get_current_microseconds(void);

/*
*	Check_file.c
*/

t_map			check_map(int fd, char **argv);

/*
*	Display.c
*/

void			display_window(t_map *map);

/*
*	Map_modifier.c
*/

void			space_to_one(t_map *map);

/*
*	Fonctions destinées au bon fonctionement du path_finding
*/

char			**copy_strings(char **src, int num_strings);
t_path_return	*list_to_arrays(t_map_corr *head);
t_path_return	*get_path_finding_input(char **map_path, int rows, int cols);

void			ft_path_red2(t_map_verif *map, t_map_corr *chain,
					t_map_corr *co);
void			ft_path_red(t_map_verif *map, t_map_corr *chain,
					t_map_corr *co);
int				ft_path_finding_map_search_neighbour(t_map_verif *map);
t_map_corr		*ft_path_finding_map_suppup(t_map_verif *map,
					t_map_corr *chain);
void			ft_path_finding_map_locate(t_map_verif *map, char c);
void			ft_path_finding_map_put_tab(t_map_verif *map);
void			ft_path_finding_map_manathan(t_map_verif *map);
t_map_corr		*lstadd_back(t_map_corr *chain, t_map_corr *co);
t_map_corr		*get_last(t_map_corr *chain);
t_path_return	*ft_path_finding(t_map_verif *map, char **map_path);
size_t			ft_strlen_back(const char *s);
void			printList(t_map_corr *head);

/*
*	display.c
*/

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*
*	raycast.c
*/

void			cast_rays(t_s *s);
t_xpm			textures_init(t_s *s, char *path);

void			update_player_movement(t_player *p, t_key_states *ks,
					t_map *m, double delta_time);
void			load_textures(t_s *s);
int				key_hook(int keycode, t_key_states *ks);
int				relase_key_hook(int keycode, t_key_states *ks);

void			display_ceiling_floor(t_data img, t_map *map);
unsigned int	get_wall_face_color(t_s *s, char wall_face, int x, int y);
float			get_corrected_distance(float distance, float angle);

/*
*	render.c
*/

void			render(t_camera *camera, char **map, t_s *s);

/*
*	render_utils.c
*/

void			render_init(t_render *r, t_camera *camera, int i);
void			render_hit(char **map, t_render *r);

/*
*	draw_minimap.c
*/
void			draw_map_2d(t_map *map, t_data *img,
					t_mlx *p, t_player *player);
void			draw_square_minimap(t_data *img, t_mlx *p,
					t_minimap_data *md);

/*
*	draw_minimap_pathfinding.c
*/
void			draw_pathfinding(t_data *img, t_mlx *p,
					t_map *map, t_minimap *mm);

/*
*	draw_minimap_circle.c
*/
void			draw_circle(t_minimap *mm, int x0, int y0, int radius);
void			draw_map_circle(t_data *img);

/*
*	draw_minimap_utils.c
*/
int				point_in_circle(double x, double y, double r);
void			set_color(t_minimap *mm, int x, int y);
void			update_position_pathfinding(t_map *map,
					t_mlx *p, t_minimap *mm);
void			draw_line_minimap(t_data *img, t_mlx *p, t_minimap_data md);

/*
*	main.c
*/
int				ft_exit(void *data);

#endif