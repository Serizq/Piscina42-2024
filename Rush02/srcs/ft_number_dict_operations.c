/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_dict_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlsanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 07:01:50 by carlsanc          #+#    #+#             */
/*   Updated: 2024/02/25 07:03:49 by carlsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ft_short_types.h>
#include "ft_short_types.h"
#include "ft_number_dictionary.h"
#include "ft_boolean.h"
#include "ft_str.h"
#include "ft_to.h"
#include "ft_array.h"
#include "ft_is.h"
#include "ft_file_utils.h"
#include "ft_split.h"
#define NOT_FOUND -1

int		ft_sort_dict_f_normal(t_dict_entry *a, t_dict_entry *b)
{
	return (a->normal > b->normal);
}

int		ft_sort_dict_f_value(t_dict_entry *a, t_dict_entry *b)
{
	return (a->value > b->value);
}

void			ft_read_line(t_dict_entry *entry, int fd, t_parse_error *error)
{
	char			buffer[SIZE_1B];
	char			*line;
	UINT			byte_read;
	UINT			total;

	total = 0;
	while ((byte_read = read(fd, buffer, SIZE_1B)) > 0)
	{
		if (byte_read == (UINT)-1)
		{
			entry->str = 0;
			*error = failed;
			break ;
		}
		line = ft_extend_array(line, buffer, total, total + byte_read);
		total += byte_read;
		if (buffer[0] == '\n')
		{
			*error = ft_process_line(entry, line, total);
			byte_read = (UINT)-2;
			break ;
		}
	}
	if (byte_read == 0)
		*error = reached_eof;
}

char			*ft_clean_line(char *str)
{
	int		size;
	char	**split;

	split = ft_split_whitespace(str);
	free(str);
	size = 0;
	while (split[size])
		size++;
	return (ft_str_join(size, split, " "));
}

t_parse_error	ft_process_line(t_dict_entry *entry, char *line, UINT length)
{
	UINT	index;
	char	*number;

	index = 0;
	while (ft_is_number(line[index]))
		index++;
	if (line[index] == '\n')
		return (empty_line);
	if (index == 0 || index >= length)
		return (failed);
	number = ft_str_n_duplicate(line, index);
	while (line[index] == ' ')
		index++;
	if (line[index] != ':')
		return (failed);
	index++;
	while (line[index] == ' ')
		index++;
	entry->value = ft_atoi_strict(number);
	entry->str = ft_clean_line(
			ft_str_n_duplicate(line + index, length - index - 1));
	if (ft_str_length(entry->str) == 0)
		return (failed);
	free(number);
	return (parsing_ok);
}

int				ft_count_valid_line(char *path)
{
	int				fd;
	int				count;
	t_dict_entry	*entry;
	t_parse_error	error;

	fd = ft_open_file(path);
	if (fd < 0)
		return (INVALID);
	count = 0;
	while (true)
	{
		error = parsing_ok;
		if (!(entry = malloc(sizeof(t_dict_entry))))
			return (INVALID);
		ft_read_line(entry, fd, &error);
		if (error == failed)
			return (INVALID);
		if (error == parsing_ok)
			count++;
		if (entry->str == 0 || error == reached_eof)
			break ;
		free(entry);
	}
	ft_close_file(fd);
	return (count);
}

t_bool			ft_load_valid_line(char *path, int size, t_dict *dict)
{
	int				fd;
	int				index;
	t_dict_entry	*entry;
	t_parse_error	error;

	fd = ft_open_file(path);
	if (fd < 0)
		return (false);
	index = 0;
	while (index < size)
	{
		error = parsing_ok;
		entry = &dict->entries[index];
		ft_read_line(entry, fd, &error);
		if (error == failed)
			return (false);
		if (error == parsing_ok)
			index++;
		if ((entry->str == 0 || error == reached_eof) && error != empty_line)
			break ;
	}
	ft_close_file(fd);
	return (true);
}
t_dict	ft_load_default_dictionary(void)
{
	return (ft_load_dictionary(ENGLISH_DICT));
}

t_dict	ft_load_dictionary(char *path)
{
	int				size;
	t_dict_entry	*entries;
	t_dict			dict;

	dict = (t_dict){path, false, 0, 0};
	size = ft_count_valid_line(path);
	if (size == INVALID)
		return (dict);
	if (!(entries = malloc((size + 1) * sizeof(t_dict_entry))))
		return (dict);
	dict.size = size;
	dict.entries = entries;
	dict.valid = ft_load_valid_line(path, size, &dict);
	if (dict.valid)
		ft_sort_dictionary(&dict);
	return (dict);
}

void	ft_free_dictionary(t_dict *dict)
{
	int		index;

	index = 0;
	while (index < dict->size)
	{
		free(dict->entries[index].str);
		index++;
	}
}
void	ft_swap_dictionary_entry(t_dict_entry *a, t_dict_entry *b)
{
	t_dict_entry	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_update_normal_flag(t_dict *dict)
{
	int				index;
	t_dict_entry	*entry;
	t_bool			normal;

	index = 0;
	while (index < dict->size)
	{
		entry = &dict->entries[index];
		normal = false;
		if (entry->value <= 20)
			normal = true;
		if (entry->value > 20 || entry->value < 100)
			if (entry->value % 10 == 0)
				normal = true;
		entry->normal = normal;
		index++;
	}
}

void	ft_do_sort_dict(t_dict *dict, int start, int end,
						int (*func)(t_dict_entry*, t_dict_entry*))
{
	int				index;
	int				jndex;
	t_bool			swapped;
	t_dict_entry	*entries;

	entries = dict->entries;
	index = start;
	while (index < end)
	{
		jndex = start;
		swapped = false;
		while (jndex < end - index)
		{
			if ((*func)(&entries[jndex], &entries[jndex + 1]))
			{
				ft_swap_dictionary_entry(&entries[jndex], &entries[jndex + 1]);
				swapped = true;
			}
			jndex++;
		}
		index++;
		if (!swapped)
			break ;
	}
}

void	ft_sort_dictionary(t_dict *dict)
{
	int		index;
	int		index_of_zero;

	ft_update_normal_flag(dict);
	ft_do_sort_dict(dict, 0, dict->size - 1, &ft_sort_dict_f_normal);
	index = 0;
	index_of_zero = INVALID;
	while (index < dict->size)
	{
		if (dict->entries[index].value == 0)
		{
			index_of_zero = index;
			break ;
		}
		index++;
	}
	if (index_of_zero == INVALID)
		return ;
	ft_do_sort_dict(dict, index_of_zero, dict->size - 1, &ft_sort_dict_f_value);
	ft_do_sort_dict(dict, 0, index_of_zero, &ft_sort_dict_f_value);
}
int		ft_resolve_dict_entry_index(t_dict *dict, ULNG number)
{
	int		index;

	index = 0;
	while (index < dict->size)
	{
		if (dict->entries[index].value == number)
			return (index);
		index++;
	}
	return (NOT_FOUND);
}

t_bool	ft_itow_is_value_power_of_ten(ULNG number)
{
	ULNG		power;

	power = 1;
	while (power <= number)
	{
		if (power == number)
			return (true);
		power *= 10;
	}
	return (false);
}

void	ft_itow_print_if(t_bool print, t_bool *put_space, char *str)
{
	if (!print)
		return ;
	if (*put_space)
		ft_str_write(" ");
	*put_space = true;
	ft_str_write(str);
}

t_bool	ft_itow_short(t_dict *dict, ULNG number, t_bool *put_sp, t_bool prnt)
{
	int		dict_index;

	dict_index = ft_resolve_dict_entry_index(dict, number);
	if (dict_index == NOT_FOUND)
		return (false);
	ft_itow_print_if(prnt, put_sp, dict->entries[dict_index].str);
	return (true);
}

t_bool	ft_itow(t_dict *dict, ULNG number, t_bool *put_space, t_bool print)
{
	int		index;
	ULNG	mult;
	ULNG	value;

	if ((number <= 20 && ft_itow_short(dict, number, 0, false))
			|| (ft_resolve_dict_entry_index(dict, number) != NOT_FOUND
					&& !ft_itow_is_value_power_of_ten(number)))
		return (ft_itow_short(dict, number, put_space, print));
	index = dict->size - 1;
	while ((value = dict->entries[index].value) != 0)
	{
		if (number % value != number)
		{
			mult = number / value;
			if (value > 99)
				if (!ft_itow(dict, mult, put_space, print))
					return (false);
			ft_itow_print_if(print, put_space, dict->entries[index].str);
			if (number - mult * value == 0)
				return (true);
			return (ft_itow(dict, number - mult * value, put_space, print));
		}
		index--;
	}
	return (true);
}

