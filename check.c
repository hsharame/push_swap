/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:32:49 by hsharame          #+#    #+#             */
/*   Updated: 2024/08/07 15:32:51 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_sorted_reverse(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->nbr < stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*
	Checks if there are still elements in the stack 
	corresponding to the chunk
*/
int	check_chunk(t_stack **stack, int until)
{
	t_stack	*temp;

	temp = *stack;
	position_update(stack);
	while (temp != NULL)
	{
		if (temp->index <= until)
			return (1);
		temp = temp->next;
	}
	return (0);
}
