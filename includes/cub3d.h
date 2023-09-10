#ifndef CUB3D_H
# define CUB3D_H

/*
*	Includes
*/

# include "constants.h"
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
# include "minimap.h"



/*
*	structure de gestion de ben
*/

typedef struct s_sprite
{
    float x;
    float y;
    float distance;
} t_sprite;



/*
*	structure de gestion du raycasting
*/

// typedef struct s_ray
// {
//     float x, y; // Position de départ du rayon
//     float dx, dy; // Direction du rayon (vecteur unitaire)
//     float maxDistance; // Distance maximale que peut parcourir le rayon
// } t_ray;

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

typedef struct	s_xpm
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

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;



/*
*	structure de gestion des autres structures
*/

typedef struct	s_s
{
	t_data	*img;
	t_map	*map;
	t_mlx	*p;
	t_player *player;
	t_key_states key_states;
	t_xpm	*xpm;
	long long start_time;
	float delta_time;
	float rotation_speed;
	t_sprite ben;
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
*	structure de gestion des vecteurs du raycasting
*/

typedef struct {
    float x;
    float y;
} vec2;


/*
*	structure de gestion de la camera dans le raycating
*/

typedef struct {
    vec2 pos;
    vec2 dir;
} camera_t;

/*
*	structure de gestion génerale du raycating
*/

typedef struct {
    float distance;
    vec2 wallHit;
    char wallType;
    char wallFace;
} ray_t;


/*
*	Parsing_map.c
*/

int	ft_put_file_table(int fd, t_map *map_struct);

/*
*	Parsing_map_utils.c
*/
int	ft_find_my_str(char *s, int i);

/*
*	Verif_shape.c
*/

int	ft_verif_map_shape(t_map *map);

/*
*	Verif_map.c
*/

void ft_verif_char_map(t_map *map);
void ft_print_map(t_map *map);

/*
*	Error.c
*/

void	ft_error(char *str);

/*
*	Utils.c
*/

void		free_tab(char **tmp);
void		*ft_realloc(void *p, size_t size);
char		*concatenate_string_array(char **map, int len);
long long	get_current_microseconds(void);
int			is_wall(char **map, float y, float x);

/*
*	Check_file.c
*/

char	**ft_allocate_table(int fd, t_map *map_struct, int line_pos, char **argv);
t_map	check_map(int fd, char **argv);

/*
*	Display.c
*/

void	display_window(t_map *map);

/*
*	Map_modifier.c
*/

void	space_to_one(t_map *map);

/*
*	Fonctions destinées au bon fonctionement du path_finding
*/

char **copyStrings(char** src, int numStrings);
t_path_return *list_to_arrays(t_map_corr* head);
t_path_return *get_path_finding_input(char **map_path, int rows, int cols);

void		ft_path_red2(t_map_verif *map, t_map_corr *chain, t_map_corr *co);
void		ft_path_red(t_map_verif *map, t_map_corr *chain, t_map_corr *co);
int			ft_path_finding_map_search_neighbour(t_map_verif *map);
t_map_corr	*ft_path_finding_map_suppup(t_map_verif *map, t_map_corr *chain);
int			ft_path_finding_alredy(int y, int x, t_map_corr *chain);
void		ft_path_finding_map_locate(t_map_verif *map, char c);
void		ft_path_finding_map_put_tab(t_map_verif *map);
void		ft_path_finding_map_manathan(t_map_verif *map);
t_map_corr	*lstadd_back(t_map_corr *chain, t_map_corr *co);
t_map_corr	*get_last(t_map_corr *chain);
t_path_return *ft_path_finding(t_map_verif *map, char **map_path);
size_t		ft_strlen_back(const char *s);
void		printList(t_map_corr* head);

/*
*	display.c
*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*
*	raycast.c
*/

void	cast_rays(t_s *s);
t_xpm	textures_init(t_s *s, char *path);

/*
*	sprite.c
*/

void draw_ben(t_s *s, int sprite_x, int sprite_y);
void	find_ben(t_s *s);

/*
*	sprites.c
*/

t_sprite sprite_init(t_s *s, char *path);

/*
*	player.c
*/
void	update_player_movement(t_s *s, double delta_time);

/*
*	textures.c
*/
void	load_textures(t_s *s);

/*
*	draw.c
*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*
*	draw_minimap.c
*/
void	draw_line_minimap(t_s *s, int x0, int y0, int x1, int y1);

#endif