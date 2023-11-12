#include <unistd.h>
#include <signal.h>
#include <stdio.h>



int main() {
    sigset_t set;

    sigemptyset(&set);/* 시그널 집합 0으로 초기화 */
    sigaddset(&set, SIGINT); /* SIGINT 시그널 추가 */
    sigprocmask(SIG_BLOCK, &set, (sigset_t *)NULL); 
    /*SIGINT (^C) 를 블로킹하라는 의미*/

    while(1) {
        printf("UNIX Programming");
        sleep(1);
    }
    printf("End...\n");
}

