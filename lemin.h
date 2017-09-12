/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 12:33:09 by ichebota          #+#    #+#             */
/*   Updated: 2017/08/22 17:35:57 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdio.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <sys/stat.h>

# define BUFF_SIZE 1

typedef struct		s_bfs
{
	int				*len;
	int				*visited;
	int				*queue;
}					t_bfs;

typedef struct		s_data
{
	int				nants;
	char			**names;
	int				start;
	int				end;
	int				nrooms;
	int				**matrix;
	int				**pathes;
	int				*mr;
	int				all;
	int				finish;
	int				space;
	int				*mark;
	int				*len;
}					t_data;

typedef struct		s_rooms
{
	char			*name;
	int				start;
	int				end;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_path
{
	int				room;
	struct s_path	*next;
}					t_path;

typedef struct		s_move
{
	int				*step;
	int				*antinr;
}					t_moving;

int					ft_check_line(char *line);
void				ft_print_check(char *line);
void				ft_bfs(t_data *data);
void				ft_error(int err);
void				ft_free_str(char **fr);
void				ft_read(t_data *data);
int					get_next_line(const int fd, char **line);
char				*ft_read_rooms(t_data *data);
void				ft_warning(int warning);
int					ft_check_int(char *line);
void				ft_read_edges(t_data *data, char *str);
void				ft_matrixzero(t_data *data, int i);
void				ft_test(t_data *data, int **mas);
void				ft_dijkstra(t_data *data);
void				ft_pathes(t_data *data);
void				ft_move(t_data *data);
void				ft_print(t_data *data, int ant, int room);
void				ft_free_list(t_rooms *rooms);
void				ft_free(t_data *data);
void				ft_free_str(char **str);

#endif
