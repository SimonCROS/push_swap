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
	int mid)
{
	int	i;

	i = 0;
	if (nearest >= 0)
	{
		while (i++ < nearest)
		{
			if (other->name == A && ((t_stack *)other)->size && ((t_stack *)other)->array[0] > mid)
				named_stack_action(stack, other, ROTATE, BOTH);
			else if (other->name == B && ((t_stack *)other)->size && ((t_stack *)other)->array[0] < mid)
				named_stack_action(stack, other, ROTATE, BOTH);
			else
				named_stack_action(stack, other, ROTATE, stack->name);
		}
	}
	else
		while (i-- > nearest)
			named_stack_action(stack, other, REVERSE_ROTATE, stack->name);
}

void	make_chunk(t_named_stack *stack, t_named_stack *other, int chunk_min,
	int chunk_max)
{
	int	nearest;
	int	middle;

	middle = chunk_min + (chunk_max - chunk_min) / 2;
	while (((t_stack *)stack)->size)
	{
		nearest = find_nearest((t_stack *)stack, chunk_min, chunk_max);
		if (nearest == ((t_stack *)stack)->size)
			break ;
		move_to_top(stack, other, nearest, middle);

		if (other->name == A && ((t_stack *)other)->size && ((t_stack *)other)->array[0] > middle)
			named_stack_action(stack, other, ROTATE, other->name);
		else if (other->name == B && ((t_stack *)other)->size && ((t_stack *)other)->array[0] < middle)
			named_stack_action(stack, other, ROTATE, other->name);

		named_stack_action(stack, other, PUSH, other->name);
	}
}

/**
 * @param options[0] size
 * @param options[1] iterations
 * @param options[2] steps
 * @param options[3] reduce on iterate
 * @param options[4] reversed
 */
int	iter_chunk(t_named_stack *a, t_named_stack *b, int opts[5], int chunk_max)
{
	t_named_stack	*p;
	int				chunk_step;
	int				chunk_min;
	int				i;

	p = a;
	if (opts[4])
		p = b;
	i = 0;
	chunk_step = opts[0] / opts[2];
	while (i++ != opts[1] && p->super.size)
	{
		chunk_min = chunk_max;
		if (!opts[4])
			chunk_max += chunk_step;
		else
			chunk_max -= chunk_step;
		if (!opts[4])
			make_chunk(a, b, chunk_min, chunk_max);
		else
			make_chunk(b, a, chunk_max, chunk_max + chunk_step);
		if (opts[3])
			chunk_step /= 2;
	}
	return (chunk_max);
}
