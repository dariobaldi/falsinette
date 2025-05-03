#include "ft.h"

typedef void (*IteriFunc)(unsigned int, char*);

void ft_odd_toupper2(unsigned int i, char *c)
{
    if (i % 2 != 0)
        *c = toupper(*c);
    else
        *c = tolower(*c);
}

typedef struct s_test
{
    char *desc;
    char *s;
    IteriFunc f;
    char *expected;
} t_test;

static int run_tests(t_test *tests, int count);

int ft_striteri_test()
{
    t_test tests[] = {
        {
             .desc = "Basic case:",
             .s = "Is this going to work?",
             .f = &ft_odd_toupper2,
             .expected = "iS ThIs gOiNg tO WoRk?",
        },
        {
             .desc = "Empty string:",
             .s = "",
             .f = &ft_odd_toupper2,
             .expected = "",
        },
        {
             .desc = "s == NULL",
             .s = NULL,
             .f = &ft_odd_toupper2,
             .expected = NULL,
        },
        {
             .desc = "f == NULL",
             .s = "Does this work too?",
             .f = NULL,
             .expected = "Does this work too?",
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
        char *result = NULL;
        if (tests[i].s)
            result = strdup(tests[i].s);
        ft_striteri(result, tests[i].f);

        if (!result && !tests[i].expected)
        {
            printf(GREEN CHECKMARK GREY " [%d] %s\n" DEFAULT, i + 1, tests[i].desc);
        }
        else if (!result || !tests[i].expected)
        {
            printf(RED "[%d] %s got \"%s\" instead of \"%s\"\n" DEFAULT, i + 1, tests[i].desc, result, tests[i].expected);
            error++;
        }
        else if (strcmp(result, tests[i].expected) != 0)
        {
            printf(RED "[%d] %s got \"%s\" instead of \"%s\"\n" DEFAULT, i + 1, tests[i].desc, result, tests[i].expected);
            error++;
        }
        else
        {
            printf(GREEN CHECKMARK GREY " [%d] %s got \"%s\" as expected\n" DEFAULT, i + 1, tests[i].desc, result);
        }

        if (result)
            free(result);
    }

    return (error);
}