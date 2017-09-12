/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 16:10:49 by ichebota          #+#    #+#             */
/*   Updated: 2017/08/22 17:39:22 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_readnants(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] != '#')
		{
			while (line[i])
			{
				if (ft_isdigit(line[i]) != 1)
					ft_error(1);
				i++;
			}
			data->nants = ft_atoi(line);
			ft_putstr(line);
			write(1, "\n", 1);
			free(line);
			break ;
		}
		ft_putstr(line);
		write(1, "\n", 1);
		free(line);
	}
}

void	ft_read(t_data *data)
{
	char	*line;

	ft_readnants(data);
	data->start = -1;
	data->end = -1;
	line = ft_read_rooms(data);
	if (data->nrooms == 0)
		ft_error(8);
	if (data->start < 0 || data->end < 0)
		ft_error(6);
	ft_read_edges(data, line);
	free(line);
}
