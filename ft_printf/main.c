#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

void test_section(const char *desc) {
    printf("\n--- %s ---\n", desc);
}

int main(void) {
    char *null_str = NULL;
    int a = 42;
    void *ptr = &a;

    test_section("1. Literal and %%");
    ft_printf("ft: Hello, world!\n");
    printf ("og: Hello, world!\n");
    ft_printf("ft: %%\n");
    printf ("og: %%\n");

    test_section("2. %c");
    ft_printf("ft: %c\n", 'A');
    printf ("og: %c\n", 'A');
    ft_printf("ft: %c\n", '\0');
    printf ("og: %c\n", '\0');

    test_section("3. %s");
    ft_printf("ft: %s\n", "Hello");
    printf ("og: %s\n", "Hello");
    ft_printf("ft: %s\n", null_str);
    printf ("og: %s\n", null_str);
    ft_printf("ft: %s\n", "");
    printf ("og: %s\n", "");

    test_section("4. %p");
    ft_printf("ft: %p\n", ptr);
    printf ("og: %p\n", ptr);
    ft_printf("ft: %p\n", NULL);
    printf ("og: %p\n", NULL);

    test_section("5. %d / %i");
    ft_printf("ft: %d %d %d %d\n", 42, -42, 0, INT_MAX);
    printf ("og: %d %d %d %d\n", 42, -42, 0, INT_MAX);
    ft_printf("ft: %i %i\n", INT_MIN, 0);
    printf ("og: %i %i\n", INT_MIN, 0);

    test_section("6. %u");
    ft_printf("ft: %u %u\n", 42u, 0u);
    printf ("og: %u %u\n", 42u, 0u);
    ft_printf("ft: %u\n", UINT_MAX);
    printf ("og: %u\n", UINT_MAX);

    test_section("7. %x / %X");
    ft_printf("ft: %x %X\n", 255, 255);
    printf ("og: %x %X\n", 255, 255);
    ft_printf("ft: %x %X\n", 0, UINT_MAX);
    printf ("og: %x %X\n", 0, UINT_MAX);

    test_section("8. Flags: -");
    ft_printf("ft: %-10s!\n", "left");
    printf ("og: %-10s!\n", "left");
    ft_printf("ft: %-5d!\n", 123);
    printf ("og: %-5d!\n", 123);

    test_section("9. Flags: 0");
    ft_printf("ft: %05d!\n", 42);
    printf ("og: %05d!\n", 42);
    ft_printf("ft: %05x!\n", 0x42);
    printf ("og: %05x!\n", 0x42);

    test_section("10. Flags: . precision");
    ft_printf("ft: %.5d!\n", 42);
    printf ("og: %.5d!\n", 42);
    ft_printf("ft: %.3s!\n", "hello");
    printf ("og: %.3s!\n", "hello");
    ft_printf("ft: %.0d!\n", 0);
    printf ("og: %.0d!\n", 0);

    test_section("11. Field width");
    ft_printf("ft: %10s!\n", "test");
    printf ("og: %10s!\n", "test");
    ft_printf("ft: %4d!\n", 123);
    printf ("og: %4d!\n", 123);

    test_section("12. Flag: #");
    ft_printf("ft: %#x %#X\n", 255, 255);
    printf ("og: %#x %#X\n", 255, 255);

    test_section("13. Flag: +");
    ft_printf("ft: %+d %+d %+d\n", 42, 0, -42);
    printf ("og: %+d %+d %+d\n", 42, 0, -42);

    test_section("14. Flag: space");
    ft_printf("ft: % d % d % d\n", 42, 0, -42);
    printf ("og: % d % d % d\n", 42, 0, -42);

    test_section("15. Flag combinations");
    ft_printf("ft: %-+10d!\n", 42);
    printf ("og: %-+10d!\n", 42);
    ft_printf("ft: %+010d!\n", 42);
    printf ("og: %+010d!\n", 42);
    ft_printf("ft: % 010d!\n", 42);
    printf ("og: % 010d!\n", 42);
    // ft_printf("ft: %-08d!\n", 42);  // '-' overrides '0'
    // printf ("og: %-08d!\n", 42);

    test_section("16. Multiple arguments");
    ft_printf("ft: %s %d %#x\n", "Number", 42, 255);
    printf ("og: %s %d %#x\n", "Number", 42, 255);

    test_section("17. Return value test");
    int r1 = printf("ft: %d %s\n", 123, "abc");
    int r2 = printf ("og: %d %s\n", 123, "abc");
    printf("Return values: ft = %d, og = %d\n", r1, r2);

    return 0;
}
