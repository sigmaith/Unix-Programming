#include <signal.h>
#include <stdio.h>

int main() {
    sigset_t st;

    sigemptyset(&st);

    sigaddset(&st, SIGILL);
    sigaddset(&st, SIGQUIT);
    sigaddset(&st, SIGTRAP);

    if (sigismember(&st, SIGILL))
        printf("SIGILL has been set.\n");
    else
        printf("SIGILL isn't set.\n");
}

