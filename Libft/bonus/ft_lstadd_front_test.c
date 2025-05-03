#include "ft.h"

typedef struct s_test
{
    char *str;
    char **expected;
} t_test;

static int run_tests(t_test *tests, int count);

int ft_lstadd_front_test()
{
    t_test tests[] = {
        {
            .str = "friend",
            .expected = (char *[2]){"friend", 0},
        },
        {
            .str = "old",
            .expected = (char *[3]){"old", "friend", 0},
        },
        {
            .str = "my",
            .expected = (char *[4]){"my", "old", "friend", 0},
        },
        {
            .str = "darkness",
            .expected = (char *[5]){"darkness", "my", "old", "friend", 0},
        },
        {
            .str = "hello",
            .expected = (char *[6]){"hello", "darkness", "my", "old", "friend", 0},
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
    int errors = 0;
    int error;
    t_list *lst = NULL;
    t_list *new;

    for (i = 0; i < count; i++)
    {
        error = 0;
        new = lstnew(tests[i].str);
        ft_lstadd_front(&lst, new);

        if (!is_valid_list(&lst, tests[i].expected))
        {
            errors++;
            printf(RED "\n[%d]" DEFAULT "\nExpected:\n", i + 1);
            putarray(tests[i].expected);
            printf("Got:\n");
            putlist(&lst);

        }
        // else
        // {
        //     printf(GREEN CHECKMARK GREY " [%d] OK\n" DEFAULT, i + 1);
        // }
    }

    lstclear(&lst, &del);

    return (errors);
}
