SRCS=			main.c \
				$(GEOMETRY_SRCS_PATH)$(GEOMETRY_SRCS) \
				$(TEST_SRCS) \
				$(INITS_SRCS) \
				$(RENDER_SRCS) \
				$(PARSING_SRCS) \
				$(GARBAGE_COLLECTION_SRCS)

INITS_SRCS = inits/initializer.c

RENDER_SRCS = render_scene/render.c \
				render_scene/light_calc.c \
				render_scene/ray_cast.c

TEST_SRCS = test_scene.c

PARSING_SRCS = /parsing/parsing.c \
				/parsing/utils.c \
				/parsing/close.c \
				/parsing/open.c \
				/parsing/read.c \
				/parsing/checks_init/ambiant_light.c \
				/parsing/checks_init/camera.c \
				/parsing/checks_init/light.c \
				/parsing/checks_init/sphere.c \
				/parsing/checks_init/plane.c \
				/parsing/checks_init/cylinder.c \

GARBAGE_COLLECTION_SRCS = garbage_collector/alloc.c \
							garbage_collector/free.c \
							garbage_collector/handler.c \
							garbage_collector/gc_functions/gc_split.c \
							garbage_collector/gc_functions/gc_strdup.c 