#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NSTRINGS        5
#define STRSIZE         3

char *strings[] = {     "aaa",  "bbb",  "ccc",  "ddd",  "eee"};

main(int argc, char **argv) {

        int i,n;
        /*FILE *fp;*/
        int fd;
        char buf[STRSIZE];

/*
        if ((fp = fopen("testfile", "w+")) == NULL) {
                        exit(1);
        }
*/
        fd = open("testdata3", O_RDWR|O_CREAT, 0644);

        for (n=0; n<NSTRINGS; n++)
                write(fd, strings[n], STRSIZE*sizeof(char));

/*
        for (n=0; n<NSTRINGS; n++)
                fwrite(strings[n], sizeof(char), STRSIZE, fp);
*/

        for (i=0; i<5; i++) {

                printf("Which string (0 to quit)? ");
                scanf("%d", &n);

                if (n == 0) {
                        /*fclose (fp);*/
                        close(fd);
                        exit(0);
                }

                if (n<0 || n>NSTRINGS) {
                        close(fd);
                        fprintf(stderr, "Out of range.\n");
                        exit(1);
                }

                /* fseek(fp, (n-1)*STRSIZE, SEEK_SET);
                fread(buf, sizeof(char), STRSIZE, fp); */

                memset(buf, 0, sizeof(buf));
                lseek(fd, (off_t)(n-1)*STRSIZE, SEEK_SET);
                read(fd, buf, STRSIZE*sizeof(char));

                buf[STRSIZE] = '\0';

                printf("String %d = %s\n\n", n, buf);
        }

        /*fclose(fp);*/
        close(fd);
        exit(0);
}
