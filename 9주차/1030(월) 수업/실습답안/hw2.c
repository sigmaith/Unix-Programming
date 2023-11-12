#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void alarm_handler(int signo) {
    printf("** Wake UP **\n");
}

int main() {
    sigset_t set;

    signal(SIGALRM, alarm_handler);

    sigfillset(&set);
    sigdelset(&set, SIGALRM);
    sigdelset(&set, SIGINT);
    sigprocmask(SIG_BLOCK, &set, (sigset_t *)NULL);

    while(1) {
       alarm(1);
       printf("...\n");
       sleep(2);
   }
}

