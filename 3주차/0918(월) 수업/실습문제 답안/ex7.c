#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dent;
    int found;

    if (argc != 2) {
        printf("Usage: prog_name filename\n");
        exit(1);
    }

    dp = opendir(".");

    found = 0;
    while ((dent = readdir(dp))) {
        if (strcmp(dent->d_name, argv[1]) ==0) {
            found = 1;
            break;
        }
    }

    closedir(dp);
    if (found) {
        printf("%s file found.\n", argv[1]);
        exit(0);
    }
    else {
        printf("%s file not found.\n", argv[1]);
        exit(1);
    }
}

