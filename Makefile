# Folders

override BIN		:= bin
override SRC		:= src
override INC		:= includes

override APP		:= app
override CHECKER	:= checker
override COMMON		:= common

# Libraries

override LIBFT_DIR	:= libft
override LIBFT		:= libft.a

# Properties

NAME				= push_swap

# Commands

override CC			:= gcc-11
override RM			:= rm -rf
override CFLAGS		:= -Wall -Wextra -Werror -O3
override INCLUDES	:= -I$(APP)/$(INC) -I$(CHECKER)/$(INC) -I$(COMMON)/$(INC) -I$(LIBFT_DIR)/$(INC)

# Sources

override CHECKER_SRCS:=									\

override COMMON_SRCS:=									\
				init.c									\
				tests.c									\
				actions.c								\
				stack1.c								\
				stack2.c								\

override APP_SRCS	:=									\
				main.c									\
				sort.c									\
				chunk.c									\

override APP_OBJS:= $(addprefix $(APP)/, $(addprefix $(BIN)/, $(APP_SRCS:.c=.o)))
override CHECKER_OBJS:= $(addprefix $(CHECKER)/, $(addprefix $(BIN)/, $(CHECKER_SRCS:.c=.o)))
override COMMON_OBJS:= $(addprefix $(COMMON)/, $(addprefix $(BIN)/, $(COMMON_SRCS:.c=.o)))

override OBJS		:= $(APP_OBJS) $(CHECKER_OBJS) $(COMMON_OBJS)

$(APP)/$(BIN)/%.o:	$(APP)/$(SRC)/%.c $(COMMON_HEADERS)
			@mkdir -p $(dir $@);
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(CHECKER)/$(BIN)/%.o:	$(CHECKER)/$(SRC)/%.c $(COMMON_HEADERS)
			@mkdir -p $(dir $@);
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(COMMON)/$(BIN)/%.o:	$(COMMON)/$(SRC)/%.c $(COMMON_HEADERS)
			@mkdir -p $(dir $@);
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#TODO recompile on headers

all:		libs $(NAME)

# bonus:		checker

libs:
			$(MAKE) -C $(LIBFT_DIR)
			ln -sf $(LIBFT_DIR)/$(LIBFT)

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
