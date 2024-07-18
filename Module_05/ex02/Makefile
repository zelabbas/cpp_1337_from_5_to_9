NAME = form

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

COMPILE = c++ 

SRCS = Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}

%.o : %.cpp Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp
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