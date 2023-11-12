#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define NAMELENGTH 64

char namebuf[NAMELENGTH];
int infile = -1;
int infile_print =-1;


main(int argc, char **argv) {
        char tmp1[NAMELENGTH] = {0}, tmp2[NAMELENGTH] = {0};
        off_t offset, set;
        ssize_t nread, nwrite;
        int i = 0, wfd, rfd;

        if(argc!=3){
            perror("two room number to exchange");
            exit(1);
        }

        /*파일 출력*/
        if (infile == -1 && (infile = open("residents", O_RDONLY)) == -1) {
            perror("open");
            exit(1);
        }

        printf("\n\n**Before Room Changed**\n\n");

        for (i=0; i<12; i++) {

                offset = (i) * NAMELENGTH;

                if (lseek(infile, offset, SEEK_SET) == -1) {
                        perror("print");
                        exit(1);
                }

                if ((nread = read(infile, namebuf, sizeof(namebuf))) <= 0) {
                        /*오프셋부터 파일을 읽기 시작*/
                        perror("Read error");
                        exit(1);
                }

                printf("room = %d, %s\n", i+1, namebuf);
        }
        close(infile);

        /* 방 바꾸기 시작 */

        if((rfd = open("residents", O_RDWR)) == -1){ /* 읽기 위해 열기 */
            perror("open to read");
            exit(1);
        }

        if((wfd = open("residents", O_RDWR)) == -1){ /* 쓰기 위해 열기 */
            perror("open to write");
            exit(1);
        }

        set = lseek(rfd, NAMELENGTH * (atoi(argv[1])-1), SEEK_SET); /* 오프셋 조정 */
        if((nread = read( rfd, tmp1 ,64 )) == -1){ /* 읽기 */
            perror("fail to read");
            exit(1);
        }

        set = lseek(rfd, NAMELENGTH * (atoi(argv[2])-1), SEEK_SET); /* 오프셋 조정 */
        if((nread = read( rfd, tmp2 ,64 )) == -1){ /* 읽기 */
            perror("fail to read");
            exit(1);
        }

        set = lseek(wfd, NAMELENGTH * (atoi(argv[1])-1), SEEK_SET); /* 오프셋 조정 */
        if((nwrite = write( wfd, tmp2 ,64 )) == -1){ /* 쓰기 */
            perror("fail to write");
            exit(1);
        }

        set = lseek(wfd, NAMELENGTH * (atoi(argv[2])-1), SEEK_SET); /* 오프셋 조정 */
        if((nwrite = write( wfd, tmp1 ,64 )) == -1){ /* 쓰기 */
            perror("fail to write");
            exit(1);
        }

        close(rfd);
        close(wfd); /* 닫기 */
        /* 방 바꾸기 끝 */



        /*파일 출력*/

        if (infile_print == -1 && (infile_print = open("residents", O_RDONLY)) == -1) { /**/
            perror("open");
            exit(1);
        }

        printf("\n\n**After Room Changed**\n\n");


        for (i=0; i<12; i++) {

                offset = (i) * NAMELENGTH;

                if (lseek(infile_print, offset, SEEK_SET) == -1) {
                        perror("print");
                        exit(1);
                }

                if ((nread = read(infile_print, namebuf, sizeof(namebuf))) <= 0) {
                        /*오프셋부터 파일을 읽기 시작*/
                        perror("Read error");
                        exit(1);
                }

                printf("room = %d, %s\n", i+1, namebuf);
        }
        close(infile_print);

}