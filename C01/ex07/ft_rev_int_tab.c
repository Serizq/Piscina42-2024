/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:13:02 by seizquie          #+#    #+#             */
/*   Updated: 2024/02/20 13:42:22 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	aux;

	i = 0;
	while (i < size / 2)
	{
		aux = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = aux;
		i++;
	}
}
/*
int	main(void)
{
	int	size;
	int	array[5];
	int	i;

	size = 5;
	array[0] = 1;
	array[1] = 35;
	array[2] = 26;
	array[3] = 12;
	array[4] = 7;
	ft_rev_int_tab(array,size);
	i = 0;
	while (i <= size)
	{
		printf("%d\n", array[i]);
		i++;
	}
	return (0);
}*/
