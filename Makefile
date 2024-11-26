#  
#  
# 
#                              
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := cube3d
CC        	:= clang
FLAGS    	:= -Wall -Wextra -Werror -g  #-fsanitize=address
MLX42   	:= MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -fsanitize=address
LIBMLX		:= MLX42/

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      src/cube3d.c \
						  src/player.c \
                          src/debug.c \
						  src/frees.c \
						  src/utils.c \
						  src/utils2.c \
						  src/utils3.c \
						  src/errors.c \
						  src/init.c \
						  src/extract_textures.c \
						  src/extract_colours.c \
						  src/extract_map.c \
                          Lib/ft_atoi.c \
                          Lib/ft_bzero.c \
                          Lib/ft_calloc.c \
                          Lib/ft_isalnum.c \
                          Lib/ft_isalpha.c \
                          Lib/ft_isascii.c \
                          Lib/ft_isdigit.c \
                          Lib/ft_isprint.c \
                          Lib/ft_itoa.c \
                          Lib/ft_lstadd_back_bonus.c \
                          Lib/ft_lstadd_front_bonus.c \
                          Lib/ft_lstclear_bonus.c \
                          Lib/ft_lstdelone_bonus.c \
                          Lib/ft_lstiter_bonus.c \
                          Lib/ft_lstlast_bonus.c \
                          Lib/ft_lstmap_bonus.c \
                          Lib/ft_lstnew_bonus.c \
                          Lib/ft_lstsize_bonus.c \
                          Lib/ft_memchr.c \
                          Lib/ft_memcmp.c \
                          Lib/ft_memcpy.c \
                          Lib/ft_memmove.c \
                          Lib/ft_memset.c \
                          Lib/ft_putchar_fd.c \
                          Lib/ft_putendl_fd.c \
                          Lib/ft_putnbr_fd.c \
                          Lib/ft_putstr_fd.c \
                          Lib/ft_split.c \
                          Lib/ft_strchr.c \
                          Lib/ft_strdup.c \
                          Lib/ft_striteri.c \
                          Lib/ft_strjoin.c \
                          Lib/ft_strlcat.c \
                          Lib/ft_strlcpy.c \
                          Lib/ft_strlen.c \
                          Lib/ft_strmapi.c \
                          Lib/ft_strncmp.c \
                          Lib/ft_strnstr.c \
                          Lib/ft_strrchr.c \
                          Lib/ft_strtrim.c \
                          Lib/ft_substr.c \
                          Lib/ft_tolower.c \
                          Lib/ft_toupper.c \
                          
OBJS        := $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

$(NAME) :    $(OBJS)
	@echo "$(GREEN)Compiling $(CLR_RMV)$(YELLOW)$(NAME) $(CLR_RMV)..."
	@$(CC) $(FLAGS) $(DEBUG_FLAGS) -lm $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created $(CLR_RMV)✔️"

# Default target
all :        $(NAME)

# Bonus target
bonus :      all

# Clean object files
clean :
	@$(RM) $(OBJS)
	@$(RM) $(SRC_DIR)/*.o $(LIB_DIR)/*.o
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objects ✔️"

# Clean everything (binary and objects)
fclean :     clean
	@$(RM) $(NAME)
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

# Rebuild everything
re :         fclean all

################################################################################
#                                PHONY TARGETS                               #
################################################################################

.PHONY :     all clean fclean re bonus



