#include <fcntl.h>

main(int argc, char *argv[]) {
    int fd, k, status;
    
    fd = open(argv[1], O_RDWR);
    
    if(fork()) {
        wait(&status);
        dup(fd);
        write(1, "who\n", 4);
        execlp("who", "who", "-u", 0); 
        write (fd, " exam1\n",5);
    }
    else {
        close(1);
        dup(fd);
        for(k = 0; k <= 3; k++)
            write(1, "exam2\n", 6); 
        }
        execlp("pwd", "pwd", 0);
}

/*
 *
 * Output:
 * who
 * *потребителите в системата*
 *
 *
 * file:
 * exam2
 * exam2
 * exam2
 * exam2
 * *текуща директория от pwd*
 *
 */
