##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## Makefile building the corewar virtual machine CLI
##

NAME = corewar
LIB_ROOT = ./libcorewar
CLI_ROOT = ./corewar-cli
CLI_PATH = $(CLI_ROOT)/$(NAME)

all: $(NAME)

$(NAME): $(CLI_PATH)
	@cp $(CLI_PATH) $(NAME)

$(CLI_PATH): $(LIB_ROOT)
	@$(MAKE) -sC $(CLI_ROOT)

clean:
	@$(MAKE) -sC $(CLI_ROOT) clean

fclean:
	@$(MAKE) -sC $(CLI_ROOT) fclean
	@rm -f $(NAME)

re: fclean all

tests_run:
	@$(MAKE) -sC $(LIB_ROOT) tests_run
	@$(MAKE) -sC $(CLI_ROOT) tests_run

.PHONY: all clean fclean re tests_run
