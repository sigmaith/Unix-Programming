#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char *val, str[256];

    if(argc != 2) {
        printf("Usage: ex6_14.out value\n");
        exit(1);
    }

    val = getenv("SHELL");
    if (val == NULL)
        printf("SHELL not defined\n");
    else
        printf("1. SHELL = %s\n", val);

    sprintf(str, "SHELL=%s", argv[1]); 
    putenv(str);

    val = getenv("SHELL");
    printf("2. SHELL = %s\n", val);
}

