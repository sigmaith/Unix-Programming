#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    struct stat statbuf;

    int check = stat(argv[1], &statbuf);

    printf("SIZE = %d\n", (int)statbuf.st_size);

}