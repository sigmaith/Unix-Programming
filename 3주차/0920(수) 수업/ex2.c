#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
    struct stat statbuf;
    int kind;

    stat(argv[1], &statbuf);

    printf("Mode = %o\n", (unsigned int)statbuf.st_mode);

    kind = statbuf.st_mode & S_IFMT;
    printf("Kind = %o\n", kind);

    switch (kind){
        case S_IFLNK:
            printf("%s: Symbolic Link\n", argv[1]);
            break;
        case S_IFDIR:
            printf("%s: Directory\n", argv[1]);
            break;
        case S_IFREG:
            printf("%s: Regular File\n", argv[1]);
            break;
    }

}