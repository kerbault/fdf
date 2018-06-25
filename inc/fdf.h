/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 13:15:38 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 23:00:59 by kerbault    ###    #+. /#+    ###.fr     */
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
# define CENTER		87
# define ZOOMIN		69
# define ZOOMOUT	78
# define ESC		53

/*
** const definition
*/

# define W_X		1280
# define W_Y		800
# define WHITE		0xFFFFFF
# define BLEU		0x6D9EE2
# define GREEN		0x96E26D
# define RED		0xE26D6D

/*
** Struct definition
*/

typedef struct	s_point
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		col;
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

typedef struct	s_size
{
	int		length;
	int		width;
}				t_size;

typedef struct	s_opt
{
	double	x_rat;
	double	y_rat;
	double	z_rat;
	double	x_decal;
	double	y_decal;
	double	tilt;
	double	tmp_tilt;
	double	mult;
	double	z_opt;
	double	x_med;
	double	y_med;
	double	t_med;
	double	x_mult;
	double	y_mult;
	double	z_mult;
	int		i_zoom;
}				t_opt;

typedef struct	s_glob
{
	void	*mlx;
	void	*win;
	int		fd;
	int		**map;
	int		length;
	int		width;
	int		col;
	t_opt	opt;
	t_map	*s_map;
}				t_glob;

/*
** Function definition
*/

t_point			pers_cav_ver(int x, int y, int **map, t_opt opt);
t_point			pers_cav_hor(int x, int y, int **map, t_opt opt);
t_point			set_point1(int x, int y, int **map);
t_point			set_point2(int x, int y, int **map);
void			ft_close(char *msg, int status);
int				kf(int keycode, t_glob *glob);
void			size_map(t_glob *glob);
int				**map_malloc(t_map size);
int				**read_map(int fd);
void			set_map(t_glob glob);
void			ft_zero(t_glob *glob);
void			ft_decrease(t_glob *glob);
void			ft_increase(t_glob *glob);
void			ft_zoomin(t_glob *glob);
void			ft_zoomout(t_glob *glob);
void			ft_color(t_glob *glob);
void			ft_ratio(t_glob *glob);
void			ft_center(t_glob *glob);
void			ft_up(t_glob *glob);
void			ft_down(t_glob *glob);
void			ft_left(t_glob *glob);
void			ft_right(t_glob *glob);
void			opt_def_1(t_glob *glob);
void			opt_def_2(t_glob *glob);
void			fdf_comment(t_glob *glob);
int				red_cross();

#endif
