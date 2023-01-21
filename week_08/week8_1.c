#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char buffer[50];

int main() {
    while (1) {
        write(1, ">>> ", 4);

        int buff_cnt = 0;

        while (read(0, &buffer[buff_cnt], 1) > 0) {
            if (buffer[buff_cnt] == '\n') {
                buffer[buff_cnt] = '\0';
                break;
            }

            if (buffer[buff_cnt] == ' ') {
                continue;
            }

            buff_cnt++;
        }

        if (strcmp(buffer, "quit") == 0) {
            exit(0);
        }
        else {
            if (fork() == 0) {
                execlp(buffer, buffer, 0);
                exit(1);
            }
            else {
                int status;
                wait(&status);

                if (status != 0) {
                    printf("ERROR: can't execute command\n");
                }
            }
        }
    }
}
