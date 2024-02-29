/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:21:33 by fmorenil          #+#    #+#             */
/*   Updated: 2024/02/18 12:40:44 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c);

int	**ft_create_grid()
{
	int	**grid;
	int	i;
	int	j;

	i = 0;
	j = 0;
	int	array[4][4] = {
		{1,2,3,4},
		{2,3,4,1},
		{3,4,1,2},
		{4,1,2,3}
	};
	grid = (int**)malloc(sizeof(int*)*4);

	while (i < 4)
	{
		grid[i] = (int*)malloc(sizeof(int)*4);
		j = 0;

		while(j < 4)
		{
			grid[i][j] = array[i][j];
			j++;
		}
		i++;
	}
	return grid;
}

void	write_grid(int **grid)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	j = 0;
	
	/*ft_putchar(' ');*/
	while (i < 4)
	{
		while (j < 4)
		{
			num = grid[i][j] + '0';
			ft_putchar(num);
			if (j != 3)
			{
			ft_putchar(' ');
			}
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}

int	main()
{
	int	**grid;
	int	i;

	grid = ft_create_grid();
	i = 0;

	write_grid(grid);
	while (i < 4)
	{
		free(grid[i]);
		i++;
	}
	free(grid);

	return (0);
}
