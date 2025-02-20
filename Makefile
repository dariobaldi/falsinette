# ============================================================================= #
# HELPERS	  																	#
# ============================================================================= #

.PHONY: help
help:
	@echo '*** Commands:'
	@sed -n 's/^##//p' ${MAKEFILE_LIST} | column -t -s ':' | sed -e 's/^/ /'

.PHONY: confirm
confirm:
	@echo -n "Are you sure? [y/N] " && read ans && [ $${ans:-N} = y ]


# ============================================================================= #
# DEVELOPMENT  																	#
# ============================================================================= #

## c00 : Run all tests for C00 project
.PHONY: c00
c00:
	@echo "\n******   Projet C00  ******"
	@echo "\n** Testing norminette"
	@norminette ../c00
	@echo "\n** EX00: ft_putchar"
	@cc -Wall -Werror -Wextra -oExe ./c00/ex00.c ../c00/ex00/ft_putchar.c && ./Exe && rm -f ./Exe
	@echo "\n** EX01: ft_print_alphabet"
	@cc -Wall -Werror -Wextra -oExe ./c00/ex01.c ../c00/ex01/ft_print_alphabet.c && ./Exe && rm -f ./Exe
	@echo "\n\n** EX02: ft_print_reverse_alphabet"
	@cc -Wall -Werror -Wextra -oExe ./c00/ex02.c ../c00/ex02/ft_print_reverse_alphabet.c && ./Exe && rm -f ./Exe
	@echo "\n\n** EX03:  ft_print_numbers"
	@cc -Wall -Werror -Wextra -oExe ./c00/ex03.c ../c00/ex03/ft_print_numbers.c && ./Exe && rm -f ./Exe
	@echo "\n\n** EX04: ft_is_negative"
	@cc -Wall -Werror -Wextra -oExe ./c00/ex04.c ../c00/ex04/ft_is_negative.c && ./Exe && rm -f ./Exe
	@echo "\n\n** EX05: ft_print_comb"
	@cc -Wall -Werror -Wextra -oExe ./c00/ex05.c ../c00/ex05/ft_print_comb.c && ./Exe && rm -f ./Exe
	@echo "<- (!) Here there should be no line return"
	@echo "\n\n** EX06: ft_print_comb2"
	@cc -Wall -Werror -Wextra -oExe ./c00/ex06.c ../c00/ex06/ft_print_comb2.c && ./Exe && rm -f ./Exe
	@echo "<- (!) Here there should be no line return"
	@echo "\n\n** EX07: ft_putnbr"
	@cc -Wall -Werror -Wextra -oExe ./c00/ex07.c ../c00/ex07/ft_putnbr.c && ./Exe && rm -f ./Exe
	@echo ""


## test : test current exo
.PHONY: test
test:
	@echo "\n** Testing norminette"
	# @norminette ../c00
	@echo "\n\n** EX08: ft_putnbr"
	@cc -Wall -Werror -Wextra -oExe ./c00/ex08.c ../c00/ex08/ft_print_combn.c && ./Exe && rm -f ./Exe
	@echo ""
