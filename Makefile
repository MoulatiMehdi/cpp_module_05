RM  = rm 
CXX = c++

RMFLAGS  = -rf 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -Wshadow

DEPS =  Bureaucrat.hpp AForm.hpp ./ShrubberyCreationForm.hpp ./RobotomyRequestForm.hpp ./PresidentialPardonForm.hpp ./Intern.hpp 
SRCS =  $(DEPS:.hpp=.cpp) main.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = run 

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ 

%.o : %.c $(DEPS)
	$(CXX) $(CXXFLAGS) -c  $< -o $@

clean : 
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean 
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all 

.PHONY : re fclean clean all 
