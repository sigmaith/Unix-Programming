#include <stdlib.h>
#include <unistd.h>

#define SIZE 512

main() {

        ssize_t nread;
        char buf[SIZE];

        while ((nread = read(0, buf, SIZE)) > 0)
                write (1, buf, nread);

        exit(0);
}


