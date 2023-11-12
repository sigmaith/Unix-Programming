#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
   char *cwd; //current working directory
   int ret;

   cwd = getcwd(NULL, BUFSIZ);
   if (cwd == NULL){//getcwd 실패 시
      perror("getcwd");
      exit(1);
   }
   printf("1.Current Directory : %s\n", cwd);

   ret = chdir("bit");
   if(ret == -1){//change dir 실패 시
      perror("chdir");
      exit(1);
   }

   cwd = getcwd(NULL, BUFSIZ);
   if (cwd == NULL){
      perror("getcwd");
      exit(1);
   }
   printf("2.Current Directory : %s\n", cwd);

   free(cwd);
}

/*

char * cwd = getcwd(NULL, BUFSIZ);
오류: NULL
int ret = chdir("bit");
오류: -1

main 문에서의 return(0) 은 exit(0)과 같은 의미를 가진다. 
즉, 프로그램이 모두 실행되고 정상 종료되는 것을 의미할 땐 exit(0)을 사용한다. 
하지만 실행 중간의 에러가 발생할 시 에러로 인한 강제종료는 exit(1)을 해주어야 한다.

*/

