/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 13:15:38 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 19:36:30 by kerbault    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** Includes part
*/

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/inc/libft.h"
# include "../minilibx_macos/mlx.h"

/*
** Keymap definition
*/

# define ZERO		82
# define DECREASE	83
# define INCREASE	85
# define UP			91
# define DOWN		84
# define LEFT		86
# define RIGHT		88
# define CLOCK		89
# define CCLOCK		92
# define CENTER		87
# define ZOOMIN		69
# define ZOOMOUT	78
# define ESC		53

/*
** const definition
*/

# define W_WIDTH 2560
# define W_HEIGHT 1440
# define WHITE 0xFFFFFF
# define BLACK 0x00000

/*
** Struct definition
*/

typedef struct	s_main
{
	void	*mlx;
	void	*win;
	int		fd;
	int		**map;
}				t_main;

typedef struct	s_point
{
	int x1;
	int y1;
	int x2;
	int y2;
	int dx;
	int dy;
	int sx;
	int sy;
	int	col;
}				t_point;

typedef struct	s_map
{
	int		length;
	int		width;
	int		*fig;
	int		bpp;
	int		sl;
	int		endian;
	void	*ptr;

}				t_map;

/*
** Function definition
*/

t_point		pers_cav1(int x, int y, int **map, size_t i);
t_point		pers_cav2(int x, int y, int **map, size_t i);
t_point		pers_point1(int x, int y, int **map);
t_point		pers_point2(int x, int y, int **map);
void		ft_close(char *msg, int status);
int			kf(int keycode, void *param);
t_map		size_map(int fd);
int			**map_malloc(t_map size);
int			**read_map(int fd);
void		drawseg(t_point pt, t_map s_map);

#endif
