#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("ERROR: Provide 2 filenames\n");
        exit(1);
    }

    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_WRONLY|O_TRUNC|O_CREAT, 0666);

    if ((fd1 == -1) || (fd2 == -1)) {
        printf("ERROR: Can't open file\n");
        exit(1);
    }

    if (fork() == 0) {
        close(0);
        dup(fd1);
        close(1);
        dup(fd2);
        close(2);
        dup(fd2);

        execlp("grep", "grep", "pts", 0);
    }
    else {
        int status;
        wait(&status);

        printf("%d\n", status);
    }
}
