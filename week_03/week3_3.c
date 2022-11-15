#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

main()
{
    int fd, fdr, l1, l2, wb1, wb2;
    char buf[25];

    fd = open("f1", O_WRONLY);
    fdr = open("f1", O_RDONLY );
    l1 = lseek(fd, -3, SEEK_END);
  
    printf("\nlseek returns -->%d\n", l1);
    wb1 = write(fd, "wxyz", 4);
    
    //printf("\nlseek2 --> %d\n", lseek(fd,-3,SEEK_END) + 4);
    
    l2 = lseek(fd, 4, SEEK_SET);
    printf("\nlseek returns -->%d\n", l2);
    write(fd, "12", 2);

    lseek(fdr, 0, SEEK_SET);
    wb2 = read(fdr, buf, 20);
    write(1, buf, wb2);
}

