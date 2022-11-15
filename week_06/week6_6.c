#include <stdio.h>
#include <fcntl.h>

#define ERROR -1

main()
{
    int i, fd1, fd2, status;
    
    if((fd1 = open("ff", O_WRONLY|O_CREAT, 0777)) == -1) {
        printf("ERROR\n");
        exit(1);
    }
  
    printf("%d\n", fd1);
    fd2=dup(fd1);
    printf("%d\n", fd2);
    
    if ( fork()==0 ) {
        write(fd1, "HELLO CHILD\n", 12);
        exit(0);
    }
    else {
        // wait(&status);
        write(fd2, "HELLO PARENT\n", 13);
    }
    
    write(fd1, "COMMON PART\n", 12);
}
