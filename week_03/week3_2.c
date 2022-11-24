#include <fcntl.h>

main() {
    int fd1, fd2, fd3;
    char buf[20];
    open("fff", O_CREAT | O_TRUNC | O_RDWR, 0777);

    fd1 = open("fff", O_RDONLY);
    fd2 = open("fff", O_WRONLY);
    fd3 = open("fff", O_RDWR);

    write(fd3, "hello", 5);
    write(fd2, "worlds", 6);
    read(fd1, buf, 6);
    write(1, buf, 6);
    close(fd2);
    write(fd3, "oops", 4);
    read(fd1, buf, 6);
    write(1, buf, 6);
}
