#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <fcntl.h>
#include    <string.h>

main(int argc, char *argv[]) {
    int i, init = 0, prom, step1 = 1, step2 = 2;
    int fd;
    char buf[30];

    if ((fd = open(argv[1], O_CREAT | O_RDWR | O_TRUNC, 0666)) == -1) {
        write(2, "Cannot open: file \n", 20);
        exit(1);
    }

    write(fd, &init, sizeof(int));

    if (fork()) {
        for (i = 1; i <= 500; ++i) {
            lseek(fd, 0, SEEK_SET);
            read(fd, &prom, sizeof(int));
            prom += step1;
            sprintf(buf, "\tp1---> prom = %d\n", prom);
            write(1, buf, strlen(buf));
            lseek(fd, 0, SEEK_SET);
            write(fd, &prom, sizeof(int));
        }
    }
    else {
        for (i = 1; i <= 1000; ++i) {
            lseek(fd, 0, SEEK_SET);
            read(fd, &prom, sizeof(int));
            prom += step2;
            sprintf(buf, "p2---> prom = %d\n", prom);
            write(1, buf, strlen(buf));
            lseek(fd, 0, SEEK_SET);
            write(fd, &prom, sizeof(int));
        }
    }

    write(1, "Final value  ---->", 18);
    lseek(fd, 0, SEEK_SET);
    read(fd, &prom, sizeof(int));
    sprintf(buf, " %d\n", prom);
    write(1, buf, strlen(buf));
}
