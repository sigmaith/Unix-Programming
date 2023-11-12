#include <sys/errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {

   if (access("test.txt", R_OK) == -1) {
       perror("test.txt");
       exit(1);
   }
   return 0;
}

