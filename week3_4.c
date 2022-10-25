#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

main (int argc, char *argv[])
{
    char c;
    int fd, nl = 0, num;

    if((fd = open(argv[2], O_RDONLY)) == -1) {
        write(2, "Cannot open file\n", 18);
        exit(1); 
    }
    num = atoi(argv[1]);
    while(read(fd, &c, 1))
    {
        if (c == '\n' )
        {
            nl++;
            if( nl > num ) 
                write(1, &c, 1);
                continue;
        }
        if ((c != '\n') && (nl < num)) 
            continue;
        else if ( c != '\n' ) 
            write(1, &c, 1);
    }
}
