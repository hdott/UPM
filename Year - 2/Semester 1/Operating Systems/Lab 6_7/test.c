#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
// #include


int main(void){
    int pipefd[2];
    int pid;

    if(pipe(pipefd) < 0){
        perror("Error on creating the pipe!");
        exit(EXIT_FAILURE);
    }

    if((pid = fork()) < 0){
        perror("Unable to create a new process!");
        exit(EXIT_FAILURE);
    }
    if(0 == pid){
        char buf[100] = "Functioneaza!";

        close(pipefd[0]);
        write(pipefd[1], buf, strlen(buf));
        close(pipefd[1]);
        return 0;
    }

    char buf[100];
    close(pipefd[1]);
    int n = read(pipefd[0], buf, 100);
    printf("%s\n", buf);
    close(pipefd[0]);
    wait(NULL);



    return 0;
}