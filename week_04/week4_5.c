#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    for (int i = 1; i <= 10; i++) {
        printf("EXAMPLE\n");
    }
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
    }
    for (int i = 1; i <= 10; i++) {
        printf("HELLO\n", i);
    }
}
