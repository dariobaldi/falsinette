#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main() {
    int     fd;
	char *line;

    // Open a file for reading
    fd = open("./gnl/ascii-art.txt", O_RDONLY);
    if (fd < 0) {
        printf("File could't be opened\n");
        return(-42);
    }

    printf("File opened successfully. Reading...\n");

	while ((line = get_next_line(fd)))
    {
		printf("\n%s", line);
        free(line);
    }

    // // Loop to read the entire file in chunks
    // while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
    //     // Null-terminate the portion of the buffer that was read
    //     buffer[bytes_read] = '\0';
    //     printf("Read %zd bytes:\n%s\n", bytes_read, buffer);
    // }

    // // Check for read errors
    // if (bytes_read == -1) {
    //     perror("Error reading file");
    // } else {
    //     printf("Reached end of file.\n");
    // }

    // // Close the file descriptor
    // if (close(fd) == -1) {
    //     perror("Error closing file");
    //     exit(EXIT_FAILURE);
    // }
    // printf("File closed.\n");
    close(fd);

    return 0;
}