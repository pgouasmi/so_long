/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_manager1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:46:48 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/14 18:30:55 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_new_node(t_list **a_head, int value)
{
	t_list	*new;
	t_list	*temp;

	temp = *a_head;
	new = malloc(sizeof(*new));
	if (!new)
		return (1);
	new->content = value;
	new->next = NULL;
	if (!*a_head)
		*a_head = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (0);
}

int	ft_str_into_list(char *str, t_list **a_head)
{
	int	value;

	value = ft_atoi(str);
	if (value == 0 && !ft_str_same_char_str((ft_strtrim
				((const char *)str, "+-")), '0'))
		return (1);
	if (ft_new_node(a_head, value))
		return (1);
	return (0);
}

char	*ft_str_ws_into_spaces(char *str)
{
	char	*result;
	size_t	i;

	result = ft_strdup((const char *) str);
	i = 0;
	while (result[i])
	{
		if (ft_is_white_space(result[i]))
			str[i] = ' ';
		i++;
	}
	return (result);
}

int	ft_ws_arg_case(char *str, t_list **a_head)
{
	int		j;
	int		count;
	char	**split;

	str = ft_strtrim((const char *)ft_str_ws_into_spaces(str), " ");
	count = ft_str_count_ws_block(str) + 1;
	split = ft_split((const char *)str, ' ');
	j = 0;
	while (j < count)
	{
		if (!ft_str_is_only_digit(ft_strtrim((const char *)split[j], "+-")))
			return (1);
		else
		{
			if (ft_str_into_list(split[j], a_head))
				return (1);
		}
		j++;
	}
	return (0);
}

int	ft_argv_into_list(int argc, char **argv, t_list **a_head)
{
	int		j;
	int		value;

	j = 0;
	while (++j < argc)
	{
		if (ft_str_has_ws(argv[j]))
		{
			if (ft_ws_arg_case(argv[j], a_head))
				return (1);
		}
		else
		{
			if (!ft_str_is_only_digit(ft_strtrim((const char *)argv[j], "+-")))
				return (1);
			value = ft_atoi(argv[j]);
			if (value == 0 && !ft_str_same_char_str((ft_strtrim
						((const char *)argv[j], "+-")), '0'))
				return (1);
			if (ft_new_node(a_head, value))
				return (1);
		}
	}
	return (0);
}
