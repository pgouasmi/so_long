/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:35:19 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/14 18:25:14 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	t_list	*a_head;
	t_list	*b_head;
	size_t	arg_count;
	

	a_head = NULL;
	b_head = NULL;
	if (ft_argv_into_list(argc, argv, &a_head))
		return (ft_printf("Error\n"), 1);
	if (ft_lst_check_duplicate(&a_head))
		return (ft_printf("Error duplicate\n"), 1);
	arg_count = ft_lstsize(a_head);
	ft_lst_position_initialize(&a_head);
	ft_lst_index_initialize(&a_head, arg_count);
	ft_push_swap_algorithms(&a_head, &b_head, arg_count);
	return (0);
}
