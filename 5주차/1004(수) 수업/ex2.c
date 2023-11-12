#include <stdlib.h>
#include <stdio.h>

int main(){
    FILE *rfp, *wfp ,*r;
    int c, n;
    char buf[4]={0};

    if((rfp = fopen("datafile", "r"))==NULL){
        perror("fopen: datafile (read)");
        exit(1);
    }

    if((wfp = fopen("datafile.out", "w"))==NULL){
        perror("fopen: datafile.out (write)");
        exit(1);
    }

    while ((c=fgets(buf,3,rfp)) != EOF){
        fputs(buf, wfp);
    }

    fclose(rfp);
    fclose(wfp);
    
    if((r = fopen("datafile.out","r"))==NULL){
        perror("fopen: datafile.out (read)");
        exit(1);
    }
    while(1){
        rewind(r);
        int a; scanf("%d", &a);
        fseek(r, 3*(a-1), SEEK_SET);
        n = fread(buf, sizeof(buf), 3, r);
        printf("%s\n", buf);
    }
    fclose(r);
}

//fread? fscanf? fwrite? fprintf?