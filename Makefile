# BASIC
CC = cc -g -pthread
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
GDB = gdb

# TESTING
VAL = valgrind --leak-check=full --track-origin=yes -g3
SANITIZE_THREAD = -fsanitize=thread
SANITIZE_ADDRESS = -fsanitize=address
HELGRIND = valgrind --tool=helgrind
DRD = valgrind --tool=drd

# COLORS
RESET			:= \033[0m
GREEN			=	\e[32m
CYAN			:= \33[1;36m
YELLOW			=	\e[033m
BLUE			=	\e[34m
WHITE			=	\e[00m
RED				:= \033[1;31m
BOLD			:= \033[1;1m

# PHILOSOPHERS
NAME = philo
SRCS =  check_args.c \
		main.c \
		routine.c \
		utils.c \
		time.c \
		threads.c \
		init.c \
		check.c

OBJSDIR = objects
OBJS = $(addprefix $(OBJSDIR)/,$(SRCS:.c=.o))

# MAKE RULES
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)$(BOLD)Creating executable...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)Executable created!$(RESET)"
	
$(OBJSDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)$(BOLD)Removing objects...$(RESET)"
	$(RM) $(OBJSDIR)
	@echo "$(YELLOW)$(BOLD)Objects removed!$(RESET)"

fclean: clean
	@echo "$(RED)$(BOLD)Removing executable...$(RESET)"
	$(RM) $(NAME)
	@echo "$(RED)$(BOLD)Executable removed!$(RESET)"

re: fclean all
	@echo "$(GREEN)$(BOLD)Recompiled successfully!$(RESET)"

.SILENT:
