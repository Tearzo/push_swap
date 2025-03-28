/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavorapa <pavorapa@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-26 16:07:54 by pavorapa          #+#    #+#             */
/*   Updated: 2025-03-26 16:07:54 by pavorapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_stack
{
	int	*data;

	int	size;
}		t_stack;

// function to initialize a stack

t_stack	*init_stack(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->data = malloc(size * sizeof(int));
	stack->size = 0;
	return (stack);
}
