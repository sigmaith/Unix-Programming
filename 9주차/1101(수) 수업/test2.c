#include <stdlib.h>
#include <stdio.h>

int main( ) {
    FILE *fp;
    char buf[256];

    fp = popen("date", "r"); /*읽기 전용으로 실행*/
    if (fp == NULL) {
       fprintf(stderr, "popen failed\n");
       exit(1);
    }

    if (fgets(buf, sizeof(buf), fp) == NULL) {
        /*파이프로부터 data를 읽음*/
        fprintf(stderr, "No data from pipe!\n");
        exit(1);
    }

    printf("line : %s\n", buf);
    pclose(fp);
}