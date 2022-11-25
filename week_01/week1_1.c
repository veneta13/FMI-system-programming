#include <stdio.h>
#include <fcntl.h>

// Program implementing the 'cp' command

main(argc, argv)
        int argc;
        char *argv[];
{
    int f1, f2, n;
    char buf[512];

    if (argc != 3) {
        printf("\nUsage: cp from ... to ...");
        exit(1);
    }

    if ((f1 = open(argv[1], O_RDONLY)) == -1) {
        printf("\ncopy: can't open %s\n", argv[1]);
        exit(1);
    }

    if ((f2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1) {
        printf("\ncopy: can't create %s\n", argv[2]);
        exit(1);
    }

    while ((n = read(f1, buf, 512)) > 0)
        if (write(f2, buf, n) != n)
            printf("\ncopy: write error\n");
    exit(0);
}
