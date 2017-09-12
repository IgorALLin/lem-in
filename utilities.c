/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 17:35:28 by ichebota          #+#    #+#             */
/*   Updated: 2017/08/22 17:59:32 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_print(t_data *data, int ant, int room)
{
	if (data->space != 0)
		ft_putchar(' ');
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(data->names[room]);
	data->space++;
}

void	ft_matrixzero(t_data *data, int i)
{
	int		in;

	in = 0;
	data->matrix[i] = (int *)malloc(sizeof(int) * data->nrooms);
	while (in < data->nrooms)
	{
		data->matrix[i][in] = 0;
		in++;
	}
}

void	ft_warning(int warning)
{
	if (warning == 1)
		ft_putstr("warning - not valid coordinats\n");
}

void	ft_error(int err)
{
	if (err == 1)
		ft_putstr("ERROR - no ants or bad format");
	if (err == 2)
		ft_putstr("ERROR - room can't start's with the character 'L'");
	if (err == 3)
		ft_putstr("ERROR - room's name in the links has'n valid format");
	if (err == 4)
		ft_putstr("ERROR - no connections with ##start and\\or ##end room");
	if (err == 5)
		ft_putstr("ERROR - there are no existing pathes");
	if (err == 6)
		ft_putstr("ERROR - there are no ##start and\\or ##end room");
	if (err == 7)
		ft_putstr("ERROR - empty line");
	if (err == 8)
		ft_putstr("ERROR - no rooms");
	exit(0);
}

int		ft_check_int(char *line)
{
	int		i;

	i = 0;
	if (line == NULL)
		return (-1);
	while (line[i])
	{
		if (i == 0 && line[i] == '-')
			i++;
		if (ft_isdigit(line[i]) != 1)
			return (-1);
		i++;
	}
	return (0);
}
