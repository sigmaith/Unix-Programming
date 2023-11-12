#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void handler() {
    printf("Timer Invoked..\n");
}

int main() {
    struct itimerval it; /*타이머 정보 저장하는 구조체*/

    signal(SIGVTALRM, handler); /*SIGVTALRM에 대한 signal handler 지정*/
    it.it_value.tv_sec = 0;
    it.it_value.tv_usec = 100000;
    it.it_interval.tv_sec = 1; /*간격*/
    it.it_interval.tv_usec = 0;

    if(setitimer(ITIMER_VIRTUAL, &it, (struct itimerval *)NULL) == -1) { /*타이머 설정*/
        /* 사용자 cpu 시간을 사용 -> 타이머 만료 시 SIGVTALRM 시그널이 생성됨 */
        perror("setitimer");
        exit(1);
    }

    while(1);
}

