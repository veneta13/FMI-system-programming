#define YES 1
#define NO 0

#include <stdio.h>
#include <fcntl.h>

main(argc, argv)
        int argc;
        char *argv[];
{
    char c;
    int fd, nl, nw, nc, inword;
    inword = NO;
    nl = nw = nc = 0;

    if ((fd = open(argv[1], O_RDONLY)) == -1)
        write(1, "error\n", 6);
    while ((read(fd, &c, 1)) > 0) {
        nc++;
        if (c == '\n')
            nl++;
        if (c == ' ' || c == '\n' || c == '\t')
            inword = NO;
        else if (inword == NO) {
            inword = YES;
            nw++;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
