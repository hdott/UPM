#include <stdio.h>
#include <signal.h>


void handle_signal(int sig) 
{ 
    static int x = 0,
            y = 0;

    if(sig == SIGINT){
        printf("SIGINT Caught signal %d\n", ++x); 
    }
    if(sig == SIGUSR1){
        printf("SIGUSR1 Caught signal %d\n", ++y);
    }
    
} 
  
int main() 
{ 
    signal(SIGHUP, SIG_IGN); 
    signal(SIGQUIT, SIG_IGN);

    signal(SIGINT, handle_signal);
    signal(SIGUSR1, handle_signal);
    

    while (1) ; 
    return 0; 
} 