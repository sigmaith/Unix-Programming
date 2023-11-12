#include <stdlib.h>
#include <stdio.h>

int main() {
     FILE *rfp;
     char buf[BUFSIZ];
     int n;

     if ((rfp = fopen("testdata", "r")) == NULL) {
        perror("fopen: testdata");
        exit(1);
     }

     while ((n=fread(buf, sizeof(char)*2, 4, rfp)) > 0) {
        buf[8] = '\0';
        printf("n=%d, buf=%s\n", n, buf);
     }

     fclose(rfp);
}

