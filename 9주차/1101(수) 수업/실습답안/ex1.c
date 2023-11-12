#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int a;
    char buf[256];

    if(argc != 2) {
        printf("Usage: ex1 command\n");
        exit(1);
    }

    sprintf(buf,"man %s", argv[1]);

    fp = popen(buf, "r");
    if(fp == NULL) {
        fprintf(stderr, "popen failed\n");
        exit(1);
    }

    while(fgets(buf, 256, fp) != NULL)
        puts(buf); 

    pclose(fp);
}

