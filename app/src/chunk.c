#include "push_swap/ps_common.h"
#include "push_swap/ps_app.h"

static int	find_nearest(const t_stack *stack, int chunk_min, int chunk_max)
{
	int				nearest;
	int				i;

	nearest = stack->size;
	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] >= chunk_min && stack->array[i] < chunk_max)
		{
			nearest = i;
			break ;
		}
		i++;
	}
	i = stack->size;
	while (i-- > 0 && stack->size - i < nearest * 0.5)
	{
		if (stack->array[i] >= chunk_min && stack->array[i] < chunk_max)
		{
			nearest = -(stack->size - i);
			break ;
		}
	}
	return (nearest);
}

static void	move_to_top(t_named_stack *stack, t_named_stack *other, int nearest,
	int middle)
{
	int	i;

	i = 0;
	if (nearest > 0)
	{
		while (i++ < nearest)
		{
			if (stack->size && stack->array[0] < middle)
				action(stack, other, ROTATE, BOTH);
			else
				action(stack, other, ROTATE, ft_ternary(!reversed, A, B));
		}
	}
	else
		while (i-- > nearest)
			action(a, b, REVERSE_ROTATE, ft_ternary(!reversed, A, B));
}

void	make_chunk(t_named_stack *stack, t_named_stack *other, int chunk_min,
	int chunk_max)
{
	int				nearest;
	int				middle;

	middle = chunk_min + (chunk_max - chunk_min) / 2;
	while (((t_stack *)stack)->size)
	{
		nearest = find_nearest(stack, chunk_min, chunk_max);
		if (nearest == ((t_stack *)stack)->size)
			break ;
		
		action((t_stack *)stack, (t_stack *)other, PUSH, other->name);
	}
}

/**
 * @param options[0] size
 * @param options[1] iterations
 * @param options[2] steps
 * @param options[3] reduce on iterate
 */
int	iter_chunk(t_named_stack *a, t_named_stack *b, int opts[4], int chunk_max)
{
	t_stack	*p;
	int		chunk_step;
	int		chunk_min;
	int		i;

	p = a;
	if (opts[4])
		p = b;
	i = 0;
	chunk_step = opts[1] / opts[2] * ft_ternary(!opts[4], 1, -1);
	while (i++ != opts[1] && p->size)
	{
		chunk_min = chunk_max;
		chunk_max += chunk_step;
		if (!opts[4])
			make_chunk(a, b, chunk_min, chunk_max);
		else
			make_chunk(b, a, chunk_max, chunk_max + chunk_step);
		if (opts[3])
			chunk_step /= 2;
	}
	return (chunk_max);
}
