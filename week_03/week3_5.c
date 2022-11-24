#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

main(argc, argv)
        int argc;
        char *argv[];
{
    int fd, fd1, k, i = 0, status;
    char buff[60], c;
    int nbytes = 0;
    {
        if ((fd = open(argv[1], O_RDONLY)) == -1) {
            printf("\nCannot open %s", argv[1]);
            exit(1);
        }
        if ((fd1 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1) {
            printf("\nCannot open %s", argv[2]);
            exit(1);
        }
    }

    if (fork() != 0) {
        wait(&status);
        execlp("wc", "wc", "-l", argv[2], 0);
    }
    else {
        while (read(fd, &c, 1) > 0) {
            if (c != '\n')
                buff[i++] = c;
            else {
                if (buff[i - 1] == '$') {
                    for (k = 0; k < i; k++)
                        write(1, &buff[k], 1);
                    write(1, "\n", 1);
                    buff[0] = '\0';
                }
                else {
                    for (k = 0; k < i; k++)
                        if (buff[k] >= '0' && buff[k] <= '9')
                            write(fd1, &buff[k], 1);
                    write(fd1, "\n", 1);
                    buff[0] = '\0';
                }
                i = 0;
            }
        }
    }
}

