#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define NSTRINGS        5
#define STRSIZE         3

char *strings[] = {     "aaa",  "bbb",  "ccc",  "ddd",  "eee"};

main(int argc, char **argv) {

        int i,n;
        FILE *fp;
        char buf[STRSIZE], template[32];

        if ((fp = fopen("testdata2", "w+")) == NULL) {
                exit(1);
        }

        for (n=0; n<NSTRINGS; n++)
                fwrite(strings[n], sizeof(char), STRSIZE, fp);

        for (i=0; i<5; i++) {

                printf("Which string (0 to quit)? ");
                scanf("%d", &n);

                if (n == 0) {
                        fclose (fp);
                        exit(0);
                }

                if (n<0 || n>NSTRINGS) {
                        fclose(fp);
                        fprintf(stderr, "Out of range. %d\n", errno);
                        exit(1);
                }

                fseek(fp, (n-1)*STRSIZE, SEEK_SET);
                fread(buf, sizeof(char), STRSIZE, fp);

                printf("String %d = %s\n\n", n, buf);
        }

        fclose(fp);
        exit(0);
}

