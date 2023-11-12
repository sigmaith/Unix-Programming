#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

main() {
        char *argv[4];

        printf("--> Before exec function\n");

        //argv[0] = "ex1_argc";
        /*자연히 실행파일은 이렇게 된다. 위 문장은 지워도 됨.*/
        argv[1] = ".";
        argv[2] = ".c";
        argv[3] = NULL;

        if (execv("./ex1_argc", argv) == -1) {
                perror("execv");
                exit(1);
        }

        printf("--> After exec function\n");
}

