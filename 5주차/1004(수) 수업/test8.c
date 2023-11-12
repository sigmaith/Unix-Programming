#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fp;
    FILE *newfp;
    int newfd;
    
    int n;
    long cur;
    fpos_t fcur;
    char buf[BUFSIZ];

    if ((fp = fopen("test.txt", "r")) == NULL) {
        perror("fopen: test.txt");
        exit(1);
    }

    newfd = fileno(fp); //파일 포인터에서 파일 디스크립터를 뽑아낼수 있다.
    printf("%d\n", newfd);

    cur = ftell(fp);//0
    printf("Offset cur=%d\n", (int)cur);

    n = fread(buf, sizeof(char), 5, fp);
    buf[n] = '\0';
    printf("-- Read Str=%s\n", buf);

    fseek(fp, 1, SEEK_CUR);

    cur = ftell(fp);//6
    printf("Offset cur=%d\n", (int)cur);

    n = fread(buf, sizeof(char), 6, fp);
    buf[n] = '\0';
    printf("-- Read Str=%s\n", buf);

    fseek(fp, 1, SEEK_CUR);

    cur = ftell(fp);//13
    printf("Offset cur=%d\n", (int)cur);

    n = fread(buf, sizeof(char), 11, fp);
    buf[n] = '\0';
    printf("-- Read Str=%s\n", buf);

    rewind(fp);// ->0 오프셋 초기화
    cur = ftell(fp);
    printf("Rewind Offset cur=%d\n", (int)cur);

    fclose(fp);

    return 0;
}

//fseek와 seek 잘 공부하기..