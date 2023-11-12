#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int pid;

    if(argc == 1) {
        printf("Input pid.\n");
        exit(1);
    }

    pid = atoi(argv[1]);//pid를 인자로 받는다
    if(pid == 0) {//0이면
        pid = getpid();//pid 받고
        printf("PPID : %d\n", getppid());//부모 pid 출력
    }

    printf("PID : %d\n", pid);
    printf("PGID : %d\n", getpgid(pid));
}
