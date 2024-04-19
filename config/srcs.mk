SRCS=			main.c \
				$(GEOMETRY_SRCS_PATH)$(GEOMETRY_SRCS) \
				$(TEST_SRCS) \
				$(INITS_SRCS) \
				$(RENDER_SRCS)

INITS_SRCS = inits/initializer.c

RENDER_SRCS = render_scene/render.c

TEST_SRCS = test_scene.c
