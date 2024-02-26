NAME		= Simulator

SRC_DIR 	= src
SUBDIRS 	= Lexical_analyse CPU RAM ALU CU Structs_init
SRCDIRS 	:= $(addprefix $(SRC_DIR)/, $(SUBDIRS))
SRC			:= $(notdir $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cpp))) $(notdir $(SRC_DIR)/main.cpp)

OBJ_DIR 	= obj
OBJ			= $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

CC			= c++ -std=c++17 $(INCLUDES) $(CPP_CFLAGS) -g3
HEADERS 	= $(wildcard headers/*.hpp)
INCLUDES	= -Iheaders
CPP_CFLAGS	= #-Wall -Wextra -Werror
MK			= mkdir -p


all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR) :
		@$(MK) $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) Makefile
	$(CC) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.cpp $(HEADERS) Makefile
	$(CC) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	$(CC) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re