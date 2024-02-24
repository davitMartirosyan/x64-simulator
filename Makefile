NAME = simulator
CPP = c++
CPP_FLAGS = -I headers/ -std=c++17 -Wall -Wextra -Werror
SRC  = $(wildcard src/*/*.cpp src/*.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPP_FLAGS) $(OBJ) -o $(NAME)


%.o : %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

fclean:
	rm -rf $(NAME) $(OBJ)

push:
	git add . && git commit -m "$(commit)" && git push
