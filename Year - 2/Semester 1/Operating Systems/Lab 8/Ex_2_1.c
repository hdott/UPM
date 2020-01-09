#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>


static int timp = 500000;
static int contor = 0;

void trateaza_signal(int sig);


int main(void){
    FILE *pFile = fopen("proc1.pid", "w");
    fprintf(pFile, "%d", getpid());
    fclose(pFile);

    signal(SIGINT, SIG_IGN);

    signal(SIGUSR1, trateaza_signal);
    signal(SIGUSR2, trateaza_signal);

    while (1)
    {
        contor += 50;
        printf("%d\t", contor);
        printf("%d\n", timp);
        usleep(timp);
    }
     


    return 0;
}


void trateaza_signal(int sig){
    if(sig == SIGUSR1){
        timp -= 50000;
    }else if(sig == SIGUSR2){
        exit(EXIT_SUCCESS);
    }
}