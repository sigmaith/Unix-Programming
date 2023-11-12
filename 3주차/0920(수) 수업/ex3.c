#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    struct stat statbuf;
    stat(argv[1], &statbuf);
    int kind;

    printf("파일명: %s\n", argv[1]);
    printf("inode번호: %o\n", (int)statbuf.st_ino);

    kind = statbuf.st_mode & S_IFMT;
    switch (kind){
        case S_IFLNK:
            printf("파일종류: Symbolic Link\n");
            break;
        case S_IFDIR:
            printf("파일종류: Directory\n");
            break;
        case S_IFREG:
            printf("파일종류: Regular File\n");
            break;
    }

    printf("permission %o\n", (unsigned int)statbuf.st_mode);
    printf("UID: %d\n", (unsigned int)statbuf.st_uid);
}