#ifndef CUB3D_H
#define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include "mlx.h"
#include "../libft/libft.h"

typedef struct s_img
{
	void *mlx_img;
	char *addr;
	int bpp;
	int line_len;
	int endian;
	int width;
	int height;
} t_img;

typedef struct s_map
{
	char	*map_path;
	char	**grid;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int 	floor_color;
	int 	ceiling_color;
	int		x_len;
	int		y_len;
} t_map;

typedef struct s_player
{
    double x;        // player position in map (float, not int)
    double y;
    double dir_x;    // direction vector
    double dir_y;
    double plane_x;  // 2D camera plane (FOV control)
    double plane_y;
} t_player;



typedef struct s_data
{
	void *mlx;
	void *win;
	t_img img;
	t_map *map;
	float min_x;
	float min_y;
	float max_x;
	float max_y;
	float zoom;
	float offset_x;
	float offset_y;
} 				t_data;

// ### QUIT_CLEAN ###
void	ft_clear_all(t_data *data);
int		click_cross(t_data *data);
int		esc_key(int keysym, t_data *data);
void	ft_clear_map(t_map *map);
void	tab_free_null(char **tab);
void	char_free_null(char *s);

// ### INIT ###
t_img initialize_image(void *mlx, int width, int height);



// ### CHECKING ###
bool	extension_is_correct(const char *map_path, size_t len_map);
int		get_safe_fd(const char *map_path);
bool	check_content(const char *map_path);
bool	is_valid(const char *map_path);
int		get_x_len(const char *map_path);
int		get_y_len(const char *map_path);

bool	process_line_check(const char *line);
bool	is_line_full_wall(char *line);
bool	map_is_closed_by_walls(const char *pathname);

// ### PARSING ###
void	fill_map_struct(const char *map_path, t_map *parsed_struct);
void	display_map(t_map *map);

// ### HANDLE ERROR ###
void	ft_error_msg(char *msg, int exit_code);



#endif