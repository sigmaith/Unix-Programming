#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    struct stat statbuf;
    int x; int a;

    stat(argv[2], &statbuf);
    printf("Mode : %o \n", (unsigned int)statbuf.st_mode);

    statbuf.st_mode = 0;
    
    for(a=0; a<3; a++){
        x = 0;
        switch(argv[1][a]){
            case '7': x |= S_IRWXU; break;
            case '6': x |= (S_IRUSR | S_IWUSR); break;
            case '5': x |= (S_IRUSR | S_IXUSR); break;
            case '4': x |= S_IRUSR; break;
            case '3': x |= (S_IWUSR | S_IXUSR); break;
            case '2': x |= S_IWUSR; break;
            case '1': x |= S_IXUSR; break;
            case '0': x |= 0; break;
        }
        if(a==0) statbuf.st_mode |= x;
        if(a==1) statbuf.st_mode |= (x>>3);
        if(a==2) statbuf.st_mode |= (x>>6);

        chmod(argv[2], statbuf.st_mode); //중요!!
    }

    
    stat(argv[2], &statbuf);
    printf("Mode : %o \n", (unsigned int)statbuf.st_mode);
    return 0;
}