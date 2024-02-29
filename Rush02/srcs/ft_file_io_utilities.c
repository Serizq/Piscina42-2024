/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_io_utilities.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlsanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 07:04:03 by carlsanc          #+#    #+#             */
/*   Updated: 2024/02/25 07:04:39 by carlsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#include "ft_number_dictionary.h"
#include <fcntl.h>
#include <unistd.h>

int		ft_open_file(char *path)
{
	return (open(path, O_RDONLY));
}

int		ft_close_file(int fd)
{
	return (close(fd));
}
void	debug_dump_dictionary(t_dict dict)
{
	int		index;

	index = 0;
	while (index < dict.size)
	{
		printf("dict.entries[%d]\n", index);
		printf("    | value : %lu\n", dict.entries[index].value);
		printf("    | str   : $%s$\n", dict.entries[index].str);
		index++;
	}
	fflush(stdout);
}
