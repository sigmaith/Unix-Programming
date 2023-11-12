#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(){
    int array[10] = {0};
    int i, j, tmp, minAd;
    for(i=0; i<10; i++){
        scanf("%d", &array[i]);
    }
    for(i=0; i<9; i++){
        minAd = i;
        for(j=i+1; j<10; j++){
            if(array[minAd]>array[j])
                minAd = j;
        }
        tmp = array[minAd]; array[minAd]=array[i]; array[i] = tmp;
    }

    for(i=0; i<10; i++)
        printf("%d ", array[i]);

    return 0;
}