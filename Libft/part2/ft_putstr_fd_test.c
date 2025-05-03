#include "ft.h"

static int run_test(char *str);

int ft_putstr_fd_test()
{
    int i;
    int errors = 0;

    char *strs[] = {
        "Don't Panic.",
        "",
        "I'm gonna make him an offer he can't refuse.",
        "Gentlemen, you can't fight in here! This is the War Room!",
        "Here's Johnny!",
        "Well, cut my legs off and call me Shorty!",
        NULL,
    };


    i = 0;
    while (strs[i])
    {
        errors += run_test(strs[i]);
        i++;
    }
    if (errors == 0)
        printf(GREEN "OK" DEFAULT);
    return (errors);
}

int run_test(char *str) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return (1);
    }

    ft_putstr_fd(str, pipefd[1]);
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

    if (strcmp(output, str) == 0)
    {
        free(output);
        return (0);
    }
    else
    {
        printf(RED "\nKO:\tFor '%s' got '%s'" DEFAULT, str, output);
        free(output);
        return (1);
    }
}
