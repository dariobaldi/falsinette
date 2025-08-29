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

# $(call MEMCHECK,title, args, stdin)
define MEMCHECK
	@echo -n "\n$(1):"
	@rm -f ./mem_check; \
	printf "$(3)" | valgrind --error-exitcode=123 --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all \
		./pipex $(2) > mem_check 2>&1; \
	exit_code=$$?; \
	if [ $$exit_code -eq 123 ]; then \
		printf "${BG_RED}${BOLD} Valgrind ${RESET}\n"; \
		cat mem_check; \
		echo ; \
	else \
		printf " ✅${GREEN}${BOLD}Valgrind ${RESET}(exit $$exit_code) "; \
	fi;
	@if command -v funcheck > /dev/null 2>&1; then \
		rm -f ./mem_check && printf "$(3)" | funcheck -a ./pipex $(2) > mem_check 2>&1; \
		grep -q -E "failed|not freed|invalid" mem_check && (printf "${BG_RED}${BOLD} Funcheck ${RESET}\n" && cat mem_check && echo) || printf " ✅${GREEN}${BOLD}Funcheck ${RESET}" ; \
	else \
		printf "${BG_RED}${BOLD} Funcheck not installed ${RESET}\n"; \
	fi
	@rm -f mem_check;
endef

# $(call RUNTEST,title, args, stdin)
define RUNTEST
	@echo -n "\n$(1):"; \
	rm -f ./pipex_out ./bash_out ./pipex_err ./bash_err; \
	# Parse arguments \
	set -- $(2); \
	if [ "$$1" = "here_doc" ]; then \
		limiter=$$2; shift 2; \
		outfile=$${!#}; \
		unset argv[$$#]; \
		cmds=""; \
		for arg; do cmds="$$cmds | $$arg"; done; \
		cmds=$${cmds# | }; \
		if [ -n "$(3)" ]; then \
			printf "$(3)" | timeout 5 ./pipex here_doc $$limiter $$cmds $$outfile > ./pipex_out 2>./pipex_err; \
			exit_pipex=$$?; \
			printf "$(3)" | timeout 5 bash -c "$${cmds} > $$outfile" > ./bash_out 2>./bash_err; \
			exit_bash=$$?; \
		else \
			timeout 5 ./pipex here_doc $$limiter $$cmds $$outfile > ./pipex_out 2>./pipex_err; \
			exit_pipex=$$?; \
			timeout 5 bash -c "$${cmds} > $$outfile" > ./bash_out 2>./bash_err; \
			exit_bash=$$?; \
		fi; \
	else \
		infile=$$1; shift; \
		outfile=$${!#}; \
		unset argv[$$#]; \
		cmds=""; \
		for arg; do cmds="$$cmds | $$arg"; done; \
		cmds=$${cmds# | }; \
		if [ -n "$(3)" ]; then \
			printf "$(3)" | timeout 5 ./pipex $$infile $$cmds $$outfile > ./pipex_out 2>./pipex_err; \
			exit_pipex=$$?; \
			printf "$(3)" | timeout 5 bash -c "cat < $$infile $$cmds > $$outfile" > ./bash_out 2>./bash_err; \
			exit_bash=$$?; \
		else \
			timeout 5 ./pipex $$infile $$cmds $$outfile > ./pipex_out 2>./pipex_err; \
			exit_pipex=$$?; \
			timeout 5 bash -c "cat < $$infile $$cmds > $$outfile" > ./bash_out 2>./bash_err; \
			exit_bash=$$?; \
		fi; \
	fi; \
	if [ $$exit_pipex -ne $$exit_bash ]; then \
		printf "${BG_RED}${BOLD} Exit mismatch (pipex=$$exit_pipex, bash=$$exit_bash) ${RESET}\n"; \
	else \
		if diff -q ./pipex_out ./bash_out >/dev/null 2>&1; then \
			printf " ✅${GREEN}${BOLD}Output+Exit OK ${RESET}"; \
		else \
			printf "${BG_RED}${BOLD} Output mismatch ${RESET}\n"; \
			diff -u ./bash_out ./pipex_out || true; \
		fi; \
	fi; \
	if [ -s ./pipex_err ] || [ -s ./bash_err ]; then \
		echo "\n--- pipex stderr ---"; cat ./pipex_err; \
		echo "--- bash stderr ---"; cat ./bash_err; \
	fi; \
	rm -f ./pipex_out ./bash_out ./pipex_err ./bash_err
endef



prepare:
	@echo "📂 Preparing test files..."
	@echo -e "hello\nworld\npipex" > input
	@touch empty
	@echo "secret data" > secret && chmod 000 secret
	@touch out_noperm && chmod 000 out_noperm
	@yes "pipex test line" | head -n 10000 > bigfile
	@echo "Done ✅"

clean_tests:
	@echo "🧹 Cleaning test files..."
	@rm -f input empty secret out_noperm bigfile output nofile
	@chmod 644 secret out_noperm 2>/dev/null || true
	@echo "Cleaned ✅"

# ============================================================================= #
# TEST																			#
# ============================================================================= #

## test : test current exo
.PHONY: test
test: prepare
	@clear
	@make -C ../../pipex -s pipex
	@mv ../../pipex/pipex ./pipex
	@printf "\n\n${SUBTITLE}Checking leaks and malloc protections${RESET}"
	@$(call RUNTEST,"R1.Basic","input cat wc -l output")
	@$(call RUNTEST,"R2.Three cmds","input cat grep pipex wc -l output")
	@$(call RUNTEST,"R3.Here_doc basic","here_doc END cat wc -l output_hd","hello\nworld\npipex\nEND\n")
	@$(call RUNTEST,"R4.Here_doc multiple","here_doc FINISH tr a-z A-Z grep PIPEX wc -l output_hd","foo\npipex\nbar\nFINISH\n")
	@echo
	@make clean_tests

.PHONY: pipex
pipex: prepare
	@clear
	@printf "\n\t${TITLE}Pipex${RESET} : Go dance salsa somewhere! :)\n\n"
	@printf "${SUBTITLE}----------------> Mandatory <----------------${RESET}\n\n"
	@printf "${SUBTITLE}Run norminette${RESET}\n"
	@rm -f norm_file && norminette ../../pipex > norm_file || echo -n
	@grep Error norm_file && $(FAILED_NORM) || printf "${BG_GREEN}${BOLD}${BLACK} NORM: PASSES ${RESET}\n"
	@rm -f norm_file
	@printf "\n\n${SUBTITLE}Checking files${RESET}\n"
	@find ../../pipex -type f -not -name "*.c" -not -name "*.h" -not -name "Makefile" -not -path "../../pipex/.git/*" -not -name ".gitignore" | grep . && printf "Turn in files: ${BG_RED}${BOLD} FAILED: files not allowed ${RESET}" || printf "Turn in files:${GREEN}${BOLD} OK ${RESET}"
	@grep wildcard -q ../../pipex/Makefile && printf "\nWildcard:${BG_RED}${BOLD} FAILED ${RESET}" || printf "\nWildcard:${GREEN}${BOLD} OK ${RESET}"
	@printf "\nFlags:" && grep -q -- '-Wall' ../../pipex/Makefile && 	grep -q -- '-Werror' ../../pipex/Makefile && 	grep -q -- '-Wextra' ../../pipex/Makefile && printf "${GREEN}${BOLD} OK ${RESET}" || printf "${BG_RED}${BOLD} FAILED ${RESET}"
	@if [ -d "../../pipex/libft" ]; then \
		if grep -q -- '-Wall' ../../pipex/libft/Makefile && \
		grep -q -- '-Werror' ../../pipex/libft/Makefile && \
		grep -q -- '-Wextra' ../../pipex/libft/Makefile; then \
			printf "${GREEN}${BOLD} Libft OK ${RESET}\n"; \
		else \
			printf "${BG_RED}${BOLD} FAILED for Libft Makefile ${RESET}\n"; \
		fi; \
	fi
	@printf "\n\n${SUBTITLE}Checking make command${RESET}\n"
	@printf "pipex:" && make -C ../../pipex -s pipex && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@printf "No relink:" && make -C ../../pipex | grep -q 'is up to date' && printf "${GREEN}${BOLD} OK ${RESET}\n" || printf "${BG_RED}${BOLD} FAILED ${RESET}\n"
	@mv ../../pipex/pipex ./pipex && make -C ../../pipex -s fclean
	@printf "\n\n${SUBTITLE}Checking leaks and malloc protections${RESET}"
	@$(call MEMCHECK,"0.Empty input",) 
	@$(call MEMCHECK,"1.Basic","input" "cat" "wc -l" "output")
	@$(call MEMCHECK,"2.Basic","input" "ls -la" "grep pipex" "output")
	@$(call MEMCHECK,"3.Space in command","input" "echo hello world" "wc -w" "output")
	@$(call MEMCHECK,"4.Input exists","input" "cat" "wc -c" "output")
	@$(call MEMCHECK,"5.Input does not exist","nofile" "cat" "wc -c" "output")
	@$(call MEMCHECK,"6.Empty input file","empty" "cat" "wc -c" "output")
	@$(call MEMCHECK,"7.No read permission input","secret" "cat" "wc -c" "output")
	@$(call MEMCHECK,"8.No write permission output","input" "cat" "wc -c" "out_noperm")
	@$(call MEMCHECK,"9.Invalid command","input" "doesnotexist" "wc -l" "output")
	@$(call MEMCHECK,"10.Empty command","input" "" "wc -l" "output")@$(call MEMCHECK,"11.Binary output","/bin/ls" "cat" "wc -c" "output")
	@$(call MEMCHECK,"12.Redirect to /dev/null","input" "cat" "wc -c" "/dev/null")
	@$(call MEMCHECK,"13.Large input","bigfile" "wc -l" "wc -c" "output")
	@$(call MEMCHECK,"14.Same infile and outfile","input" "cat" "wc -l" "input")
	@$(call MEMCHECK,"15.Command with quotes","input" "echo 'hello world'" "wc -w" "output")
	@$(call MEMCHECK,"16.Chain grep","input" "grep hello" "grep pipex" "output")
	@printf "\n\n${SUBTITLE}Error management${RESET}\n"
	@printf "\n\n${SUBTITLE}Checking leaks and malloc protections${RESET}"
	@$(call MEMCHECK,"B1.Three commands","input" "cat" "grep pipex" "wc -l" "output")
	@$(call MEMCHECK,"B2.Four commands","input" "cat" "tr a-z A-Z" "sort" "uniq" "output")
	@$(call MEMCHECK,"B3.Command not found in chain","input" "cat" "doesnotexist" "wc -l" "output")
	@$(call MEMCHECK,"B4.Large chain","input" "cat" "grep pipex" "grep hello" "wc -c" "sort" "uniq" "wc -l" "output")
	@make clean_tests