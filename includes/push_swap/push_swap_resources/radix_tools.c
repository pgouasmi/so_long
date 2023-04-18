/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:40:53 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/13 09:42:13 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_position_is_ordered(t_list **head)
{
	t_list	*temp;
	int		value;

	temp = (*head)->next;
	value = (*head)->position;
	while (temp)
	{
		if (value > temp->position)
			return (0);
		value = temp->position;
		temp = temp->next;
	}
	return (1);
}

void	ft_lst_position_initialize(t_list **head)
{
	int		i;
	t_list	*temp;

	i = 1;
	temp = *head;
	while (temp)
	{
		temp->position = i;
		i++;
		temp = temp->next;
	}
}

void	ft_lst_rotate_to_top_a(t_list **head, int place, int size)
{
	t_list	*temp;

	temp = *head;
	if (place > (size / 2))
	{
		while (place != (*head)->position)
			ft_reverse_rotate_a(head);
	}
	else
	{
		while (place != (*head)->position)
			ft_rotate_a(head);
	}
}

void	ft_lst_rotate_to_top_b(t_list **head, int place, int size)
{
	t_list	*temp;

	temp = *head;
	if (place > (size / 2))
	{
		while (place != (*head)->position)
			ft_reverse_rotate_b(head);
	}
	else
	{
		while (place != (*head)->position)
			ft_rotate_b(head);
	}
}

void	ft_lst_reorder_position(t_list **head)
{
	int	list_size;

	list_size = ft_lstsize(*head);
	if (list_size == 2)
		ft_lst_two_elements_sort(head);
	else if (list_size == 3)
		ft_lst_three_elements_sort(head);
}
