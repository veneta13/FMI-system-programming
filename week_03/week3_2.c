#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char buffer[20];

int main() {
    int fdr = open("f1", O_RDONLY);
    int fdw = open("f1", O_WRONLY);

    if (fdr == -1 || fdw == -1) {
        printf("error: can't open file");
        exit(1);
    }

    lseek(fdw, -3, SEEK_END);
    write(fdw, "wxyz", 4);

    lseek(fdw, 4, 0);
    write(fdw, "12", 2);

    int readBytes = read(fdr, buffer, 20);
    write(1, buffer, readBytes);
}

/*
 *
 * Output:
 *
 * abcd12bcd-abwxyz
 *
 */