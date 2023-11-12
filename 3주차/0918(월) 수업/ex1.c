#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    if(mkdir("dir1", 0755)==-1){
        perror("dir1");
        exit(1);
    }
    if(mkdir("dir2", 0755)==-1){
        perror("dir2");
        exit(1);
    }
    if(rmdir("dir1")==-1){
        perror("dir1");
        exit(1);
    }
    if(rename("dir2", "testdir")==-1){
        perror("rename");
        exit(1);
    }
}