#include <unistd.h>
#include <stdio.h>
#include <string.h>

extern char **environ;

int main(int argc, char *argv[]) {
    char **env;

    env = environ;
    

    while (*env) {
        if(strncmp(argv[1] , *env, strlen(argv[1]))==0){
            printf("%s\n", *env);
        }
        env++;
    }
}
