#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

main(argc,argv)
int argc;
char *argv[];
{

    int fd[5], i;
    char buff[10];
    int nbytes=0;
      
    for (i=1; i < argc; i++) { 
        if (( fd[i] = open(argv[i], O_CREAT|O_WRONLY|O_TRUNC, 0666)) == -1) {
            printf("\nCannot creat %s", argv[i]);
            exit(1);
        }
    }
    while ( nbytes=read(0, buff, sizeof(buff))) {
        write( 1, buff, nbytes);
        for (i = 1; i < argc; i++)
            write(fd[i], buff, nbytes);
    }
}
