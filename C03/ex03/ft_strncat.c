/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:36:25 by seizquie          #+#    #+#             */
/*   Updated: 2024/02/27 16:07:23 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*start;

	start = dest;
	while (*dest)
	{
		dest++;
	}
	while (*src && nb > 0)
	{
		*dest = *src;
		dest ++;
		src++;
		nb--;
	}
	*dest = '\0';
	return (start);
}
