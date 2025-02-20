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
	@echo test


## c00/ex00 : ft_putchar 
.PHONY: c00/ex00
c00/ex00:
	@norminette ../c00/ex00/
	@cc -Wall -Werror -Wextra -oExe ./c00/ex00.c ../c00/ex00/ft_putchar.c && ./Exe && rm -f ./Exe
