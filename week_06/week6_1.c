#include <fcntl.h>

main(int argc, char* argv[]) {
    int fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        write(2, "error: can't open file\n", sizeof("error: can't open file\n"));
        exit(0);
    }

    close(0);
    dup(fd);

    execlp("grep", "grep", "int", 0);
}
