#include "ft.h"

typedef struct {
    char *desc;
    void *input;
} t_test;

static int run_test(t_test test, int i);

int ft_lstnew_test()
{
    int errors = 0;
    char *str = strdup("hello"); // str must outlive the test
    int value = 42;

    t_test tests[] = {
        {
            .desc = "Test with string content",
            .input = str,
        },
        {
            .desc = "Test with int pointer content",
            .input = &value,
        },
        {
            .desc = "Test with NULL content",
            .input = NULL,
        },
    };

    size_t count = sizeof(tests) / sizeof(t_test);
    for (size_t i = 0; i < count; i++) {
        errors += run_test(tests[i], i);
    }

    free(str);
    return 0;
}

int run_test(t_test test, int i)
{
    int error = 0;
    t_list *node = ft_lstnew(test.input);

    if (!node) {
        printf(RED "[%d] %s returned NULL\n" DEFAULT, i + 1, test.desc);
        return (1);
    }


    if (test.input != node->content) {
        printf(RED "[%d] %s content pointer mismatch\n" DEFAULT, i + 1, test.desc);
        error++;
    }

    if (node->next != NULL) {
        printf(RED "[%d] %s → next is not NULL\n" DEFAULT, i + 1, test.desc);
        error++;
    }

    if (!error) {
        printf(GREEN CHECKMARK GREY " [%d] %s\n" DEFAULT, i + 1, test.desc);
    }

    free(node); // Only free the node, not the content (depends on ownership)
    return (error);
}
