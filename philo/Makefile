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

SRCS	= ./src/main.c \
          ./src/philosopher/philosopher_sleep_state.c \
          ./src/philosopher/philosopher_eat_state.c \
          ./src/philosopher/philosopher_routine.c \
          ./src/shared/has_eaten_required_meals.c \
          ./src/shared/is_even.c \
          ./src/shared/print_log.c \
          ./src/shared/timediff.c \
          ./src/shared/timestamp.c \
          ./src/shared/to_uint64.c \
          ./src/shared/is_philo_dead.c \
          ./src/state_machine/set_machine_error.c \
          ./src/state_machine/state_machine_factory.c \
          ./src/states/create_forks_state.c \
          ./src/states/destroy_simulation_state.c \
          ./src/states/error/error_state.c \
          ./src/states/global/create_global_state.c \
          ./src/states/monitor_simulation_state.c \
          ./src/states/start_simulation_state.c \
          ./src/states/validation/validate_arguments_state.c \
          ./src/states/create_philosophers_state.c \
          ./src/states/join_threads_state.c \

OBJS	= ${SRCS:.c=.o}

HEADERS	= -I ./include

CC = cc
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -g3
RM = rm -rf

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#
%.o: %.c
	@echo -e "$(YELLOW) ◎ Compiling $(GREEN)$< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) -o $(NAME)
	@echo -e "\n $(GREEN)◎ $(NAME) has been created successfully!$(DEF_COLOR)"

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@echo -e " $(RED)◎ Objects files have been removed!$(DEF_COLOR)"

fclean: clean
	@$(RM)  $(NAME)
	@echo -e " $(RED)◎ $(NAME) has been removed!$(DEF_COLOR)\n"

re: fclean all

#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#
.PHONY: all, clean, fclean, re
.DEFAULT_GOAL = all
