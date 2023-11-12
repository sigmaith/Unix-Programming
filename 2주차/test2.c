#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

extern int errno;

main() {

	FILE *fp;

	if ((fp = fopen("test.txt", "r")) == NULL) {
		printf("test2 : errno = %d\n", errno);
		exit(1);
	}

	fclose(fp);

	return(0);
}
