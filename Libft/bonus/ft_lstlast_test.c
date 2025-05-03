#include "ft.h"

typedef struct s_test
{
    char **strs;
    char *expected;
} t_test;

static int run_tests(t_test *tests, int count);

int ft_lstlast_test()
{
    t_test tests[] = {
        {
            .strs = (char *[2]){"hello", 0},
            .expected = "hello",
        },
        {
            .strs = (char *[3]){"hello", "darkness", 0},
            .expected = "darkness",
        },
        {
            .strs = (char *[4]){"hello", "darkness", "my", 0},
            .expected = "my",
        },
        {
            .strs = (char *[5]){"hello", "darkness", "my", "old", 0},
            .expected = "old",
        },
        {
            .strs = (char *[6]){"hello", "darkness", "my", "old", "friend", 0},
            .expected = "friend",
        },
    };
    
    int count = sizeof(tests) / sizeof(tests[0]);

    int errors = run_tests(tests, count);
    if (errors == 0)
        printf(GREEN "OK" DEFAULT);
    return (errors);
}

static int run_tests(t_test *tests, int count)
{
    int i;
    t_list *result;
    int errors = 0;
    int error;
    
    for (i = 0; i < count; i++)
    {
        t_list *lst;
        error = 0;
        lst = create_linked_list((void **)tests[i].strs, strslen(tests[i].strs));
        result = ft_lstlast(lst);

        if (!result)
        {
            errors++;
            printf(RED "\n[%d] Returned NULL element" DEFAULT, i + 1);
        }
        else if (!result->content)
        {
            errors++;
            printf(RED "\n[%d] Empty content" DEFAULT, i + 1);
        }
        else if (strcmp(tests[i].expected, (char *)result->content))
        {
            errors++;
            printf(RED "\n[%d] expected \"%s\" got \"%s\"" DEFAULT, i + 1, tests[i].expected, (char *)result->content);
        }
        else
        // {
        //     printf(GREEN CHECKMARK GREY " [%d] OK\n" DEFAULT, i + 1);
        // }
        lstclear(&lst, &del);
    }

    return (errors);
}
