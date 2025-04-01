# ============================================================================= #
# HELPERS									#
# ============================================================================= #
GREEN="'\033[38;5;84m'"
RED="'\033[38;5;197m'"
BLUE="'\033[38;5;45m'"
PURPLE="'\033[38;5;63m'"
PINK="'\033[38;5;207m'"
BLACK="'\033[38;5;0m'"
BG_GREEN="'\033[48;5;84m'"
BG_RED="'\033[48;5;197m'"
GREY="'\033[38;5;8m'"
BOLD="'\033[1m'"
DEFAULT="'\033[0m'"
CHECKMARK="'\xE2\x9C\x93'"

GOOD = printf "${BG_GREEN}${BOLD}${BLACK} GOOD ${DEFAULT}"
FAILED = printf "${BG_RED}${BOLD} FAILED ${DEFAULT}"
CC := cc
CFLAGS := -Wall -Werror -Wextra
CW := $(CC) $(CFLAGS) -o Executable
VCW := $(CC) $(CFLAGS) -g -o Executable
XCLEAN_FAIL := ./Executable && rm -f ./Executable || $(FAILED)
XCLEAN_FAIL_OK := ./Executable && $(GOOD) && rm -f ./Executable || $(FAILED)
VXCLEAN_FAIL := valgrind ./Executable && rm -f ./Executable || $(FAILED)

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
	@norminette -R CheckForbiddenSourceHeader ../C00 && $(GOOD) || $(FAILED)
	@echo "\n\n** EX00: ft_putchar"
	@$(CW) ./C00/ex00.c ../C00/ex00/ft_putchar.c && ./Executable > ./diff.txt && diff ./diff.txt ./C00/diff00 && $(GOOD) && rm -f ./Executable ./diff.txt || $(FAILED)
	@echo "\n** EX01: ft_print_alphabet"
	@$(CW) ./C00/ex01.c ../C00/ex01/ft_print_alphabet.c && ./Executable > ./diff.txt && diff ./diff.txt ./C00/diff01 && $(GOOD) && rm -f ./Executable ./diff.txt || $(FAILED)
	@echo "\n\n** EX02: ft_print_reverse_alphabet"
	@$(CW) ./C00/ex02.c ../C00/ex02/ft_print_reverse_alphabet.c && ./Executable > ./diff.txt && diff ./diff.txt ./C00/diff02 && $(GOOD) && rm -f ./Executable ./diff.txt || $(FAILED)
	@echo "\n\n** EX03:  ft_print_numbers"
	@$(CW) ./C00/ex03.c ../C00/ex03/ft_print_numbers.c && ./Executable > ./diff.txt && diff ./diff.txt ./C00/diff03 && $(GOOD) && rm -f ./Executable ./diff.txt || $(FAILED)
	@echo "\n\n** EX04: ft_is_negative"
	@$(CW) ./C00/ex04.c ../C00/ex04/ft_is_negative.c && ./Executable > ./diff.txt && diff ./diff.txt ./C00/diff04 && $(GOOD) && rm -f ./Executable ./diff.txt || $(FAILED)
	@echo "\n\n** EX05: ft_print_comb"
	@$(CW) ./C00/ex05.c ../C00/ex05/ft_print_comb.c && ./Executable > ./diff.txt && diff ./diff.txt ./C00/diff05 && $(GOOD) && rm -f ./Executable ./diff.txt || $(FAILED)
	@echo "\n\n** EX06: ft_print_comb2"
	@$(CW) ./C00/ex06.c ../C00/ex06/ft_print_comb2.c && ./Executable > ./diff.txt && diff ./diff.txt ./C00/diff06 && $(GOOD) && rm -f ./Executable ./diff.txt || $(FAILED)
	@echo "\n\n** EX07: ft_putnbr"
	@$(CW) ./C00/ex07.c ../C00/ex07/ft_putnbr.c && ./Executable 2 > ./diff.txt && diff ./diff.txt ./C00/diff07 && $(GOOD) && rm -f ./Executable ./diff.txt || $(FAILED)
	@echo "\n\n** EX08: ft_print_combn"
	@$(CW) ./C00/ex08.c ../C00/ex08/ft_print_combn.c && ./Executable 2 > ./diff.txt && diff ./diff.txt ./C00/diff08_2 && $(GOOD) && rm -f ./Executable ./diff.txt || printf "${BG_RED}${BOLD} FAILED: n=2 ${DEFAULT}"
	@$(CW) ./C00/ex08.c ../C00/ex08/ft_print_combn.c && ./Executable 3 > ./diff.txt && diff ./diff.txt ./C00/diff08_3 && $(GOOD) && rm -f ./Executable ./diff.txt || printf "${BG_RED}${BOLD} FAILED: n=3 ${DEFAULT}"
	@$(CW) ./C00/ex08.c ../C00/ex08/ft_print_combn.c && ./Executable 7 > ./diff.txt && diff ./diff.txt ./C00/diff08_7 && $(GOOD) && rm -f ./Executable ./diff.txt || printf "${BG_RED}${BOLD} FAILED: n=7 ${DEFAULT}"
	@$(CW) ./C00/ex08.c ../C00/ex08/ft_print_combn.c && ./Executable 9 > ./diff.txt && diff ./diff.txt ./C00/diff08_9 && $(GOOD) && rm -f ./Executable ./diff.txt || printf "${BG_RED}${BOLD} FAILED: n=9 ${DEFAULT}"
	@echo ""


