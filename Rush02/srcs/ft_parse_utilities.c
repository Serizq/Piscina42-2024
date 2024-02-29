/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utilities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlsanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 06:56:10 by carlsanc          #+#    #+#             */
/*   Updated: 2024/02/25 06:58:34 by carlsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "ft_boolean.h"
#include "ft_is.h"
#include "ft_str.h"
#include "ft_is.h"
#include "ft_io.h"
#include "ft_short_types.h"
int		ft_split_whitespace_count_word(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (ft_is_whitespace(*str))
			str++;
		if (*str == '\0')
			break ;
		while (!ft_is_whitespace(*str) && *str != '\0')
			str++;
		count++;
	}
	return (count);
}
void	ft_str_write_to(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

void	ft_str_write(char *str)
{
	ft_str_write_to(OUT, str);
}
char	**ft_split_whitespace(char *str)
{
	int		index;
	int		word_count;
	char	*word_start;
	char	**array;

	word_count = ft_split_whitespace_count_word(str);
	if (!(array = malloc((word_count + 1) * sizeof(char *))))
		return (NULL);
	index = 0;
	while (*str)
	{
		while (ft_is_whitespace(*str))
			str++;
		if (*str == '\0')
			break ;
		word_start = str;
		while (!ft_is_whitespace(*str) && *str != '\0')
			str++;
		array[index] = ft_str_n_duplicate(word_start, str - word_start);
		index++;
	}
	array[index] = 0;
	return (array);
}
t_bool	x_is_operator(char c)
{
	return (c == '-' || c == '+');
}

int		ft_atoi(char *str)
{
	int	result;
	int	minus;

	minus = 1;
	while (ft_is_whitespace(*str))
		str++;
	if (x_is_operator(*str))
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	result = 0;
	while (ft_is_number(*str))
	{
		result *= 10;
		result += (*str) - '0';
		str++;
	}
	return (result * minus);
}
ULNG	ft_atoi_strict(char *str)
{
	ULNG	result;

	while (ft_is_whitespace(*str))
		str++;
	result = 0;
	while (ft_is_number(*str))
	{
		result *= 10;
		result += (*str) - '0';
		str++;
	}
	if (*str == '\0')
		return (result);
	return (-1);
}
t_bool	ft_is_number(char c)
{
	return (c >= '0' && c <= '9');
}

t_bool	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r'
			|| c == '\f');
}

