# Folders

override BIN		:= bin
override SRC		:= src
override INC		:= includes

override APP		:= app
override CHECKER	:= checker_app
override COMMON		:= common

# Libraries

override LIBFT_DIR	:= libft
override LIBFT		:= libft.a

# Properties

NAME				= push_swap
CHECKER_NAME		= checker

# Commands

override CC			:= gcc
override RM			:= rm -rf
override CFLAGS		:= -Wall -Wextra -Werror -O3
override INCLUDES	:= -I$(APP)/$(INC) -I$(CHECKER)/$(INC) -I$(COMMON)/$(INC) -I$(LIBFT_DIR)/$(INC)

# Sources

override CHECKER_SRCS:=									\
				main.c									\
				../libs/gnl/get_next_line.c				\
				../libs/gnl/get_next_line_utils.c		\

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

override OBJS		:= $(APP_OBJS) $(COMMON_OBJS)

override APP_HEADERS	:= \
				$(APP)/includes/push_swap/ps_app.h			\

override CHECKER_HEADERS	:= \
				$(CHECKER)/includes/push_swap/ps_checker.h	\

override COMMON_HEADERS	:= \
				$(COMMON)/includes/stack.h					\
				$(COMMON)/includes/push_swap/ps_common.h	\

$(APP)/$(BIN)/%.o:	$(APP)/$(SRC)/%.c $(APP_HEADERS) $(COMMON_HEADERS)
			@mkdir -p $(dir $@);
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(CHECKER)/$(BIN)/%.o:	$(CHECKER)/$(SRC)/%.c $(CHECKER_HEADERS) $(COMMON_HEADERS)
			@mkdir -p $(dir $@);
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(COMMON)/$(BIN)/%.o:	$(COMMON)/$(SRC)/%.c $(COMMON_HEADERS)
			@mkdir -p $(dir $@);
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BIN)/%.o:	$(SRC)/%.c $(APP_HEADERS) $(CHECKER_HEADERS) $(COMMON_HEADERS)
			@mkdir -p $(dir $@);
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#TODO recompile on headers

all:		libs $(NAME)

bonus:		all $(CHECKER_NAME)

libs:
			$(MAKE) -C $(LIBFT_DIR)

$(NAME):	$(OBJS) $(LIBFT_DIR)/$(LIBFT)
			ln -sf $(LIBFT_DIR)/$(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(CHECKER_NAME):	$(CHECKER_OBJS) $(COMMON_OBJS)
			$(CC) $(CFLAGS) $(CHECKER_OBJS) $(COMMON_OBJS) $(LIBFT) -o $(CHECKER_NAME)			

clean:
			$(RM) $(OBJS) $(CHECKER_OBJS)
			$(MAKE) -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)
			$(MAKE) -C $(LIBFT_DIR) fclean

re:			fclean all

unit:		all
			@	trap "exit" INT							&&\
				clear									&&\
				./complexity 500 100 5500 ./checker_Mac	&&\
				echo									&&\
				./complexity 100 100 700 ./checker_Mac	&&\
				echo									&&\
				./complexity 5 100 12 ./checker_Mac		&&\
				echo									&&\
				./complexity 3 100 4 ./checker_Mac		\

.PHONY:		all libs bonus unit clean fclean re