## C01 : Run all tests for C01 project
.PHONY: C01
C01:
	@echo "\n******   Projet C01 : Pointers  ******"
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../C01 && $(GOOD) || $(FAILED)
	@echo "\n\n** EX00: ft_ft"
	@$(CW) ./C01/ex00.c ../C01/ex00/ft_ft.c && $(XCLEAN_FAIL_OK)
	@echo "\n\n** EX01: ft_ultimate_ft"
	@$(CW) ./C01/ex01.c ../C01/ex01/ft_ultimate_ft.c && $(XCLEAN_FAIL_OK)
	@echo "\n\n** EX02: ft_swap"
	@$(CW) ./C01/ex02.c ../C01/ex02/ft_swap.c && $(XCLEAN_FAIL_OK)
	@echo "\n\n** EX03: ft_div_mod"
	@$(CW) ./C01/ex03.c ../C01/ex03/ft_div_mod.c && $(XCLEAN_FAIL_OK)
	@echo "\n\n** EX04: ft_ultimate_div_mod"
	@$(CW) ./C01/ex04.c ../C01/ex04/ft_ultimate_div_mod.c && $(XCLEAN_FAIL_OK)
	@echo "\n\n** EX05: ft_putstr"
	@$(CW) ./C01/ex05.c ../C01/ex05/ft_putstr.c && ./Executable > ./diff.txt && diff ./diff.txt ./C01/diff05 && $(GOOD) && rm -f ./Executable ./diff.txt || $(FAILED)
	@echo "\n\n** EX06: ft_strlen"
	@$(CW) ./C01/ex06.c ../C01/ex06/ft_strlen.c && $(XCLEAN_FAIL_OK)
	@echo "\n\n** EX07: ft_rev_int_tab"
	@$(CW) ./C01/ex07.c ../C01/ex07/ft_rev_int_tab.c && $(XCLEAN_FAIL_OK)
	@echo "\n\n** EX08: ft_sort_int_tab"
	@$(CW) ./C01/ex08.c ../C01/ex08/ft_sort_int_tab.c && $(XCLEAN_FAIL_OK)
	@echo ""

