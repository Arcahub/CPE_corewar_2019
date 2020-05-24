##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## Makefile to build test champions
##

AS = ./asm

SRC = \
	./src/aff.s \
	./src/circular.s \
	./src/overrider.s \

src2cor = ./$(patsubst %.s,%.cor,$(notdir $(1)))

COR = $(foreach path,$(SRC),$(call src2cor,$(path)))

all: $(COR)

%.cor: ./src/%.s
	$(AS) $<

clean:
	rm -rf $(COR)

fclean: clean

re: fclean all
