#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *rfp, *wfp;
    char buf[BUFSIZ];
    int n;

    if (argc != 3) {
        printf("Usage: newname file1 file2\n");
        exit(1);
    }

    if ((rfp = fopen(argv[1], "r")) == NULL) {//읽기
        perror("fopen");
        exit(1);
    }

    if ((wfp = fopen(argv[2], "a")) == NULL) {//추가하기
        perror("fopen");
        exit(1);
    }

    while (fgets(buf, BUFSIZ, rfp) != NULL) {//읽고
        fputs(buf, wfp);//쓰기
    }

    fclose(rfp);
    fclose(wfp);

    remove(argv[1]);//삭제
}

//파일 이름 바구기

