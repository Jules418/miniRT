NAME = libgeometry.a

include config/srcs.mk
SRC_PATH			=	srcs/
DIR_BUILD			=	.build/
OBJS				=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS))
DEPS				=	$(patsubst %.c, $(DIR_BUILD)%.d, $(SRCS))
DEPS_FLAGS			=	-MMD -MP
BASE_CFLAGS			=	-Wall -Werror -Wextra -O2 -pipe
BASE_DEBUG_CFLAGS	=	-g3
DEBUG_CLFAGS		=	$(BASE_DEBUG_CFLAGS) #-fsanitize=address
# DEBUG_CLFAGS		=	$(BASE_DEBUG_CFLAGS) -fsanitize=memory -fsanitize-memory-track-origins
FLAGS				=	$(BASE_CFLAGS)
RM					=	rm -rf
AR					=	ar rcs
CC					=	gcc

VECTOR_PATH			=	../vector/
VECTOR_INCLUDES		=	$(VECTOR_PATH)
VECTOR_L			=	-L $(VECTOR_PATH) -l vector
VECTOR_A			=	$(VECTOR_PATH)libvector.a
MAKE_VECTOR			=	$(MAKE) -C $(VECTOR_PATH)

DIR_INCS =\
	includes/\
	. \
	$(VECTOR_INCLUDES)

INCLUDES = \
	$(addprefix -I , $(DIR_INCS))

LIBS = \
	-lm \
	$(VECTOR_L)

DEPENDENCIES =\
	$(VECTOR_A)

.PHONY:		all
all:
			$(MAKE_VECTOR)
			$(MAKE) $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

.PHONY:	clean
clean:
			$(RM) $(DIR_BUILD)

.PHONY: cclean
cclean: clean
			$(MAKE_VECTOR) clean

.PHONY:	fclean
fclean:	clean
			$(RM) $(NAME)

.PHONY: ffclean
ffclean: fclean
			$(MAKE_VECTOR) fclean

.PHONY:	re
re:		fclean
			$(MAKE) all

.PHONY: rre
rre:	ffclean
			$(MAKE) all

-include $(DEPS)
$(DIR_BUILD)%.o : $(SRC_PATH)%.c Makefile
			@mkdir -p $(shell dirname $@)
			$(CC) $(FLAGS) $(DEPS_FLAGS) $(INCLUDES) -c $< -o $@