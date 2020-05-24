##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## Makefile
##

all clean fclean re:
	@$(MAKE) $@ $(1) $(2) -sC ./asm/
	@$(MAKE) $@ $(1) $(2) -sC ./corewar
