#include <stdlib.h>
#include <stdio.h>

int main() {
     FILE *rfp, *wfp;
     int id, s1, s2, s3, s4, n;

     if ((rfp = fopen("test.dat", "r")) == NULL) {
        perror("fopen: test.dat");
        exit(1);
     }

     if ((wfp = fopen("test.scr", "w")) == NULL) {
        perror("fopen: test.scr");
        exit(1);
     }

     fprintf(wfp, "학번 평균\n");
     while ((n=fscanf(rfp, "%d %d %d %d %d", &id,&s1,&s2,&s3,&s4)) != EOF) {
         fprintf(wfp, "%d : %d\n", id, (s1+s2+s3+s4)/4);
     }

     fclose(rfp);
     fclose(wfp);
}

