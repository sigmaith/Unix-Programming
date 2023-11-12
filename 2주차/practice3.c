#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(){
    int array[3] = {0};
    int i, j, tmp, minAd;
    for(i=0; i<3; i++){
        scanf("%d", &array[i]);
    }
    for(i=0; i<2; i++){
        minAd = i;
        for(j=i+1; j<3; j++){
            if(array[minAd]>array[j])
                minAd = j;
        }
        tmp = array[minAd]; array[minAd]=array[i]; array[i] = tmp;
    }

    printf("%d %d", array[2], array[0]);



    return 0;
}