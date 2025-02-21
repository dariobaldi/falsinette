# ============================================================================= #
# HELPERS									#
# ============================================================================= #

CC := cc
CFLAGS := -Wall -Werror -Wextra
CW := $(CC) $(CFLAGS) -o Executable
XCLEAN_FAIL := ./Executable && rm -f ./Executable || echo FAILED

.PHONY: help
help:
	@echo '*** Commands:'
	@sed -n 's/^##//p' ${MAKEFILE_LIST} | column -t -s ':' | sed -e 's/^/ /'

.PHONY: confirm
confirm:
	@echo -n "Are you sure? [y/N] " && read ans && [ $${ans:-N} = y ]


# ============================================================================= #
# TEST										#
# ============================================================================= #

## c00 : Run all tests for C00 project
.PHONY: c00
c00:
	@echo "\n******   Projet C00  ******"
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../c00 || echo "FAILED the Norme"
	@echo "\n** EX00: ft_putchar"
	@$(CW) ./c00/ex00.c ../c00/ex00/ft_putchar.c && $(XCLEAN_FAIL)
	@echo "\n** EX01: ft_print_alphabet"
	@$(CW) ./c00/ex01.c ../c00/ex01/ft_print_alphabet.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX02: ft_print_reverse_alphabet"
	@$(CW) ./c00/ex02.c ../c00/ex02/ft_print_reverse_alphabet.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX03:  ft_print_numbers"
	@$(CW) ./c00/ex03.c ../c00/ex03/ft_print_numbers.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX04: ft_is_negative"
	@$(CW) ./c00/ex04.c ../c00/ex04/ft_is_negative.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX05: ft_print_comb"
	@$(CW) ./c00/ex05.c ../c00/ex05/ft_print_comb.c && $(XCLEAN_FAIL)
	@echo "<- (!) Here there should be no line return"
	@echo "\n\n** EX06: ft_print_comb2"
	@$(CW) ./c00/ex06.c ../c00/ex06/ft_print_comb2.c && $(XCLEAN_FAIL)
	@echo "<- (!) Here there should be no line return"
	@echo "\n\n** EX07: ft_putnbr"
	@$(CW) ./c00/ex07.c ../c00/ex07/ft_putnbr.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX08: ft_putnbr"
	@cc -Wall -Werror -Wextra -oExe ./c00/ex08.c ../c00/ex08/ft_print_combn.c && ./Exe && rm -f ./Exe
	@echo "<- (!) Here there should be no line return"
	@echo ""


## c01 : Run all tests for C01 project
.PHONY: c01
c01:
	@echo "\n******   Projet C01 : Pointers  ******"
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../c01 || echo "FAILED the Norme"
	@echo "\n** EX00: ft_ft"
	@$(CW) ./c01/ex00.c ../c01/ex00/ft_ft.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX01: ft_ultimate_ft"
	@$(CW) ./c01/ex01.c ../c01/ex01/ft_ultimate_ft.c && $(XCLEAN_FAIL)
	@echo ""
	

## test : test current exo
.PHONY: test
test:
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../c01 || echo "FAILED the Norme"
	@echo "\n\n** EX01: ft_ultimate_ft"
	@$(CW) ./c01/ex01.c ../c01/ex01/ft_ultimate_ft.c && $(XCLEAN_FAIL)
	@echo ""
