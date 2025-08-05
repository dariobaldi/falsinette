# ============================================================================= #
# HELPERS									#
# ============================================================================= #
TITLE="'\033[1;30;45m'"
SUBTITLE="'\033[1;35;40m'"
GREEN="'\033[38;5;84m'"
RED="'\033[38;5;197m'"
BLUE="'\033[38;5;45m'"
PURPLE="'\033[38;5;63m'"
PINK="'\033[38;5;207m'"
BLACK="'\033[38;5;0m'"
BG_GREEN="'\033[48;5;84m'"
BG_RED="'\033[48;5;197m'"
BG_YELLOW="'\033[48;5;11m'"
GREY="'\033[38;5;8m'"
BOLD="'\033[1m'"
RESET="'\033[0m'"
CHECKMARK="'\xE2\x9C\x93'"

GOOD = printf "${BG_GREEN}${BOLD}${BLACK} GOOD ${RESET}"
FAILED = printf "${BG_RED}${BOLD} FAILED ${RESET}"
FAILED_NORM = printf "${BG_RED}${BOLD} FAILED NORM ${RESET}\n"
CC := cc
CFLAGS := -Wall -Werror -Wextra
CW := $(CC) $(CFLAGS) -o Executable
VCW := $(CC) $(CFLAGS) -g -o Executable
VC := $(CC) -g -o Executable
XCLEAN_FAIL := ./Executable && rm -f ./Executable || $(FAILED)
XCLEAN_FAIL_OK := ./Executable && $(GOOD) && rm -f ./Executable || $(FAILED)
VXCLEAN_FAIL := valgrind -q --leak-check=full ./Executable && rm -f ./Executable || $(FAILED)

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

## test : test current exo
.PHONY: test
test:
	@clear
	@make -s -C ../push_swap push_swap
	@make -s -C ../push_swap bonus
	@mv ../push_swap/push_swap ./push_swap/push_swap
	@mv ../push_swap/checker ./push_swap/checker
	@printf "\n${SUBTITLE}Right tests${RESET}\n"
	@echo -n | ./push_swap/checker 0 1 2 1> parse_err 2>/dev/null || echo -n
	@printf "./checker 0 1 2:" && grep -q OK parse_err && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@echo "pb\nra\npb\nra\nsa\nra\npa\npa" | ./push_swap/checker 0 9 1 8 2 1> parse_err 2>/dev/null || echo -n
	@printf "[pb, ra, pb, ra, sa, ra, pa, pa] > ./checker 0 9 1 8 2:" && grep -q OK parse_err && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
# 	@rm -f ./parse_err ./push_swap/push_swap ./push_swap/checker
	
