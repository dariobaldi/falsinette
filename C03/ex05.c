#include<stdio.h>
#include<string.h>
#include<bsd/string.h>
#include "../utils/constants.h"

unsigned int    ft_strlcat(char *dest, char *src, unsigned int size);

typedef struct s_test
{
    char *desc;
    char *src;
    char *dest;
    int size;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
        {
            .desc = "Concatenate two strings",
            .src = " clavo un palito",
            .dest = "Pablito",
            .size = 22,
        },
        {
            .desc = "Concatenate empty strings",
            .src = "",
            .dest = "",
            .size = 10,
        },
        {
            .desc = "Append to an empty string",
            .src = "hello",
            .dest = "",
            .size = 10,
        },
        {
            .desc = "Concatenate with string larger than size",
            .src = " clavo Pablito",
            .dest = "Cuantos palitos",
            .size = 7,
        },
        {
            .desc = "Concatenate same strings with size larger than sum of their lengths",
            .src = "Test",
            .dest = "Test",
            .size = 15,
        },
    };
    int count = sizeof(tests) / sizeof(tests[0]);

    return run_tests(tests, count);
}

int run_tests(t_test *tests, int count)
{
    int i;
    int error = 0;
	int result, expected;

    for (i = 0; i < count; i++)
    {
        char dest[100];
        char dest2[100];
        strcpy(dest, tests[i].dest);
        strcpy(dest2, tests[i].dest);

        result = ft_strlcat(dest, tests[i].src, tests[i].size);
		expected = strlcat(dest2, tests[i].src, tests[i].size);

        if (strcmp(dest, dest2) != 0)
        {
            printf("    " RED "[%d] %s Expected \"%s\" output \"%s\"\n" DEFAULT, i + 1, tests[i].desc, dest2, dest);
            error -= 1;
        }
        else
        {
            printf("  " GREEN CHECKMARK GREY " [%d] %s Expected \"%s\" output \"%s\"\n" DEFAULT, i + 1, tests[i].desc, dest2, dest);
        }
    }

    return error;
}