#include <stdio.h>
#include <unistd.h>

int main() {
    int pid;
    int b = 1, a = 5, status;
    char buff[1];
    pid = fork();

    if (pid == 0) {
        b = 3;
        a = 0;
    }
    else {
        a = 9;
        wait(&status);
    }

    write(1, "\n a= ", 5);
    sprintf(buff, "%d", a);
    write(1, buff, sizeof(buff));

    write(1, "\n b= ", 5);
    sprintf(buff, "%d", b);
    write(1, buff, sizeof(buff));
}

/*
 *
 * Output:
 *
 *
 * a= 0
 * b= 3
 * a= 9
 * b= 1
 *
 */