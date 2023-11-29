#include <stdio.h>
#include <stdlib.h>
#include "q.h"

int serve(void) {

        int mlen, r_qid;
        struct q_entry r_entry;

        if ((r_qid = init_queue()) == -1) /*메시지 큐 식별자를 받음*/
                return(-1);

        for (;;) { /*무한 loop*/
                if ((mlen = msgrcv(r_qid, &r_entry, MAXOBN, (-1*MAXPRIOR), MSG_NOERROR)) == -1)  {
                        /* 식별자, buffer 내용, 메시지 길이, -1*maxprior은 굉장히 작은 음수를 넣으면 
                        작은 번호부터 차례대로 메시지를 받으니깐 , 잘라서라도 받겠다?*/
                        perror("msgrcv failed");
                        return(-1);
                }
                else {

                        r_entry.mtext[mlen] = '\0';
                        proc_obj(&r_entry);
                }
        }
}

main() {

        pid_t pid;

        switch(pid = fork()) {

        case 0:
                serve();
                break;

        case -1:

                perror("fork to start server failed");
                break;

        default:

                printf("server process pid is %d\n", pid);
        }

        exit(pid != -1 ? 0 : 1);
}


