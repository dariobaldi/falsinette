#include <stdio.h>
#include <limits.h>
#include "../ft_printf/ft_printf.h"
#include "../utils/constants.h"

void test_section(const char *desc) {
    printf("\n--- %s ---\n", desc);
}

int main(void) {
    char *null_str = NULL;
    int a = 42;
    void *ptr = &a;

    int og, ft;

    // test_section("0. printf(0)");
    // ft = ft_printf(0);
    // og = printf (0);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    // test_section("1. Literal and %%");
    // ft = ft_printf("ft: Hello, world!\n");
    // og = printf ("og: Hello, world!\n");
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %%\n");
    // og = printf ("og: %%\n");
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    // test_section("2. %c");
    // ft = ft_printf("ft: %c\n", 'A');
    // og = printf ("og: %c\n", 'A');
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %c\n", '\0');
    // og = printf ("og: %c\n", '\0');
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %c\n", '4');
    // og = printf ("og: %c\n", '4');
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    // test_section("3. %s");
    // ft = ft_printf("ft: %s\n", "Hello");
    // og = printf ("og: %s\n", "Hello");
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft Null char *: %s\n", null_str);
    // og = printf ("og Null char *: %s\n", null_str);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft Empty string: %s\n", "");
    // og = printf ("og Empty string: %s\n", "");
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    // test_section("4. %p");
    // ft = ft_printf("ft: %p\n", ptr);
    // og = printf ("og: %p\n", ptr);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %p %p\n", 7, 15);
    // og = printf ("og: %p %p\n", 7, 15);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %p %p\n", LONG_MIN, LONG_MAX);
    // og = printf ("og: %p %p\n", LONG_MIN, LONG_MAX);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %p %p\n", ULONG_MAX, -ULONG_MAX);
    // og = printf ("og: %p %p\n", ULONG_MAX, -ULONG_MAX);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %p\n", NULL);
    // og = printf ("og: %p\n", NULL);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    // test_section("5. %d / %i");
    // ft = ft_printf("ft: %d %d %d %d\n", 42, -42, 0, INT_MAX);
    // og = printf ("og: %d %d %d %d\n", 42, -42, 0, INT_MAX);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %i %i\n", INT_MIN, 0);
    // og = printf ("og: %i %i\n", INT_MIN, 0);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    // test_section("6. %u");
    // ft = ft_printf("ft: %u %u\n", 42u, 0u);
    // og = printf ("og: %u %u\n", 42u, 0u);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %u\n", UINT_MAX);
    // og = printf ("og: %u\n", UINT_MAX);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    // test_section("7. %x / %X");
    // ft = ft_printf("ft: %x %X\n", 255, 255);
    // og = printf ("og: %x %X\n", 255, 255);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %x %X\n", INT_MAX, -42);
    // og = printf ("og: %x %X\n", INT_MAX, -42);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %x %X\n", 0, UINT_MAX);
    // og = printf ("og: %x %X\n", 0, UINT_MAX);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    // test_section("8. Flags: -");
    // ft = ft_printf("ft: %-10s!\n", "left");
    // og = printf ("og: %-10s!\n", "left");
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %-5d!\n", 123);
    // og = printf ("og: %-5d!\n", 123);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %-5d!\n", 1231111);
    // og = printf ("og: %-5d!\n", 1231111);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    // test_section("9. Flags: 0");
    // ft = ft_printf("ft: %05d!\n", 42);
    // og = printf ("og: %05d!\n", 42);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %05x!\n", 42);
    // og = printf ("og: %05x!\n", 42);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    // test_section("10. Flags: . precision");
    // ft = ft_printf("ft: %-8.5d!\n", -42);
    // og = printf ("og: %-8.5d!\n", -42);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %-8.5d!\n", 4242);
    // og = printf ("og: %-8.5d!\n", 4242);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %-8.5d!\n", 0);
    // og = printf ("og: %-8.5d!\n", 0);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %.5d!\n", 21);
    // og = printf ("og: %.5d!\n", 21);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %8.5d!\n", 123);
    // og = printf ("og: %8.5d!\n", 123);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %5d!\n", 7891);
    // og = printf ("og: %5d!\n", 7891);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %.3s!\n", "hello");
    // og = printf ("og: %.3s!\n", "hello");
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %.0d!\n", 0);
    // og = printf ("og: %.0d!\n", 0);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    // test_section("11. Field width");
    // ft = ft_printf("ft: %10s!\n", "test");
    // og = printf ("og: %10s!\n", "test");
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %4d!\n", 123);
    // og = printf ("og: %4d!\n", 123);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    // test_section("12. Flag: #");
    // ft = ft_printf("ft: %#x %#X %#x %#X\n", 255, 255, 0, 0);
    // og = printf ("og: %#x %#X %#x %#X\n", 255, 255, 0, 0);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    // test_section("13. Flag: +");
    // ft = ft_printf("ft: %+d %+d %+d\n", 42, 0, -42);
    // og = printf ("og: %+d %+d %+d\n", 42, 0, -42);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    // test_section("14. Flag: space");
    // ft = ft_printf("ft: % d % d % d\n", 42, 0, -42);
    // og = printf ("og: % d % d % d\n", 42, 0, -42);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    // test_section("15. Flag combinations");
    // ft = ft_printf("ft: %-+10d!\n", 42);
    // og = printf ("og: %-+10d!\n", 42);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %+010d!\n", 42);
    // og = printf ("og: %+010d!\n", 42);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: % 010d!\n", 42);
    // og = printf ("og: % 010d!\n", 42);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %-08d!\n", 42);  // '-' overrides '0'
    // og = printf ("og: %-08d!\n", 42);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    // test_section("16. Multiple arguments");
    // ft = ft_printf("ft: %s %d %#x\n", "Number", 42, 255);
    // og = printf ("og: %s %d %#x\n", "Number", 42, 255);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    // test_section("17. Tests Francinette");
    // ft = ft_printf("ft: %23s\n", NULL);
    // og = printf ("og: %23s\n", NULL);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %.s\n", NULL);
    // og = printf ("og: %.s\n", NULL);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %-5s!\n", "abc");
    // og = printf ("og: %-5s!\n", "abc");
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %7.5s\n", "yolo");
    // og = printf ("og: %7.5s\n", "yolo");
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %7.5s\n", "bombastic");
    // og = printf ("og: %7.5s\n", "bombastic");
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: %.03s\n", NULL);
    // og = printf ("og: %.03s\n", NULL);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: |%7i|\n", -14);
    // og = printf ("og: |%7i|\n", -14);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: |%3i|\n", 13862);
    // og = printf ("og: |%3i|\n", 13862);
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    ft = ft_printf("ft: |%038.4x%97p%030.48X|\n" ,3857355889u,(void*)807170435392081871lu,1801588532u);
    og = printf ("og: |%038.4x%97p%030.48X|\n" ,3857355889u,(void*)807170435392081871lu,1801588532u);
    if (ft != og)
        printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    return 0;
}