## push_swap : Because Swap_push doesn’t feel as natural.
.PHONY: push_swap
push_swap:
	@clear
	@printf "\n\t${TITLE}Push_swap${RESET} : Because Swap_push doesn’t feel as natural.\n\n"
	@printf "${SUBTITLE}----------------> Mandatory <----------------${RESET}\n\n"
	@printf "${SUBTITLE}Run norminette${RESET}\n"
	@norminette ../push_swap > norm_file && printf "${BG_GREEN}${BOLD}${BLACK} NORM: PASSES ${RESET}\n" || ($(FAILED_NORM) && grep Error norm_file)
	@rm -f norm_file
	@printf "\n\n${SUBTITLE}Checking files${RESET}\n"
	@find ../push_swap -type f -not -name "*.c" -not -name "*.h" -not -name "Makefile" -not -path "../push_swap/.git/*" -not -name ".gitignore" | grep . && printf "Turn in files: ${BG_RED}${BOLD} FAILED: files not allowed ${RESET}" || printf "Turn in files:${GREEN}${BOLD} OK ${RESET}"
	@grep wildcard -q ../push_swap/Makefile && printf "\nWildcard:${BG_RED}${BOLD} FAILED ${RESET}" || printf "\nWildcard:${GREEN}${BOLD} OK ${RESET}"
	@printf "\nFlags:" && grep -q -- '-Wall' ../push_swap/Makefile && 	grep -q -- '-Werror' ../push_swap/Makefile && 	grep -q -- '-Wextra' ../push_swap/Makefile && printf "${GREEN}${BOLD} OK ${RESET}" || printf "${BG_RED}${BOLD} FAILED ${RESET}"
	@if [ -d "../push_swap/libft" ]; then \
    if grep -q -- '-Wall' ../push_swap/libft/Makefile && \
       grep -q -- '-Werror' ../push_swap/libft/Makefile && \
       grep -q -- '-Wextra' ../push_swap/libft/Makefile; then \
        : ; \
    else \
        printf "${BG_RED}${BOLD} FAILED for Libft Makefile ${RESET}\n"; \
    fi; \
	fi
	@printf "\n\n${SUBTITLE}Checking make command${RESET}\n"
	@printf "push_swap:" && make -C ../push_swap -s push_swap && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@printf "No relink:" && make -C ../push_swap push_swap | grep -q "'push_swap' is up to date." && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@mv ../push_swap/push_swap ./push_swap/push_swap
	@printf "\n\n${SUBTITLE}Checking leaks and malloc protections${RESET}\n"
	@echo -n "Valgrind basic input: "
	@valgrind --leak-check=full --show-leak-kinds=all ./push_swap/push_swap 5 1 2 3 4 > mem_check 2>&1
	@grep -q "0 errors" mem_check && printf "${GREEN}${BOLD} OK ${RESET}\n" || (printf "${BG_RED}${BOLD} FAILED ${RESET}\n" && cat mem_check)
	@echo -n "Valgrind bad input: "
	@valgrind --leak-check=full --show-leak-kinds=all ./push_swap/push_swap 1 dos 3 4 5 > mem_check 2>&1 || echo -n
	@grep -q "0 errors" mem_check && printf "${GREEN}${BOLD} OK ${RESET}\n" || (printf "${BG_RED}${BOLD} FAILED ${RESET}\n" && cat mem_check)
	@if command -v funcheck > /dev/null 2>&1; then \
		funcheck ./push_swap/push_swap 1 2 3 4 5 > mem_check 2>&1 || echo -n; \
		echo -n "Funcheck basic input: " && grep -q "failed" mem_check && (printf "${BG_RED}${BOLD} FAILED ${RESET}\n" && cat mem_check) || printf "${GREEN}${BOLD} OK ${RESET}\n" ; \
		funcheck ./push_swap/push_swap 1 dos 3 4 > mem_check 2>&1 || echo -n; \
		echo -n "Funcheck bad input: " && grep -q "failed" mem_check && (printf "${BG_RED}${BOLD} FAILED ${RESET}\n" && cat mem_check) || printf "${GREEN}${BOLD} OK ${RESET}\n" ; \
	else \
		printf "Funcheck:${BG_YELLOW}${BOLD} Not Installed ${RESET}\n"; \
	fi
	@printf "\n${SUBTITLE}Error management${RESET}\n"
	@./push_swap/push_swap 5 1 six 2 3 4 2> parse_err 1>/dev/null || echo -n
	@printf "Non numeric parameters:" && grep -q Error parse_err && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@./push_swap/push_swap 5 1 2 2 3 4 2> parse_err 1>/dev/null || echo -n
	@printf "Duplicate number:" && grep -q Error parse_err && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@./push_swap/push_swap 5 1 2 3 4 2147483648 2> parse_err 1>/dev/null || echo -n
	@printf "Int overflow (INT MAX):" && grep -q Error parse_err && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@./push_swap/push_swap 5 1 2 3 4 -2147483649 2> parse_err 1>/dev/null || echo -n
	@printf "Int overflow (INT MIN):" && grep -q Error parse_err && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@./push_swap/push_swap 2> parse_err 1>/dev/null || echo -n
	@printf "No parameters:" && grep -q Error parse_err && printf "${BG_RED}${BOLD} FAILED ${RESET}\n" || printf "${GREEN}${BOLD} OK ${RESET}\n"
	@printf "\n${SUBTITLE}Identity test${RESET}\n"
	@printf "Sorted input (42): "
	@ARG="42"; \
	OPS=$$(./push_swap/push_swap $$ARG); \
	CHECK=$$(./push_swap/push_swap $$ARG | ./push_swap/main_checker $$ARG); \
	if [ -n "$$OPS" ]; then COUNT=$$(echo "$$OPS" | wc -l); else COUNT=0; fi; \
	if [ "$$CHECK" = "OK" ] && [ "$$COUNT" -eq 0 ]; then \
		echo "✅ ${GREEN}${BOLD} OK ${RESET} 0 operations"; \
	else \
		echo "❌ ${BG_RED}FAILED${RESET} — $$COUNT operations (should be 0) or checker failed"; \
	fi
	@printf "Sorted input (2 3): "
	@ARG="2 3"; \
	OPS=$$(./push_swap/push_swap $$ARG); \
	CHECK=$$(./push_swap/push_swap $$ARG | ./push_swap/main_checker $$ARG); \
	if [ -n "$$OPS" ]; then COUNT=$$(echo "$$OPS" | wc -l); else COUNT=0; fi; \
	if [ "$$CHECK" = "OK" ] && [ "$$COUNT" -eq 0 ]; then \
		echo "✅ ${GREEN}${BOLD} OK ${RESET} 0 operations"; \
	else \
		echo "❌ ${BG_RED}FAILED${RESET} — $$COUNT operations (should be 0) or checker failed"; \
	fi
	@printf "Sorted input (0 1 2 3): "
	@ARG="0 1 2 3"; \
	OPS=$$(./push_swap/push_swap $$ARG); \
	CHECK=$$(./push_swap/push_swap $$ARG | ./push_swap/main_checker $$ARG); \
	if [ -n "$$OPS" ]; then COUNT=$$(echo "$$OPS" | wc -l); else COUNT=0; fi; \
	if [ "$$CHECK" = "OK" ] && [ "$$COUNT" -eq 0 ]; then \
		echo "✅ ${GREEN}${BOLD} OK ${RESET} 0 operations"; \
	else \
		echo "❌ ${BG_RED}FAILED${RESET} — $$COUNT operations (should be 0) or checker failed"; \
	fi
	@printf "Sorted input (0 1 2 3 4 5 6 7 8): "
	@ARG="0 1 2 3 4 5 6 7 8"; \
	OPS=$$(./push_swap/push_swap $$ARG); \
	CHECK=$$(./push_swap/push_swap $$ARG | ./push_swap/main_checker $$ARG); \
	if [ -n "$$OPS" ]; then COUNT=$$(echo "$$OPS" | wc -l); else COUNT=0; fi; \
	if [ "$$CHECK" = "OK" ] && [ "$$COUNT" -eq 0 ]; then \
		echo "✅ ${GREEN}${BOLD} OK ${RESET} 0 operations"; \
	else \
		echo "❌ ${BG_RED}FAILED${RESET} — $$COUNT operations (should be 0) or checker failed"; \
	fi
	@printf "9 randomly sorted values: "
	@ARG="$$(shuf -i 0-999 -n 9 | sort -n | tr '\n' ' ')"; \
	OPS=$$(./push_swap/push_swap $$ARG); \
	CHECK=$$(./push_swap/push_swap $$ARG | ./push_swap/main_checker $$ARG); \
	if [ -n "$$OPS" ]; then COUNT=$$(echo "$$OPS" | wc -l); else COUNT=0; fi; \
	if [ "$$CHECK" = "OK" ] && [ "$$COUNT" -eq 0 ]; then \
		echo "✅ ${GREEN}${BOLD} OK ${RESET} 0 operations"; \
	else \
		echo "❌ ${BG_RED}FAILED${RESET} — $$COUNT operations (should be 0) or checker failed\nARGS=$$ARG"; \
	fi
	@printf "\n${SUBTITLE}Simple version${RESET}\n"
	@printf "Input 2 1 0: "
	@ARG="2 1 0"; \
	OPS=$$(./push_swap/push_swap $$ARG); \
	CHECK=$$(./push_swap/push_swap $$ARG | ./push_swap/main_checker $$ARG); \
	if [ -n "$$OPS" ]; then COUNT=$$(echo "$$OPS" | wc -l); else COUNT=0; fi; \
	if [ "$$CHECK" = "OK" ] && [ "$$COUNT" -lt 4 ]; then \
		echo "✅ ${GREEN}${BOLD} OK ${RESET} $$COUNT operations"; \
	else \
		echo "❌ ${BG_RED}FAILED${RESET} — $$COUNT operations (should be less than 4) or checker failed"; \
	fi
	@printf "\n🔁 Between 1 and 3 random numbers: Running 10 tests...\n"
	@total=0; \
	fail=0; \
	max=0; \
	for i in $$(seq 1 10); do \
		NUM=$$(shuf -i 1-3 -n 1); \
		ARG=$$(shuf -i 0-1000 -n $$NUM | tr '\n' ' '); \
		OPS=$$(./push_swap/push_swap $$ARG); \
		COUNT=$$(echo "$$OPS" | wc -l); \
		CHECK=$$( \
			if [ -z "$$OPS" ]; then \
				./push_swap/main_checker $$ARG < /dev/null; \
			else \
				echo "$$OPS" | ./push_swap/main_checker $$ARG; \
			fi \
		); \
		if [ "$$CHECK" != "OK" ] || [ "$$COUNT" -gt 3 ]; then \
			printf "❌ Test $$i: ${BG_RED}FAILED${RESET} $$COUNT operations (should be less than 4) \nARG=$$ARG\nOPS=\n$$OPS\n"; \
			fail=$$((fail + 1)); \
