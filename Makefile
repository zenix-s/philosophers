#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#
NAME	= philo

SRCS	= $(shell find ./src -iname "*.c")
OBJS	= ${SRCS:.c=.o}

HEADERS	= -I ./include

CC = cc
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -g3
RM = rm -rf

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM)  $(NAME)

re: clean all

#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#
.PHONY: all, clean, fclean, re
.DEFAULT_GOAL = all
