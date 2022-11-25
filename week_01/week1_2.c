#include <stdio.h>
#include <fcntl.h>

# define BUFSIZE 512

// Program implementing the 'cat' command without parameters

main(argc, argv)
        int argc;
        char *argv[];
{
    if (argc != 1) {
        printf("cat: must be no parameters passed to cat\n");
        exit(1);
    }

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
