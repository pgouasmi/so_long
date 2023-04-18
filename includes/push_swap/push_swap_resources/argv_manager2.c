/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_manager2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:50:22 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/13 10:56:04 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_white_space(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

size_t	ft_str_count_ws_block(char *str)
{
	size_t	i;
	size_t	count;
	size_t	is_digit;

	i = 0;
	count = 0;
	is_digit = 0;
	while (str[i])
	{
		if (ft_is_white_space(str[i]))
		{
			count++;
			while (ft_is_white_space(str[i]))
				i++;
		}
		else
		{
			if (ft_isdigit(str[i]))
				is_digit++;
			i++;
		}
	}
	if (!is_digit)
		return (0);
	return (count);
}

int	ft_str_is_only_digit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_str_has_ws(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_white_space(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_str_same_char_str(const char *str, int c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}
