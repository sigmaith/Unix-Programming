#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

main() {

	int fd;
	struct flock my_lock;
	struct flock b_lock;

	my_lock.l_type = F_WRLCK;//읽기 록
	my_lock.l_whence = SEEK_SET;
	my_lock.l_start = 0;
	my_lock.l_len = 10;//파일의 시작부터 10바이트

	fd = open("testdata", O_RDWR);

	if (fcntl(fd, F_SETLKW, &my_lock) == -1) {//거부하면 sleep되는걸로 lock
		perror("parent : locking");
		exit(1);
	}

	printf("parent : locked record %d\n", getpid());

	switch(fork()) {
		case -1 :
			perror("fork");
			exit(1);
		case 0 : /*child*/
			my_lock.l_len = 5;//5바이트 읽는 걸로 바뀜
			if (fcntl(fd, F_SETLK, &my_lock) == -1) {//록 ->바로 -1반환.
				if (errno == EACCES || errno == EAGAIN) {
					fcntl(fd, F_GETLK, &b_lock);//록정보 획득
					printf("record locked by %d\n", b_lock.l_pid);
				}
				else {
					perror("unexpected lock error");
					exit(1);
				}
			}
			printf("child: exiting\n");
			exit(0);
	}
	
	sleep(2);

	printf("parent: unlocking\n");

	my_lock.l_type = F_UNLCK;
	if (fcntl(fd, F_SETLK, &my_lock) == -1) {
		printf("parent : unlocking");
		exit(1);
	}

	exit(0);
}




