/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push_swap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:32:53 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/03/30 22:24:41 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_a(t_list **a_head)
{
	t_list	*temp_first;
	t_list	*temp_second;

	if (!(*a_head)->next || !(*a_head))
		return ;
	temp_first = *a_head;
	temp_second = (*a_head)->next;
	temp_first->next = temp_second->next;
	temp_second->next = temp_first;
	*a_head = temp_second;
	ft_printf("sa\n");
}

void	ft_swap_b(t_list **b_head)
{
	t_list	*temp_first;
	t_list	*temp_second;

	if (!(*b_head)->next || !(*b_head))
		return ;
	temp_first = *b_head;
	temp_second = (*b_head)->next;
	temp_first->next = temp_second->next;
	temp_second->next = temp_first;
	*b_head = temp_second;
	ft_printf("sb\n");
}

void	ft_ss(t_list **a_head, t_list **b_head)
{
	ft_swap_a(a_head);
	ft_swap_b(b_head);
}

void	ft_push_a(t_list **a_head, t_list **b_head)
{
	t_list	*first_a;
	t_list	*first_b;
	t_list	*second_a;
	t_list	*second_b;

	if (!b_head || !*b_head)
		return ;
	first_b = *b_head;
	second_b = (*b_head)->next;
	if (!*a_head)
		second_a = NULL;
	else
		second_a = (*a_head)->next;
	first_a = *a_head;
	if (!second_b)
		*b_head = NULL;
	else
		*b_head = second_b;
	if (!*a_head)
		first_b->next = NULL;
	else
		first_b->next = first_a;
	*a_head = first_b;
	ft_printf("pa\n");
}

void	ft_push_b(t_list **a_head, t_list **b_head)
{
	t_list	*first_a;
	t_list	*first_b;
	t_list	*second_a;
	t_list	*second_b;

	if (!a_head || !*a_head)
		return ;
	first_a = *a_head;
	second_a = (*a_head)->next;
	if (!*b_head)
		second_b = NULL;
	else
		second_b = (*b_head)->next;
	first_b = *b_head;
	if (!second_a)
		*a_head = NULL;
	else
		*a_head = second_a;
	if (!*b_head)
		first_a->next = NULL;
	else
		first_a->next = first_b;
	*b_head = first_a;
	ft_printf("pb\n");
}
