#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    char *cwd, *owd;

    owd = getcwd(NULL, BUFSIZ);
    printf("1. dir=%s\n", owd);

    chdir("testdir");
    cwd = getcwd(NULL, BUFSIZ);
    printf("** in dir: %s\n", cwd);
    
    chdir(owd);
    cwd = getcwd(NULL, BUFSIZ);
    printf("2. dir=%s\n", cwd);

    free(owd);
    free(cwd);
}

