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
