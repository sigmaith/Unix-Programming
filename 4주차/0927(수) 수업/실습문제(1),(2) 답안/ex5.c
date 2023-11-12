#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define NAMELENGTH 64

char namebuf[NAMELENGTH];
int infile = -1;

main(void) {

        off_t offset;
        ssize_t nread;
        int i = 0;

        if (infile == -1 && (infile = open("residents", O_RDONLY)) == -1) {

                exit(1);
        }



        for (i=0; i<12; i++) {

                offset = (i) * NAMELENGTH;

                if (lseek(infile, offset, SEEK_SET) == -1) {
                //오프셋 조정
                        exit(1);
                }

                if ((nread = read(infile, namebuf, sizeof(namebuf))) <= 0) {
                        //오프셋부터 파일을 읽기 시작
                        perror("Read error");
                        exit(1);
                }

                printf("room = %d, %s\n", i+1, namebuf);
        }

}

