#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    struct stat statbuf;

    stat("test.txt", &statbuf);
        printf("Mode = %o\n", (unsigned int)statbuf.st_mode);

    if ((statbuf.st_mode & S_IREAD) != 0)
        printf("test.txt: User has a read permission\n");

    if ((statbuf.st_mode & (S_IREAD >> 3)) != 0)
        printf("test.txt: Group has a read permission\n");

    if ((statbuf.st_mode & S_IROTH) != 0)
        printf("test.txt: Other have a read permission\n");
}

/* IREAD 나 IROTH 같은 상수를 이용할 수도 있고 
bit shift를 이용할 수도 있음 */

