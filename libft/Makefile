#		Sources & output variables	#
LIBFT 			= 	Libft.a
DIR_INCS		= 	./includes
DIR_LIBFT 		= 	./libft
DIR_PRINTF 		= 	./ft_printf
DIR_GNL 		= 	./get_next_line


LIBFT_SRC 		=	ft_memset.c					\
					ft_bzero.c					\
					ft_memcpy.c					\
					ft_memmove.c 				\
					ft_memchr.c					\
					ft_memcmp.c					\
					ft_strlen.c					\
					ft_isalpha.c 				\
					ft_isdigit.c				\
					ft_isalnum.c				\
					ft_isascii.c				\
					ft_isprint.c				\
					ft_toupper.c				\
					ft_tolower.c				\
					ft_strchr.c					\
					ft_strrchr.c				\
					ft_strncmp.c				\
					ft_strlcat.c				\
					ft_strnstr.c				\
					ft_atoi.c					\
					ft_strdup.c					\
					ft_strjoin.c 				\
					ft_strtrim.c				\
					ft_itoa.c					\
					ft_strmapi.c				\
					ft_putchar_fd.c				\
					ft_putstr_fd.c				\
					ft_putendl_fd.c				\
					ft_putnbr_fd.c				\
					ft_strlcpy.c				\
					ft_calloc.c					\
					ft_substr.c					\
					ft_split.c					\
					ft_striteri.c				\
					ft_lstnew_bonus.c			\
					ft_lstadd_front_bonus.c		\
					ft_lstadd_back_bonus.c		\
					ft_lstsize_bonus.c			\
					ft_lstlast_bonus.c			\
					ft_lstdelone_bonus.c		\
					ft_lstiter_bonus.c			\
					ft_lstclear_bonus.c			\
					ft_lstmap_bonus.c			\


PRINTF_SRC		=	ft_printf.c					\
					print_functions.c			\
					print_ptr.c					\

GNL_SRC			=	get_next_line.c				\
					get_next_line_utils.c		\


LIBFT_OBJ		=	$(addprefix $(DIR_LIBFT)/, $(LIBFT_SRC:.c=.o))
PRINTF_OBJ		=	$(addprefix $(DIR_PRINTF)/, $(PRINTF_SRC:.c=.o))
GNL_OBJ			=	$(addprefix $(DIR_GNL)/, $(GNL_SRC:.c=.o))

#		Compilation variables		#
CFLAGS			= 	-Wall -Wextra -Werror
CC 				= 	cc


#		Colors						#
COLOUR_GREEN	=	\033[0;32m
COLOUR_RED		=	\033[0;31m
COLOUR_BLUE		=	\033[0;34m
COLOR_PURPLE	=   \033[0;35m
COLOR_CYAN		=   \033[0;36m
COLOR_YELLOW	=	\033[0;33m
COLOUR_END		=	\033[0m


#		Rules						#

all : $(LIBFT)


$(LIBFT) : $(LIBFT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ)
	@echo "$(COLOUR_GREEN)[LIBFT] Libft Created !$(COLOUR_END)"
	ar rcs $(LIBFT) $(LIBFT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ)

-include $(OBJS:.o=.d)
$(DIR_LIBFT)/%.o : $(DIR_LIBFT)/%.c $(INC_LIBFT)
	@printf "$(COLOR_YELLOW)[LIBFT] Compiling $<$(COLOUR_END)\n"
	@$(CC) $(CFLAGS) -I$(DIR_INCS) -MMD -MP -c $< -o $@


-include $(OBJS:.o=.d)
$(DIR_PRINTF)/%.o : $(DIR_PRINTF)/%.c $(INC_PRINTF)
	@printf "$(COLOR_YELLOW)[FT_PRINTF] Compiling $<$(COLOUR_END)\n"
	@$(CC) $(CFLAGS) -I$(DIR_INCS) -MMD -MP -c $< -o $@

-include $(OBJS:.o=.d)
$(DIR_GNL)/%.o : $(DIR_GNL)/%.c $(INC_GNL)
	@printf "$(COLOR_YELLOW)[GNL] Compiling $<$(COLOUR_END)\n"
	@$(CC) $(CFLAGS) -I$(DIR_INCS) -MMD -MP -c $< -o $@


# start :
# 	@printf "$(COLOR_CYAN)  .____      .___  __________  ___________ ___________$(COLOUR_END)\n"
# 	@printf "$(COLOUR_BLUE)  |    |     |   | \______   \ \_   _____/ \__    ___/$(COLOUR_END)\n"
# 	@printf "$(COLOUR_GREEN)  |    |     |   |  |    |  _/  |    __)     |    |$(COLOUR_END)\n"
# 	@printf "$(COLOR_YELLOW)  |    |___  |   |  |    |   \  |     \      |    |$(COLOUR_END)\n"
# 	@printf "$(COLOUR_RED)  |_______ \ |___|  |______  /  \___  /      |____|$(COLOUR_END)\n"
# 	@printf "$(COLOR_CYAN)          \/               \/       \/$(COLOUR_END)\n\n"

clean :
	@echo "$(COLOUR_RED)[LIBFT] Cleaning object files$(COLOUR_END)"
	@rm -f $(LIBFT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ)

fclean : clean
	@echo "$(COLOUR_RED)[LIBFT] Cleaning library$(COLOUR_END)"
	@rm -f $(LIBFT) $(PRINTF) $(GNL)

re : fclean all

.PHONY : all clean fclean re
