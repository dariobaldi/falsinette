# ============================================================================= #
# HELPERS									#
# ============================================================================= #

CC := cc
CFLAGS := -Wall -Werror -Wextra
CW := $(CC) $(CFLAGS) -o Executable
VCW := $(CC) $(CFLAGS) -g -o Executable
XCLEAN_FAIL := ./Executable && rm -f ./Executable || echo FAILED
VXCLEAN_FAIL := valgrind ./Executable && rm -f ./Executable || echo FAILED

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

## C00 : Run all tests for C00 project
.PHONY: C00
C00:
	@echo "\n******   Projet C00  ******"
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../C00 || echo "FAILED the Norme"
	@echo "\n** EX00: ft_putchar"
	@$(CW) ./C00/ex00.c ../C00/ex00/ft_putchar.c && $(XCLEAN_FAIL)
	@echo "\n** EX01: ft_print_alphabet"
	@$(CW) ./C00/ex01.c ../C00/ex01/ft_print_alphabet.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX02: ft_print_reverse_alphabet"
	@$(CW) ./C00/ex02.c ../C00/ex02/ft_print_reverse_alphabet.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX03:  ft_print_numbers"
	@$(CW) ./C00/ex03.c ../C00/ex03/ft_print_numbers.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX04: ft_is_negative"
	@$(CW) ./C00/ex04.c ../C00/ex04/ft_is_negative.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX05: ft_print_comb"
	@$(CW) ./C00/ex05.c ../C00/ex05/ft_print_comb.c && $(XCLEAN_FAIL)
	@echo "<- (!) Here there should be no line return"
	@echo "\n\n** EX06: ft_print_comb2"
	@$(CW) ./C00/ex06.c ../C00/ex06/ft_print_comb2.c && $(XCLEAN_FAIL)
	@echo "<- (!) Here there should be no line return"
	@echo "\n\n** EX07: ft_putnbr"
	@$(CW) ./C00/ex07.c ../C00/ex07/ft_putnbr.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX08: ft_putnbr"
	@cc -Wall -Werror -Wextra -oExe ./C00/ex08.c ../C00/ex08/ft_print_combn.c && ./Exe && rm -f ./Exe
	@echo "<- (!) Here there should be no line return"
	@echo ""


## C01 : Run all tests for C01 project
.PHONY: C01
C01:
	@echo "\n******   Projet C01 : Pointers  ******"
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../C01 || echo "FAILED the Norme"
	@echo "\n** EX00: ft_ft"
	@$(CW) ./C01/ex00.c ../C01/ex00/ft_ft.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX01: ft_ultimate_ft"
	@$(CW) ./C01/ex01.c ../C01/ex01/ft_ultimate_ft.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX02: ft_swap"
	@$(CW) ./C01/ex02.c ../C01/ex02/ft_swap.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX03: ft_div_mod"
	@$(CW) ./C01/ex03.c ../C01/ex03/ft_div_mod.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX04: ft_ultimate_div_mod"
	@$(CW) ./C01/ex04.c ../C01/ex04/ft_ultimate_div_mod.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX05: ft_putstr"
	@$(CW) ./C01/ex05.c ../C01/ex05/ft_putstr.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX06: ft_strlen"
	@$(CW) ./C01/ex06.c ../C01/ex06/ft_strlen.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX07: ft_rev_int_tab"
	@$(CW) ./C01/ex07.c ../C01/ex07/ft_rev_int_tab.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX08: ft_sort_int_tab"
	@$(CW) ./C01/ex08.c ../C01/ex08/ft_sort_int_tab.c && $(XCLEAN_FAIL)
	@echo ""

## C02 : Run all tests for C02 project
.PHONY: C02
C02:
	@echo "\n******   Projet C02 : string manipulation  ******"
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../C02 || echo "FAILED the Norme"
	@echo "\n** EX00: ft_strcpy"
	@$(CW) ./C02/ex00.c ../C02/ex00/ft_strcpy.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX01: ft_strncpy"
	@$(CW) ./C02/ex01.c ../C02/ex01/ft_strncpy.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX02: ft_str_is_alpha"
	@$(CW) ./C02/ex02.c ../C02/ex02/ft_str_is_alpha.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX03: ft_str_is_numeric"
	@$(CW) ./C02/ex03.c ../C02/ex03/ft_str_is_numeric.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX04: ft_str_is_lowercase"
	@$(CW) ./C02/ex04.c ../C02/ex04/ft_str_is_lowercase.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX05: ft_str_is_uppercase"
	@$(CW) ./C02/ex05.c ../C02/ex05/ft_str_is_uppercase.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX06: ft_str_is_printable"
	@$(CW) ./C02/ex06.c ../C02/ex06/ft_str_is_printable.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX07: ft_strupcase"
	@$(CW) ./C02/ex07.c ../C02/ex07/ft_strupcase.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX08: ft_strlowcase"
	@$(CW) ./C02/ex08.c ../C02/ex08/ft_strlowcase.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX09: ft_strcapitalize"
	@$(CW) ./C02/ex09.c ../C02/ex09/ft_strcapitalize.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX10: ft_strlcpy"
	@$(CW) ./C02/ex10.c ../C02/ex10/ft_strlcpy.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX11: ft_putstr_non_printable"
	@$(CW) ./C02/ex11.c ../C02/ex11/ft_putstr_non_printable.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX12: ft_print_memory"
	@$(CW) ./C02/ex12.c ../C02/ex12/ft_print_memory.c && $(XCLEAN_FAIL)
	@echo ""

## C03 : Run all tests for C03 project
.PHONY: C03
C03:
	@echo "\n******   Projet C03 : string manipulation 2  ******"
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../C03 || echo "FAILED the Norme"
	@echo "\n\n** EX00: ft_strcmp"
	@$(CW) ./C03/ex00.c ../C03/ex00/ft_strcmp.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX01: ft_strncmp"
	@$(CW) ./C03/ex01.c ../C03/ex01/ft_strncmp.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX02: ft_strcat"
	@$(CW) ./C03/ex02.c ../C03/ex02/ft_strcat.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX03: ft_strncat"
	@$(CW) ./C03/ex03.c ../C03/ex03/ft_strncat.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX04: ft_strstr"
	@$(CW) ./C03/ex04.c ../C03/ex04/ft_strstr.c && $(XCLEAN_FAIL)
	@echo ""
	
## test : test current exo
.PHONY: test
test:
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../C03 || echo "FAILED the Norme"
	@echo "\n\n** EX04: ft_strstr"
	@$(CW) ./C03/ex04.c ../C03/ex04/ft_strstr.c && $(XCLEAN_FAIL)
	@echo ""
