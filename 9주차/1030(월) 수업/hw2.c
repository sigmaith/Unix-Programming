#include <unistd.h>
#include <signal.h>
#include <stdio.h>


void sig_handler(int signo){
    printf("Wake up\n");
    psignal(signo, "Received Signal");
}

int main(){
    sigset_t set;
    sigfillset(&set); /*집합을 1로 초기화*/
    sigdelset(&set, SIGINT);
    sigdelset(&set, SIGALRM);
    signal(SIGALRM, sig_handler);

    while(1){
        sigprocmask(SIG_BLOCK, &set, (sigset_t *)NULL);
        alarm(1);
        sleep(1);
    }
}