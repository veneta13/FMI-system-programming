#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main(int argc, char *argv[]) {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(fd[0]); // close unused pipe read fd
        close(1); // close standard out
        dup(fd[1]); // dup pipe write to standard out
        close(fd[1]); // close the pipe write fd
        execlp("who", "who", 0); // execute 'who' writing to pipe write fd
    }
    else {
        wait(NULL); // wait for child
        close(fd[1]); // close unused pipe write fd
        close(0); // close standard in
        dup(fd[0]); // dup pipe read to standard in
        close(fd[0]); // close the pipe read fd
        execlp("wc", "wc", "-l", 0); // execute 'wc' reading from pipe read fd
    }
}
