#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void read_child(int input, int output);
char randomStarPlus(void);


int main(int argc, char **argv){
    if(argc != 2){
        fprintf(stderr, "Programul ia ca argument un singur numar intreg pozitiv!");
        exit(EXIT_FAILURE);
    }
    
    srand((unsigned) time(0));

    int pipe_1[2],
        pipe_2[2];
    
    if(pipe(pipe_1) || pipe(pipe_2)){
        fprintf(stderr, "Unable to open pipe!\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < atoi(argv[1]); ++i){
        if(fork() == 0){
            close(pipe_1[1]);
            close(pipe_2[0]);

            read_child(pipe_1[0], pipe_2[1]);
            
            close(pipe_1[0]);
            close(pipe_2[1]);

            return EXIT_SUCCESS;
        }
    }

    close(pipe_1[0]);
    close(pipe_2[1]);
    for(int i = 0; i < atoi(argv[1]); ++i){
        char buf[1] = randomStarPlus();
        write(pipe_1[1], buf, 1);
    }

    while(wait(NULL) != -1) ;


    return 0;
}

void read_child(int input, int output){
    FILE *stream;
    stream = fdopen(input, "r");

    int ch,
        i = 1,
        star = 0,
        plus = 0;
    while((ch = fgetc(stream)) != EOF){
        switch(ch){
            case '*':
                i++;
                star++;
                break;
            case '+':
                i++;
                plus++;
                break;
        }

        if(!(i%10)){
            char str[100];
            sprintf(str, "pid = %u star = %d plus = %d", getpid(), star, plus);
            write(output, str, 100);
        }
    }
    fclose(stream);
}

char randomStarPlus(void){
    int x = random() % 100 + 1;
    if(x < 50){
        return '*';
    } else{
        return '+';
    }
}