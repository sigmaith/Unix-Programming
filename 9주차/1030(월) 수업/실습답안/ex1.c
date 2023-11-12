#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void sig_handler(int signo) {
    psignal(signo, "Received Signal:");
    sleep(3);
    printf("In Signal Handler, After Sleep\n");
}

int main() {
    struct sigaction act;/*sigaction 구조체 선언*/

    sigemptyset(&act.sa_mask);/*0으로 초기화*/
/*
    sigaddset(&act.sa_mask, SIGQUIT);
*/
    act.sa_flags = SA_RESETHAND; /*flag를 default로 설정.. 시그널 기본 처리방법이 SIG_DFL로 재설정됨*/
    act.sa_handler = sig_handler; 
    if (sigaction(SIGQUIT, &act, (struct sigaction *)NULL) < 0) {/*SIGQUIT을 붙잡고 hander로 시그널 처리*/
        perror("sigaction");
        exit(1);
    }

    fprintf(stderr, "Input SIGQUIT: ");
    pause();
    fprintf(stderr, "After Signal Handler\n");
}
