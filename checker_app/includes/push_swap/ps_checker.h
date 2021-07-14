#ifndef PS_CHECKER_H
# define PS_CHECKER_H

# include "libft.h"
# include "stack.h"

# define BUFF_SIZE		4

/*** Types ********************************************************************/

typedef struct s_gnl_entry	t_gnl_entry;
typedef enum e_read_status	t_read_status;

/*** GNL **********************************************************************/

struct s_gnl_entry
{
	void	*next;
	int		fd;
	char	*content;
};

enum e_read_status
{
	READ_ERROR = -1,
	READ_EOF = 0,
	READ_SUCCESS = 1
};

char	**ft_gnl_split(char *s, char c);
int		get_next_line(int fd, char **line);
int		gnl_init(char ***current, char **tmp_line, ssize_t *result);

#endif
