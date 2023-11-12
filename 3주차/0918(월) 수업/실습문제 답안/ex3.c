#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *cwd;
    int ret;

    cwd = getcwd(NULL, BUFSIZ);
    if (cwd == NULL) {
        perror("getcwd");
        exit(1);
    }
    printf("1.Current Directory : %s\n", cwd);

    ret = chdir("bit");
    if (ret == -1) {
        perror("chdir");
        exit(1);
    }

    cwd = getcwd(NULL, BUFSIZ);
    if (cwd == NULL) {
        perror("getcwd");
        exit(1);
    }
    printf("2.Current Directory : %s\n", cwd);

    free(cwd);
}
