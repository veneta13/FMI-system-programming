#include <stdio.h>

#define ERROR -1

main() {
    int flag, status;

    if (fork()) {
        printf("parent - pid= %d, ppid= %d\n", getpid(), getppid());
        flag = 100;
    }
    else {
        printf("child - pid= %d ppid= %d\n", getpid(), getppid());
        flag = 200;
    }

    printf("\n Common part of parent+child--->flag = %d\n", flag);
}
