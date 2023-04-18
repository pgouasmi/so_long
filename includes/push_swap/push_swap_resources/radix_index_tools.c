/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_index_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:40:50 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/13 09:41:46 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_index_initialize(t_list **head, int elements_count)
{
	int		index_value;
	int		value_to_compare;
	t_list	*temp;

	index_value = 0;
	temp = *head;
	ft_lst_index_initialize_to_zero(head);
	while (index_value++ < elements_count)
	{
		value_to_compare = ft_lst_get_int_min(head);
		while (temp)
		{
			if (temp->content == value_to_compare)
				temp->index = index_value;
			temp = temp->next;
		}
		temp = *head;
	}
	temp = *head;
	while (temp)
	{
		if (temp->index == 0)
			temp->index = elements_count;
		temp = temp->next;
	}
}

void	ft_lst_index_initialize_to_zero(t_list **head)
{
	t_list	*temp;

	temp = *head;
	while (temp)
	{
		temp->index = 0;
		temp = temp->next;
	}
}

int	ft_lst_get_int_min(t_list **head)
{
	t_list	*temp;
	int		value;

	value = 2147483647;
	temp = *head;
	while (temp)
	{
		if (temp->index == 0 && temp->content <= value)
			value = temp->content;
		temp = temp->next;
	}
	return (value);
}

void	ft_print_list_index(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp)
	{
		ft_printf("%d\n", temp->index);
		temp = temp->next;
	}
}
