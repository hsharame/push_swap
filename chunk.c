/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:38:55 by hsharame          #+#    #+#             */
/*   Updated: 2024/08/07 12:38:58 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_top(t_stack *temp, int until, int *index_top, int *pos_top)
{
	while (temp->index > until)
		temp = temp->next;
	*index_top = temp->index;
	*pos_top = temp->pos;
}

void	find_bottom(t_stack *temp, int until, int *index_bot, int *pos_bot)
{
	while (temp != NULL)
	{
		if (temp->index <= until)
		{
			*index_bot = temp->index;
			*pos_bot = temp->pos;
		}
		temp = temp->next;
	}
}

void	chunk(t_stack **stack_a, t_stack **stack_b, int until)
{
	int		index_top;
	int		pos_top;
	int		index_bottom;
	int		pos_bottom;
	t_stack	*temp;

	if (!check_chunk(stack_a, until))
		return ;
	temp = *stack_a;
	find_top(temp, until, &index_top, &pos_top);
	find_bottom(temp, until, &index_bottom, &pos_bottom);
	if (pos_top <= stack_size(*stack_a) - pos_bottom)
		do_ra_pb(stack_a, stack_b, index_top);
	else
		do_rra_pb(stack_a, stack_b, index_bottom);
	chunk(stack_a, stack_b, until);
}

void	do_ra_pb(t_stack **stack_a, t_stack **stack_b, int index_top)
{
	while ((*stack_a)->index != index_top)
		ra(stack_a);
	pb(stack_a, stack_b);
}

void	do_rra_pb(t_stack **stack_a, t_stack **stack_b, int index_bottom)
{
	while ((*stack_a)->index != index_bottom)
		rra(stack_a);
	pb(stack_a, stack_b);
}
