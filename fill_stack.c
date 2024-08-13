/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:45:15 by hsharame          #+#    #+#             */
/*   Updated: 2024/07/16 15:45:18 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(int argc, char *argv[])
{
	long int	nbr;
	int			i;
	t_stack		*stack_a;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			if (ft_strlen(argv[0]) <= 2)
				free_argv(argv, argc);
			ft_error(&stack_a, NULL);
		}
		if (i == 1)
			stack_a = new_stack((int)nbr);
		else
			add_bottom(&stack_a, new_stack((int)nbr));
		i++;
	}
	return (stack_a);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

/*
	Assigns descending indices to the elements of the stack
	based on the descending order of their values.
	nbr:		-3	 0	 9	 2
	index:		[1]	[2]	[4]	[3]
*/
void	stack_index(t_stack *stack, int size)
{
	t_stack	*ptr;
	t_stack	*top;
	int		nbr;

	while (--size > 0)
	{
		ptr = stack;
		nbr = INT_MIN;
		top = NULL;
		while (ptr)
		{
			if (ptr->nbr == INT_MIN && ptr->index == -1)
				ptr->index = 1;
			if (ptr->nbr > nbr && ptr->index == -1)
			{
				nbr = ptr->nbr;
				top = ptr;
				ptr = stack;
			}
			else
				ptr = ptr->next;
		}
		if (top != NULL)
			top->index = size;
	}
}

void	position_update(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}
