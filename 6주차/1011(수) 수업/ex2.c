#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    char str[100] ={0}; 
    strcat (str, "SHELL=");
    strcat (str, argv[1]);

    char* val;
    val = getenv("SHELL");
    if(!val)
        printf("SHELL not defined\n");
    else
        printf("1.SHELL = %s\n", val);

    putenv(str);
    val = getenv("SHELL");
    printf("1.SHELL = %s\n", val);
    return 0;
}



/*




*/