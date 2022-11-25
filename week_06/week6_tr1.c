#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

main(int argc, char *argv[]) {
    int fd, i = 4, nb1, status;
    char buf[5];

    if (fork() == 0) {
        ++i;
        printf("Stoinostta na i= %d\n", i);
    }
    else {
        --i;
        exit(0);
        wait(&status);
        if (execlp("ls", "ls", "-l", 0) == -1)
            i = i + 1;
        else
            printf("Stoinostta na i= %d\n", i);
    }

    printf("Stoinostta na i= %d\n", i);
}

/*
 *
 * Output:
 *
 * Stoinostta na i= 5
 * Stoinostta na i= 5
 *
 */
