#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("ERROR: provide 2 commands");
        exit(1);
    }

    int stat1, stat2, c1, c2;

    if (fork()) {
        if (fork()) {
            c1 = wait(&stat1);
            c2 = wait(&stat2);
            printf("%d %d\n", stat1, c1);
            printf("%d %d\n", stat2, c2);
        }
        else {
            execvp(argv[2], &argv[2]);
        }
    }
    else {
        execlp(argv[1], argv[1], 0);
    }
}
