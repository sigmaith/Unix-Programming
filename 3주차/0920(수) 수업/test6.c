#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>

extern int errno;

main() {

        int per;

        if (access("test.bak", F_OK) == -1 && errno == ENOENT)
                printf("test.bak : File not exist.\n");

        per = access("test.txt", R_OK);
        if (per == 0)
                printf("unix.txt : Read permission is permitted.\n");
        else if (per == -1 && errno == EACCES)
                printf("unix.txt : Read permission is not permitted.\n");

}

