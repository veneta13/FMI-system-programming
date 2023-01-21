#include <stdio.h>
#include <fcntl.h>

main(argc, argv)
int argc; 
char *argv[];
{
	int fd, fd1, i = 0;
	char c;
	
	if (( fd = open( argv[1], O_RDONLY)) == -1 ) {
		printf("\n Cannot open %s  ", argv[1]);
		exit(1);
	}
	
	if (( fd1 = open( argv[2], O_CREAT|O_TRUNC|O_RDWR, 0644)) == -1 ) {
		printf("\n Cannot open %s  ", argv[2]);
		exit(1);
	}

	while ( read(fd, &c, 1))
	{
		++i;
		if (c == '\n') { 
			
			if ( i < 10 )  
                for (i; i < 15; i++) {
					write(1, "$", 1);
					write(fd1, "#", 1);
				}
            
			i = 0;
        }
        
		write(1,&c,1);     			
	}
	
	close(fd);
	close(fd1);
}

/*
 * fileA.txt
 *
 * abc123-x
 * 999aaa
 * yyyyyy6xxxxx
 *
 *
 * Output:
 * abc123-x$$$$$$
 * 999aaa$$$$$$$$
 * yyyyyy6xxxxx
 *
 * file1:
 * ##############
 */
