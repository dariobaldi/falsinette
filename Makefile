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
	@echo ""


