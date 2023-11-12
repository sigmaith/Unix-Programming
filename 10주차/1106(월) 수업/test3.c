#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main( ) {
    if (mknod("TEST_FIFO1", S_IFIFO | 0644, 0) == -1) {
        perror("mknod");
        exit(1);
    }

    if (mkfifo("TEST_FIFO2", 0644) == -1) {
        perror("mkfifo");
        exit(1);
    }
}
