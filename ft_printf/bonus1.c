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

    freopen(name, "w", stdout);
    result = f("- flag c %-15c!\n", 'A');
    f("- flag c result = %d\n", result);
    result = f("- flag string %-10s!\n", "left");
    f("- flag string result = %d\n", result);

    result = f("- flag number %-5d!\n", 123);
    f("- flag number result = %d\n", result);
    result = f("- flag bigger number than width %-5d!\n", 1231111);
    f("- flag bigger number than width result = %d\n", result);

    result = f("- flag number %-5i!\n", 123);
    f("- flag number result = %i\n", result);
    result = f("- flag bigger number than width %-5i!\n", 1231111);
    f("- flag bigger number than width result = %i\n", result);

    result = f("- flag number %-5u!\n", 123);
    f("- flag number result = %u\n", result);
    result = f("- flag bigger number than width %-5u!\n", 1231111);
    f("- flag bigger number than width result = %u\n", result);

    result = f("- flag pointer %-15p!\n", 1231111);
    f("- flag pointer result = %d\n", result);
    
    result = f("- flag x %-15x!\n", 1231111);
    f("- flag x result = %d\n", result);
    result = f("- flag X %-15X!\n", 1231111);
    f("- flag X result = %d\n", result);
}

int main(void) {
    t_test_input input;

    input.str = "Lo viejo funciona, Juan\n";

    test_func("diff_expected", &input, &printf);
    test_func("diff_result", &input, &ft_printf);

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
