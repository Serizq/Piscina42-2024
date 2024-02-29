/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:44:33 by seizquie          #+#    #+#             */
/*   Updated: 2024/02/26 18:29:53 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		if ((to_find[j] == str[i + j]) && (to_find[j] != '\0'))
			temp = &str[i];
		while ((to_find[j] == str[i + j]) && (to_find[j] != '\0'))
		{
			j++;
		}
		if (to_find[j] == '\0')
			return (temp);
		i++;
	}
	return (0);
}
