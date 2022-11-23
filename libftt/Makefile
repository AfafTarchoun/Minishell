NAME=libft.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SRC =  ft_striteri.c ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strmapi.c ft_substr.c ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c ft_calloc.c ft_isprint.c ft_memmove.c ft_putstr_fd.c ft_strlcat.c ft_strnstr.c ft_toupper.c ft_isalnum.c ft_itoa.c ft_memset.c ft_split.c ft_strlcpy.c ft_strrchr.c ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlen.c ft_strtrim.c
BONUS =	ft_lstiter_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstlast_bonus.c \
		ft_lstnew_bonus.c ft_lstsize_bonus.c
BONUS_OBJS = $(BONUS:.c=.o)
DEPS = libft.h
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
		$(RM) $(OBJ)
		$(RM) $(BONUS_OBJS)
fclean: clean
		$(RM) $(NAME)

re: fclean all
bonus:	$(BONUS_OBJS)
	ar rc $(NAME) $(BONUS_OBJS)
