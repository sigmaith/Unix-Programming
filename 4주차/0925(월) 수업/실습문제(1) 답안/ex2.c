#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

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

    count = 0;
    while(dent = readdir(dp)) {
        stat(dent->d_name, &statbuf);
        ind[count] = (int)statbuf.st_ino;
        count++;
    }
    closedir(dp);

    find = 0;
    for(n=0; n<count; n++) {
        cind = ind[n];
        for(k=0; k<count; k++) {
            if (k != n && (cind == ind[k]) && (ind[k] != -1)) {
                printf("Same inode: %d\n", cind);
                ind[k] = -1;
                find = 1;
            }
        }
    }
    if (!find) printf("No same inode file\n");

}

