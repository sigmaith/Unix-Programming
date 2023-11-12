#include <stdlib.h>
#include <stdio.h>

int main() {
     FILE *rfp, *wfp;
     char buf[BUFSIZ];
     int n;

     if ((rfp = fopen("test.txt", "r")) == NULL) {
        perror("fopen: test.txt");
        exit(1);
     }

     if ((wfp = fopen("test.out", "a")) == NULL) {
         perror("fopen: test.out");
         exit(1);
     }

     while ((n = fread(buf, sizeof(char)*2, 4, rfp)) > 0) {
        fwrite(buf, sizeof(char)*2, n, wfp);
     }

     fclose(rfp);
     fclose(wfp);
}

//복사 프로그램을 짤수 있다.
