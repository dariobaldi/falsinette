#include <stdio.h>
#include <stdlib.h>
#include "../utils/constants.h"

int ft_is_sort(int *tab, int length, int (*f)(int, int));

int ft_compare(int a, int b)
{
	if (a > b)
		return (42);
	if (a < b)
		return (-42);
	return (0);
}

typedef struct s_test
{
	char *desc;
	int *tab;
	int length;
	int expected;
} t_test;

int run_tests(t_test *tests, int count);

int main()
{
	t_test tests[] = {
			{
					.desc = "Basic: 1-5",
					.tab = (int[]){1, 2, 3, 4, 5},
					.length = 5,
					.expected = 1,
			},
			{
					.desc = "Sorted with repeated middle",
					.tab = (int[]){1, 2, 3, 3, 3, 4, 5},
					.length = 7,
					.expected = 1,
			},
			{
					.desc = "Basic invers: 1-5",
					.tab = (int[]){5, 4, 3, 2, 1},
					.length = 5,
					.expected = 1,
			},
			{
					.desc = "Sorted inv with repeated middle",
					.tab = (int[]){5, 4, 3, 3, 3, 2, 1},
					.length = 7,
					.expected = 1,
			},
			{
					.desc = "Basic unsorted",
					.tab = (int[]){4, 2, 5, 2, 9},
					.length = 8,
					.expected = 0,
			},
			{
					.desc = "Unsorted with repeated middle",
					.tab = (int[]){1, 2, 3, 3, 3, 2, 4, 5},
					.length = 8,
					.expected = 0,
			},
	};
	int count = sizeof(tests) / sizeof(tests[0]);

	return run_tests(tests, count);
}

int run_tests(t_test *tests, int count)
{
	int i;
	int error = 0;

	for (i = 0; i < count; i++)
	{
		int result = ft_is_sort(tests[i].tab, tests[i].length, &ft_compare);

		if (!result == !tests[i].expected)
		{
			printf(GREEN CHECKMARK GREY " [%d] %s\n" DEFAULT, i + 1, tests[i].desc);
		}
		else if (!result != !tests[i].expected)
		{
			printf(RED "[%d] %s got %d instead of %d\n" DEFAULT, i + 1, tests[i].desc, result, tests[i].expected);
			error -= 1;
		}
		else
		{
			printf(GREEN CHECKMARK GREY " [%d] %s got %d as expected\n" DEFAULT, i + 1, tests[i].desc, result);
		}
	}

	if (error == 0)
		printf(BG_GREEN BLACK BOLD "OK: Good job!" DEFAULT "\n");
	return error;
}