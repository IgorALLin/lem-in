/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 16:11:24 by ichebota          #+#    #+#             */
/*   Updated: 2017/08/22 17:57:12 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	ft_read(data);
	ft_bfs(data);
	ft_pathes(data);
	ft_move(data);
	ft_free(data);
	return (0);
}
