#include <stdio.h>
#include <fcntl.h>

# define BUFSIZE 512

// Program implementing the 'cat' command

main(argc, argv)
        int argc;
        char *argv[];
{
    int fileCount = 0;

    while (argc-- > 1)
        cat(argv[++fileCount]);

    if (fileCount == 0)
        cat((char *) 0);  /* cat (0); */
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

    while ((length = read(fd, buffer, BUFSIZ)))
        write(1, buffer, length);
}
