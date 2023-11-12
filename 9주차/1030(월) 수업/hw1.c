#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void sig_handler(int signo, siginfo_t *sf, ucontext_t*uc) {
    psiginfo(sf, "\nReceived Signal:");
    printf("si_code: %d\n", sf->si_code);
}

int main() {
    struct sigaction act;/*sigaction 구조체 선언*/


    act.sa_flags = SA_SIGINFO; /*flag를 SA_SIGINFO로 설정 -> 시그널 핸들러는 인자를 3개 받음*/
    act.sa_sigaction = (void(*)(int, siginfo_t *, void*))sig_handler; 
    sigemptyset(&act.sa_mask);/*0으로 초기화*/

    
    if (sigaction(SIGINT, &act, (struct sigaction *)NULL) < 0) {/*SIGINT을 붙잡고 hander로 시그널 처리*/
        perror("sigaction");
        exit(1);
    }

    fprintf(stderr, "Input SIGINT: ");
    pause();
    fprintf(stderr, "After Signal Handler\n");
}
