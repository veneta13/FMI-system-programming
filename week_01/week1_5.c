#include <stdio.h>
#include <fcntl.h>

#define YES 1
#define NO 0

main(argc, argv)
        int argc;
        char *argv[];
{
    char c;
    int fd;
    int inWord = NO;
    int nl = 0, nw = 0, nc = 0;

    if ((fd = open(argv[1], O_RDONLY)) == -1)
        write(1, "wc: error\n", 9);

    while ((read(fd, &c, 1)) > 0) {
        nc++;
        if (c == '\n')
            nl++;

        if (c == ' ' || c == '\n' || c == '\t')
            inWord = NO;
        else if (inWord == NO) {
            inWord = YES;
            nw++;
        }
    }

    printf("%d %d %d\n", nl, nw, nc);
}
