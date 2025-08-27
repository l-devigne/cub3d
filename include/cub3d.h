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
	int **grid;
	char *north_texture;
	char *south_texture;
	char *west_texture;
	char *east_texture;
	int floor_color;
	int ceiling_color;
} t_map;

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
void ft_clear_all(t_data *data);
int click_cross(t_data *data);
int esc_key(int keysym, t_data *data);

// ### INIT ###
t_img initialize_image(void *mlx, int width, int height);

bool	is_map_square(const char *pathname);
bool	only_valid_chars(const char *pathname);
bool	is_valid(const char *map);


#endif