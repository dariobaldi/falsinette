#include "ft.h"

typedef struct s_test
{
    char *desc;
    char *s1;
    char *s2;
    char *expected;
} t_test;

static int run_tests(t_test *tests, int count);

int ft_strjoin_test()
{
    t_test tests[] = {
        {
             .desc = "Basic test:",
             .s1 = "Weisst du schon ",
             .s2 = "wie schoen das ist",
             .expected = "Weisst du schon wie schoen das ist",
        },
        {
            .desc = "Empty s1:",
            .s1 = "",
            .s2 = "ein Apfelbaum und Pferdemist",
            .expected = "ein Apfelbaum und Pferdemist",
        },
        {
            .desc = "Empty s2:",
            .s1 = "und Wolken, die sich selber ziehen",
            .s2 = "",
            .expected = "und Wolken, die sich selber ziehen",
        },
        {
            .desc = "Both empty:",
            .s1 = "",
            .s2 = "",
            .expected = "",
        },
        {
            .desc = "NULL s1",
            .s1 = NULL,
            .s2 = "und Wolken, die sich selber ziehen",
            .expected = NULL,
        },
        {
            .desc = "NULL s2",
            .s1 = "und Wolken, die sich selber ziehen",
            .s2 = NULL,
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
        char *result = ft_strjoin(tests[i].s1, tests[i].s2);

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