NAME = convert

FLAGS = -Wall -Wextra -Werror -std=c++98 

RM = rm -rf

COMPILE = c++ 

SRCS = ScalarConverter.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}

%.o : %.cpp ScalarConverter.hpp
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