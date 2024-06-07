NAME				=	miniRT

include config/srcs.mk

SRC_PATH			=	srcs/
SRC_BONUS_PATH		=	srcs_bonus/

OBJS				=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS))
OBJS_BONUS			=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS_BONUS))

DEPS				=	$(patsubst %.c, $(DIR_BUILD)%.d, $(SRCS))
DEPS_BONUS			=	$(patsubst %.c, $(DIR_BUILD)%.d, $(SRCS_BONUS))

OBJS_TEST			=	$(patsubst %.c, $(DIR_BUILD)%.o, $(TEST))
DIR_BUILD			=	.build/
DEPS_FLAGS			=	-MMD -MP
BASE_CFLAGS			=	-Wall -Werror -Wextra -O2 -g3
BASE_DEBUG_CFLAGS	=	-g3
DEBUG_CLFAGS		=	$(BASE_DEBUG_CFLAGS) -fsanitize=address #-fsanitize=thread
# DEBUG_CLFAGS		=	$(BASE_DEBUG_CFLAGS) -fsanitize=memory -fsanitize-memory-track-origins
FLAGS				=	$(BASE_CFLAGS)
RM					=	rm -rf
AR					=	ar rcs
CC					=	cc

MINILIBX_PATH		=	mlx/
MINILIBX_INCLUDES	=	$(MINILIBX_PATH)
MINILIBX_L			=	-L $(MINILIBX_PATH) -l mlx
MINILIBX_A			=	$(MINILIBX_PATH)libmlx.a
MAKE_MINILIBX		=	$(MAKE) -C $(MINILIBX_PATH)

GEOMETRY_PATH		=	geometry/
GEOMETRY_INCLUDES	=	$(GEOMETRY_PATH)
GEOMETRY_L			=	-L $(GEOMETRY_PATH) -l geometry
GEOMETRY_A			=	$(GEOMETRY_PATH)libgeometry.a
MAKE_GEOMETRY		=	$(MAKE) -C $(GEOMETRY_PATH)

VECTOR_PATH			=	vector/
VECTOR_INCLUDES		=	$(VECTOR_PATH)
VECTOR_L			=	-L $(VECTOR_PATH) -l vector
VECTOR_A			=	$(VECTOR_PATH)libvector.a
MAKE_VECTOR			=	$(MAKE) -C $(VECTOR_PATH)


LIBFT_PATH			=	libft/
LIBFT_INCLUDES		=	$(LIBFT_PATH)
LIBFT_L				=	-L	$(LIBFT_PATH) -l ft
LIBFT_A				=	$(LIBFT_PATH)libft.a
MAKE_LIBFT			= 	$(MAKE) -C $(LIBFT_PATH)



DIR_INCS =					\
	includes/				\
	$(LIBFT_INCLUDES) 		\
	$(MINILIBX_INCLUDES) 	\
	$(VECTOR_INCLUDES) 		\
	$(GEOMETRY_INCLUDES)

INCLUDES =					\
	$(addprefix -I , $(DIR_INCS))

LIBS = 						\
	$(MINILIBX_L)			\
	$(VECTOR_L) 			\
	$(GEOMETRY_L) 			\
	$(LIBFT_L) 				\
	-lm 					\
	-lXext					\
	-lX11					\
	-lpthread

DEPENDENCIES =				\
	$(MINILIBX_A) 			\
	$(GEOMETRY_A) 			\
	$(VECTOR_A) 			\
	$(LIBFT_A)


all:
	$(MAKE_MINILIBX)
	$(MAKE_VECTOR)
	$(MAKE_GEOMETRY)
	$(MAKE_LIBFT)
	$(MAKE) $(NAME)

bonus:
	$(MAKE_MINILIBX)
	$(MAKE_VECTOR)
	$(MAKE_GEOMETRY)
	$(MAKE_LIBFT)
	$(MAKE) $(NAME) SRC_PATH="$(SRC_BONUS_PATH)" OBJS="$(OBJS_BONUS)" SRCS="$(SRCS_BONUS)" DEPS="$(DEPS_BONUS)"

test:	$(OBJS_TEST)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS_TEST) $(LIBS) -o $(NAME)


$(NAME):	$(OBJS) $(DEPENDENCIES)
	$(CC) $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)


clean:
			$(RM) $(DIR_BUILD)


fclean:	clean
			$(RM) $(NAME)


ffclean: fclean
			$(MAKE_VECTOR) 		fclean
			$(MAKE_GEOMETRY) 	ffclean
			$(MAKE_MINILIBX) 	clean
			$(MAKE_LIBFT)		fclean


debug:
			$(MAKE) -j FLAGS="$(DEBUG_CLFAGS)"


re:		fclean
			$(MAKE) all


rre:	ffclean
			$(MAKE) all


norm:
	norminette srcs vector geometry includes libft srcs_bonus

.PHONY: all bonus test debug clean fclean ffclean re rre norm

-include $(DEPS)
$(DIR_BUILD)%.o : $(SRC_PATH)%.c
			@mkdir -p $(shell dirname $@)
			$(CC) $(FLAGS) $(DEPS_FLAGS) $(INCLUDES) -c $< -o $@
