#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

extern int errno;

main() {

	if (access("test.txt", F_OK) == -1){
		printf("test1 : errno = %d\n", errno);
	}

	return(0);
}
