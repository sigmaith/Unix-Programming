#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct stat statbuf;

    if (argc == 1) {
        printf("Usage: ex3_01.out filename\n");
        exit(1);
    }

    stat(argv[1], &statbuf);

    printf("SIZE = %d\n", (int)statbuf.st_size);
}

