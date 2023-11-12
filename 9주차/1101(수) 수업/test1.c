#include <stdlib.h>
#include <stdio.h>

int main( ) {
    FILE *fp;
    int a;

    fp = popen("wc -l", "w"); /*셸명령, 쓰기 전용 실행*/
    if (fp == NULL) {
        fprintf(stderr, "popen failed\n");
        exit(1);
    }

    for (a = 0; a < 100; a++)
        fprintf(fp, "test line\n"); /**/

    pclose(fp);
}

