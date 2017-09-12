/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 17:03:28 by ichebota          #+#    #+#             */
/*   Updated: 2017/08/08 12:49:44 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_puttodata(t_data *data, t_rooms *rooms)
{
	int		i;

	i = 0;
	data->names = (char **)malloc(sizeof(char *) * data->nrooms + 1);
	data->names[data->nrooms] = 0;
	data->matrix = (int **)malloc(sizeof(int *) * data->nrooms + 1);
	data->matrix[data->nrooms] = 0;
	while (rooms)
	{
		data->names[i] = ft_strdup(rooms->name);
		if (rooms->start == 1)
			data->start = i;
		if (rooms->end == 1)
			data->end = i;
		i++;
		rooms = rooms->next;
	}
	i = 0;
	while (i < data->nrooms)
	{
		ft_matrixzero(data, i);
		i++;
	}
}

int		ft_dies(char *line, int startend)
{
	if (ft_strcmp(line, "##start") == 0)
		return (1);
	if (ft_strcmp(line, "##end") == 0)
		return (2);
	if (startend > 0)
		return (startend);
	return (0);
}

void	ft_add_room(char *room, int startend, t_rooms **rooms)
{
	t_rooms *head;
	t_rooms *new;

	new = (t_rooms *)malloc(sizeof(t_rooms));
	head = *rooms;
	new->name = ft_strdup(room);
	new->next = NULL;
	if (startend == 1)
		new->start = 1;
	if (startend == 2)
		new->end = 1;
	if (head == NULL)
		*rooms = new;
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = new;
	}
}

int		ft_new_room(char *line, t_rooms **rooms, int startend, t_data *data)
{
	char	**str;
	int		dies;

	if (line[0] == '#')
	{
		dies = ft_dies(line, startend);
		return (dies);
	}
	str = ft_strsplit(line, ' ');
	if (str[0][0] == 'L')
		ft_error(2);
	if (str[3] != 0 || ft_check_int(str[1]) != 0 ||
		ft_check_int(str[2]) != 0 || str[1] == NULL || str[2] == NULL)
		ft_warning(1);
	ft_add_room(str[0], startend, rooms);
	data->nrooms++;
	ft_free_str(str);
	return (0);
}

char	*ft_read_rooms(t_data *data)
{
	t_rooms	*rooms;
	char	*line;
	char	*ret;
	int		startend;

	data->nrooms = 0;
	rooms = NULL;
	startend = 0;
	while (get_next_line(0, &line) > 0)
	{
		ft_print_check(line);
		if (ft_check_line(line) == 1)
		{
			ft_puttodata(data, rooms);
			ft_free_list(rooms);
			ret = ft_strdup(line);
			free(line);
			return (ret);
		}
		startend = ft_new_room(line, &rooms, startend, data);
		free(line);
	}
	return (0);
}
