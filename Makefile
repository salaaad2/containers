default: all
#==============================================================================#
#--------------------------------- SHELL --------------------------------------#
#==============================================================================#
SHELL			:= /bin/sh
#==============================================================================#
#------------------------------ DIRECTORIES -----------------------------------#
#==============================================================================#
INCS_DIR		 = include/
SRCS_DIR		 = src/
OBJS_DIR		 = obj/
#==============================================================================#
#--------------------------------- FILES --------------------------------------#
#==============================================================================#
SRCS_NAME		  = containers
SRCS_NAME		  += list
SRCS_NAME		  += vector
SRCS_NAME		  += map
#------------------------------------------------------------------------------#
SRCS			 = $(addprefix ${SRCS_DIR}, $(addsuffix .cpp, ${SRCS_NAME}))
#------------------------------------------------------------------------------#
INCS			 = ${INCS_DIR}containers.hpp
INCS			+= ${INCS_DIR}list.hpp
#------------------------------------------------------------------------------#
OBJS			 = $(patsubst ${SRCS_DIR}%.cpp,${OBJS_DIR}%.o,${SRCS})
#------------------------------------------------------------------------------#
NAME			 = containers
#------------------------------------------------------------------------------#
#==============================================================================#
#-------------------------------- COMPILER ------------------------------------#
#==============================================================================#
CC				 = clang++
CFLAGS			+= -Wall
CFLAGS			+= -Wextra
CFLAGS			+= -Werror
CFLAGS			+= -pedantic
#--------------------------------- UNIX ---------------------------------------#
#==============================================================================#
RM				= rm -rf
MKDIR			= mkdir -p
#==============================================================================#
#--------------------------------- RULES --------------------------------------#
#==============================================================================#
${OBJS_DIR}%.o:	${SRCS_DIR}%.cpp
	${CC} -c ${CFLAGS} ${CDEFS} -o $@ $< ${LDFLAGS}
#------------------------------------------------------------------------------#
${OBJS_DIR}:
	${MKDIR} ${OBJS_DIR}
#------------------------------------------------------------------------------#
$(NAME): ${OBJS}
	${CC} ${CFLAGS} ${CDEFS} -o ${NAME} ${OBJS} ${LDFLAGS}
#------------------------------------------------------------------------------#
all: ${OBJS_DIR} ${NAME}
#------------------------------------------------------------------------------#
asan: CFLAGS += -g3
asan: CFLAGS += -fsanitize=address
asan: LFTRULE = asan
asan: all
#------------------------------------------------------------------------------#
msan: CFLAGS += -g3
msan: CFLAGS += -fsanitize=memory
msan: CFLAGS += -fsanitize-memory-track-origins
msan: CFLAGS += -fno-common
msan: CFLAGS += -fno-omit-frame-pointer
msan: LFTRULE = msan
msan: all
#------------------------------------------------------------------------------#

tags:
	ctags -e -R .
#------------------------------------------------------------------------------#
clean:
	${RM} ${OBJS_DIR} vgcore*
#------------------------------------------------------------------------------#
fclean: clean
	${RM} ${NAME} ${NAME}.core ${NAME}.dSYM/ valgrind.log
#------------------------------------------------------------------------------#
re: fclean run
#------------------------------------------------------------------------------#
run: clean all
	@echo "~running containers~"
	./containers
#------------------------------------------------------------------------------#
.PHONY:	all clean clean fclean re debug asan run
