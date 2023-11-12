#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct stat statbuf;
    int kind;

    if (argc == 1) {
        printf("Usage: ex3_08.out filename\n");
        exit(1);
    }

    stat(argv[1], &statbuf);

    printf("%s\n", argv[1]);
    printf("inode : = %d\n", (int)statbuf.st_ino);

    kind = statbuf.st_mode & S_IFMT;
    switch (kind) {
        case S_IFLNK:
            printf("link file\n");
            break;
        case S_IFDIR:
            printf("directory\n");
            break;
        case S_IFREG:
            printf("regular file\n");
            break;
    }
    printf("permission %o\n", (unsigned int)statbuf.st_mode);
    printf("UID: %d\n", (unsigned int)statbuf.st_uid);
}

