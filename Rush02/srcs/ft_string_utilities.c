/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlsanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 06:38:44 by carlsanc          #+#    #+#             */
/*   Updated: 2024/02/25 06:55:14 by carlsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_str.h"

int		ft_str_length(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}
char	*ft_str_copy(char *dest, char *src)
{
	int index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_str_n_copy(char *dest, char *src, int n)
{
	int		index;

	index = 0;
	while (index < n && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}

char	*ft_str_duplicate(char *src)
{
	int		length;
	int		index;
	char	*dest;

	length = ft_str_length(src);
	index = 0;
	if ((dest = (char *)malloc((length + 1) * sizeof(char))) == NULL)
		return (0);
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_str_n_duplicate(char *str, int n)
{
	int		index;
	int		length;
	char	*dup;

	length = 0;
	while (str[length])
		length++;
	if (length > n)
		length = n;
	if (!(dup = malloc((length + 1) * sizeof(char))))
		return (NULL);
	index = 0;
	while (index < length)
	{
		dup[index] = str[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}

