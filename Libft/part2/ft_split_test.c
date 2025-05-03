#include "ft.h"

typedef struct s_test
{
    char *desc;
    char *str;
    char c;
    char **expected;
} t_test;

static int run_tests(t_test *tests, int count);

int ft_split_test()
{
    t_test tests[] = {
        {
            .desc = "Basic split with two words",
            .str = "hello,world",
            .c = ',',
            .expected = (char *[3]){"hello", "world", 0},
        },
        {
            .desc = "Multiple consecutive delimiters",
            .str = "one,,two,,,three",
            .c = ',',
            .expected = (char *[4]){"one", "two", "three", 0},
        },
        {
            .desc = "Leading and trailing delimiters",
            .str = ",,start,middle,end,,",
            .c = ',',
            .expected = (char *[4]){"start", "middle", "end", 0},
        },
        {
            .desc = "Only delimiters",
            .str = ",,,,",
            .c = ',',
            .expected = (char *[1]){0},
        },
        {
            .desc = "No delimiters at all",
            .str = "justastring",
            .c = ',',
            .expected = (char *[2]){"justastring", 0},
        },
        {
            .desc = "Empty string input",
            .str = "",
            .c = ',',
            .expected = (char *[1]){0},
        },
        {
            .desc = "Delimiter is space",
            .str = "split this string",
            .c = ' ',
            .expected = (char *[4]){"split", "this", "string", 0},
        },
        {
            .desc = "Single character string, is delimiter",
            .str = ",",
            .c = ',',
            .expected = (char *[1]){0},
        },
        {
            .desc = "Single character string, not delimiter",
            .str = "x",
            .c = ',',
            .expected = (char *[2]){"x", 0},
        },
        {
            .desc = "String with all same characters, all delimiters",
            .str = ";;;;;;",
            .c = ';',
            .expected = (char *[1]){0},
        },
    };
    
    int count = sizeof(tests) / sizeof(tests[0]);

    return run_tests(tests, count);
}

static int run_tests(t_test *tests, int count)
{
    int i, j;
    int errors = 0;
    int error;

    for (i = 0; i < count; i++)
    {
        error = 0;
        char **result = ft_split(tests[i].str, tests[i].c);

        if (!result && !tests[i].expected)
        {
            // printf(GREEN CHECKMARK GREY "\n [%d] %s\n" DEFAULT, i + 1, tests[i].desc);
        }
        else if (!result || !tests[i].expected)
        {
            printf(RED "\n[%d] %s got \"", i + 1, tests[i].desc);
            if (result)
            {
                printf("%s", result[0]);
                for (j = 1; result[j]; j++)
                {
                    printf("\", \"%s", result[j]);
                }
            }
            else
            {
                printf("(null)");
            }
            printf("\" instead of \"");
            if (tests[i].expected)
            {
                printf("%s", tests[i].expected[0]);
                for (j = 1; tests[i].expected[j]; j++)
                {
                    printf("\", \"%s", tests[i].expected[j]);
                }
            }
            else
            {
                printf("(null)");
            }
            printf("\"" DEFAULT);
            error++;
        }
        else
        {
            j = 0;
            while (tests[i].expected[j] && result[j])
            {
                if (strcmp(tests[i].expected[j], result[j]) != 0)
                {
                    printf(RED "\n[%d] %s Element %d: expected \"%s\", got \"%s\"" DEFAULT, i + 1, tests[i].desc, j, tests[i].expected[j], result[j]);
                    error++;
                }
                j++;
            }
        }

        // if (error == 0)
        //     printf(GREEN CHECKMARK GREY "\n [%d] %s\n" DEFAULT, i + 1, tests[i].desc);

        if (result)
        {
            j = 0;
            while (result[j])
            {
                free(result[j]);
                j++;
            }
            free(result);
        }
        errors += error;
    }
    if (error == 0)
        printf(GREEN "OK" DEFAULT);
    return (errors);
}