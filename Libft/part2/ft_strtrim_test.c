#include "ft.h"

typedef struct s_test
{
    char *desc;
    char *s1;
    char *set;
    char *expected;
} t_test;

static int run_tests(t_test *tests, int count);

int ft_strtrim_test()
{
    t_test tests[] = {
        {
             .desc = "Normal case:",
             .s1 = "123Weisst du schon321",
             .set = "123",
             .expected = "Weisst du schon",
        },
        {
            .desc = "Characters to trim are also in the middle:",
            .s1 = "123Weisst d123 u schon321",
            .set = "123 ",
            .expected = "Weisst d123 u schon",
        },
        {
            .desc = "No characters to trim:",
            .s1 = "El Eternauta",
            .set = "",
            .expected = "El Eternauta",
        },
        {
            .desc = "String is fully made of trim characters:",
            .s1 = "165324845016487984500164451",
            .set = "0123456789",
            .expected = "",
        },
        {
            .desc = "Empty input string:",
            .s1 = "",
            .set = "0123456789",
            .expected = "",
        },
        {
            .desc = "Both Empty:",
            .s1 = "",
            .set = "",
            .expected = "",
        },
        {
            .desc = "One character in the middle",
            .s1 = "130840a2084021",
            .set = "0123456789",
            .expected = "a",
        },
        {
            .desc = "s1 NULL",
            .s1 = NULL,
            .set = "0123456789",
            .expected = NULL,
        },
        {
            .desc = "set NULL",
            .s1 = "0123456789",
            .set = NULL,
            .expected = NULL,
        },
    };
    int count = sizeof(tests) / sizeof(tests[0]);

    return run_tests(tests, count);
}

static int run_tests(t_test *tests, int count)
{
    int i;
    int error = 0;

    for (i = 0; i < count; i++)
    {
        char *result = ft_strtrim(tests[i].s1, tests[i].set);

        if (!result && !tests[i].expected)
        {
            // printf(GREEN CHECKMARK GREY "\n [%d] %s" DEFAULT, i + 1, tests[i].desc);
        }
        else if (!result || !tests[i].expected)
        {
            printf(RED "\n[%d] %s got \"%s\" instead of \"%s\"" DEFAULT, i + 1, tests[i].desc, result, tests[i].expected);
            error++;
        }
        else if (strcmp(result, tests[i].expected) != 0)
        {
            printf(RED "\n[%d] %s got \"%s\" instead of \"%s\"" DEFAULT, i + 1, tests[i].desc, result, tests[i].expected);
            error++;
        }
        else
        {
            // printf(GREEN CHECKMARK GREY "\n [%d] %s got \"%s\" as expected" DEFAULT, i + 1, tests[i].desc, result);
        }

        if (result)
            free(result);
    }

    if (error == 0)
        printf(GREEN "OK" DEFAULT);
    return (error);
}