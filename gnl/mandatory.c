#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main() {
    int     fd;
	char *line;

    fd = open("./gnl/files/nl", O_RDONLY);
    if (fd < 0) {
        printf("File could't be opened\n");
        return(-42);
    }

    line = get_next_line(fd);
    line = get_next_line(fd);
    line = get_next_line(fd);
    line = get_next_line(fd);

    close(fd);

    return 0;
}