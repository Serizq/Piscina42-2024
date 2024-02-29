/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:33:41 by seizquie          #+#    #+#             */
/*   Updated: 2024/02/25 15:18:06 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (!((str[i] >= 97) && (str[i] <= 122)))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/*
int main (void)
{
	char str[] = "perrete";
	printf("%d", ft_str_is_lowercase(str));
	return (0);
}*/
