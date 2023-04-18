/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:40:47 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/13 11:38:35 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_check_duplicate(t_list **head)
{
	t_list	*temp;
	t_list	*temp2;

	ft_lst_position_initialize(head);
	temp = *head;
	temp2 = (*head)->next;
	while (temp)
	{
		while (temp2)
		{
			if ((temp->content == temp2->content) && (temp->position != temp2->position))
				return (1);
			temp2 = temp2->next;
		}
		temp2 = *head;
		temp = temp->next;
	}
	return (0);
}

void	ft_print_list_values(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}
}

void	ft_free_list(t_list	**head)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *head;
	while (temp)
	{
		temp2 = temp;
		temp = temp->next;
		free(temp);
	}
	free(head);
}

int	ft_lst_content_is_ordered(t_list **head)
{
	t_list	*temp;
	int		value;

	temp = (*head)->next;
	value = (*head)->content;
	while (temp)
	{
		if (value > temp->content)
			return (0);
		value = temp->content;
		temp = temp->next;
	}
	return (1);
}
