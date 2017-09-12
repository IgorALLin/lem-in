/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 19:34:50 by ichebota          #+#    #+#             */
/*   Updated: 2017/08/08 12:24:30 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_new_edge(t_data *data, char *line)
{
	char	**str;
	int		room1;
	int		room2;
	int		i;

	str = ft_strsplit(line, '-');
	room1 = -1;
	room2 = -1;
	i = 0;
	if (line[0] != '#')
	{
		while (data->names[i])
		{
			if (ft_strcmp(str[0], data->names[i]) == 0)
				room1 = i;
			else if (ft_strcmp(str[1], data->names[i]) == 0)
				room2 = i;
			i++;
		}
		if (room1 == -1 || room2 == -1 || str[2] != 0)
			ft_error(3);
		data->matrix[room1][room2] = -1;
		data->matrix[room2][room1] = -1;
	}
	ft_free_str(str);
}

void	ft_read_edges(t_data *data, char *str)
{
	char	*line;

	ft_new_edge(data, str);
	while (get_next_line(0, &line) > 0)
	{
		ft_print_check(line);
		ft_new_edge(data, line);
		free(line);
	}
}
