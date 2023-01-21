#include <stdio.h>
#include <fcntl.h>

#define COM "ps"

main() {
    int i=2, status;

	if (fork()) {
		wait(&status);
		--i;
		printf(" Stoinostta na i = %d;", i);
	}
	else {
		i++; 
        if ( execlp(COM, COM, 0) == -1) {
			i = i + 2;
        	printf(" Stoinostta na i = %d;", i);
		}
    }

	printf(" Stoinostta na i = %d;", --i);
}

/*
 *
 * Output:
 *
 * *информация за процесите в системата*
 * Stoinostta na i = 1; Stoinostta na i = 0;
 *
 */