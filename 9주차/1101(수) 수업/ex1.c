#include <stdlib.h>
#include <stdio.h>

int main(){
    FILE *fp;
    char buf[BUFSIZ];

   fp = popen("man string help", "r");

    if(fp == NULL){
        fprintf(stderr, "popen failed\n");
        exit(1);
    }

    while(fgets(buf,sizeof(buf), fp)!=NULL){
        printf("%s\n", buf);
    }

    pclose(fp);

}