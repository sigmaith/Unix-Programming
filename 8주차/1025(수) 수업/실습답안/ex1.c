#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main() {
    printf("Send SIGUSR1 Signal to me.\n");
    kill(getpid(), SIGUSR1);

    printf("After SIGQUIT Signal.\n");
}

