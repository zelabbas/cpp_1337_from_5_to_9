NAME = serialization

FLAGS = -Wall -Wextra -Werror -std=c++98 

RM = rm -rf

COMPILE = c++ 

SRCS = Serializer.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}

%.o : %.cpp Serializer.hpp Data.hpp
	@${COMPILE} ${FLAGS} -c $< -o $@
	@echo "compilation file {$<} done 	✅"

all : ${NAME}

${NAME} : ${OBJS}
	@${COMPILE} ${OBJS} -o $@
	@echo "create file executable {$@} done 	✅"

clean :
	@${RM} ${OBJS}
	@echo "Delete files objects ${OBJS} Done	✅"

fclean : clean
	@${RM} ${NAME}
	@echo "Delete file executable ${NAME} Done 	✅"

re : fclean all