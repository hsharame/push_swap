/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:08:43 by hsharame          #+#    #+#             */
/*   Updated: 2024/07/16 13:08:45 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sorted(t_stack *stack)
{
    while (stack->next != NULL)
    {
        if (stack->nbr > stack->next->nbr)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void    push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
    if (size == 2 && !check_sorted(*stack_a))
        sa(stack_a);
    /*else if (size == 3)
        tiny_sort(stack_a);*/
    else if (size > 3 && !check_sorted(*stack_a))
        quicksort(stack_a, stack_b);
}

void    stack_position(t_stack **stack)
{
    int i;

    i = 1;
    while ((*stack)->next != NULL)
    {
        (*stack)->pos = i;
        i++;
        stack = (*stack)->next;
    }
}

void    quicksort(t_stack **stack_a, t_stack **stack_b)
{
    int pivot;

    if (stack_size(*stack_a) <= 1)
        return;
    pivot = get_pivot(*stack_a);
}

int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;
    int     size;

    if (argc < 2 || (argc == 2 && !check_argv(argv[1])))
        return (1);
    if (!check_input(argc, argv))
        ft_error(NULL, NULL);
    if (argc == 2 && check_argv(argv[1]))
        argv = ft_split(argv[1],' ');
    stack_a = fill_stack(argc, argv);
    stack_b = NULL;
    size = stack_size(stack_a);
    stack_index(stack_a, size + 1);
    stack_position(stack_a);
    push_swap(&stack_a, &stack_b, size);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
