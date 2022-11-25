#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

# define BUFSIZE 512

// Program implementing the 'cat >> file' command

main(argc, argv)
        int argc;
        char *argv[];
{
    int fileCount = 0;

    while (argc-- > 1)
        cat(argv[++fileCount]);

    if (fileCount == 0) {
        printf("cat: please provide files\n");
        exit(1);
    }

    exit(0);
}

cat(s)
        char *s;
{
    char buffer[BUFSIZE];
    int length;
    int fd;

    if (s) {
        if ((fd = open(s, O_RDONLY)) == -1) {
            printf("\ncat: can't open %s\n", s);
            exit(1);
        }
    }

    while ((length = read(fd, buffer, BUFSIZ)) > 0)
        write(1, buffer, length);
}
