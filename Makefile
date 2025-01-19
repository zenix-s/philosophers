#------------------------------------------------------------------------------#
#                                COLORS                                        #
#------------------------------------------------------------------------------#
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m

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
	@echo -e "${BLUE} ◎ $(YELLOW)Compiling  ${RED}→  $(GREEN)$< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) -o $(NAME)
	@echo -e "\n ${BLUE}◎ ${GREEN}$(NAME) has been created successfully!${DEF_COLOR}"

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@echo -e " ${BLUE}◎ ${RED}Objects files have been removed!${DEF_COLOR}\n"

fclean: clean
	@$(RM)  $(NAME)
	@echo -e " ${BLUE}◎ ${RED}$(NAME) has been removed!${DEF_COLOR}\n"

re: fclean all

#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#
.PHONY: all, clean, fclean, re
.DEFAULT_GOAL = all