## C02 : Run all tests for C02 project
.PHONY: C02
C02:
	@echo "\n******   Projet C02 : string manipulation  ******"
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../C02 && $(GOOD) || $(FAILED)
	@echo "\n\n** EX00: ft_strcpy"
	@$(CW) ./C02/ex00.c ../C02/ex00/ft_strcpy.c && $(XCLEAN_FAIL_OK)
	@echo "\n\n** EX01: ft_strncpy"
	@$(CW) ./C02/ex01.c ../C02/ex01/ft_strncpy.c && $(XCLEAN_FAIL_OK)
	@echo "\n\n** EX02: ft_str_is_alpha"
	@$(CW) ./C02/ex02.c ../C02/ex02/ft_str_is_alpha.c && $(XCLEAN_FAIL_OK)
	@echo "\n\n** EX03: ft_str_is_numeric"
	@$(CW) ./C02/ex03.c ../C02/ex03/ft_str_is_numeric.c && $(XCLEAN_FAIL_OK)
	@echo "\n\n** EX04: ft_str_is_lowercase"
	@$(CW) ./C02/ex04.c ../C02/ex04/ft_str_is_lowercase.c && $(XCLEAN_FAIL_OK)
	@echo "\n\n** EX05: ft_str_is_uppercase"
	@$(CW) ./C02/ex05.c ../C02/ex05/ft_str_is_uppercase.c && $(XCLEAN_FAIL_OK)
	@echo "\n\n** EX06: ft_str_is_printable"
	@$(CW) ./C02/ex06.c ../C02/ex06/ft_str_is_printable.c && $(XCLEAN_FAIL_OK)
	@echo "\n\n** EX07: ft_strupcase"
	@$(CW) ./C02/ex07.c ../C02/ex07/ft_strupcase.c && $(XCLEAN_FAIL_OK)
	@echo "\n\n** EX08: ft_strlowcase"
	@$(CW) ./C02/ex08.c ../C02/ex08/ft_strlowcase.c && $(XCLEAN_FAIL_OK)
	@echo "\n\n** EX09: ft_strcapitalize"
	@$(CW) ./C02/ex09.c ../C02/ex09/ft_strcapitalize.c && $(XCLEAN_FAIL_OK)
	@echo "\n\n** EX10: ft_strlcpy"
	@$(CW) ./C02/ex10.c ../C02/ex10/ft_strlcpy.c && $(XCLEAN_FAIL_OK)
	@echo "\n\n** EX11: ft_putstr_non_printable"
	@$(CW) ./C02/ex11.c ../C02/ex11/ft_putstr_non_printable.c && ./Executable > ./diff.txt && diff ./diff.txt ./C02/diff11 && $(GOOD) && rm -f ./Executable ./diff.txt || $(FAILED)
	@echo "\n\n** EX12: ft_print_memory"
	@$(CW) ./C02/ex12.c ../C02/ex12/ft_print_memory.c && ./Executable && diff ./diff_expected ./diff_result && $(GOOD) && rm -f ./Executable ./diff_expected ./diff_result || $(FAILED) && rm -f ./Executable ./diff_expected ./diff_result
	@echo ""

## C03 : Run all tests for C03 project
.PHONY: C03
C03: confirm
	@echo "\n******   Projet C03 : string manipulation 2  ******"
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../C03 || $(FAILED)
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
	@echo "\n\n** EX05: ft_strlcat"
	@$(CW) ./C03/ex05.c ../C03/ex05/ft_strlcat.c -lbsd && $(XCLEAN_FAIL)
	@echo ""

## C04 : Run all tests for C04 project
.PHONY: C04
C04:
	@echo "\n******   Projet C04 : putnbr and atoi  ******"
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../C04 || $(FAILED)
	@echo "\n\n** EX00: ft_strlen"
	@$(CW) ./C04/ex00.c ../C04/ex00/ft_strlen.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX01: ft_putstr"
	@$(CW) ./C04/ex01.c ../C04/ex01/ft_putstr.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX02: ft_putnbr"
	@$(CW) ./C04/ex02.c ../C04/ex02/ft_putnbr.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX03: ft_atoi"
	@$(CW) ./C04/ex03.c ../C04/ex03/ft_atoi.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX04: ft_putnbr_base"
	@$(CW) ./C04/ex04.c ../C04/ex04/ft_putnbr_base.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX05: ft_atoi_base"
	@$(CW) ./C04/ex05.c ../C04/ex05/ft_atoi_base.c && $(XCLEAN_FAIL)
	@echo ""

## C05 : Run all tests for C05 project
.PHONY: C05
C05:
	@echo "\n******   Projet C05 : recursive functions ******"
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../C05 || $(FAILED)
	@echo "\n\n** EX00: ft_iterative_factorial"
	@$(CW) ./C05/ex00.c ../C05/ex00/ft_iterative_factorial.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX01: ft_recursive_factorial"
	@$(CW) ./C05/ex01.c ../C05/ex01/ft_recursive_factorial.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX02: ft_iterative_power"
	@$(CW) ./C05/ex02.c ../C05/ex02/ft_iterative_power.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX03: ft_recursive_power"
	@$(CW) ./C05/ex03.c ../C05/ex03/ft_recursive_power.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX04: ft_fibonacci"
	@$(CW) ./C05/ex04.c ../C05/ex04/ft_fibonacci.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX05: ft_sqrt"
	@$(CW) ./C05/ex05.c ../C05/ex05/ft_sqrt.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX06: ft_is_prime"
	@$(CW) ./C05/ex06.c ../C05/ex06/ft_is_prime.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX07: ft_find_next_prime"
	@$(CW) ./C05/ex07.c ../C05/ex07/ft_find_next_prime.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX08: ft_ten_queens_puzzle"
	@$(CW) ./C05/ex08.c ../C05/ex08/ft_ten_queens_puzzle.c && ./Executable > ./diff.txt && diff ./diff.txt ./C05/diff_ex08.txt && $(GOOD) && rm -f ./Executable ./diff.txt || $(FAILED)
	@echo ""	

