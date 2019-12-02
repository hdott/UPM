/*
    Sa se demonstreze aplicarea functiei fork() pentru creearea unui proces fiu. Sa se
        afiseze pid pentru procesele fiu si parinte.
*/

#include <stdio.h>
#include <stdlib.h>
// #include <syscall.h>
// #include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(void){
    __pid_t pid;
    int status;

    if((pid = fork()) < 0){
        perror("Erooare la creearea procesului!\n");
        exit(-1);
    } else if(0 == pid){
        printf("Eu sunt procesul fiu (pid=%u)!\n", getpid());
    } else{
        printf("Eu sunt procesul parinte (pid=%u)!\n", getpid());
        wait(&status);
    }


    return 0;
}