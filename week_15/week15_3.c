#include <stdio.h>
#include <fcntl.h>

main() {
    int fdr, fdw, n_byt, i = 0, status;
    char symbols[40], c;

    if (fork()) {
        wait(&status);

        if (open("file_new", O_RDONLY) != -1) {
            write(1, "\n", 1);
            execlp("wc", "wc", "-c", "file_new", 0);
            execlp("head", "head", "-5c", "file_new", 0 );
        }
    }
    else {

        if ((fdr = open("fileD.txt", O_RDONLY)) == -1 ) {
            printf("\n Cannot open  \n");
            exit(1);
        }

        if ((fdw = open("file_new", O_CREAT | O_TRUNC | O_RDWR, 0666)) == -1) {
            printf("\n Cannot creat  \n");
            exit(1);
        }

        n_byt = read(fdr, symbols, 40);
        c = symbols[i++];

        if (c >= '0' && c <= '9') {
            while (symbols[i++] != '\n' && i < n_byt)
                write(fdw, "$", 1);

            write(fdw, "\n", 1);
            write(1, "\n", 1);
        }
        else {
            write(1, symbols, n_byt);
            write(1, "\n", 1);
        }

        write(fdw, "$\n", 2);
        write(1, symbols, 12);
        close(fdr);
        close(fdw);
    }
}

/*
 *
 * Output:
 *
 * 123456789
 * $$
 * 11 file_new
 *
 *
 * file_new:
 * $$$$$$$$
 * $
 *
 */

