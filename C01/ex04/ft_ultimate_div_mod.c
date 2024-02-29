/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:19:41 by seizquie          #+#    #+#             */
/*   Updated: 2024/02/23 13:15:57 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

#include <stdio.h>
int	main(void)
{
	int	a = 30;
	int	b = 4;

	ft_ultimate_div_mod(&a, &b);
	printf("div : %d\n, mod : %d\n", a, b);
	return (0);
}
