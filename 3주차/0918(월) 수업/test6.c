#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

main() {

        DIR *dp;
        struct dirent *dent;

        if ((dp = opendir(".")) == NULL) { ////현재 디렉토리 열기
        //if ((dp = opendir("han")) == NULL) {
                perror ("opendir : han");
                exit(1);
        }

        while ((dent = readdir(dp))) {
                printf("Name : %s ", dent->d_name);
                printf("Inode : %d\n", (int)dent->d_ino);
        }

        closedir(dp);
}

