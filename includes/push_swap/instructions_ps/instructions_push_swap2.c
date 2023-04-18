/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push_swap2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:02:53 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/03/30 22:24:29 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rotate_a(t_list **head)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!*head)
		return ;
	first = *head;
	second = (*head)->next;
	if (!second)
		return ;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*head = second;
	ft_printf("ra\n");
}

void	ft_rotate_b(t_list **head)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!*head)
		return ;
	first = *head;
	second = (*head)->next;
	if (!second)
		return ;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*head = second;
	ft_printf("rb\n");
}

void	ft_rr(t_list **head_a, t_list **head_b)
{
	ft_rotate_a(head_a);
	ft_rotate_b(head_b);
}
