#include <stdlib.h>
#include <stdio.h>

int main(){
    FILE *fp;
    int fd;
    char buf[BUFSIZ];

    fp = popen("more", "w");
    if(fp == NULL){
        fprintf(stderr, "popen failed\n");
        exit(1);
    }

    pclose(fp);
}