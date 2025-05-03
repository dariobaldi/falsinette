#include "ft.h"

typedef struct s_test
{
    char *str;
    char *expected;
} t_test;

static int run_test(t_test *test);

int ft_putendl_fd_test()
{
    int i;
    int errors = 0;

    t_test tests[] = {
        {"Don't Panic.","Don't Panic.\n"},
        {"","\n"},
        {"I'm gonna make him an offer he can't refuse.","I'm gonna make him an offer he can't refuse.\n"},
        {"Gentlemen, you can't fight in here! This is the War Room!","Gentlemen, you can't fight in here! This is the War Room!\n"},
        {"Here's Johnny!","Here's Johnny!\n"},
        {"Well, cut my legs off and call me Shorty!","Well, cut my legs off and call me Shorty!\n"},
     };
    
    
    int count = sizeof(tests) / sizeof(tests[0]);

    i = 0;
    while (i < count)
    {
        errors += run_test(tests + i);
        i++;
    }
    if (errors == 0)
        printf(GREEN "OK" DEFAULT);
    return (errors);
}

int run_test(t_test *test) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return (1);
    }

    ft_putendl_fd(test->str, pipefd[1]);
    close(pipefd[1]);

    // Read from the pipe in chunks
    char buffer[1024];
    char *output = NULL;
    size_t output_len = 0;

    ssize_t bytes_read;
    while ((bytes_read = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
        char *new_output = realloc(output, output_len + bytes_read + 1); // +1 for '\0'
        if (!new_output) {
            perror("realloc");
            free(output);
            close(pipefd[0]);
            return (1);
        }

        output = new_output;
        memcpy(output + output_len, buffer, bytes_read);
        output_len += bytes_read;
        output[output_len] = '\0'; // Always keep it null-terminated
    }

    close(pipefd[0]);

    if (!output) output = strdup(""); // Handle NULL case safely

    if (strcmp(output, test->expected) == 0)
    {
        free(output);
        return (0);
    }
    else
    {
        printf(RED "\nKO: For input string '%s'" DEFAULT, test->str);
        free(output);
        return (1);
    }
}
