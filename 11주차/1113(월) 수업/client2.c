#include <stdio.h>
#include <stdlib.h>
#include "q.h"

int enter(char *objname, int priority) {

        int len, s_qid;
        struct q_entry s_entry;

        if ((len = strlen(objname)) > MAXOBN) {

                perror("name too long");
                return(-1);
        }

        if (priority > MAXPRIOR || priority < 0) {

                perror("invalid priority level");
                return(-1);
        }

        if ((s_qid = init_queue()) == -1) /*메시지 식별자*/
                return(-1);

        s_entry.mtype = (long)priority;
        strncpy(s_entry.mtext, objname, MAXOBN);

        if (msgsnd(s_qid, &s_entry, len, 0) == -1) {
                /*블록모드*/
                perror("msgsnd failed");
                return(-1);
        }
        else
                return(0);
}

main(int argc, char **argv) {

        int priority;

        if (argc != 3) {
                
                fprintf(stderr, "Usuage: %s objname priority\n", argv[0]);
                exit(1);
        }
        if ((priority = atoi(argv[2])) <= 0 || priority > MAXPRIOR) {

                perror("invalid priority");
                exit(2);
        }

        if (enter(argv[1], priority) < 0) {

                perror("enter failure");
                exit(3);
        }

        exit(0);
}

