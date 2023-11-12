#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int printpos(const char *string, int filedes);

main() {

	int fd;
	int nread;
	pid_t pid;
	char buf[10];

	if ((fd = open("testdata", O_RDONLY)) == -1)
		perror("open failed");

	read(fd, buf, 10);

	printpos("Before fork", fd);

	switch(pid = fork()) {
	case -1:

		perror("fork failed");
		break;
	case 0://child

		printpos("Child before read", fd);
		read(fd, buf, 10);
		printpos("Child after read", fd);
		close (fd);
		break;
	default://parent

		wait((int *)0);
		printpos("Parent after wait", fd);
		if ((nread = read(fd, buf, 10)) <= 0) 
			perror("file read error");
	
	}
}

int printpos(const char *string, int filedes) {

	off_t pos;

	if ((pos = lseek(filedes, 0, SEEK_CUR)) == -1)
		perror ("lseek failed");

	printf("%s:%ld\n", string, pos);
}



