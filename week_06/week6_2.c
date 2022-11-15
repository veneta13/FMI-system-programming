#include <stdio.h>

#define ERROR -1

main()
{
    int i, status;

    if ( fork() ) {
        wait(&status);
        printf("parent - pid= %d, ppid= %d\n", getpid(), getppid());
    }
    else {
        printf("child - pid= %d ppid= %d\n", getpid(), getppid());
        for(i = 1; i < 100000000; i++) ;
    }
    
    printf("\n Common part of parent+child\n");
}
