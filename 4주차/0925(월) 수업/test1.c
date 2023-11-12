#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FILENAME "test.txt"

int main(void)
{

	int fd = open(FILENAME, O_CREAT|O_RDWR, 0644);	
/* 110 100 100 & 111 111 111 (~0) = 0644*/
	umask(0);
	unlink(FILENAME);
	fd = open(FILENAME, O_CREAT|O_RDWR, 0644);	

//#if 0
/* 110 100 100 & 100 101 110 (~011 010 001) = 0444*/
	unlink(FILENAME);
	umask(0321);
	fd = open(FILENAME, O_CREAT|O_RDWR, 0644);

	unlink(FILENAME);
	umask(0444);
	fd = open(FILENAME, O_CREAT|O_RDWR, 0755);
	return 0;

//#endif
}

/*

umask는 fileopen전에 사용해야한다.

*/
