
SRCS = $(SPHERE_SRCS) \
		$(CYLINDER_SRCS) \
		$(PLANE_SRCS)\
		$(UTILS_SRCS)\
		$(RAY_SRCS) \
		$(CONE_SRCS)

SPHERE_SRCS = sphere/sphere.c

CYLINDER_SRCS = cylinder/cylinder.c \
				cylinder/cylinder_intersection.c

RAY_SRCS = ray/ray.c

PLANE_SRCS = plane/plane.c

CONE_SRCS = cone/cone.c \
			cone/cone_intersection.c

UTILS_SRCS = utils.c