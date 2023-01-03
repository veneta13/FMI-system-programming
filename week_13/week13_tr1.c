#include <stdio.h>
#include <fcntl.h>

main(int args, char* argv[]) {
    int pid, var = 1, status;

    if ((pid = fork()) == 0) {
        var += 2; 
        printf("\n Var = %d ", var);
    } 
    else {
        wait(&status);
        var++;
        printf("\n Var = %d ", var); 
        exit(0);
    }

    --var;
    printf("\n Var = %d ", var);
}
