#include <stdlib.h>
#include <stdio.h>

int main(){
    char *val;

    setenv("TESTENV", "ubuntu", 0);
    val = getenv("TESTENV");
    if(val == NULL)
        printf("TESTENV not defined\n");
    else
        printf("TESTENV = %s\n", val);
}