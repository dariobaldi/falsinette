#include <stdio.h>
#include <limits.h>
#include "../ft_printf/ft_printf.h"
#include "../utils/constants.h"

void test_func(const char *name, int (*f)(const char *str, ...))
{
    int result;

    freopen(name, "w", stdout);
    result = f("- Width only      |%5d|\n", 42);
    f("- Width only result = %d\n", result);
    result = f("- Plus sign       |%+d|\n", 42);
    f("- Plus sign result = %d\n", result);
    result = f("- Space flag      |% d|\n", 42);
    f("- Space flag result = %d\n", result);
    result = f("- Plus overrides space |% +d|\n", 42);
    f("- Plus overrides space result = %d\n", result);
    result = f("- Negative number |%+d|\n", -42);
    f("- Negative number result = %d\n", result);
    result = f("- Zero flag       |%05d|\n", 42);
    f("- Zero flag result = %d\n", result);
    result = f("- Zero and plus   |%+05d|\n", 42);
    f("- Zero and plus result = %d\n", result);
    result = f("- Zero and space  |% 05d|\n", 42);
    f("- Zero and space result = %d\n", result);
    result = f("- Precision only  |%.4d|\n", 42);
    f("- Precision only result = %d\n", result);
    result = f("- Dash and width  |%-6d|\n", 42);
    f("- Dash and width result = %d\n", result);
    result = f("- All flags       |%+0- 10.5d|\n", 42);
    f("- All flags result = %d\n", result);
    result = f("- Int zero        |%+5.0d|\n", 0);
    f("- Int zero result = %d\n", result);
    result = f("- Int INT_MAX     |%+d|\n", 2147483647);
    f("- Int INT_MAX result = %d\n", result);
    result = f("- Int INT_MIN     |%+d|\n", -2147483648);
    f("- Int INT_MIN result = %d\n", result);

    result = f("- Unsigned width     |%6u|\n", 123);
    f("- Unsigned width result = %d\n", result);
    result = f("- Unsigned zero      |%06u|\n", 123);
    f("- Unsigned zero result = %d\n", result);
    result = f("- Unsigned precision |%.5u|\n", 123);
    f("- Unsigned precision result = %d\n", result);
    result = f("- Unsigned all flags |%-0 10.5u|\n", 123);
    f("- Unsigned all flags result = %d\n", result);
    result = f("- Unsigned max       |%u|\n", 4294967295u);
    f("- Unsigned max result = %d\n", result);

    result = f("- Hex basic         |%x|\n", 48879);
    f("- Hex basic result = %d\n", result);
    result = f("- Hex alternate     |%#x|\n", 48879);
    f("- Hex alternate result = %d\n", result);
    result = f("- Hex alternate 0   |%#x|\n", 0);
    f("- Hex alternate 0 result = %d\n", result);
    result = f("- Hex upper + alt   |%#X|\n", 48879);
    f("- Hex upper + alt result = %d\n", result);
    result = f("- Hex zero-padded   |%08x|\n", 48879);
    f("- Hex zero-padded result = %d\n", result);
    result = f("- Hex all flags     |%-#010.6x|\n", 48879);
    f("- Hex all flags result = %d\n", result);
}

int main(void) {

    test_func("diff_expected", &printf);
    test_func("diff_result", &ft_printf);

    return (0);
}
