#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("--> Before exec function\n");

/*    if (execlp("ls", "ls", "-a", (char *)NULL) == -1) { */   /*PATH 환경 변수에 지정된 디렉토리에서 "ls" 명령을 찾아 실행*/
      if (execl("/bin/ls", "ls", "-a", (char *)NULL) == -1) {  /*실행할 프로그램의 정확한 경로(/bin/ls)를 제공해야 함*/
        /*마지막에 널 포인터 꼭 넘겨줘야 함!!*/
        perror("execl");
        exit(1);
    }

    printf("--> After exec function\n");
}

