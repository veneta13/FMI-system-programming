#include <stdio.h>

#define DATEPATH "/bin/date"
#define DATE "date"
#define ERROR -1

main(argc, argv)
        int argc;
        char *argv[];
{
    int rc = 0;

    if (execl(DATEPATH, DATE, 0) == ERROR) {
        perror(DATEPATH);
        printf("\n123This line is never printed\n");
        rc = 1;
    }
    else {
        printf("This line is never printed\n");
    }

    exit(rc);
}
