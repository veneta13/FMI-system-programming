#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char buffer[15];

int main() {
    const char *file_name = "fff";
    int fd1 = open(file_name, O_RDONLY | O_CREAT, 0777);
    int fd2 = open(file_name, O_WRONLY);
    int fd3 = open(file_name, O_RDWR);

    if (fd1 == -1 || fd2 == -1 || fd3 == -1) {
        printf("Error opening file\n");
        return 0;
    }

    // Part A
    write(fd2, "Hello world", 11);

    read(fd3, buffer, 6);
    write(1, buffer, 6);

    read(fd1, buffer, 5);
    write(1, buffer, 5);

    write(fd3, "chil", 4);
    write(fd2, "!!!", 3);

    read(fd1, buffer, 9);
    write(1, buffer, 9);

    printf("\n------------------------------------\n");

    // Part B
    write(fd3, "Hello", 5);

    write(fd2, "worlds", 6);

    read(fd1, buffer, 6);
    write(1, buffer, 6);

    close(fd2);

    write(fd3, "oops", 4);
    read(fd1, buffer, 6);
    write(1, buffer, 6);
}

/*
 *
 * Output:
 *
 * Hello Hello child!!!
 * ------------------------------------
 * worldsworlds
 *
 */
