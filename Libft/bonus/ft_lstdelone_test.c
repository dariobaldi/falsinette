#include "ft.h"

typedef struct s_test
{
    char **expected;
} t_test;

static int run_tests(t_test *tests);

int ft_lstdelone_test()
{
    t_test tests[] = {
        {
            .expected = (char *[5]){"darkness", "my", "old", "friend", 0},
        },
        {
            .expected = (char *[4]){"my", "old", "friend", 0},
        },
        {
            .expected = (char *[3]){"old", "friend", 0},
        },
        {
            .expected = (char *[2]){"friend", 0},
        },
        {
            .expected = (char *[1]){0},
        },
    };


   int errors = run_tests(tests);
    if (errors == 0)
        printf(GREEN "OK\n" DEFAULT);
    return (errors);
}

static int run_tests(t_test *tests)
{
    int i;
    int errors = 0;
    char **strs = (char *[6]){"hello", "darkness", "my", "old", "friend", 0};
    t_list *lst = create_linked_list((void **)strs, 5);
    t_list *next;

    i = 0;
    while (lst)
    {
        next = lst->next;
        ft_lstdelone(lst, &del);

        lst = next;
        if (!is_valid_list(&lst, tests[i].expected))
        {
            errors++;
            printf(RED "[%d] FAILED" DEFAULT "\nExpected:\n", i + 1);
            putarray(tests[i].expected);
            printf("Got:\n");
            putlist(&lst);

        }
        // else
        // {
        //     printf(GREEN CHECKMARK GREY " [%d] OK\n" DEFAULT, i + 1);
        // }
        i++;
    }
    return (errors);
}
