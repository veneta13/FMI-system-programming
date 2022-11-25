#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        write(2, "error: provide 2 commands\n", sizeof("error: provide 2 commands\n"));
        exit(1);
    }

    int status;

    if (fork() == 0) {
        execlp(argv[1], argv[1], 0);
        exit(1);
    }
    else {
        wait(&status);
        if (status != 0) {
            exit(-1);
        }

        execlp(argv[2], argv[2], 0);
    }
}
