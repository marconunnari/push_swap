NAME=checker
GCC=gcc -Wall -Wextra -Werror
DLIBFT=../libft
LIBFT=$(DLIBFT)/libft.a
LFT= -L $(DLIBFT) -lft
INCLUDES= -I includes -I ../includes -I $(DLIBFT)/includes
DOBJS=objs
DSRCS=srcs

SRCS_FILES= main parse_args print_stacks \
	swap push rotate reverse_rotate #new#

SRCS = $(addprefix $(DSRCS)/, $(addsuffix .c, $(SRCS_FILES)))
OBJS = $(SRCS:$(DSRCS)/%.c=$(DOBJS)/%.o)

all: $(NAME)

$(DOBJS):
	mkdir -p $(DOBJS)

libft:
	make -C $(DLIBFT)

$(OBJS): $(DOBJS)/%.o: $(DSRCS)/%.c
	$(GCC) $(INCLUDES) -c $< -o $@

$(NAME): libft $(DOBJS) $(OBJS)
	$(GCC) -o $(NAME) $(OBJS) $(LFT)

clean:
	make clean -C $(DLIBFT)
	rm -rf $(DOBJS)

fclean: clean
	make fclean -C $(DLIBFT)
	rm -f $(NAME)

re: fclean all
