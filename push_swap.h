
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_number
{
	int	value;
	struct s_number *next;
	struct s_number *prev;
} t_number;

typedef struct s_stack
{
	t_number *first;
	t_number *last;
	int		total;
}	t_list;

#endif