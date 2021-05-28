LINUX				:= 0

# Folders

override BIN		:= bin
override SRC		:= src
override INC		:= includes

# Libraries

override LIBFT_DIR	:= libft
override LIBFT		:= libft.a

# Properties

NAME				= push

# Commands

override CC			:= gcc
override RM			:= rm -rf
override CFLAGS		:= -Wall -Wextra -Werror -O3
override INCLUDES	:= -I$(INC) -I$(LIBFT_DIR)/$(INC) -I$(MINILIBX_DIR)

# Sources

override SRCS		:=									\
				main.c									\
				actions.c								\

override OBJS		:= $(addprefix $(BIN)/, $(SRCS:.c=.o))

override HEADERS	:= $(addprefix $(INC)/,				\
				push_swap.h								\
				)

all:		libs $(NAME)

bonus:		all

$(BIN)/%.o:	$(SRC)/%.c $(HEADERS)
			@mkdir -p $(dir $@);
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT) $(MINILIBX)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(LIBRARIES)

clean:
			$(RM) $(OBJS)
			find $(BIN) -type d -empty -delete
			$(MAKE) -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)
			$(MAKE) -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all libs bonus clean fclean re
