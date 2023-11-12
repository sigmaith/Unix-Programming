#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

main() {

	int fd;
	struct flock my_lock;
	struct flock b_lock;

	my_lock.l_type = F_WRLCK; //write lock
	my_lock.l_whence = SEEK_SET; //파일의 시작
	my_lock.l_start = 0; //offset
	my_lock.l_len = 10;

	fd = open("testdata", O_RDWR);

	if (fcntl(fd, F_SETLKW, &my_lock) == -1) {
		perror("parent : locking");
		exit(1);
	}

	printf("parent : locked record\n");

	switch(fork()) {
		case -1 :
			perror("fork");
			exit(1);
		case 0 : /*child*/
			my_lock.l_len = 5;//읽는 길이 변경
			if (fcntl(fd, F_SETLKW, &my_lock) == -1) {//sleep.. block
				perror("child : locking");
				exit(1);
			}
			printf("child: locked\n"); //부모process에서 unlock 후 실행됨
			printf("child: exiting\n");
			exit(0);
	}
	
	sleep(2);

	printf("parent: unlocking\n");

	my_lock.l_type = F_UNLCK; //록 제거
	if (fcntl(fd, F_SETLK, &my_lock) == -1) {
		printf("parent : unlocking");
		exit(1);
	}
	exit(0);
}

