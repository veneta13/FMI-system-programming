#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

main() {
    int fd, i, j, k ;
    
    if ((fd = open("abc", O_CREAT|O_TRUNC|O_RDWR, 0666)) == -1) { 
        write(2, "Cannot open file abc \n", 24);
        exit(1);  
    }

    k = dup(fd);
    write(fd, "I AM STUDENT ", 13);
    write(k, "AT FMI", 6);
}
