/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 17:36:19 by ichebota          #+#    #+#             */
/*   Updated: 2017/08/23 19:06:47 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_check_queue(int *queue, int room, t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nrooms)
	{
		if (queue[i] == room)
			return (1);
		i++;
	}
	return (0);
}

int		ft_deequeue(t_bfs *bfs, int room, t_data *data)
{
	int		i;
	int		i1;

	i = 0;
	i1 = 0;
	while (i < data->nrooms && bfs->queue[i] > -1)
	{
		bfs->queue[i] = bfs->queue[i + 1];
		i++;
	}
	i = 0;
	while (bfs->queue[i] != -1)
		i++;
	while (i1 < data->nrooms)
	{
		if (data->matrix[room][i1] != 0 && bfs->visited[i1] != 1
			&& ft_check_queue(bfs->queue, i1, data) == 0)
		{
			bfs->queue[i] = i1;
			i++;
		}
		i1++;
	}
	return (bfs->queue[0]);
}

int		ft_equeu(t_data *data, t_bfs *bfs, int room)
{
	int		i;

	i = 0;
	bfs->visited[room] = 1;
	while (i < data->nrooms)
	{
		if (data->matrix[room][i])
		{
			if (bfs->len[i] == 0)
				bfs->len[i] = bfs->len[room] + 1;
			data->matrix[i][room] = bfs->len[room] + 1;
		}
		i++;
	}
	return (ft_deequeue(bfs, room, data));
}

void	ft_bfs(t_data *data)
{
	t_bfs	*bfs;
	int		room;

	bfs = (t_bfs*)malloc(sizeof(t_bfs));
	bfs->queue = ft_creatint(data->nrooms, -1);
	bfs->visited = ft_creatint(data->nrooms, 0);
	bfs->len = ft_creatint(data->nrooms, 0);
	bfs->queue[0] = data->end;
	room = data->end;
	while (room != -1)
		room = ft_equeu(data, bfs, room);
	free(bfs->queue);
	free(bfs->visited);
	free(bfs->len);
	free(bfs);
}
