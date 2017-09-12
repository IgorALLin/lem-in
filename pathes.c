/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 21:02:57 by ichebota          #+#    #+#             */
/*   Updated: 2017/08/22 17:42:19 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_checkpathes(int **pathes, int size)
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (i < size)
	{
		if (pathes[i][0] != -1)
			p++;
		i++;
	}
	if (p == 0)
		ft_error(5);
}

int		ft_next_step(t_data *data, int room)
{
	int		i;
	int		ret;

	i = 0;
	ret = -1;
	while (i < data->nrooms)
	{
		if (data->matrix[room][i] != 0 && data->mr[i] != 1 &&
			(ret == -1 || data->matrix[room][i] < data->matrix[room][ret]))
			ret = i;
		i++;
	}
	if (ret != -1 && ret != data->end)
		data->mr[ret] = 1;
	if (room == data->start && ret != -1)
		data->matrix[room][ret] = 0;
	return (ret);
}

void	ft_add_path(t_data *data, int j, int room, int i)
{
	int		next;

	if ((next = ft_next_step(data, room)) == -1)
		data->pathes[j][0] = -1;
	else
	{
		if (i == 1)
			data->pathes[j][0] = 1;
		data->pathes[j][i] = next;
		if (next != data->end)
		{
			i++;
			ft_add_path(data, j, next, i);
		}
	}
	if (data->pathes[j][0] != -1)
	{
		next = 1;
		while (data->pathes[j][next] != data->end)
			next++;
		data->pathes[j][0] = next;
	}
}

void	ft_pathes(t_data *data)
{
	int		npathes;
	int		i;

	i = 0;
	npathes = 0;
	while (i < data->nrooms)
	{
		if (data->matrix[data->start][i] != 0)
			npathes++;
		i++;
	}
	i = 0;
	data->mr = ft_creatint(data->nrooms, 0);
	data->mr[data->start] = 1;
	data->pathes = (int**)malloc(sizeof(int*) * npathes + 1);
	data->pathes[npathes] = 0;
	while (i < npathes)
	{
		data->pathes[i] = ft_creatint(data->nrooms, 0);
		ft_add_path(data, i, data->start, 1);
		i++;
	}
	ft_checkpathes(data->pathes, npathes);
	free(data->mr);
}
