#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct stat buf;
    int x, a;
    
    if(argc != 3) {
        printf("Usage : mychmod perm file\n");
        exit(1);
    }

    stat(argv[2], &buf);

    printf("1.buf=%o\n",buf.st_mode);
    for(a=0;a<3;a++) {
        x = 0;
        switch(argv[1][a]) {
            case '7': x |= S_IRWXU; break;
            case '6': x |= (S_IRUSR | S_IWUSR); break;
            case '5': x |= (S_IRUSR | S_IXUSR); break;
            case '4': x |= S_IRUSR; break;
            case '3': x |= (S_IWUSR | S_IXUSR); break;
            case '2': x |= S_IWUSR; break;
            case '1': x |= S_IXUSR; break;
            case '0': x |= 0; break;
        }
        if(a == 0) buf.st_mode |= x; 
        if(a == 1) buf.st_mode |= (x>>3); 
        if(a == 2) buf.st_mode |= (x>>6); 
        printf("2.x=%o, buf=%o\n",x, buf.st_mode);
    }

    printf("3.buf=%o\n",buf.st_mode);
    chmod(argv[2], buf.st_mode);
}

