/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:37:20 by ichebota          #+#    #+#             */
/*   Updated: 2017/08/22 17:40:04 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_add_ants(t_data *data, t_moving *mv)
{
	int		j;

	j = 0;
	while (data->pathes[j])
	{
		if (data->all > 0 && data->pathes[j][0] != -1)
		{
			if (data->pathes[j][1] == data->end)
			{
				data->all--;
				data->finish++;
				ft_print(data, data->nants - data->all, data->end);
			}
			else if (mv->antinr[data->pathes[j][1]] == 0)
			{
				data->all--;
				mv->antinr[data->pathes[j][1]] = data->nants - data->all;
				ft_print(data, mv->antinr[data->pathes[j][1]],
				data->pathes[j][1]);
			}
		}
		j++;
	}
}

int		ft_next_room(int prev, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->pathes[j])
	{
		i = 1;
		while (data->pathes[j][i] != data->end)
		{
			if (data->pathes[j][i] == prev)
				return (data->pathes[j][i + 1]);
			i++;
		}
		j++;
	}
	return (0);
}

int		ft_find_ant(t_data *data, t_moving *mv)
{
	int		ret;
	int		i;

	ret = -1;
	i = 0;
	while (i < data->nrooms)
	{
		if (mv->antinr[i] != 0 && mv->step[i] != 1 &&
			(ret == -1 || mv->antinr[i] < mv->antinr[ret]))
			ret = i;
		i++;
	}
	return (ret);
}

void	ft_mvants(t_data *data, t_moving *mv)
{
	int		prev;
	int		next;

	while ((prev = ft_find_ant(data, mv)) != -1)
	{
		next = ft_next_room(prev, data);
		ft_print(data, mv->antinr[prev], next);
		if (next == data->end)
			data->finish++;
		else
		{
			mv->antinr[next] = mv->antinr[prev];
			mv->step[next] = 1;
		}
		mv->antinr[prev] = 0;
	}
}

void	ft_move(t_data *data)
{
	t_moving	*mv;
	int			i;

	mv = (t_moving *)malloc(sizeof(t_moving));
	mv->step = ft_creatint(data->nrooms, 0);
	mv->antinr = ft_creatint(data->nrooms, 0);
	data->finish = 0;
	data->all = data->nants;
	while (data->finish != data->nants)
	{
		ft_putchar('\n');
		data->space = 0;
		ft_mvants(data, mv);
		ft_add_ants(data, mv);
		i = 0;
		while (i < data->nrooms)
		{
			mv->step[i] = 0;
			i++;
		}
	}
	ft_putchar('\n');
	free(mv->antinr);
	free(mv->step);
	free(mv);
}
