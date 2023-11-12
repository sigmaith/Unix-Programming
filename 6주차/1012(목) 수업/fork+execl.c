#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t child_pid;
    
    // 부모 프로세스에서 자식 프로세스를 생성
    child_pid = fork();
    
    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    if (child_pid == 0) {
        // 이 코드는 자식 프로세스에서 실행됩니다.
        printf("Child process (PID: %d) is running.\n", getpid());

        // 새로운 프로그램 실행 (예: "ls" 명령 실행)
        execl("/bin/ls", "ls", "-a", (char *)NULL);

        // execl 함수가 실패한 경우 이 코드가 실행됨
        perror("execl");
        exit(1);
    } else {
        // 이 코드는 부모 프로세스에서 실행됩니다.
        printf("Parent process (PID: %d) created child process with PID: %d.\n", getpid(), child_pid);
    }

    return 0;
}
