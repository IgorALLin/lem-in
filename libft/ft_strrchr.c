/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:44:27 by ichebota          #+#    #+#             */
/*   Updated: 2016/12/14 16:44:37 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	b;
	char	*tmp;
	int		flag;

	b = '\0' + c;
	if (b == '\0')
	{
		while (*str)
			str++;
		return ((char*)str);
	}
	tmp = (char*)str;
	flag = 0;
	while (*str)
	{
		if (*str == b)
		{
			tmp = (char*)str;
			flag = 1;
		}
		str++;
	}
	if (flag == 0)
		return (0);
	return (tmp);
}
