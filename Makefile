#=================== NAME ===================#
NAME = ft_ping

#================ COMPILATOR ================#
CC = cc

#=================== FLAGS ==================#

CFLAGS = -Wall -Werror -Wextra -g

#============= MANDATORY SOURCES ============#

SRCS = src/dns.c \
          src/main.c \
          src/packet.c \
          src/ping.c \
          src/print.c \
          src/signal.c \
          src/socket.c

#============ TRANSFORM .c TO .o ============#

OBJS=$(SRCS:.c=.o)

#============ Colors ========================#

white='\033[1;37m'
dark_green='\033[0;32m'

#================ UTILS PART ================#

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(dark_green)"Executable is ready"

clean: 
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re 