#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    struct stat statbuf;
    int x;

    stat(argv[2], &statbuf);
    printf("Mode : %o \n", (unsigned int)statbuf.st_mode);
    
    switch(argv[1][0]){
        case 'u':
            switch(argv[1][2]){
                case 'r': x = S_IRUSR; break;
                case 'w': x = S_IWUSR; break;
                case 'x': x = S_IXUSR; break;
            }
            break;
        case 'g':
            switch(argv[1][2]){
                case 'r': x = S_IRGRP; break;
                case 'w': x = S_IWGRP; break;
                case 'x': x = S_IXGRP; break;
            }
            break;
        case 'o':
            switch(argv[1][2]){
                case 'r': x = S_IROTH; break;
                case 'w': x = S_IWOTH; break;
                case 'x': x = S_IXOTH; break;
            }
            break;
    }
    
    if(argv[1][1] == '+') statbuf.st_mode |= x;
    else if(argv[1][1] == '-') statbuf.st_mode &= ~(x);

    chmod(argv[2], statbuf.st_mode);
    stat(argv[2], &statbuf);
    printf("Mode : %o \n", (unsigned int)statbuf.st_mode);
}