#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "q.h"

int enter(char *objname1, char*objname2, int priority);

int main(int argc, char** argv){
    int priority;

    if(argc != 4){
        fprintf(stderr,"Usage: %s object name, priority\n", argv[0]);
        exit(1);
    }

    if((priority = atoi(argv[3]))<=0 || priority >100){
        perror("invalid priority");
        exit(2);
    }

    if(enter(argv[1], argv[2], priority)<0){
        perror("enter failure");
        exit(3);
    }
    exit(0);
}

int enter(char *objname1, char*objname2, int priority){
    int s_qid;
    struct q_entry s_entry;
    char objname[100] ={0};
    strcpy(objname,objname1);
    strcat(objname," ");
    strcat(objname,objname2);

    if((s_qid = init_queue())==-1) /*메시지 큐 생성 후 id return*/
        return -1;

    /*메시지 구조체 채워넣기*/
    s_entry.mtype = (long)priority;/*우선순위*/
    strcpy(s_entry.mtext, objname);/*메시지*/

    if(msgsnd(s_qid, &s_entry, strlen(objname), 0)==-1){/*메시지 전송*/
        perror("msgsnd failed");
        return -1;
    }
    else return 0;
}