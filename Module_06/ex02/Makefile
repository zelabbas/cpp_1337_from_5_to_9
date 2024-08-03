NAME = real_type

FLAGS = -Wall -Wextra -Werror -std=c++98 

RM = rm -rf

COMPILE = c++ 

SRCS = main.cpp Base.cpp A.cpp C.cpp B.cpp Functions.cpp
OBJS = ${SRCS:.cpp=.o}

%.o : %.cpp Base.hpp Functions.hpp A.hpp B.hpp C.hpp
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