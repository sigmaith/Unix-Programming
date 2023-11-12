#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define WBUFSIZE 1024 
#define RBUFSIZE 64 


int main(int argc, char **argv) {
        int fd, i, n;
        int wbuf[WBUFSIZE], rbuf[RBUFSIZE];
	int offset, length;

	fd = open("testdata", O_RDWR|O_CREAT, 0644); //파일 생성
	for (i=0; i<1024; i++) wbuf[i]=i; //정수 배열
	write(fd, wbuf, sizeof(wbuf)); //testdata에 wbuf 내용을 쓰기
	close(fd);

	offset = atoi(argv[1]);//offset은 입력받은 수
	offset *= sizeof(int);//int만큼 곱해주기

	length = atoi(argv[2]);//출력할 길이

	fd = open("testdata", O_RDWR, 0644);//testdata를 읽고 쓰기모드로 열기
	bzero(rbuf, sizeof(rbuf));//rbuf 값을 0으로 초기화

	lseek(fd, (off_t)offset, SEEK_SET);//파일 오프셋 설정 - 처음에서 입력받은 수
	read(fd, rbuf, length*sizeof(int));//파일 읽기 - 설정한 길이만큼 파일 읽기

	for (i=0; i<length; i++) {
		printf("%d ", rbuf[i]);//숫자 출력
	}

	printf("\n");
	close(fd);
}

