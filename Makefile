##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## Makefile
##

all:
	@make -sC ./asm/

debug:
	@make debug -sC ./asm

clean:
	@make clean -sC ./asm

fclean:
	@make fclean -sC ./asm

re:
	@make re -sC ./asm
