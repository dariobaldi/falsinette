#include <stdio.h>
#include <limits.h>
#include "../ft_printf/ft_printf.h"
#include "../utils/constants.h"

typedef struct s_test_input {
    char    *str;
} t_test_input;

void test_func(const char *name, t_test_input *input, int (*f)(const char *str, ...))
{
    int result;


    FILE *fp = freopen(name, "w", stdout);
    if (fp == NULL)
    {
        printf("freopen did not work for %s\n", name);
        return ;
    }
    f("printf(0)");
    result = f(0);
    f("printf(0) result = %d\n", result);
    result = f("Literal and %%\n");
    f("Literal result = %d\n", result);

    result = f("%%c %c %c %c %c", '4', '2', '\0', '\n');
    f("%%c result = %d\n", result);

    result = f("%%s %s", "La Llama que llama\n");
    f("%%s result = %d\n", result);
    result = f("%%s empty string %s\n", "");
    f("%%s empty string result = %d\n", result);
    result = f("%%s NULL string %s\n", 0);
    f("%%s NULL string result = %d\n", result);

    result = f("%%p %p\n", input->str);
    f("%%p result = %d\n", result);
    result = f("%%p 7 15 %p %p\n", 7, 15);
    f("%%p 7 15 result = %d\n", result);
    result = f("%%p LONG_MIN, LONG_MAX %p %p\n", LONG_MIN, LONG_MAX);
    f("%%p LONG_MIN, LONG_MAX result = %d\n", result);
    result = f("%%p ULONG_MAX, -ULONG_MAX %p %p\n", ULONG_MAX, -ULONG_MAX);
    f("%%p ULONG_MAX, -ULONG_MAX result = %d\n", result);
    result = f("%%p NULL %p\n", NULL);
    f("%%p NULL result = %d\n", result);

    result = f("%%d %d %d %d %d %d\n", 42, -42, 0, INT_MAX, INT_MIN);
    f("%%d result = %d\n", result);
    result = f("%%i %i %i %i %i %i\n", 42, -42, 0, INT_MAX, INT_MIN);
    f("%%i result = %d\n", result);

    result = f("%%u %u %u %u\n", 42u, 0u, UINT_MAX);
    f("%%u result = %d\n", result);

    result = f("%%x %x %x %x %x %x\n", 0, 255, -42, INT_MAX, UINT_MAX);
    f("%%x result = %d\n", result);
    result = f("%%X %X %X %X %X %X\n", 0, 255, -42, INT_MAX, UINT_MAX);
    f("%%X result = %d\n", result);

    result = f("Combined %c, %s, %i, %d, %u, %x, %X, %%\n",'Y', "Dale que va\t\n", INT_MIN, INT_MAX, UINT_MAX, 0x242, 0x29575);
    f("Combined result = %d\n", result);
    fclose(fp);
}

int main(void) {
    t_test_input input;

    input.str = "Lo viejo funciona, Juan\n";

    test_func("diff_expected", &input, &printf);
    test_func("diff_result", &input, &ft_printf);

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
    // ft = ft_printf("ft: |%-.48d%-166.126d%--137p%131c%111.86s|\n" ,-1733961224,-1148896912,(void*)17695841004645625598lu,-90,"v-Q/)ZI3");
    // og = printf ("og: |%-.48d%-166.126d%--137p%131c%111.86s|\n" ,-1733961224,-1148896912,(void*)17695841004645625598lu,-90,"v-Q/)ZI3");
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);
    // ft = ft_printf("ft: |as soon as %-16peasible|\n", (void *) (((long int)3 << 42) + 15));
    // og = printf ("og: |as soon as %-16peasible|\n", (void *) (((long int)3 << 42) + 15));
    // if (ft != og)
    //     printf (RED "KO og=%d ft=%d\n" DEFAULT, og, ft);

    return (0);
}
