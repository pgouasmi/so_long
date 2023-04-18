/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push_swap3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:38:13 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/03/30 22:25:09 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse_rotate_a(t_list **head)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;
	t_list	*before_last;

	if (!*head)
		return ;
	first = *head;
	second = (*head)->next;
	if (!second)
		return ;
	last = *head;
	while (last->next)
		last = last->next;
	before_last = *head;
	while (before_last->next != last)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = first;
	*head = last;
	ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_list **head)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;
	t_list	*before_last;

	if (!*head)
		return ;
	first = *head;
	second = (*head)->next;
	if (!second)
		return ;
	last = *head;
	while (last->next)
		last = last->next;
	before_last = *head;
	while (before_last->next != last)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = first;
	*head = last;
	ft_printf("rrb\n");
}

void	ft_rrr(t_list **head_a, t_list **head_b)
{
	ft_reverse_rotate_a(head_a);
	ft_reverse_rotate_b(head_b);
}
