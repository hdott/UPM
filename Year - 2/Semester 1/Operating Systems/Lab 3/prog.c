#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){
    time_t t;

    srand((unsigned) time(&t));

    int nr;
    if(!((nr = random() % 100) % 2)){
        printf("0");
        return 0;
    } else{
        printf("100", nr);
        return 100;
    }


    return 0;
}