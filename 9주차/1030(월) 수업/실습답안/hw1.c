#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void sig_handler(int signo, siginfo_t *si, void *ucontext) {
    psignal(si->si_signo, "Received Signal:");
    printf("si_code: %d\n", si->si_code);
    sleep(3);
    printf("In Signal Handler, After Sleep\n");
}

int main() {
    struct sigaction act;

    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = sig_handler;
    if (sigaction(SIGINT, &act, (struct sigaction *)NULL) < 0) {
        perror("sigaction");
        exit(1);
    }

    fprintf(stderr, "Input SIGINT: ");
    pause();
    fprintf(stderr, "After Signal Handler\n");
}

