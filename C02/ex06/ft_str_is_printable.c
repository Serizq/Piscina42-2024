/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:44:23 by seizquie          #+#    #+#             */
/*   Updated: 2024/02/22 09:00:57 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!((str[i] >= 32) && (str[i] <= 126)))
			return (0);
		i++;
	}
	return (1);
}
/*
int main(void)
{
	char	str[] = "buenos dias $$$ ## ";
	printf("el resultado es : %d", ft_str_is_printable(str));
	return (0);
}*/