# 		else \
# 			printf "✅ Test $$i: ${GREEN}OK${RESET} — $$COUNT operations\n"; \
		fi; \
		if [ "$$COUNT" -gt "$$max" ]; then max=$$COUNT; fi; \
		total=$$((total + COUNT)); \
	done; \
	if [ "$$fail" -eq 0 ]; then \
		avg=$$((total / 10)); \
		echo "📊 Average number of operations: $$avg"; \
		echo "📈 Maximum number of operations: $$max"; \
		echo "✅ All tests passed."; \
	else \
		echo ""; \
		echo "⚠️  $$fail test(s) ${BG_RED}FAILED${RESET}. Check your implementation."; \
	fi
	@printf "\n${SUBTITLE}Another simple version${RESET}\n"
	@printf "Input 1 5 2 4 3: "
	@ARG="1 5 2 4 3"; \
	OPS=$$(./push_swap/push_swap $$ARG); \
	CHECK=$$(./push_swap/push_swap $$ARG | ./push_swap/main_checker $$ARG); \
	if [ -n "$$OPS" ]; then COUNT=$$(echo "$$OPS" | wc -l); else COUNT=0; fi; \
	if [ "$$CHECK" = "OK" ] && [ "$$COUNT" -lt 13 ]; then \
		echo "✅ ${GREEN}${BOLD} OK ${RESET} $$COUNT operations"; \
	else \
		echo "❌ ${BG_RED}FAILED${RESET} — $$COUNT operations (should be less than 4) or checker failed"; \
	fi
	@printf "\n🔁 5 numbers: Running 100 random tests...\n"
	@total=0; \
	fail=0; \
	max=0; \
	for i in $$(seq 1 100); do \
		ARG=$$(shuf -i 0-1000 -n 5 | tr '\n' ' '); \
		OPS=$$(./push_swap/push_swap $$ARG); \
		COUNT=$$(echo "$$OPS" | wc -l); \
		CHECK=$$( \
			if [ -z "$$OPS" ]; then \
				./push_swap/main_checker $$ARG < /dev/null; \
			else \
				echo "$$OPS" | ./push_swap/main_checker $$ARG; \
			fi \
		); \
		if [ "$$CHECK" != "OK" ]; then \
			printf "❌ Test $$i: ${BG_RED}FAILED${RESET}\nARGS=$$ARG\n"; \
			fail=$$((fail + 1)); \
# 		else \
# 			printf "✅ Test $$i: ${GREEN}OK${RESET} — $$COUNT operations\n"; \
		fi; \
		if [ "$$COUNT" -gt "$$max" ]; then max=$$COUNT; fi; \
		total=$$((total + COUNT)); \
	done; \
	if [ "$$fail" -eq 0 ]; then \
		avg=$$((total / 100)); \
		echo "📊 Average number of operations: $$avg"; \
		echo "📈 Maximum number of operations: $$max"; \
		echo "✅ All tests passed."; \
	else \
		echo ""; \
		echo "⚠️  $$fail test(s) ${BG_RED}FAILED${RESET}. Check your implementation."; \
	fi
	@printf "\n${SUBTITLE}Middle version${RESET}\n"
	@printf "\n🔁 100 numbers: Running 50 random tests...\n"
	@total=0; \
	fail=0; \
	max=0; \
	for i in $$(seq 1 50); do \
		ARG=$$(shuf -i 0-1000 -n 100 | tr '\n' ' '); \
		OPS=$$(./push_swap/push_swap $$ARG); \
		COUNT=$$(echo "$$OPS" | wc -l); \
		CHECK=$$( \
			if [ -z "$$OPS" ]; then \
				./push_swap/main_checker $$ARG < /dev/null; \
			else \
				echo "$$OPS" | ./push_swap/main_checker $$ARG; \
			fi \
		); \
		if [ "$$CHECK" != "OK" ]; then \
			printf "❌ Test $$i: ${BG_RED}FAILED${RESET}\nARGS=$$ARG\n"; \
			fail=$$((fail + 1)); \
# 		else \
# 			printf "✅ Test $$i: ${GREEN}OK${RESET} — $$COUNT operations\n"; \
		fi; \
		if [ "$$COUNT" -gt "$$max" ]; then max=$$COUNT; fi; \
		total=$$((total + COUNT)); \
	done; \
	if [ "$$fail" -eq 0 ]; then \
		avg=$$((total / 50)); \
		echo "📊 Average number of operations: $$avg"; \
		echo "📈 Maximum number of operations: $$max"; \
		echo "✅ All tests passed."; \
	else \
		echo ""; \
		echo "⚠️  $$fail test(s) ${BG_RED}FAILED${RESET}. Check your implementation."; \
	fi
	@printf "\n${SUBTITLE}Advanced version${RESET}\n"
	@printf "\n🔁 500 numbers: Running 10 random tests...\n"
	@total=0; \
	fail=0; \
	max=0; \
	for i in $$(seq 1 10); do \
		ARG=$$(shuf -i 0-10000 -n 500 | tr '\n' ' '); \
		OPS=$$(./push_swap/push_swap $$ARG); \
		COUNT=$$(echo "$$OPS" | wc -l); \
		CHECK=$$( \
			if [ -z "$$OPS" ]; then \
				./push_swap/main_checker $$ARG < /dev/null; \
			else \
				echo "$$OPS" | ./push_swap/main_checker $$ARG; \
			fi \
		); \
		if [ "$$CHECK" != "OK" ]; then \
			printf "❌ Test $$i: ${BG_RED}FAILED${RESET}\nARGS=$$ARG\n"; \
			fail=$$((fail + 1)); \
