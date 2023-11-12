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
        if(dent->d_name[0] == '.') continue;
        /*if(dent->d_name[0] == '..') continue; 원래 없던거 */
        if(strcmp(dent->d_name, "..")==0) continue; /*원래 없던거*/

        stat(dent->d_name, &statbuf);
        if(S_ISDIR(statbuf.st_mode)) {
            printf("Name : %s\n", dent->d_name);
        }
    }
    closedir(dp);
}

