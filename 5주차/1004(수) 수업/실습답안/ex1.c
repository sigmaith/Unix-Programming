#include <stdio.h>
#include <fcntl.h>

main() {

	int fd;
	int arg1;

	fd = open("testdata1", O_WRONLY|O_CREAT, 0644);
	write(fd, "hi there...\n", 15);
	lseek(fd, (off_t)0, SEEK_SET);
	fcntl(fd, F_SETFL, O_WRONLY|O_APPEND);
	write (fd, "students...\n", 15);

	arg1 = fcntl(fd, F_GETFL);
	switch (arg1 & O_ACCMODE) {
		case O_WRONLY:
			printf("write-only\n");
			break;
		case O_RDWR:
			printf("read_write\n");
			break;
		case O_RDONLY:
			printf("read-only\n");
			break;
		default:
			printf("No such mode");
	}

	if (arg1 & O_APPEND)
		printf(" - append flag set\n");

	close (fd);
}

