/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:23:51 by seizquie          #+#    #+#             */
/*   Updated: 2024/02/28 18:11:04 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	total;

	i = 0;
	j = 0;
	total = 0;
	while (dest[i] != '\0')
		i++;
	while (src[total] != '\0')
		total ++;
	if (size <= i)
		total += size;
	else
		total += i;
	while (src[j] != '\0' && (i + 1) < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (total);
}
/*
int main() {
    char dest[20] = " ";
    char src[] = "world!";
    unsigned int size = 20;
    unsigned int total;

    printf("Destino antes de la concatenación: %s\n", dest);
    printf("Fuente a concatenar: %s\n", src);

    total = ft_strlcat(dest, src, size);

    printf("Destino después de la concatenación: %s\n", dest);
    printf("Tamaño total de la cadena concatenada: %u\n", total);

    return 0;
}*/
