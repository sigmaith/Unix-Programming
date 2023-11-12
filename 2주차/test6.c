#include <sys/errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern int errno;

int main(void) {
     char *err;

     if (access("test.txt", R_OK) == -1) {
         err = strerror(errno);
         printf("ERROR:%s(test.txt)\n", err);
         exit(1);
     }
     return 0;
}

