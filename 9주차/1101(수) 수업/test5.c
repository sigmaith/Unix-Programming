#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*파이프에 한번에 보낼 수 있는 최대 데이터 사이즈 측정*/

int count;
void alrm_action(int);

main() {
        int p[2];
        int pipe_size;
        char c='x';
        static struct sigaction act;

        act.sa_handler = alrm_action;
        sigfillset(&(act.sa_mask)); /*1로 초기화*/

        if (pipe(p) == -1) {
                perror("pipe call");
                exit(1);
        }

        pipe_size = fpathconf(p[0], _PC_PIPE_BUF); /**/
        printf("Maximum size of write to pipe : %d bytes\n", pipe_size);

        sigaction(SIGALRM, &act, NULL);/*알람 시그널 enable*/

        while (1) {
                alarm(5);
                write(p[1], &c, 1);/*1바이트씩 쓰기*/

                if ((++count % 1024) == 0) printf("%d characters in pipe\n", count);
        }
}

void alrm_action(int signo) {

        printf("write blocked after %d characters\n", count);
        exit(0);
}

