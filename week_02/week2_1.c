#include<stdio.h>
#include<fcntl.h>

char buf[16];

int main() {
    int file = open("aa.txt", O_RDONLY);
    int i;
    for (i = 5; i > 0; i--) {
        read(file, buf, i);
        printf("%s\n", buf);
    }
    return 0;
}

/*
abcde
fghie
jklie
mnlie
onlie
*/
