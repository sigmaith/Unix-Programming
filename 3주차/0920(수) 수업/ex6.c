#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

int main(){
    DIR *dp;
    dp = opendir(".");
    struct dirent *dent;
    struct stat statbuf;
    int kind;

    while(dent = readdir(dp)){
        if(dent->d_name[0] != '.'){
            stat(dent->d_name, &statbuf);
            kind = statbuf.st_mode &S_IFMT;

            if(kind == S_IFDIR)
                printf("Name : %s\n", dent->d_name);
        }
    }

    closedir(dp);
    return 0;
}

/*

답안이 좀 더 간결하게 잘 되어있길래 필사..

while(dent = readdir(dp)){
    if(dent->d_name[0] == '.') continue;

    stat(dent->d_name, &statbuf);
    if(S_ISDIR(statbuf.st_mode)){
        printf("Name : %s\n", dent->d_name);
    }
}

*/