# 		else \
# 			printf "✅ Test $$i: ${GREEN}OK${RESET} — $$COUNT operations\n"; \
		fi; \
		if [ "$$COUNT" -gt "$$max" ]; then max=$$COUNT; fi; \
		total=$$((total + COUNT)); \
	done; \
	if [ "$$fail" -eq 0 ]; then \
		avg=$$((total / 10)); \
		echo "📊 Average number of operations: $$avg"; \
		echo "📈 Maximum number of operations: $$max"; \
		echo "✅ All tests passed."; \
	else \
		echo ""; \
		echo "⚠️  $$fail test(s) ${BG_RED}FAILED${RESET}. Check your implementation."; \
	fi
	@printf "\n${SUBTITLE}Just for fun${RESET}\n"
	@printf "\n${SUBTITLE}Sorted input (1 2 3 ... 500)${RESET}\n"
	@ARG="$$(seq 1 500)"; \
	OPS=$$(./push_swap/push_swap $$ARG); \
	CHECK=$$(./push_swap/push_swap $$ARG | ./push_swap/main_checker $$ARG); \
	if [ -n "$$OPS" ]; then COUNT=$$(echo "$$OPS" | wc -l); else COUNT=0; fi; \
	if [ "$$CHECK" = "OK" ] && [ "$$COUNT" -eq 0 ]; then \
		echo "✅ Result: ${GREEN}${BOLD} OK ${RESET} — Already sorted, 0 operations"; \
	else \
		echo "❌ Result: ${BG_RED}FAILED${RESET} — $$COUNT operations (should be 0) or checker failed"; \
	fi
	@printf "\n${SUBTITLE}Reverse sorted input (500 499 ... 1)${RESET}\n"
	@ARG="$$(seq 500 -1 1)"; \
	OPS=$$(./push_swap/push_swap $$ARG); \
	CHECK=$$(./push_swap/push_swap $$ARG | ./push_swap/main_checker $$ARG); \
	if [ -n "$$OPS" ]; then COUNT=$$(echo "$$OPS" | wc -l); else COUNT=0; fi; \
	if [ "$$CHECK" = "OK" ] ; then \
		echo "✅ Result: ${GREEN}${BOLD} OK ${RESET} — $$COUNT operations"; \
	else \
		echo "❌ Result: ${BG_RED}FAILED${RESET}"; \
	fi
	@printf "\n${SUBTITLE}Reverse sorted input (5 ... 1)${RESET}\n"
	@ARG="$$(seq 5 -1 1)"; \
	OPS=$$(./push_swap/push_swap $$ARG); \
	CHECK=$$(./push_swap/push_swap $$ARG | ./push_swap/main_checker $$ARG); \
	if [ -n "$$OPS" ]; then COUNT=$$(echo "$$OPS" | wc -l); else COUNT=0; fi; \
	if [ "$$CHECK" = "OK" ] ; then \
		echo "✅ Result: ${GREEN}${BOLD} OK ${RESET} — $$COUNT operations"; \
	else \
		echo "❌ Result: ${BG_RED}FAILED${RESET}"; \
	fi
	@printf "\n${SUBTITLE}Almost sorted input (2 1 3 4 ... 500)${RESET}\n"
	@ARG="2 1 $$(seq 3 500)"; \
	OPS=$$(./push_swap/push_swap $$ARG); \
	COUNT=$$(echo "$$OPS" | wc -l); \
	CHECK=$$(echo "$$OPS" | ./push_swap/main_checker $$ARG); \
	if [ "$$CHECK" = "OK" ]; then \
		echo "✅ Result: ${GREEN}${BOLD} OK ${RESET} — $$COUNT operations"; \
	else \
		echo "❌ Result: ${BG_RED}FAILED${RESET} — checker failed"; \
		exit 1; \
	fi
	@printf "\n${SUBTITLE}Almost sorted input (2 1 3 4 5)${RESET}\n"
	@ARG="2 1 $$(seq 3 5)"; \
	OPS=$$(./push_swap/push_swap $$ARG); \
	COUNT=$$(echo "$$OPS" | wc -l); \
	CHECK=$$(echo "$$OPS" | ./push_swap/main_checker $$ARG); \
	if [ "$$CHECK" = "OK" ]; then \
		echo "✅ Result: ${GREEN}${BOLD} OK ${RESET} — $$COUNT operations"; \
	else \
		echo "❌ Result: ${BG_RED}FAILED${RESET} — checker failed"; \
		exit 1; \
	fi

	@printf "\n\n${SUBTITLE}----------------> Bonus <----------------${RESET}\n"
	@make -qp -C ../push_swap | grep -q bonus: || (printf "${BG_RED}${BOLD} No bonus ${RESET}\n" && exit 1)
	@printf "\n${SUBTITLE}Checking make command${RESET}\n"
	@printf "bonus:" && make -s -C ../push_swap bonus && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@printf "No relink:" && make -C ../push_swap bonus | grep -q "Nothing to be done for 'bonus'" && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@mv ../push_swap/checker ./push_swap/checker
	@printf "\n\n${SUBTITLE}Checking leaks and protections (checker)${RESET}\n"
	@echo -n "Valgrind basic input: "
	@echo sa | valgrind --leak-check=full --show-leak-kinds=all ./push_swap/checker 2 1 3 4 5 > mem_check 2>&1 || echo -n
	@grep -q "0 errors" mem_check && printf "${GREEN}${BOLD} OK ${RESET}\n" || (printf "${BG_RED}${BOLD} FAILED ${RESET}\n" && cat mem_check)
	@echo -n "Valgrind bad input: "
	@echo sa | valgrind --leak-check=full --show-leak-kinds=all ./push_swap/checker 2 uno 3 4 5 > mem_check 2>&1 || echo -n
	@grep -q "0 errors" mem_check && printf "${GREEN}${BOLD} OK ${RESET}\n" || (printf "${BG_RED}${BOLD} FAILED ${RESET}\n" && cat mem_check)
	@if command -v funcheck > /dev/null 2>&1; then \
		echo sa | funcheck ./push_swap/checker 2 1 3 4 5 > mem_check 2>&1 || echo -n; \
		echo -n "Funcheck basic input: " && grep -q "failed" mem_check && (printf "${BG_RED}${BOLD} FAILED ${RESET}\n" && cat mem_check) || printf "${GREEN}${BOLD} OK ${RESET}\n" ; \
		echo sa | funcheck ./push_swap/checker 2 uno 3 4 5 > mem_check 2>&1 || echo -n; \
		echo -n "Funcheck bad input: " && grep -q "failed" mem_check && (printf "${BG_RED}${BOLD} FAILED ${RESET}\n" && cat mem_check) || printf "${GREEN}${BOLD} OK ${RESET}\n" ; \
	else \
		printf "Funcheck:${BG_YELLOW}${BOLD} FAILED (not installed) ${RESET}\n"; \
	fi
	@printf "\n${SUBTITLE}Error management${RESET}\n"
	@echo "pa sa" | ./push_swap/checker 5 1 six 2 3 4 2> parse_err 1>/dev/null || echo -n
	@printf "Non numeric parameters:" && grep -q Error parse_err && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@echo "pa sa" | ./push_swap/checker 5 1 2 2 3 4 2> parse_err 1>/dev/null || echo -n
	@printf "Duplicate number:" && grep -q Error parse_err && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@echo "pa sa" | ./push_swap/checker 5 1 2 3 4 2147483648 2> parse_err 1>/dev/null || echo -n
	@printf "Int overflow (INT MAX):" && grep -q Error parse_err && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@echo "pa sa" | ./push_swap/checker 5 1 2 3 4 -2147483649 2> parse_err 1>/dev/null || echo -n
	@printf "Int overflow (INT MIN):" && grep -q Error parse_err && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@echo -n | ./push_swap/checker 2> parse_err 1>/dev/null || echo -n
	@printf "No parameters:" && grep -q Error parse_err && printf "${BG_RED}${BOLD} FAILED ${RESET}\n" || printf "${GREEN}${BOLD} OK ${RESET}\n"
	@echo "ra\nsaa" | ./push_swap/checker 5 2 1 3 4 2> parse_err 1>/dev/null || echo -n
	@printf "Non existent action:" && grep -q Error parse_err && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@echo "ra  \n  sa" | ./push_swap/checker 5 2 1 3 4 2> parse_err 1>/dev/null || echo -n
	@printf "Spaces before and after actions" && grep -q Error parse_err && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@printf "\n${SUBTITLE}False tests${RESET}\n"
	@echo "sa\npb\nrrr" | ./push_swap/checker 0 9 1 8 2 7 3 6 4 5 1> parse_err 2>/dev/null || echo -n
	@printf "[sa, pb, rrr] > ./checker 0 9 1 8 2 7 3 6 4 5:" && grep -q KO parse_err && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@echo "\n🔁 Running 10 random tests with wrong instructions..."
	@fail=0; \
	for i in $$(seq 1 10); do \
		ARG=$$(shuf -i 0-1000 -n 10 | tr '\n' ' '); \
		OPS="sa\npb\nrrr\npb\nrr\npa"; \
		CHECK=$$(echo "$$OPS" | ./push_swap/checker $$ARG); \
		if [ "$$CHECK" != "KO" ] ; then \
			printf "❌ Test $$i: ${BG_RED}FAILED${RESET} (checker failed)\nARG=$$ARG\nOPS=\"sa pb rrr pb rr pa\"\n\n"; \
			fail=$$((fail + 1)); \
		fi; \
	done; \
	if [ "$$fail" -eq 0 ]; then \
		echo "✅ All tests passed."; \
	else \
		echo "⚠️  $$fail test(s) ${BG_RED}FAILED${RESET}. Check your implementation."; \
	fi
	@printf "\n${SUBTITLE}Right tests${RESET}\n"
	@echo -n | ./push_swap/checker 0 1 2 1> parse_err 2>/dev/null || echo -n
	@printf "./checker 0 1 2:" && grep -q OK parse_err && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@echo "pb\nra\npb\nra\nsa\nra\npa\npa" | ./push_swap/checker 0 9 1 8 2 1> parse_err 2>/dev/null || echo -n
	@printf "[pb, ra, pb, ra, sa, ra, pa, pa] > ./checker 0 9 1 8 2:" && grep -q OK parse_err && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@echo "\n🔁 100 numbers: Running 10 random tests..."
	@total=0; \
	fail=0; \
	for i in $$(seq 1 10); do \
		ARG=$$(shuf -i 0-1000 -n 100 | tr '\n' ' '); \
		OPS=$$(./push_swap/push_swap $$ARG); \
		COUNT=$$(echo "$$OPS" | wc -l); \
		CHECK=$$(echo "$$OPS" | ./push_swap/checker $$ARG); \
		CHECK2=$$(echo "pb" | ./push_swap/checker $$ARG); \
		if [ "$$CHECK" != "OK" ] || [ "$$CHECK2" != "KO" ]; then \
			printf "❌ Test $$i: ${BG_RED}FAILED${RESET}\nARG=$$ARG\n"; \
			fail=$$((fail + 1)); \
		fi; \
		total=$$((total + COUNT)); \
	done; \
	if [ "$$fail" -eq 0 ]; then \
		echo "✅ All tests passed."; \
	else \
		echo "⚠️  $$fail test(s) ${BG_RED}FAILED${RESET}. Check your implementation."; \
		exit 1; \
	fi
	@echo "\n🔁 500 numbers: Running 10 random tests..."
	@total=0; \
	fail=0; \
	for i in $$(seq 1 10); do \
		ARG=$$(shuf -i 0-10000 -n 500 | tr '\n' ' '); \
		OPS=$$(./push_swap/push_swap $$ARG); \
		COUNT=$$(echo "$$OPS" | wc -l); \
		CHECK=$$(echo "$$OPS" | ./push_swap/checker $$ARG); \
		CHECK2=$$(echo "pb" | ./push_swap/checker $$ARG); \
		if [ "$$CHECK" != "OK" ] || [ "$$CHECK2" != "KO" ]; then \
			printf "❌ Test $$i: ${BG_RED}FAILED${RESET}\nARG=$$ARG\n"; \
			fail=$$((fail + 1)); \
		fi; \
		total=$$((total + COUNT)); \
	done; \
	if [ "$$fail" -eq 0 ]; then \
		echo "✅ All tests passed."; \
	else \
		echo "⚠️  $$fail test(s) ${BG_RED}FAILED${RESET}. Check your implementation."; \
		exit 1; \
	fi
	@make -C ../push_swap -s fclean
	@rm -f ./parse_err ./mem_check ./push_swap/push_swap ./push_swap/checker

