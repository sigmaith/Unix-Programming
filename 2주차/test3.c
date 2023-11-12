#include <stdlib.h>
#include <stdio.h>
extern int addnum(int a, int b);


int main(int argc, char *argv[]) {

        int sum;
        int num1 = atoi(argv[1]);
        int num2 = atoi(argv[2]);

        sum = addnum(num1, num2);
        printf("Sum %d~%d = %d\n",num1,num2, sum);

        return(0);
}

//전역변수 extern

