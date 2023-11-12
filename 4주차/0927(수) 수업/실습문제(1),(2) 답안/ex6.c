#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define NAMELENGTH 64

char namebuf[NAMELENGTH];
int infile = -1;

int main(int argc, char **argv) {

	off_t offset;
	ssize_t nread;
	int i = 0;


        if (infile == -1 && (infile = open("residents", O_RDONLY)) == -1) {
                //infile - residents 파일 디스크립터
                exit(1);
        }

	offset = (atoi(argv[1])-1) * NAMELENGTH;//offset
        if (lseek(infile, offset, SEEK_SET) == -1) { //시작부터 offset만큼
            perror("Seek error");
            exit(1);
        }

        if ((nread = read(infile, namebuf, sizeof(namebuf))) <= 0) {
            perror("Read error");
            exit(1);
        }

        printf("room = %d, %s\n", atoi(argv[1]), namebuf);
	
	close(infile);
}

