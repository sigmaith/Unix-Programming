#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

main() {

        char buf1[BUFSIZ], buf2[BUFSIZ];
        int n;

        n = readlink("test.sym", buf1, BUFSIZ);
        if (n == -1) {
                perror("readlink");
                exit(1);
        }

        buf1[n] = '\0';
        printf("test.sym : READLINK = %s\n", buf1);

        realpath("test.sym", buf2);
	printf("test.sym : REALPATH = %s\n", buf2);

}

