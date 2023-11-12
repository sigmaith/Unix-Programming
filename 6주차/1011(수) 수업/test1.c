#include <unistd.h>
#include <stdio.h>

extern char **environ; 
/*전역변수 environ*/

int main() {
    char **env;

    env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}
