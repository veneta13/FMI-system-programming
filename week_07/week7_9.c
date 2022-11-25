#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main(int argc, char *argv[]) {
    int pid1, pid2, status1, status2, i = -1;
    if ((pid1 = fork()) > 0) {
        if ((pid2 = fork()) > 0) {
            if (wait(&status1) == pid1) {
                if (status1 == 0) {
                    printf("%d\n", pid1);
                }
                else {
                    wait(&status2);
                    if (status2 == 0) {
                        printf("%d\n", pid2);
                    }
                    if (status1 != 0 && status2 != 0) {
                        printf("%d\n", i);
                    }
                }
            }
        }
        else {
            execlp(argv[2], argv[2], 0);
        }
    }
    else {
        execlp(argv[1], argv[1], 0);
    }
}  
