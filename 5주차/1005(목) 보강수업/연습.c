#include <sys/types.h>
#include <sys/times.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
프로그램 내에서 함수를 사용해 5초간 
잠들게 했을때 전체 수행시간은?
*/

int main(){
    int i;
    time_t t;
    struct tms mytms;
    clock_t ct, t1, t2;

    ct = sysconf(_SC_CLK_TCK);
    
    if((t1 = times(&mytms)) == -1){
        perror("times 1");
        exit(1);
    }

    sleep(5);

    if((t2 = times(&mytms)) == -1){
        perror("times 2");
        exit(1);
    }

    printf("Real time : %.1f sec\n", (double)(t2-t1)/ct);
    printf("User time : %.1f sec\n", (double)mytms.tms_utime / ct);
    printf("System time : %.1f sec\n", (double)mytms.tms_stime / ct);

}