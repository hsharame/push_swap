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

char	**argv_split(char *argv[])
{
	char	**result;

	result = ft_split(argv[1], ' ');
	if (!result)
		return (NULL);
	return (result);
}

int	argc_split(char	*argv[])
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc == 1)
		return (0);
	if ((argc >= 3 && !check_input(argv))
		|| (argc == 2 && is_word(argv[1])))
		return (write(2, "Error\n", 6));
	if (argc == 2 && check_one(argv[1]))
		return (0);
	else if (argc == 2 && check_argv(argv[1]))
		return (split_argv(argv));
	stack_a = fill_stack(argc, argv);
	stack_b = NULL;
	size = stack_size(stack_a);
	stack_index(stack_a, size + 1);
	push_swap(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

int	split_argv(char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;
	int		split_argc;
	char	**split_argv;

	split_argv = argv_split(argv);
	split_argc = argc_split(split_argv);
	if (!check_input(split_argv))
	{
		free_argv(split_argv, split_argc);
		return (write(2, "Error\n", 6));
	}
	stack_a = fill_stack(split_argc, split_argv);
	stack_b = NULL;
	size = stack_size(stack_a);
	stack_index(stack_a, size + 1);
	push_swap(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free_argv(split_argv, split_argc);
	return (0);
}
