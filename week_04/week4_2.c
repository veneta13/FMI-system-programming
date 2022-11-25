#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

main() {
    for (int i = 0; i < 10; i++) {
        write(1, "EXAMPLE\n", 8);
    }
}