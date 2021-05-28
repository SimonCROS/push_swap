#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef enum e_action		t_action;
typedef enum e_stack		t_stack;
typedef struct s_int_entry	t_int_entry;

enum e_action
{
	SWAP,
	PUSH,
	ROTATE,
	REVERSE_ROTATE
};

enum e_stack
{
	A,
	B,
	BOTH
};

struct s_int_entry
{
	t_int_entry	*next;
	int			value;
};

#endif
