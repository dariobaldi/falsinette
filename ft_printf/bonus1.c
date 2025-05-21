#include <stdio.h>
#include <limits.h>
#include "../ft_printf/ft_printf.h"
#include "../utils/constants.h"

void test_func(const char *name, int (*f)(const char *str, ...))
{
    int result;

    freopen(name, "w", stdout);
    result = f("- Char basic |%c|\n", 'A');
    f("- Char basic result = %d\n", result);
    result = f("- Char with dash |%-3c|\n", 'B');
    f("- Char with dash result = %d\n", result);
    result = f("- Char with dot (ignored) |%.3c|\n", 'D');
    f("- Char with dot result = %d\n", result);

    result = f("- String basic |%s|\n", "hello");
    f("- String basic result = %d\n", result);
    result = f("- String NULL |%s|\n", NULL);
    f("- String NULL result = %d\n", result);
    result = f("- String with precision |%.3s|\n", "world");
    f("- String with precision result = %d\n", result);
    result = f("- String with dash and precision |%-10.4s|\n", "format");
    f("- String dash/precision result = %d\n", result);
    result = f("- String zero flag (ignored) |%010s|\n", "zero");
    f("- String zero flag result = %d\n", result);


    result = f("- Pointer basic |%p|\n", (void*)1231111);
    f("- Pointer basic result = %d\n", result);
    result = f("- Pointer NULL |%p|\n", NULL);
    f("- Pointer NULL result = %d\n", result);
    result = f("- Pointer with dash |%-20p|\n", (void*)1234);
    f("- Pointer with dash result = %d\n", result);


    result = f("- Int basic |%d|\n", 42);
    f("- Int basic result = %d\n", result);
    result = f("- Int negative |%d|\n", -42);
    f("- Int negative result = %d\n", result);
    result = f("- Int zero |%d|\n", 0);
    f("- Int zero result = %d\n", result);
    result = f("- Int INT_MAX |%d|\n", 2147483647);
    f("- Int INT_MAX result = %d\n", result);
    result = f("- Int INT_MIN |%d|\n", -2147483648);
    f("- Int INT_MIN result = %d\n", result);
    result = f("- Int precision |%.5d|\n", 42);
    f("- Int precision result = %d\n", result);
    result = f("- Int width + zero |%05d|\n", 42);
    f("- Int width + zero result = %d\n", result);
    result = f("- Int width + dash |%-5d|\n", 42);
    f("- Int width + dash result = %d\n", result);
    result = f("- Int width + zero + precision |%08.3d|\n", 42);
    f("- Int width + zero + precision result = %d\n", result);


    result = f("- Unsigned basic |%u|\n", 42);
    f("- Unsigned basic result = %d\n", result);
    result = f("- Unsigned zero |%u|\n", 0);
    f("- Unsigned zero result = %d\n", result);
    result = f("- Unsigned max |%u|\n", 4294967295u);
    f("- Unsigned max result = %d\n", result);
    result = f("- Unsigned precision |%.6u|\n", 123);
    f("- Unsigned precision result = %d\n", result);
    result = f("- Unsigned dash |%-8u|\n", 123);
    f("- Unsigned dash result = %d\n", result);
    result = f("- Unsigned zero flag |%010u|\n", 123);
    f("- Unsigned zero flag result = %d\n", result);
    result = f("- Unsigned all flags |%-010.5u|\n", 123);
    f("- Unsigned all flags result = %d\n", result);


    result = f("- Hex lowercase |%x|\n", 255);
    f("- Hex lowercase result = %d\n", result);
    result = f("- Hex uppercase |%X|\n", 255);
    f("- Hex uppercase result = %d\n", result);
    result = f("- Hex zero |%x|\n", 0);
    f("- Hex zero result = %d\n", result);
    result = f("- Hex precision |%.4x|\n", 42);
    f("- Hex precision result = %d\n", result);
    result = f("- Hex dash |%-8x|\n", 42);
    f("- Hex dash result = %d\n", result);
    result = f("- Hex zero flag |%08x|\n", 42);
    f("- Hex zero flag result = %d\n", result);
    result = f("- Hex all flags |%-08.5x|\n", 42);
    f("- Hex all flags result = %d\n", result);

    result = f("- Percent basic |%%|\n");
    f("- Percent basic result = %d\n", result);
    result = f("- Percent with width |%5%|\n");
    f("- Percent with width result = %d\n", result);
    result = f("- Percent with dash |%-5%|\n");
    f("- Percent with dash result = %d\n", result);
    result = f("- Percent with zero |%05%|\n");
    f("- Percent with zero result = %d\n", result);
}

int main(void) {

    test_func("diff_expected", &printf);
    test_func("diff_result", &ft_printf);

    return (0);
}
