main() {
    int a = 2000;

    if (fork()) {
        a /= 2;
        printf("Stoinostta na a = %d\n ", a);
    }
    else {
        if (fork()) {
            a *= 2;
            printf("Stoinostta na a = %d\n ", a);

            if (execlp("ps", "ps", "-u", "student", 0 ) == -1) {
                a = a + 2;
                printf("Stoinostta na a = %d\n ", a);
            }
        }
        else {
            a += 2;
            printf("Stoinostta na a = %d\n ", a);
        }
    }

    a++;
    printf("Stoinostta na a = %d\n ", a);
}


/*
 *
 * Output:
 * *в произволен ред, може да са и с други стойности*
 * Stoinostta na a = 4000
 * Stoinostta na a = 4004
 * Stoinostta na a = 4005
 * Stoinostta na a = 2002
 * Stoinostta na a = 2003
 * *може да има и информация за процесите на потребител student*
 *
 *
 */

