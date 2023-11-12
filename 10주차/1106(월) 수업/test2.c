#include <sys/time.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSIZE 6

char *msg1 = "hello";
char *msg2 = "bye!!";

void parent(int p[3][2]);
int child(int[]);

main() {

        int pip[3][2];
        int i;
        for (i=0; i<3; i++) {
                if (pipe(pip[i]) == -1) perror("pipe call");

                switch(fork()) {
                        case -1: perror("fork call");
                        case 0 : child(pip[i]);
                }
        }

        parent(pip);

        exit(0);
}


void parent(int p[3][2]) {

        char buf[MSGSIZE], ch;
        fd_set set, master;
        int i;

        for (i=0; i<3; i++) close(p[i][1]);/*쓰기 close*/

        FD_ZERO(&master); /*초기화*/
        FD_SET(0, &master); /*표준입력 활성화*/

        for (i=0; i<3; i++) FD_SET(p[i][0], &master);/*읽기를 1로 설정.. master는 fd를 나타내는 큰 상자 */

        while (set = master, select(p[2][0]+1, &set, NULL, NULL, NULL) > 0) {


                if (FD_ISSET(0, &set)) {
                        printf("From standard input ...");
                        read(0, &ch, 1);
                        printf("%c\n", ch);
                }

                for (i=0; i<3; i++) {
                        if (FD_ISSET(p[i][0], &set)) {

                                if (read(p[i][0], buf, MSGSIZE) > 0) {
                                        printf("Message from child %d\n", i);
                                        printf("MSG=%s\n", buf);
                                }
                        }
                }

                if (waitpid (-1, NULL, WNOHANG) == -1) return; /*오류 검사 문장*/
        }
}

int child(int p[2]) {

        int count;

        close (p[0]);

        for (count = 0; count < 2; count ++) {

                write(p[1], msg1, MSGSIZE);
                sleep(getpid() % 4);
        }

        write(p[1], msg2, MSGSIZE);
        exit(0);
}

/*

p[0][0]: 첫 번째 파이프의 읽기 디스크립터
p[0][1]: 첫 번째 파이프의 쓰기 디스크립터
p[1][0]: 두 번째 파이프의 읽기 디스크립터
p[1][1]: 두 번째 파이프의 쓰기 디스크립터
p[2][0]: 세 번째 파이프의 읽기 디스크립터
p[2][1]: 세 번째 파이프의 쓰기 디스크립터

*/
