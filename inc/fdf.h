/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 13:15:38 by kerbault     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/28 17:54:20 by kerbault    ###    #+. /#+    ###.fr     */
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
** Struct definition
*/

typedef struct		s_point
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		dy;
}					t_point;

#endif
