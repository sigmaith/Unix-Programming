#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>

/*#define QKEY            (key_t)0100*/
#define QPERM           0660
#define MAXOBN          50
#define MAXPRIOR        10

struct q_entry {
        long mtype;
        char mtext [MAXOBN+1];
};

int init_queue(void) {

        int queue_id;
        key_t msq_key;

        /*msq_key = ftok("keyfile", 1);*/
        if ((queue_id = msgget(1068, IPC_CREAT | QPERM)) == -1)
                /*메시지 큐 생성*/
                perror("msgget failed");

        return (queue_id);
}

int proc_obj (struct q_entry *msg) {

        printf("\npriority: %ld name: %s\n", msg->mtype, msg->mtext);
}

/*이 함수가 sever.c에 쓰임*/
