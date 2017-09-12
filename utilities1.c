/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 12:44:53 by ichebota          #+#    #+#             */
/*   Updated: 2017/08/23 19:08:40 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_print_check(char *line)
{
	ft_putstr(line);
	write(1, "\n", 1);
	if (ft_strcmp(line, "") == 0)
		ft_error(7);
}

int		ft_check_line(char *line)
{
	char	**split;

	if (line[0] == '#')
		return (0);
	split = ft_strsplit(line, ' ');
	if (ft_strchr(split[0], '-') != 0)
	{
		ft_free_str(split);
		return (1);
	}
	ft_free_str(split);
	return (0);
}

void	ft_free_str(char **str)
{
	int i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			ft_strdel(&str[i]);
			i++;
		}
		free(str);
		str = NULL;
	}
}

void	ft_free_list(t_rooms *rooms)
{
	t_rooms *tmp;

	while (rooms != NULL)
	{
		tmp = rooms;
		rooms = rooms->next;
		free(tmp->name);
		free(tmp);
	}
}

void	ft_free(t_data *data)
{
	int		i;

	i = 0;
	while (data->pathes[i])
	{
		free(data->pathes[i]);
		i++;
	}
	free(data->pathes);
	i = 0;
	while (i < data->nrooms)
	{
		free(data->names[i]);
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
	free(data->names);
	free(data->mark);
	free(data->len);
	free(data);
}
