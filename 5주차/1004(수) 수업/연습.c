#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *rfp, *wfp;
    char buf[BUFSIZ];
    int n;

    if(argc != 3){
        printf("Usage: newname file1 file2\n");
        exit(1);
    }

    if((rfp = fopen(argv[1], "r")) == NULL){
        perror("fopen");
        exit(1);
    }

    if((wfp = fopen(argv[2], "a")) == NULL){
        perror("fopen");
        exit(1);
    }

    while(fgets(buf, BUFSIZ, rfp)!=NULL){
        fputs(buf, wfp);
    }

    fclose(rfp);
    fclose(wfp);

    remove (argv[1]);
}