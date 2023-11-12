#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

int main(){
    DIR *dp;//디렉토리 포인터
    struct dirent *dent;
    int count;
    
    dp = opendir("testdir"); 
    if (dp == NULL){//오류처리: 디렉터리 포인터가 NULL
        printf("hanbit 디렉터리가 없음\n");
        exit(1);
    }

    count = 0;
    while ((dent = readdir(dp))){
        printf("Name : %s ", dent->d_name);
        printf("Inode : %d\n", (int)dent->d_ino);
        count++;
    }

    closedir(dp);

    /* ., .. 밖에 없으면 삭제 */
    if (count==2) rmdir("testdir");
}


/*


디렉토리 열기: opendir
#include <sys/types.h>
#include <dirent.h>
DIR *opendir(Const char *name);

typedef struct dirent{
    ino_t	        d_ino;
	off_t	        d_off;
	unsigned short	d_reclen;
	unsigned char   d_type;
    char            d_name[256];
}dirent_t;


*/