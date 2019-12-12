#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


int main(void){
    int N,
        M,
        O;

    scanf("%d %d %d", &N, &M, &O);
    int vect[N];
    for(int i = 0; i < N; ++i){
        scanf("%d", vect[i]);
    }
    for(int i = 0; i < N; ++i){
        printf("%d ", vect[i]);
    }
    putchar('\n');


    return 0;
}