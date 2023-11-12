#include <unistd.h>
#include <stdio.h>

int main() {
    printf("PID : %d\n", (int)getpid());//자신 프로세스
    printf("PPID : %d\n", (int)getppid());//부모 프로세스
}

