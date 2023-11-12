#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char*argv[]){
    char *cwd;

    if (argc !=2){
        printf("Usage: prog_name dirname\n");
        exit(1);
    }

    mkdir(argv[1], 0755); //argv[1] 이름의 0755 접근권한 디렉터리 생성
    chdir(argv[1]); //

    cwd = getcwd(NULL, BUFSIZ);
    printf("** dir=%s\n", cwd);

    free(cwd);
}

/*

#include <unistd.h>			

int chdir(const char *path);

path: 이동하려는 디렉터리 경로
chdir()의 특징
- 이동하려는 디렉터리의 경로를 인자로 받으며, 절대경로와 상대경로 모두 사용 가능


*/