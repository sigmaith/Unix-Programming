#include <sys/types.h>
#include <sys/times.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    time_t t;
    struct tms mytms;
    clock_t ct, t1, t2;

    ct = sysconf(_SC_CLK_TCK);
    /*함수를 사용하여 시스템의 클록 틱 수를 가져옵니다. 
    클록 틱 수는 초당 클록 (clock) 수를 나타냅니다.*/

    if((t1 = times(&mytms)) == -1) {
        /*현재 CPU 시간 정보를 mytms 구조체에 저장*/
        perror("times 1");
        exit(1);
    }

    sleep(5);
    /*프로세스를 5초 동안 일시 정지->
    실제 실행 시간 및 CPU 시간 정보가 변경됨*/
    
    if((t2 = times(&mytms)) == -1) {
        /*times(&mytms) 함수를 다시 
        호출하여 5초 동안의 CPU 시간 정보를 업데이트*/
        perror("times 2");
        exit(1);
    }

    printf("Real time : %.1f sec\n", (double)(t2 - t1) / ct);
    printf("User time : %.1f sec\n", (double)mytms.tms_utime / ct);
    printf("System time : %.1f sec\n", (double)mytms.tms_stime / ct);
}
