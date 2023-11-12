#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dent;
    struct stat statbuf;
    int count, n, k, find;
    int ind[256], cind;

    if((dp = opendir(".")) == NULL) {
        perror("opendir");
        exit(1);
    }

    while(dent = readdir(dp)) {
        stat(dent->d_name, &statbuf);
        if (((statbuf.st_mode & S_IFMT) == S_IFREG) && (statbuf.st_nlink > 1)){
            /*일반 파일이고 링크 개수가 1 초과일때*/
            unlink(dent->d_name);
        }
    }
    closedir(dp);
}

