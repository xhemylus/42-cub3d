/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:58:06 by abollen           #+#    #+#             */
/*   Updated: 2022/12/02 11:48:46 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// SYS
# define FOV 80.0
# define PIXEL_W 1920
# define PIXEL_H 1080
# define HEX_BASE	"0123456789abcdef"

// MATH
# define DEG2RAD 0.017453292
# define TAU 6.28318530

# include <libft.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

// KEYS
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct s_int2d
{
	int	x;
	int	y;
}				t_int2d;

typedef struct s_float2d
{
	float	x;
	float	y;
}				t_float2d;

typedef struct s_color
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		floor;
	int		ceiling;
	int		count;
}				t_color;

typedef struct s_player
{
	t_float2d	pos;
	float		speed;
	double		r_speed;
	double		angle;
}				t_player;

typedef struct s_input
{
	int	x;
	int	y;
	int	r;
	int	tab;
}				t_input;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		width;
	int		height;
	int		endian;
}				t_data;

typedef struct s_ray
{
	float		angle;
	t_float2d	pos;
	float		xoffset;
	float		yoffset;
	t_int2d		uv;
	float		distance;
	float		atan;
	int			dof;
	int			dir;
	t_data		*texture;
}				t_ray;

typedef struct s_renderer
{
	double	rayoffset[PIXEL_W];
	double	dangle[PIXEL_W];
	double	fov;
	t_data	canvas;
	t_data	background;
	t_data	north;
	t_data	south;
	t_data	west;
	t_data	east;
}			t_renderer;

typedef struct s_map
{
	t_list	*list;
	char	*buffer;
	int		height;
	int		width;
}				t_map;

typedef struct s_cube {
	void		*mlx;
	void		*win;
	t_input		input;
	t_player	player;
	t_color		color;
	t_map		map;
	t_renderer	renderer;
}				t_cube;

// MAIN.C
int		update(void *info);

// CHECKER.C
int		player_checker(t_cube *cube, t_map *map);
int		map_checker(t_cube *cube, t_map *map);

// COLLISION.C
void	collision_horizontal(t_cube *cube, t_player *player, t_float2d vel);
void	collision_vertical(t_cube *cube, t_player *player, t_float2d vel);

// DRAW.C
void	puttexpix(t_data *data, t_data *text, t_int2d pos, t_int2d uv);
void	putpixel(t_data *data, int x, int y, int color);
void	drawzone(t_data *img, int start, int end, int color);

// ENGINE.C
void	drawray(t_data *canvas, int start, int height, t_ray *ray);
void	ray_calc(t_ray *ray, t_cube *cube, float rayangle);
void	getu(t_ray *ray, t_renderer *renderer);
void	raycast(t_cube *cube, t_renderer *renderer, t_player *player);

// INPUT.C
int		cube_close(void *info);
void	cube_input(t_cube *cube);
int		press_hook(int keycode, t_cube *cube);
int		release_hook(int keycode, t_cube *cube);
void	cube_init(t_cube *cube);

// MAP.C
int		rgbtohex(char *str, t_color *color);
int		map_reader(t_map *map, int fd);
int		map_alloc(t_map *map);
void	player_setup(t_cube *cube, t_map *map, int index);
int		parse_abort(t_cube *cube, int ret);

// MATH.C
float	fwrap(float num, float min, float max);
float	distance(float ax, float ay, float bx, float by);

// PARSE.C
int		texture_handler(t_color *color, char *str);
int		color_handler(t_color *color, char *str, t_cube *cube);
int		color_parser(t_cube *cube, int fd);
char	*texture_parse(char *path, t_color *color);
int		map_parser(t_cube *cube, char *path);

// RAY.C
void	ray_init(t_ray *ray);
void	mapi(t_map *map, t_player *player, t_ray *ray);
void	ray_hit_horizontal(t_map *map, t_player *player, t_ray *ray);
void	ray_hit_vertical(t_map *map, t_player *player, t_ray *ray);

// RENDERER.C
int		texture_abort(t_cube *cube);
int		texture_init(t_data *data, t_cube *cube, char **path);
void	image_init(t_data *data, t_cube *cube, int width, int height);
void	offset_init(t_renderer *renderer);
int		renderer_init(t_cube *cube, t_renderer *renderer);

// TOOLS.C
char	*get_next_line(int fd);
char	*ft_strrsearch(const char *string, char searchedChar);
int		ft_isbase(char c, char *base);
int		ft_atoi_base(char *str, char *base);

// WALLS.C
void	setneighbors(t_int2d *np, int x, int y);
int		checktiles(t_map *map, t_int2d head);
int		checkwalls(t_map *map);

#endif