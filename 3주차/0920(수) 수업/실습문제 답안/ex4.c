#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void CheckMode(unsigned int mode, int m, int k) {
    if ((mode & m) != 0) {
        switch(k) {
            case 0:  /* r */
                printf("r");
                break;
            case 1:  /* 1 */
                printf("w");
                break;
            case 2:  /* 2 */
                printf("x");
                break;
        }
    }
    else
         printf("-");
}

int main(int argc, char *argv[]) {
    struct stat statbuf;
    int kind;

    if (argc == 1) {
        printf("Usage: ex3_09.out filename\n");
        exit(1);
    }

    stat(argv[1], &statbuf);

    printf("%s %d ", argv[1], (unsigned int)statbuf.st_uid);

    CheckMode(statbuf.st_mode, S_IRUSR, 0);
    CheckMode(statbuf.st_mode, S_IWUSR, 1);
    CheckMode(statbuf.st_mode, S_IXUSR, 2);
    CheckMode(statbuf.st_mode, S_IRGRP, 0);
    CheckMode(statbuf.st_mode, S_IWGRP, 1);
    CheckMode(statbuf.st_mode, S_IXGRP, 2);
    CheckMode(statbuf.st_mode, S_IROTH, 0);
    CheckMode(statbuf.st_mode, S_IWOTH, 1);
    CheckMode(statbuf.st_mode, S_IXOTH, 2);

    printf("\n");
}

