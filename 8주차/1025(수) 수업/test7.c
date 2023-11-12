#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handler(int signo) {
    psignal(signo, "Received Signal:");
    sleep(5); /*blocking이 됐기 때문에 바로 끝나지 않고 5초 있다가 다음문장 실행*/
    printf("In Signal Handler, After Sleep\n");
}


int main(void) {

   struct sigaction act;
 
   sigemptyset(&act.sa_mask);/*0으로 초기화*/
   sigaddset(&act.sa_mask, SIGQUIT);/*더해줌*/
   act.sa_flags = 0;/*플래그는 0 union에서 첫번째 구조체의 함수명*/
   act.sa_handler = handler;
   if (sigaction(SIGINT, &act, (struct sigaction *)NULL) < 0) {/*ctrl + c*/
       perror("sigaction");
       exit(1);
   }
  
   fprintf(stderr, "Input SIGINT: ");
   pause();
   fprintf(stderr, "After Signal Handler\n");
  
   return 0;
}

