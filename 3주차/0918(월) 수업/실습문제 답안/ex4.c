#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

int main() {
    DIR *dp;
    struct dirent *dent;
    int count;

    dp = opendir("testdir");
    if (dp == NULL) {
        printf("hanbit 디렉터리가 없음\n");
        exit(1);
    }

    count = 0;
    while ((dent = readdir(dp))) {
        printf("Name : %s ", dent->d_name);
        printf("Inode : %d\n", (int)dent->d_ino);
        count++;
    }

    closedir(dp);

    if (count == 2) rmdir("testdir");
}

