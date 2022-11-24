
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

main() {
    int fd, i, k;
    char str[8];

    for (i = 0; i <= 5; ++i)
        printf("i = %d\n", i);
    k = dup(1);

    write(1, "duplicated descriptor k = ", sizeof("duplicated descriptor k = "));
    sprintf(str, "%d", k);
    write(1, str, strlen(str));
    write(1, "\n", 1);

    for (i = 0; i <= 10; ++i) {
        sprintf(str, "i = %d\n", i);
        write(k, str, strlen(str));
    }
}
