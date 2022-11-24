#include <stdio.h>
#include <fcntl.h>

main() {
    char buff[13];
    int fd, fd1;

    fd = open("ff", O_RDONLY);
    fd1 = dup(fd);
    read(fd, buff, 4);
    write(1, buff, 4);
    close(fd);

    read(fd1, buff, 9);
    write(1, buff, 9);
}
