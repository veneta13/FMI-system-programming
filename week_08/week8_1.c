#include <stdlib.h>
#include <unistd.h>

main() {
    char cmd[32];
    int i = 0;

    while (1) {
        write(1, "CI>", 3);

        while((read(0, &cmd[i], 1)) && cmd[i] != '\n') {
            if(cmd[i] == ' ')
                continue;
            else
                ++i;
        }

        if(cmd[i] == '\n') 
            cmd[i] = '\0';

        if(strcmp(cmd,"quit") == 0)
            exit(0);
        else {
            if(fork()) {
                wait();
                i=0;
            }
            else {
                if(execlp(cmd,cmd,0) < 0) {
                    printf("cannot execute %s\n", cmd);
                    exit(1);
                }
            }
        }   
    }
}
