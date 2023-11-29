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
	rewinddir(dp);/*읽는 위치를 파일의 처음으로 돌림*/
	printf("Cur position : %ld\n", telldir(dp)); 
        /*telldir: 파일의 현재 읽는 위치 알려줌*/

	printf("** Move Directory Pointer **\n");
	readdir(dp); /*맨 첫번째 파일 읽기*/
	loc = telldir(dp);/*현재 읽는 위치*/
	seekdir(dp, loc);/*현재읽는 위치를 loc으로 수정*/
        printf("Cur Position : %ld\n", telldir(dp));

	dent = readdir(dp);/*두번째 파일 읽음*/
	printf("Read : %s\n", dent->d_name);	
        closedir(dp);
}

