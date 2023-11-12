#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void sig_handler(int signo) {
    printf("Signal Handler signum: %d\n", signo);
    sleep(3);
    psignal(signo, "Received Signal");
    signal(SIGQUIT, SIG_DFL);
}

int main() {
    void (*hand)(int);

    hand = signal(SIGQUIT, sig_handler);
    if (hand == SIG_ERR) {
        perror("signal");
        exit(1);
    }

    kill(getpid(), SIGQUIT);
    pause();
    kill(getpid(), SIGQUIT);
}

