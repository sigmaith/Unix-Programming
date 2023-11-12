#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>

main() {

        struct stat buf;

        printf("1. stat : test.txt ---\n");
        stat("test.txt", &buf);
        printf("test.txt : Link Count = %d\n", (int)buf.st_nlink);
        printf("test.txt : Inode = %d\n", (int)buf.st_ino);

        printf("2. stat : test.sym ---\n");
        stat("test.sym", &buf);
        printf("test.sym : Link Count = %d\n", (int)buf.st_nlink);
        printf("test.sym : Inode = %d\n", (int)buf.st_ino);

        printf("3. lstat : test.sym ---\n");
        lstat("test.sym", &buf);
        printf("test.sym : Link Count = %d\n", (int)buf.st_nlink);
        printf("test.sym : Inode = %d\n", (int)buf.st_ino);

}

