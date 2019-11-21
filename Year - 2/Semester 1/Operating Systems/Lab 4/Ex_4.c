/*
    Elaborati un program C care creeaza N procese fiu. Fiecare proces fiu asteapta 2
        secunde, dupa care afiseaza urmatoarele informatii pe o singura linie:
    - pid
    - ppid
    - uid
    - guid
        Dupa afisarea informatiilor de mai sus, fiecare proces se va termina cu un cod,
        diferit. Procesul parinte va astepta fiecare proces fiu si va afisa codul 
        returnat de catre fiecare proces fiu.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int isNr(char *str);


int main(int argc, char **argv){
    pid_t pid;
    int status;

    if(argc == 2){
        if(isNr(argv[1])){
            int nr = atoi(argv[1]);

            for(int i = 0; i < nr; ++i){
                if(fork() == 0){
                    printf("PID: %u - PPID: %u - UID: %u - GUID: %u\n", getpid(), getppid(),
                                                                        getuid(), getgid());
                    
                    printf("@CHILD PID: %u - PPID: %u - UID: %u - GUID: %u\n", getpid(), getppid(),
                                                                        getuid(), getgid());
                    // sleep(2);
                    break;
                }
                // wait(&status);
            }
            // wait(&status);
        }
    }


    return 0;
}


int isNr(char *str){
    int status = 1;

    for(int i = strlen(str)-1, j = 1; i >= 0; --i, j+=10){
        if(!isdigit(str[i])){
            return (status = 0);
        }
    }

    return status;
}