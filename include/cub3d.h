/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevigne <ldevigne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:11:13 by ldevigne          #+#    #+#             */
/*   Updated: 2025/09/03 12:15:39 by ldevigne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "../libft/libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_map
{
	char		*map_path;
	int			num_of_lines_to_skip;
	char		**grid;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			floor_color;
	int			ceiling_color;
	char		*wall_path_choice;
	int			x_len;
	int			y_len;
}				t_map;

typedef struct s_player
{
	float	x;
	float	y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
}				t_player;

typedef struct s_coord
{
	float		x;
	float		y;
}				t_coord;

typedef struct s_ray
{
	t_coord		*ray_dir;
	t_coord		ray_origin;
	int			ray_map_origin_x;
	int			ray_map_origin_y;
	t_coord		dist_next_cel;
	t_coord		step_map;
	t_coord		side_dist;
	int			type_side;
}				t_ray;

typedef struct s_keys
{
	bool		key_w;
	bool		key_s;
	bool		key_a;
	bool		key_d;
	bool		key_left;
	bool		key_right;
}				t_keys;

typedef struct s_texture
{
	void		*tex_img;
	char		*tex_addr;
	int			width;
	int			height;
	int			tex_x;
	int			tex_y;
	int			line_len;
	int			bpp;
	int			endian;
}				t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		*map;
	t_player	*player;
	t_texture	*text;
	t_keys		*keys;
	int			screen_height;
	int			screen_width;
}				t_data;

enum
{
	KEEP_OPEN,
	CLOSE,
};

// ### QUIT_CLEAN ###
void			ft_clear_all(t_data *data, int error_code);
int				click_cross(t_data *data);
int				esc_key(int keysym, t_data *data);
void			ft_clear_map(t_map *map, int error_code);
void			tab_free_null(char ***tab);
void			char_free_null(char **s);
void			close_window(t_data *data);

// ### INIT ###
t_img			initialize_image(void *mlx, int width, int height);
void			init_player(t_data *data, char **grid, t_player *player);
void			init_keys(t_data *data, t_keys *keys);
void			init_data_null(t_data *data);

// ### CHECKING ###
bool			check_map(t_map *map);
int				check_left(t_map *map, int i, int j);
int				check_right(t_map *map, int i, int j);
int				check_up(t_map *map, int i, int j);
int				check_down(t_map *map, int i, int j);
bool			extension_is_correct(const char *map_path, size_t len_map);
int				get_safe_fd(const char *map_path, int flag);
bool			is_file_valid(const char *map_path);
bool			is_player_inside_lab(t_map *map);
bool			map_get_only_valid_chars(t_map *map);
bool			map_get_valid_player(t_map *map);
bool			map_get_valid_textures(t_map *map);
bool			map_is_closed_by_walls(t_map *map);
bool			no_walls_alone(const char *map_path);
bool			process_line_check(const char *line);
bool			textures_are_in_valid_format(char *texture);

// ### PARSING ###
int				get_lines_num_to_skip(const char *map_path);
int				get_x_len(const char *map_path);
int				get_y_len(const char *map_path);
void			skip_lines(int fd, char *line, int nb_to_skip);
void			fill_single_line(t_map *map, char *line, int y);
void			fill_grid(t_map *map);
int				set_color_limit(int val);
int				get_color_from_string(char *str);
void			get_textures(t_data *data, t_map *map);
void			fill_map_struct(t_data *data, const char *map_path, t_map *map);
char			*get_str_without_eol(char *s, t_data *data);

// ### TERM DISPLAY ###
void			display_grid(char **grid);
void			display_map(t_map *map);

// ### HANDLE ERROR ###
void			ft_error_msg(char *msg, int exit_code);
bool			is_map_square(const char *pathname);
// bool	map_is_closed_by_walls(const char *pathname);
bool			only_valid_chars(const char *pathname);

// ### DRAW STRIPES UTILS ###
void			put_pixel_image(t_img img, int x, int y, int color);
int				draw_end_wall(t_data *data, float real_wall_dist);
int				draw_start_wall(t_data *data, float real_wall_dist);
int				screen_wall_height(t_data *data, float real_wall_dist);
void			choose_wall_textures(t_data *data, t_ray ray);
void			texture_handling(t_data *data, t_ray ray, float real_wall_dist);

// ### DRAW STRIPES ###
void			draw_stripe(t_data *data, float cam_step, int index);
void			draw_whole_screen(t_data *data);

// ### DDA ALGO ###
float			ray_dda_algo(t_data *data, float cam_step);

// ### DDA ALGO UTILS###
void			init_ray(t_ray *ray, t_data *data, float cam_step);
int				which_side_hit(t_data *data, t_ray *ray);

// ### RAY DIRECTION ###
float			camera_choice(int screen_width, float camrange_index);
t_coord			*ray_direction(t_player *player, float cameraX);

// ### MOVE KEYS ###
void			move_forward(t_data *data);
void			move_backward(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);

// ### VIEW TURN KEYS ###
void			rotate_right(t_data *data);
void			rotate_left(t_data *data);

// ### KEY PRESS MANAGEMENT ###
int				handle_keys(t_data *data);
int				detect_key_release(int keysym, t_data *data);
int				detect_key_press(int keysym, t_data *data);

// ### STAY IN MAP ###
bool			move_to_wall(t_data *data, float new_x, float new_y);

// ### INIT PLAYER DIR ###
char			find_player_in_grid(t_player *player, char **grid);
void			player_look_north(t_player *player);
void			player_look_south(t_player *player);
void			player_look_west(t_player *player);
void			player_look_east(t_player *player);

#endif