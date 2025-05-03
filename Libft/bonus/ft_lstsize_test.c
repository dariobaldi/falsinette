#include "ft.h"

typedef struct s_test
{
    char **strs;
    int expected;
} t_test;

static int run_tests(t_test *tests, int count);

int ft_lstsize_test()
{
    t_test tests[] = {
        {
            .strs = (char *[2]){"friend", 0},
            .expected = 1,
        },
        {
            .strs = (char *[3]){"old", "friend", 0},
            .expected = 2,
        },
        {
            .strs = (char *[4]){"my", "old", "friend", 0},
            .expected = 3,
        },
        {
            .strs = (char *[5]){"darkness", "my", "old", "friend", 0},
            .expected = 4,
        },
        {
            .strs = (char *[6]){"hello", "darkness", "my", "old", "friend", 0},
            .expected = 5,
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
    int i, result;
    int errors = 0;
    int error;
    
    for (i = 0; i < count; i++)
    {
        t_list *lst;
        error = 0;
        lst = create_linked_list((void **)tests[i].strs, strslen(tests[i].strs));
        result = ft_lstsize(lst);

        if (result != tests[i].expected)
        {
            errors++;
            printf(RED "\n[%d] expected %d got %d" DEFAULT, i + 1, tests[i].expected, result);
        }
        // else
        // {
        //     printf(GREEN CHECKMARK GREY " [%d] OK\n" DEFAULT, i + 1);
        // }
        lstclear(&lst, &del);
    }

    return (errors);
}
