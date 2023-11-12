#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

main() {

        DIR *dp;
        struct dirent *dent;
	long loc;

        if ((dp = opendir(".")) == NULL) {
                perror ("opendir : .");
                exit(1);
        }

        while ((dent = readdir(dp))) {
                printf("Name : %s ", dent->d_name);
		printf("Cur position : %ld\n", telldir(dp));
        }

	printf("** Directory Position Rewind **\n");
	rewinddir(dp);
	printf("Cur position : %ld\n", telldir(dp));

	printf("** Move Directory Pointer **\n");
	readdir(dp);
	loc = telldir(dp);
	seekdir(dp, loc);
        printf("Cur Position : %ld\n", telldir(dp));

	dent = readdir(dp);
	printf("Read : %s\n", dent->d_name);	
        closedir(dp);
}

