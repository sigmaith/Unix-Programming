#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char *cwd;

    if (argc != 2) {
        printf("Usage: prog_name dirname\n");
        exit(1);
    }

    mkdir(argv[1], 0755);
    chdir(argv[1]);

    cwd = getcwd(NULL, BUFSIZ);
    printf("** dir=%s\n", cwd);

    free(cwd);
}

