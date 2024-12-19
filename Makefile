NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
INCDIR = include

SRC = $(SRCDIR)/push_swap.c \
      $(SRCDIR)/chunk.c \
      $(SRCDIR)/control_center.c \
      $(SRCDIR)/control_center_utils.c \
      $(SRCDIR)/instruction.c \
      $(SRCDIR)/instruction2.c \
      $(SRCDIR)/instruction3.c \
      $(SRCDIR)/noeux.c \
      $(SRCDIR)/noeux_utils.c \
      $(SRCDIR)/sort_utils.c \
      $(SRCDIR)/sort.c

LIBFTDIR = libft-main
LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -I$(INCDIR) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(MAKE) clean -C $(LIBFTDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re