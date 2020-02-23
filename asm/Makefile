##
## EPITECH PROJECT, 2019
## bootstap_runner
## File description:
## Makefile
##

CC = gcc

FILES = $(shell find ./src/ -iname "*.c")

SRC = $(FILES:./src/%=src/%)

LIBS_DIR = $(shell find ./lib/ -type d -name "my*")

LIB_NAME = $(LIB:./lib/%=%)

BUILD_DIR = build/

OBJ = $(addprefix $(BUILD_DIR), $(SRC:.c=.o))

RMD_FILES = $(OBJ) vgcore.* lib/my_graph/*.o lib/my/*.o

NAME = asm

CFLAGS += $(LDFLAGS) $(HEADER) -W -Wall -Wno-unused-parameter -Wextra -pedantic $(DEBUG)

LDFLAGS = -L./lib $(LIBS)

LIBS = $(foreach LIB, $(LIBS_DIR), $(addprefix -l, $(LIB_NAME)))

HEADER = -I./include -I../include

REDDARK	=	\033[31;1m
RED	=	\033[31;1m
GREEN	=	\033[32;1m
YEL	=	\033[33;1m
BLUE	=	\033[34;1m
PINK	=	\033[35;1m
CYAN	=	\033[36;1m
WHITE	=	\033[0m

all : $(NAME)

debug:
	$(eval CFLAGS += -g3)
	@printf "$(PINK)[DEBUG]$(WHITE)\n"
	@make BLUE='\033[35;1m' DEBUG='-g3' -s fclean $(NAME)

$(BUILD_DIR)%.o:%.c
	@mkdir -p `dirname  $@`
	@printf "$(GREEN)[$(WHITE)ASM$(GREEN)] — $(BLUE)%-70s" $@
	@printf "$(GREEN)[$(WHITE)√$(GREEN)]\n$(WHITE)"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : make_lib start_compil $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@printf "\n$(GREEN) → Successfully build.  "
	@printf "$(BLUE) Binary :$(CYAN) $(NAME)\n\n$(WHITE)"

start_compil:
	@printf "\n$(GREEN)[$(WHITE)ASM$(GREEN)] — START BUILD\n\n"

make_lib :
	@printf "\n$(GREEN)[$(WHITE)LIB$(GREEN)] — $(YEL)BUILDING LIBS\n\n"
	@$(foreach LIB, $(LIBS_DIR), \
	printf "$(GREEN)[$(WHITE)LIB$(GREEN)] — $(YEL)BUILDING %-67s" $(LIB_NAME) \
	&& make -sC $(LIB) \
	&& printf "$(YEL)[$(WHITE)√$(YEL)]\n$(WHITE)";)
	@printf "\n"

doc :
	@doxygen doxyconf
	@printf "\n$(GREEN)[$(WHITE)LIB$(GREEN)] — $(PURPLE)CREATE DOC$(WHITE)\n\n"

clean :
	@printf "$(REDDARK)\nCleaning build files of \
	$(GREEN)[$(WHITE)ASM$(GREEN)]\n\n"
	@printf "$(GREEN)[$(WHITE)ASM$(GREEN)] — $(RED)%-45s\n" $(OBJ)
	@printf "\n$(GREEN) → $(RED) Build clean.\n\n$(WHITE)"
	@rm -f $(RMD_FILES)

fclean :
	@printf "$(REDDARK)\nCleaning Repository \
	$(GREEN)[$(WHITE)ASM$(GREEN)] \n"
	@make -s clean
	@rm -rf $(BUILD_DIR)
	@printf "$(GREEN)[$(WHITE)ASM$(GREEN)] — $(RED)%-45s\n" $(BUILD_DIR)
	@rm -f $(NAME)
	@$(foreach LIB, $(LIBS_DIR), \
	rm -f $(addsuffix .a, $(addprefix lib/lib, $(LIB_NAME))) && \
	printf "$(GREEN)[$(WHITE)ASM$(GREEN)] — $(RED)%-45s\n" \
	$(addsuffix .a, $(addprefix lib/lib, $(LIB_NAME)));)
	@printf "$(GREEN)[$(WHITE)ASM$(GREEN)] — $(RED)%-45s\n" $(NAME)
	@printf "\n$(GREEN) → $(REDDARK) Repository clean.\n\n$(WHITE)"

re : fclean all