#include <stdio.h>
#include <fcntl.h>

main(argc, argv)
        int argc;
        char *argv[];
{
    int flg = 0;

    while (argc-- > 1)
        ct(argv[++flg]);

    if (flg == 0)
        ct((char *) 0);  /* ct (0); */
}

ct(s)
        char *s;
{
    char buffer[BUFSIZ];
    int length;
    int fd = 0;

    if (s)
        if ((fd = open(s, O_RDONLY)) == -1) {
            printf("\ncat: can't open %s\n", s);
            exit(1);
        }
    while ((length = read(fd, buffer, BUFSIZ)))
        write(1, buffer, length);
}
