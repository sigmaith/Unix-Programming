#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(int argc, char **argv) {

	key_t mkey;
	int msq_id;
	struct msqid_ds msq_status;

	/*mkey = ftok("keyfile", 1);*/
        if ((msq_id = msgget(1068, IPC_CREAT | 0644)) == -1) {
                perror("msgget failed");
                exit(1);
        }

	printf("Before IPC_RMID\n");/*ipc:메시지 큐 삭제 전*/
	system("ipcs -q | grep s21011068");/*system함수는 뭐지*/
	if (msgctl(msq_id, IPC_RMID, &msq_status) == -1) {
		/*메시지 큐 삭제*/
		perror("msgctl failed");
		exit(3);
	}
	printf("After IPC_RMID\n");/*ipc:메시지 큐 삭제 후*/
	system("ipcs -q | grep s21011068");
}

