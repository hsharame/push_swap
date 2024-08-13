/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:38:36 by hsharame          #+#    #+#             */
/*   Updated: 2024/08/07 15:38:38 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	research_remote(t_stack **stack_a, t_stack **stack_b)
{
	int		key;
	int		size_b;
	int		pos_key;
	t_stack	*temp;

	position_update(stack_b);
	temp = *stack_b;
	key = ((*stack_a)->index) + 1;
	size_b = stack_size(*stack_b);
	while (temp->index != key)
		temp = temp->next;
	pos_key = temp->pos;
	if (pos_key < size_b / 2)
	{
		while ((*stack_b)->pos != pos_key)
			rb(stack_b);
	}
	else if (pos_key >= size_b / 2)
	{
		while ((*stack_b)->pos != pos_key)
			rrb(stack_b);
	}
	pa(stack_a, stack_b);
	sa(stack_a);
}

void	research_normal(t_stack **stack_a, t_stack **stack_b)
{
	int		key;
	int		size_b;
	int		pos_key;
	int		next_key;
	t_stack	*temp;

	position_update(stack_b);
	temp = *stack_b;
	key = ((*stack_a)->index) - 1;
	next_key = key - 1;
	size_b = stack_size(*stack_b);
	while (temp->index != key && temp->index != next_key)
		temp = temp->next;
	pos_key = temp->pos;
	if (pos_key < size_b / 2)
	{
		while ((*stack_b)->pos != pos_key)
			rb(stack_b);
	}
	else if (pos_key >= size_b / 2)
	{
		while ((*stack_b)->pos != pos_key)
			rrb(stack_b);
	}
	pa(stack_a, stack_b);
}

/*
	If there is only one element left in stack b, it does pa, 
	otherwise it looks at the difference between the element on top of stack a 
	and the element before it. Does a simple search, or a distant search, 
	chooses as key index + 1 of the element at the top.
	example:
	A : [5] [7] [8] [9] -> (7 - 5 = 2) -> 
		it looks for index 6 in stack B.
	A : [6] [7] [8] [9] -> normal -> 
		it looks for index 5, or 4, if it is less expensive to replace
*/
void	research_next(t_stack **stack_a, t_stack **stack_b)
{
	int	size_b;

	size_b = stack_size(*stack_b);
	if (size_b == 1)
	{
		pa(stack_a, stack_b);
		return ;
	}
	if ((*stack_a)->next->index - (*stack_a)->index == 2)
		research_remote(stack_a, stack_b);
	else
		research_normal(stack_a, stack_b);
}
