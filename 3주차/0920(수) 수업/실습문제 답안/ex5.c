#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dent;
    int count;
    struct stat statbuf;

    if((dp = opendir(".")) == NULL) {
        perror("opendir");
        exit(1);
    }

    while(dent = readdir(dp)) {
        stat(dent->d_name, &statbuf); //파일 정보 검색!!
        printf("Name : %s ", dent->d_name);
        printf("Inode = %d\n", (int)statbuf.st_ino);

    }
    closedir(dp);
}
