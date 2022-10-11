#include<stdio.h>
#include<fcntl.h>

char buf[16];
int main() {
        int file = open("aa.txt", O_RDONLY);
        int i;
        for (i = 5; i > 0; i--) {
                read(file, buf, i);
                write(1, buf, i);
        }
        return 0;
}

/*
  abcdefghijklmno
*/
