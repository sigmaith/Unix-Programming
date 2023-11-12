#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void sig_handler(int signo) {
    printf("Signal Handler signum: %d\n", signo);
    psignal(signo, "Received Signal");
}

int main() {
    void (*hand)(int);

    hand = signal(SIGILL, sig_handler);
    if (hand == SIG_ERR) {
        perror("signal");
        exit(1);
    }

    kill(getpid(), SIGILL);
}