## gnl : Reading a line from a file descriptor is far too tedious.
.PHONY: gnl
gnl:
	@clear
	@printf "\n\t${TITLE}Get Next Line${RESET} : Reading a line from a file descriptor is far too tedious.\n\n"
	@printf "${SUBTITLE}Run norminette${RESET}\n"
	@norminette ../gnl > norm_file && printf "${BG_GREEN}${BOLD}${BLACK} NORM: PASSES ${RESET}" || ($(FAILED_NORM) && grep Error norm_file)
	@rm -f norm_file
	@printf "\n\n${SUBTITLE}Mandatory${RESET}\n"
	@printf "\n${SUBTITLE}BUFFER_SIZE=42${RESET}\n"
	@rm -rf results && mkdir results
	@$(VCW) -D BUFFER_SIZE=42 -I ../gnl/ ./gnl/mandatory.c ../gnl/get_next_line.c ../gnl/get_next_line_utils.c
	@valgrind -q --leak-check=full ./Executable
	@rm -f ./Executable
	@for f in ./gnl/files/*; do \
		name=$$(basename $$f); \
		printf "$$name: " &&diff ./results/$$name ./gnl/files/$$name && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"; \
	done
	@printf "\n${SUBTITLE}BUFFER_SIZE=1${RESET}\n"
	@rm -rf results && mkdir results
	@$(VCW) -D BUFFER_SIZE=1 -I ../gnl/ ./gnl/mandatory.c ../gnl/get_next_line.c ../gnl/get_next_line_utils.c
	@valgrind -q --leak-check=full ./Executable
	@rm -f ./Executable
	@for f in ./gnl/files/*; do \
		name=$$(basename $$f); \
		printf "$$name: " &&diff ./results/$$name ./gnl/files/$$name && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"; \
	done
	@printf "\n${SUBTITLE}BUFFER_SIZE=10000000${RESET}\n"
	@rm -rf results && mkdir results
	@$(VCW) -D BUFFER_SIZE=10000000 -I ../gnl/ ./gnl/mandatory.c ../gnl/get_next_line.c ../gnl/get_next_line_utils.c
	@valgrind -q --leak-check=full ./Executable
	@rm -f ./Executable
	@for f in ./gnl/files/*; do \
		name=$$(basename $$f); \
		printf "$$name: " &&diff ./results/$$name ./gnl/files/$$name && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"; \
	done
	@printf "\n${SUBTITLE}BUFFER_SIZE=9999${RESET}\n"
	@rm -rf results && mkdir results
	@$(VCW) -D BUFFER_SIZE=9999 -I ../gnl/ ./gnl/mandatory.c ../gnl/get_next_line.c ../gnl/get_next_line_utils.c
	@valgrind -q --leak-check=full ./Executable
	@rm -f ./Executable
	@for f in ./gnl/files/*; do \
		name=$$(basename $$f); \
		printf "$$name: " &&diff ./results/$$name ./gnl/files/$$name && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"; \
	done
	@rm -rf results && mkdir results

## ft_printf : Because ft_putnbr() and ft_putstr() aren’t enough
.PHONY: ft_printf
ft_printf:
	@clear
	@printf "\n\t${TITLE}Project ft_printf${RESET} : Because ft_putnbr() and ft_putstr() aren’t enough\n\n"
	@printf "${SUBTITLE}Run norminette${RESET}\n"
	@norminette ../ft_printf > norm_file && printf "${BG_GREEN}${BOLD}${BLACK} NORM: PASSES ${RESET}" || ($(FAILED_NORM) && grep Error norm_file)
	@rm -f norm_file
	@printf "\n\n${SUBTITLE}Checking files${RESET}\n"
	@find ../ft_printf -type f -not -name "*.c" -not -name "*.h" -not -name "Makefile" -not -path "../ft_printf/.git/*" | grep . && printf "Turn in files: ${BG_RED}${BOLD} KO: files not allowed ${RESET}" || printf "Turn in files:${GREEN}${BOLD} OK ${RESET}"
	@grep wildcard -q ../ft_printf/Makefile && printf "\nWildcard:${BG_RED}${BOLD} KO ${RESET}" || printf "\nWildcard:${GREEN}${BOLD} OK ${RESET}"
	@grep libtool -q ../ft_printf/Makefile && printf "\nLibtool:${BG_RED}${BOLD} KO ${RESET}" || printf "\nLibtool:${GREEN}${BOLD} OK ${RESET}"
	@printf "\nFlags:" && grep -q -- '-Wall' ../ft_printf/Makefile && 	grep -q -- '-Werror' ../ft_printf/Makefile && 	grep -q -- '-Wextra' ../ft_printf/Makefile && printf "${GREEN}${BOLD} OK ${RESET}" || printf "${BG_RED}${BOLD} KO ${RESET}"
	@if [ -d "../ft_printf/Libft" ]; then \
    if grep -q -- '-Wall' ../ft_printf/Libft/Makefile && \
       grep -q -- '-Werror' ../ft_printf/Libft/Makefile && \
       grep -q -- '-Wextra' ../ft_printf/Libft/Makefile; then \
        : ; \
    else \
        printf "${BG_RED}${BOLD} KO for Libft Makefile ${RESET}\n"; \
    fi; \
	fi
	@printf "\n\n${SUBTITLE}Checking make commands${RESET}\n"
	@make -C ../ft_printf -s libftprintf.a && printf "libftprintf.a:${GREEN}${BOLD} OK ${RESET}\n"|| printf "libftprintf.a:${BG_RED}${BOLD} KO ${RESET}\n"
	@make -C ../ft_printf -s fclean && printf "fclean:${GREEN}${BOLD} OK ${RESET}\n"|| printf "fclean:${BG_RED}${BOLD} KO ${RESET}\n"
	@make -C ../ft_printf -s all && printf "all:${GREEN}${BOLD} OK ${RESET}\n"|| printf "all:${BG_RED}${BOLD} KO ${RESET}\n"
	@make -C ../ft_printf -s clean && printf "clean:${GREEN}${BOLD} OK ${RESET}\n"|| printf "clean:${BG_RED}${BOLD} KO ${RESET}\n"
	@make -C ../ft_printf -s re && printf "re:${GREEN}${BOLD} OK ${RESET}\n"|| printf "re:${BG_RED}${BOLD} KO ${RESET}\n"
	@printf "\n\n${SUBTITLE}Mandatory part${RESET}\n"
	@$(VCW) ./ft_printf/mandatory.c -I ../ft_printf/ -L ../ft_printf/ -lftprintf
	@valgrind -q --leak-check=full ./Executable && diff ./diff_expected ./diff_result && $(GOOD) || $(FAILED)
	@rm -f ./Executable ./diff_expected ./diff_result
	@make -C ../ft_printf -s bonus
	@printf "\n\n${SUBTITLE}Bonus part 1${RESET}\n"
	@$(VCW) ./ft_printf/bonus1.c -I ../ft_printf/ -L ../ft_printf/ -lftprintf
	@valgrind -q --leak-check=full ./Executable && diff --side-by-side --suppress-common-lines ./diff_expected ./diff_result && printf "${BG_GREEN}${BOLD}${BLACK} Ba ba baaaa ${RESET}\n" || printf "\n${RESET}${BG_RED}${BOLD} Mince ${RESET}"
	@rm -f ./Executable ./diff_expected ./diff_result
	@printf "\n${SUBTITLE}Bonus part 2${RESET}\n"
	@$(VCW) ./ft_printf/bonus2.c -I ../ft_printf/ -L ../ft_printf/ -lftprintf
	@valgrind -q --leak-check=full ./Executable && diff --side-by-side --suppress-common-lines ./diff_expected ./diff_result && printf "${BG_GREEN}${BOLD}${BLACK} Barrilete Cosmico ! ${RESET}\n" || printf "\n${RESET}${BG_RED}${BOLD} Puree de pomme de terre ${RESET}"
	@rm -f ./Executable ./diff_expected ./diff_result
	@make -C ../ft_printf -s fclean

## Libft : Your very first own library
.PHONY: Libft
Libft:
	@clear
	@printf "\n\t${TITLE}Project Libft${RESET} : Your very first own library\n\n"
	@printf "${SUBTITLE}Run norminette${RESET}\n"
	@norminette ../Libft > norm_file && printf "${BG_GREEN}${BOLD}${BLACK} NORM: PASSES ${RESET}" || ($(FAILED_NORM) && grep Error norm_file)
	@rm -f norm_file
	@printf "\n\n${SUBTITLE}Checking files${RESET}\n"
	@find ../Libft -type f -not -name "*_bonus.c" -not -path "../Libft/.git/*" | sort > files && diff ./files ./Libft/part1/files && $(GOOD)|| printf "${BG_RED}${BOLD} KO: mismatched files (Mandatory) ${RESET}"
	@find ../Libft -type f -name "*_bonus.c" -not -path "../Libft/.git/*" | sort > files && diff ./files ./Libft/bonus/files || printf "${BG_YELLOW}${BOLD} KO: Bonus Files ${RESET}"
	@printf "\n\n${SUBTITLE}Checking make commands${RESET}\n"
	@make -C ../Libft -s libft.a
	@find ../Libft -type f -not -name "*_bonus.c" -not -path "../Libft/.git/*" | sort > files && diff ./files ./Libft/part1/files_all && printf "libft.a:${GREEN}${BOLD} OK ${RESET}\n"|| printf "libft.a:${BG_RED}${BOLD} KO ${RESET}\n"
	@make -C ../Libft -s fclean
	@find ../Libft -type f -not -name "*_bonus.c" -not -path "../Libft/.git/*" | sort > files && diff ./files ./Libft/part1/files && printf "fclean:${GREEN}${BOLD} OK ${RESET}\n"|| printf "fclean:${BG_RED}${BOLD} KO ${RESET}\n"
	@make -C ../Libft -s all
	@find ../Libft -type f -not -name "*_bonus.c" -not -path "../Libft/.git/*" | sort > files && diff ./files ./Libft/part1/files_all && printf "all:${GREEN}${BOLD} OK ${RESET}\n"|| printf "all:${BG_RED}${BOLD} KO ${RESET}\n"
	@make -C ../Libft -s clean
	@find ../Libft -type f -not -name "*_bonus.c" -not -path "../Libft/.git/*" | sort > files && diff ./files ./Libft/part1/files_clean && printf "clean:${GREEN}${BOLD} OK ${RESET}\n"|| printf "clean:${BG_RED}${BOLD} KO ${RESET}\n"
	@make -C ../Libft -s fclean
	@make -C ../Libft -np | awk '/^re:/ {print; exit}' > files && diff ./files ./Libft/part1/files_re && printf "re:${GREEN}${BOLD} OK ${RESET}\n"|| printf "re:${BG_RED}${BOLD} KO ${RESET}\n"
	@make -C ../Libft -s bonus \
		&& find ../Libft -type f -not -path "../Libft/.git/*" | sort > files && diff ./files ./Libft/bonus/files_bonus && printf "bonus:${GREEN}${BOLD} GREAT JOB ${RESET}\n"|| printf "bonus:${BG_YELLOW}${BOLD} KO ${RESET}\n"
	@rm -f ./files
	@make -C ../Libft -s fclean
	@make -C ../Libft -s all
	@printf "\n\n${SUBTITLE}Part 1 - Libc functions${RESET}\n"
	@$(VCW) ./Libft/part1/*.c -I ../Libft/ -L ../Libft -lft -lbsd
	@valgrind -q --leak-check=full ./Executable && $(GOOD) || printf "${BG_RED}${BOLD} FAILED ${RESET}"
	@rm -f ./Executable
	@printf "\n\n${SUBTITLE}Part 2 - Additional functions${RESET}\n"
	@$(VCW) ./Libft/part2/*.c -I ../Libft/ -L ../Libft -lft -lbsd
	@valgrind -q --leak-check=full ./Executable && printf "\n${BG_GREEN}${BOLD}${BLACK} FANTASTIC ! ${RESET}\n" || printf "\n${RESET}${BG_RED}${BOLD} FAILED ${RESET}"
	@rm -f ./Executable
	@make -C ../Libft -s fclean
	@printf "\n\n${SUBTITLE}Bonus part${RESET}\n"
	@make -C ../Libft -s bonus || (printf "${BG_YELLOW}${BOLD} NO BONUS ${RESET}\n" && make -C ../Libft -s fclean && exit 1)
	@$(VCW) ./Libft/bonus/*.c -I ../Libft/ -L ../Libft -lft -lbsd
	@valgrind -q --leak-check=full ./Executable && printf "\n${BG_GREEN}${BOLD}${BLACK} THAT'S A BINGO ! ${RESET}\n" || printf "\n${RESET}${BG_RED}${BOLD} PUREE DE POMME DE TERRE ${RESET}"
	@rm -f ./Executable
	@make -C ../Libft -s fclean

## C00 : So it begins
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
	@$(CW) ./C00/ex08.c ../C00/ex08/ft_print_combn.c && ./Executable 2 > ./diff.txt && diff ./diff.txt ./C00/diff08_2 && $(GOOD) && rm -f ./Executable ./diff.txt || printf "${BG_RED}${BOLD} FAILED: n=2 ${RESET}"
	@$(CW) ./C00/ex08.c ../C00/ex08/ft_print_combn.c && ./Executable 3 > ./diff.txt && diff ./diff.txt ./C00/diff08_3 && $(GOOD) && rm -f ./Executable ./diff.txt || printf "${BG_RED}${BOLD} FAILED: n=3 ${RESET}"
	@$(CW) ./C00/ex08.c ../C00/ex08/ft_print_combn.c && ./Executable 7 > ./diff.txt && diff ./diff.txt ./C00/diff08_7 && $(GOOD) && rm -f ./Executable ./diff.txt || printf "${BG_RED}${BOLD} FAILED: n=7 ${RESET}"
	@$(CW) ./C00/ex08.c ../C00/ex08/ft_print_combn.c && ./Executable 9 > ./diff.txt && diff ./diff.txt ./C00/diff08_9 && $(GOOD) && rm -f ./Executable ./diff.txt || printf "${BG_RED}${BOLD} FAILED: n=9 ${RESET}"
	@echo ""


## C01 : Pointers
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

## C02 : string manipulation
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

## C03 : string manipulation 2
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

## C04 : putnbr and atoi
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

## C05 : recursive functions
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

## C06 : main arguments
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

## C07 : malloc and free
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
	@$(CW) ../C07/ex05/ft_split.c ./C07/ex05.c && ./Executable && printf "${BG_GREEN}${BOLD}${BLACK} GOOD ${RESET}" && rm -f ./Executable || printf "${BG_RED}${BOLD} FAILED ${RESET}"
	@echo ""

## C08 : Header files
.PHONY: C08
C08:
	@echo "\n******   Projet C08 : Header files ******"
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../C08 || $(FAILED)
	@echo "\n\n** EX00: ft.h"
	@cp ../C08/ex00/ft.h ./C08/ft.h || echo "FAILED copying ft.h file"
	@$(CW) ./C08/ex00.c && $(XCLEAN_FAIL)
	@rm -f ./C08/ft.h || echo "FAILED removing ft.h file"
	@echo "\n\n** EX01: ft_boolean"
	@cp ../C08/ex01/ft_boolean.h ./C08/ex01/ft_boolean.h || echo "FAILED copying ft.h file"
	@$(CW) ./C08/ex01/main.c
	@./Executable > test1.diff && diff ./test1.diff ./C08/ex01/test1.diff && $(GOOD): no arguments && rm -f ./test1.diff || printf "${BG_RED}${BOLD} FAILED: no arguments ${RESET}"
	@./Executable arg1 > test2.diff && diff ./test2.diff ./C08/ex01/test2.diff && $(GOOD): 1 argument && rm -f ./test2.diff || printf "${BG_RED}${BOLD} FAILED: 1 argument ${RESET}"
	@./Executable arg1 arg2 > test3.diff && diff ./test3.diff ./C08/ex01/test3.diff && $(GOOD): 2 arguments && rm -f ./test3.diff || printf "${BG_RED}${BOLD} FAILED: 2 arguments ${RESET}"
	@rm -f ./C08/ex01/ft_boolean.h ./Executable || echo "FAILED removing ft_boolean files"
	@echo "\n\n** EX02: ft_abs.h"
	@cp ../C08/ex02/ft_abs.h ./C08/ex02/ft_abs.h || echo "FAILED copying ft_abs.h file"
	@$(CW) ./C08/ex02/main.c
	@./Executable 42 > test1.diff && diff ./test1.diff ./C08/ex02/test.diff && $(GOOD): positive number && rm -f ./test1.diff || printf "${BG_RED}${BOLD} FAILED: positive number ${RESET}"
	@./Executable -42 > test2.diff && diff ./test2.diff ./C08/ex02/test.diff && $(GOOD): negative number && rm -f ./test2.diff || printf "${BG_RED}${BOLD} FAILED: negative number ${RESET}"
	@rm -f ./C08/ex02/ft_abs.h ./Executable || echo "FAILED removing ft_abs files"
	@echo "\n\n** EX03: ft_point.h"
	@cp ../C08/ex03/ft_point.h ./C08/ex03/ft_point.h || echo "FAILED copying ft_point.h file"
	@$(CW) ./C08/ex03/main.c && $(XCLEAN_FAIL_OK)
	@rm -f ./C08/ex03/ft_point.h || echo "FAILED removing ft_point.h"
	@echo "\n\n** EX04: ft_strs_to_tab"
	@cp ../C08/ex04/ft_strs_to_tab.c ./C08/ex04/ft_strs_to_tab.c || echo "FAILED copying ft_strs_to_tab.c file"
	@$(CW) ./C08/ex04/*.c && ./Executable test coso cuestion > ./diff.txt && diff ./diff.txt ./C08/ex05/diff_ex05.txt && $(GOOD) && rm -f ./Executable ./diff.txt || printf "${BG_RED}${BOLD} FAILED ${RESET}"
	@rm -f ./C08/ex04/ft_strs_to_tab.c || echo "FAILED removing ft.h file"
	@echo "\n\n** EX05: ft_show_tab.c"
	@cp ../C08/ex05/ft_show_tab.c ./C08/ex05/ft_show_tab.c || echo "FAILED copying ft_strs_to_tab.c file"
	@$(CW) ./C08/ex05/*.c && ./Executable test coso cuestion > ./diff.txt && diff ./diff.txt ./C08/ex05/diff_ex05.txt && $(GOOD) && rm -f ./Executable ./diff.txt || printf "${BG_RED}${BOLD} FAILED ${RESET}"
	@rm -f ./C08/ex05/ft_show_tab.c || echo "FAILED removing ft.h file"
	@echo ""

## C11 : pointer to function
.PHONY: C11
C11:
	@echo "\n******   Projet C11 : pointer to function ******"
	@echo "\n** Testing norminette"
	@norminette -R CheckForbiddenSourceHeader ../C11 && printf "${BG_GREEN}${BOLD}${BLACK} GOOD ${RESET}"  || $(FAILED)
	@echo "\n\n** EX00: ft_foreach"
	@$(CW) ../C11/ex00/ft_foreach.c ./C11/ex00.c && ./Executable > ./diff.txt && diff ./diff.txt ./C11/diff_ex00.txt && printf "${BG_GREEN}${BOLD}${BLACK} GOOD ${RESET}" && rm -f ./Executable || printf "${BG_RED}${BOLD} FAILED ${RESET}"
	@echo "\n\n** EX01: ft_map"
	@$(CW) ../C11/ex01/ft_map.c ./C11/ex01.c && ./Executable && printf "${BG_GREEN}${BOLD}${BLACK} GOOD ${RESET}" && rm -f ./Executable || printf "${BG_RED}${BOLD} FAILED ${RESET}"
	@echo "\n\n** EX02: ft_any"
	@$(CW) ../C11/ex02/ft_any.c ./C11/ex02.c && ./Executable && printf "${BG_GREEN}${BOLD}${BLACK} GOOD ${RESET}" && rm -f ./Executable || printf "${BG_RED}${BOLD} FAILED ${RESET}"
	@echo "\n\n** EX03: ft_count_if"
	@$(CW) ../C11/ex03/ft_count_if.c ./C11/ex03.c && ./Executable && printf "${BG_GREEN}${BOLD}${BLACK} GOOD ${RESET}" && rm -f ./Executable || printf "${BG_RED}${BOLD} FAILED ${RESET}"
	@echo "\n\n** EX04: ft_is_sort"
	@$(CW) ../C11/ex04/ft_is_sort.c ./C11/ex04.c && ./Executable && rm -f ./Executable || printf "${BG_RED}${BOLD} FAILED ${RESET}"
	@echo ""


