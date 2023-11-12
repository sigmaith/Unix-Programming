#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define SIZE 1024

/*

명령행 인자가 있는지 조사하고, 만일 인자가 존재하면, 
각 인자를 하나의 파일 이름으로 취급하고 각 파일의 내용을 
표준 출력으로 복사하는 프로그램을 작성하시오. 만일 명령행 
인자가 존재하지 않으면, 입력을 표준 입력으로부터 받아야 한다

*/
int main(int argc, char **argv) {

        ssize_t nread;
        char buf[SIZE];
        int fd, i;

        if (argc==1) { //인자 없을 경우
                while ((nread = read(0, buf, SIZE)) > 0)//표준 입력으로 입력받고
                        write (1, buf, nread);//표준 출력으로 출력
                exit(0);
        };

        for (i=1; i<argc; i++) {

                fd = open(argv[i], O_RDWR, 0644);//읽기 전용 열기

                memset(buf, 0, SIZE);//메모리 세팅
                while ((nread = read(fd, buf, SIZE)) > 0) {//읽고
                        write(1, buf, SIZE);//출력
                }

                close (fd);
        }
}


