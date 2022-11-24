#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define CMD "who"

main() {
    int fd, i = 2, k = 0, status;
    if (fork()) {
        wait(&status);
        i--;
        k--;
        write(1, "exam1\n", 6);
        printf("I=%d K= %d \n", i, k);
    }
    else {
        for (k = 1; k <= 3; k++) {
            write(1, "exam2\n", 6);
            i = k + i;
            printf("I=%d K=%d\n", i, k);

            if ((execlp(CMD, CMD, 0)) == -1)
                write(1, "exam3\n", 6);

            printf("I=%d K=%d\n", i, k);
        }
    }

    write(1, "exam4\n", 6);

    if ((execlp("ls", "ls", 0)) == -1)
        printf("I=%d K=%d\n", i, k);
    else {
        write(1, "exam5\n", 6);
    }
}
