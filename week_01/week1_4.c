#include <stdio.h>
#include <fcntl.h>

# define FILE_COUNT 10
# define BUFSIZE 512

// Program implementing the 'tee' command

main(argc, argv)
        int argc;
        char *argv[];
{

    int fd[FILE_COUNT];
    char buffer[BUFSIZE];
    int numberBytes = 0;

    for (int i = 1; i < argc; i++) {
        if ((fd[i] = open(argv[i], O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1) {
            printf("\nCannot creat %s", argv[i]);
            exit(1);
        }
    }

    while ((numberBytes = read(0, buffer, sizeof(buffer)))) {
        write(1, buffer, numberBytes);

        for (int i = 1; i < argc; i++)
            write(fd[i], buffer, numberBytes);
    }
}
