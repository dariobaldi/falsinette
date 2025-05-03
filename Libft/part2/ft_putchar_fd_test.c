#include "ft.h"

int run_test(char c, char *expected);

int ft_putchar_fd_test()
{
    char    c;
    char    expected[2] = {0};
    int     errors = 0;

    for (c = 32; c < 127; c++)
    {
        expected[0] = c;
        errors += run_test(c, expected);
    }

    if (errors == 0)
        printf(GREEN "OK" DEFAULT);
    return (errors);
}

int run_test(char c, char *expected)
{
    int pipefd[2];
    char buffer[10] = {0};

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return (1);
    }

    ft_putchar_fd(c, pipefd[1]);
    close(pipefd[1]);

    ssize_t bytes_read = read(pipefd[0], buffer, sizeof(buffer) - 1);
    close(pipefd[0]);

    if (bytes_read < 0) {
        perror("read");
        return (1);
    }

    buffer[bytes_read] = '\0'; // Null-terminate for string comparison

    if (strcmp(buffer, expected) == 0)
    {
        return (0);
    }
    else
    {
        printf(RED "\nKO:\tFor '%s' got '%s'" DEFAULT, expected, buffer);
        return (1);
    }
}
