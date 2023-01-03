#include <stdio.h>
#include <fcntl.h>

main(int args, char* argv[]) {
    int fdr, fdw, n_byt, i = 0, status;
    char symbols[40], c;
    
    if (fork()) { 
        wait(&status);
        
        if (open("file_second", O_RDONLY) != -1)
            write(1, "\n", 1);
        
        execlp("grep", "grep", "234", "file_second", 0);
        execlp("wc", "wc", "-l", "file_second", 0);
    }
    else {
        if ((fdr = open("file_first.txt", O_RDONLY)) == -1) {
            printf("\n Cannot open \n");
            exit(1);
        }
        
        if ((fdw = open("file_second", O_CREAT|O_TRUNC|O_RDWR, 0666)) == -1) {
            printf("\n Cannot open \n");
            exit(1);
        }
        
        n_byt = read(fdr, symbols, 22);
        write(fdw, "12345\n", 6);
        c = symbols[i++];
        
        if ( c >= '0' && c <= '9') { 
            while (symbols[i++] != '\n' && i < n_byt)
                write(fdw, "12345", 5);
            
            write(fdw, "\n", 1);
            write(1, "AAA\n", 4);
        }
        else {
            write(1, symbols, n_byt); 
            write(fdw, symbols, 8);
            write(1, "\n", 1);
        }
        
        write(fdw, "AAA\n", 4);
        write(1, symbols, 12);
        close(fdr);
        close(fdw);
    }
}

// file_first.txt

// 123456789
// AABBCCDDE
