
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <time.h>
#include "get_next_line.h"
#include "../utils/constants.h"

int main(void) {
    clock_t start, end;
    double cpu_time_used;
    char *line;
    int errors = 0;

    const char *gnl_path = "./gnl/files/";
    const char *res_path = "./results/";

    DIR *dir = opendir(gnl_path);
    if (!dir) {
        perror("opendir");
        return 1;
    }

    start = clock();
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (entry->d_type == DT_REG) {  // Only regular files
            char gnl_file[512];
            char res_file[512];

            snprintf(gnl_file, sizeof(gnl_file), "%s%s", gnl_path, entry->d_name);
            snprintf(res_file, sizeof(res_file), "%s%s", res_path, entry->d_name);

            ft_test(gnl_file, res_file);
        }
    }
    closedir(dir);
    fdopen(1, "w");

    // Test wrong fd and closed file
    line = get_next_line(-1);
    if (line)
    {
        errors++;
        free(line);
    }
    line = get_next_line(42);
    if (line)
    {
        errors++;
        free(line);
    }
    int fd = open("./gnl/basic.txt", O_RDONLY);
    close(fd);
    line = get_next_line(fd);
    if (line)
    {
        errors++;
        free(line);
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n\n", cpu_time_used);
    if (errors)
        printf("Invalid ids: " RED "KO\n" DEFAULT);

    return 0;
}