#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    struct stat buf;
    int x;

    if(argc != 3){
        printf("Usage : mychmod perm file");
        exit(1);
    }

    stat(argv[2], &buf);

    switch(argv[1][0]){
        case 'u':
            switch(argv[1][2]){
                case 'r': x = S_IRUSR; break;
            }
    }
}