E#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct mymsgbuf {
    long mtype;
    char mtext[80];
};

int main() {
    key_t key;
    int msgid; //메시지 식별자
    struct mymsgbuf mesg;

    /*key = ftok("keyfile", 1); //key 생성*/
    msgid = msgget(1068, IPC_CREAT|0644); //메시지 큐 id 얻음
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    mesg.mtype = 1; //메시지 번호
    strcpy(mesg.mtext, "Message Q Test"); //메시지 구조체 텍스트 넣기

    if (msgsnd(msgid, (void *)&mesg, 80, IPC_NOWAIT) == -1) {//논블록 형식
        //메시지 전송. 메시지 식별자 필요
        perror("msgsnd");
        exit(1);
    }
}
