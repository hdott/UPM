#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

static int pid;

void trateaza_signal(int sig);


int main(void){
    FILE *pFile;
    while(!(pFile = fopen("proc1.pid", "r")))      printf("file");

    fscanf(pFile, "%d", &pid);
    fclose(pFile);

    signal(SIGINT, trateaza_signal);
    signal(SIGQUIT, trateaza_signal);
    while(1)    ;

    return 0;
}


void trateaza_signal(int sig){
    if(sig == SIGINT){
        sleep(5);
        kill(pid, SIGUSR1);
    }else if(sig == SIGQUIT){
        kill(pid, SIGUSR2);
        exit(EXIT_SUCCESS);
    }
}