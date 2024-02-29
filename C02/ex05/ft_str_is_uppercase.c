/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:04:27 by seizquie          #+#    #+#             */
/*   Updated: 2024/02/22 08:40:14 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!((str[i] >= 65) && (str[i] <= 90)))
			return (0);
		i++;
	}
	return (1);
}
/*
int	main()
{
	char	str[] = "";

	printf("el resultado debería ser : %d", ft_str_is_uppercase(str));
	return (0);
}*/