## C06 : Run all tests for C05 project
.PHONY: C06
C06:
	@echo "\n******   Projet C06 : main arguments ******"
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../C06 || $(FAILED)
	@echo "\n\n** EX00: ft_print_program_name"
	@$(CW) ../C06/ex00/ft_print_program_name.c && ./Executable > ./diff.txt && diff ./diff.txt ./C06/diff_ex00.txt && echo "OK" && rm -f ./Executable ./diff.txt || $(FAILED)
	@echo "\n\n** EX01: ft_print_params"
	@$(CW) ../C06/ex01/ft_print_params.c && ./Executable test1 test2 test 3 > ./diff.txt && diff ./diff.txt ./C06/diff_ex01.txt && echo "OK" && rm -f ./Executable ./diff.txt || $(FAILED)
	@echo "\n\n** EX02: ft_rev_params"
	@$(CW) ../C06/ex02/ft_rev_params.c && ./Executable test1 test2 test 3 > ./diff.txt && diff ./diff.txt ./C06/diff_ex02.txt && echo "OK" && rm -f ./Executable ./diff.txt || $(FAILED)
	@echo "\n\n** EX03: ft_sort_params"
	@$(CW) ../C06/ex03/ft_sort_params.c && ./Executable abcd ab a abc test1 test2 test 3 > ./diff.txt && diff ./diff.txt ./C06/diff_ex03.txt && echo "OK" && rm -f ./Executable ./diff.txt || $(FAILED)
	@echo ""

## C07 : Run all tests for C05 project
.PHONY: C07
C07:
	@echo "\n******   Projet C07 : malloc and free ******"
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../C07 || $(FAILED)
	@echo "\n\n** EX00: ft_strdup"
	@$(CW) ./C07/ex00.c ../C07/ex00/ft_strdup.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX01: ft_range"
	@$(CW) ./C07/ex01.c ../C07/ex01/ft_range.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX02: ft_ultimate_range"
	@$(CW) ./C07/ex02.c ../C07/ex02/ft_ultimate_range.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX03: ft_strjoin"
	@$(CW) ./C07/ex03.c ../C07/ex03/ft_strjoin.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX04: ft_convert_base"
	@$(CW) ./C07/ex04.c && $(XCLEAN_FAIL)
	@echo "\n\n** EX07: ft_split"
	@$(CW) ../C07/ex05/ft_split.c ./C07/ex05.c && ./Executable && printf "${BG_GREEN}${BOLD}${BLACK} GOOD ${DEFAULT}" && rm -f ./Executable || printf "${BG_RED}${BOLD} FAILED ${DEFAULT}"
	@echo ""

