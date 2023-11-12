#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(){
    int sum = 0;
    int i;

    for(i=1; i<=10 ; i++){
        int input; scanf("%d", &input);
        sum += input;
    }

    printf("%d", sum);

    return 0;
}