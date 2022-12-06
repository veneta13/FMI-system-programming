#include <stdio.h>

#define	YES	1
#define	NO	0
#define	MAXLINE	80
#define	MAXARG	10

char *cmd[MAXARG], com[MAXLINE];
int BG;

main() {
    int status, k, pid;

	write(1, "COM>", 4);
    
	while(( k = input_l() ) >= 0) {
	    if(k) {
	        if (( pid = fork() ) < 0) {
                write(2, "Cannot fork\n", 12);
                exit(0);
            }
	        else {
		        if( pid != 0 )
                    wait(&status);
		        else {
		 		    execlp(cmd[0], cmd[0], 0);
				    write(1, "cannot exec ", 12);
				    write(1, cmd[0], 10);
				    exit(1);
		        }
		    }
	    }
	    write(1,"\nCOM>",5);
    }
}


int input_l ()  {
    int i, j, nbyt, word;

    word = NO; j = 0; i = 0;
    
    while(( nbyt = read(0, &com[j], 1)) != 0 ) {
        if ( com[j] == ' ' ) {
            if ( word == YES ) {
                word = NO;
                com[j++] = '\0';
            }
        }
        else  
            if ( com[j] != '\n' ) {
                if ( word == NO ) {
                    word = YES;
                    cmd[i++] = &com[j];
                }
                ++j;
            }
            else
                if  ( com[j] == '\n' ) {
                    if( word == YES ) 
                        com[j] = '\0';
                        
                    cmd[i] = NULL;
                    
                    if(strcmp(cmd[0], "logout" ) == 0)
                        return(-1);
                    else 
                        return (i);
                }
    }
    if( nbyt == 0 ) 
        return (-1);
}
