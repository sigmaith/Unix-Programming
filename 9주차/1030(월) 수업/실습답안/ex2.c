#include <signal.h>
#include <stdio.h>

main() {
    sigset_t st;

    sigfillset(&st); /*집합을 1로 초기화*/

    if(sigismember(&st, SIGBUS)) /*SIGBUS가 st집합에 설정되어있는지 확인*/
    /*시그널 SIGBUS는 버스 오류로 발생됨, 디폴트 처리: 코어덤프*/
        printf("SIGBUS is setting.\n");
    else
        printf("SIGBUS is not setting.\n");
}