## C08 : Run all tests for C05 project
.PHONY: C08
C08:
	@echo "\n******   Projet C08 : malloc and free ******"
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../C08 || $(FAILED)
	@echo "\n\n** EX00: ft.h"
	@cp ../C08/ex00/ft.h ./C08/ft.h || echo "FAILED copying ft.h file"
	@$(CW) ./C08/ex00.c && $(XCLEAN_FAIL)
	@rm -f ./C08/ft.h || echo "FAILED removing ft.h file"
	@echo "\n\n** EX01: ft_boolean"
	@cp ../C08/ex01/ft_boolean.h ./C08/ex01/ft_boolean.h || echo "FAILED copying ft.h file"
	@$(CW) ./C08/ex01/main.c
	@./Executable > test1.diff && diff ./test1.diff ./C08/ex01/test1.diff && $(GOOD): no arguments && rm -f ./test1.diff || printf "${BG_RED}${BOLD} FAILED: no arguments ${DEFAULT}"
	@./Executable arg1 > test2.diff && diff ./test2.diff ./C08/ex01/test2.diff && $(GOOD): 1 argument && rm -f ./test2.diff || printf "${BG_RED}${BOLD} FAILED: 1 argument ${DEFAULT}"
	@./Executable arg1 arg2 > test3.diff && diff ./test3.diff ./C08/ex01/test3.diff && $(GOOD): 2 arguments && rm -f ./test3.diff || printf "${BG_RED}${BOLD} FAILED: 2 arguments ${DEFAULT}"
	@rm -f ./C08/ex01/ft_boolean.h ./Executable || echo "FAILED removing ft_boolean files"
	@echo "\n\n** EX02: ft_abs.h"
	@cp ../C08/ex02/ft_abs.h ./C08/ex02/ft_abs.h || echo "FAILED copying ft_abs.h file"
	@$(CW) ./C08/ex02/main.c
	@./Executable 42 > test1.diff && diff ./test1.diff ./C08/ex02/test.diff && $(GOOD): positive number && rm -f ./test1.diff || printf "${BG_RED}${BOLD} FAILED: positive number ${DEFAULT}"
	@./Executable -42 > test2.diff && diff ./test2.diff ./C08/ex02/test.diff && $(GOOD): negative number && rm -f ./test2.diff || printf "${BG_RED}${BOLD} FAILED: negative number ${DEFAULT}"
	@rm -f ./C08/ex02/ft_abs.h ./Executable || echo "FAILED removing ft_abs files"
	@echo "\n\n** EX03: ft_point.h"
	@cp ../C08/ex03/ft_point.h ./C08/ex03/ft_point.h || echo "FAILED copying ft_point.h file"
	@$(CW) ./C08/ex03/main.c && $(XCLEAN_FAIL_OK)
	@rm -f ./C08/ex03/ft_point.h || echo "FAILED removing ft_point.h"
	@echo "\n\n** EX04: ft_strs_to_tab"
	@cp ../C08/ex04/ft_strs_to_tab.c ./C08/ex04/ft_strs_to_tab.c || echo "FAILED copying ft_strs_to_tab.c file"
	@$(CW) ./C08/ex04/*.c && ./Executable test coso cuestion > ./diff.txt && diff ./diff.txt ./C08/ex05/diff_ex05.txt && $(GOOD) && rm -f ./Executable ./diff.txt || printf "${BG_RED}${BOLD} FAILED ${DEFAULT}"
	@rm -f ./C08/ex04/ft_strs_to_tab.c || echo "FAILED removing ft.h file"
	@echo "\n\n** EX05: ft_show_tab.c"
	@cp ../C08/ex05/ft_show_tab.c ./C08/ex05/ft_show_tab.c || echo "FAILED copying ft_strs_to_tab.c file"
	@$(CW) ./C08/ex05/*.c && ./Executable test coso cuestion > ./diff.txt && diff ./diff.txt ./C08/ex05/diff_ex05.txt && $(GOOD) && rm -f ./Executable ./diff.txt || printf "${BG_RED}${BOLD} FAILED ${DEFAULT}"
	@rm -f ./C08/ex05/ft_show_tab.c || echo "FAILED removing ft.h file"
	@echo ""

## C11 : Run all tests for C05 project
.PHONY: C11
C11:
	@echo "\n******   Projet C11 : pointer to function ******"
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../C11 && printf "${BG_GREEN}${BOLD}${BLACK} DE 10 ${DEFAULT}"  || $(FAILED)
	@echo "\n\n** EX00: ft_foreach"
	@$(CW) ../C11/ex00/ft_foreach.c ./C11/ex00.c && ./Executable > ./diff.txt && diff ./diff.txt ./C11/diff_ex00.txt && printf "${BG_GREEN}${BOLD}${BLACK} GOOD ${DEFAULT}" && rm -f ./Executable || printf "${BG_RED}${BOLD} FAILED ${DEFAULT}"
	@echo "\n\n** EX01: ft_map"
	@$(CW) ../C11/ex01/ft_map.c ./C11/ex01.c && ./Executable && printf "${BG_GREEN}${BOLD}${BLACK} GOOD ${DEFAULT}" && rm -f ./Executable || printf "${BG_RED}${BOLD} FAILED ${DEFAULT}"
	@echo "\n\n** EX02: ft_any"
	@$(CW) ../C11/ex02/ft_any.c ./C11/ex02.c && ./Executable && printf "${BG_GREEN}${BOLD}${BLACK} GOOD ${DEFAULT}" && rm -f ./Executable || printf "${BG_RED}${BOLD} FAILED ${DEFAULT}"
	@echo ""

## test : test current exo
.PHONY: test
test:
	@echo "\n\n** EX12: ft_print_memory"
	@$(CW) ./C02/ex12.c ../C02/ex12/ft_print_memory.c && ./Executable && diff ./diff_expected ./diff_result && $(GOOD) && rm -f ./Executable ./diff_expected ./diff_result || $(FAILED) && rm -f ./Executable ./diff_expected ./diff_result
	@echo ""