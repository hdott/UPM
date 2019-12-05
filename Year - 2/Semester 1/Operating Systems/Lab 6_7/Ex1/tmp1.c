#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX 10

void read_child1(int input, int output){
    char bufInput[MAX],
        bufOutput[MAX];
        
    while(read(input, bufInput, MAX)){
        for(int i = 0, j = 0; i < MAX; ++i){
            if(islower(bufInput[i])){
                bufOutput[j++] = bufInput[i];
            }
        }
        write(output, bufOutput, MAX);
    }
}

void read_child2(int input, int out){
    char bufInput[MAX],
        bufOutput[MAX];

    int vowels,
        consonants;
    while(read(input, bufInput, MAX)){
        vowels = consonants = 0;
        for(int i = 0; i < MAX; ++i){
            switch(bufInput[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowels++;
                break;
            default:
                consonants++;
                break;
            }
        }
        char str[100],
            toParent[100];
        sprintf(str, "echo vowels = %d consonants = %d >> out.txt", vowels, consonants);
        sprintf(toParent, "vowels = %d consonants = %d", vowels, consonants);
        system(str);
        write(out, toParent, 100);
    }
}


int main(void){
    int firstFD[2],
        secondFD[2],
        thirdFD[2];

    if(pipe(firstFD)){
        fprintf(stderr, "Unable to open pipe1!\n");
        exit(EXIT_FAILURE);
    } else if(pipe(secondFD)){
        fprintf(stderr, "Unable to open pipe2!\n");
        exit(EXIT_FAILURE);
    } else if(pipe(thirdFD)){
        fprintf(stderr, "Unable to open pipe3!\n");
        exit(EXIT_FAILURE);
    }

    char buf[MAX];

    int pid[2];

    for(int i = 0; i < 2; ++i){
        switch(i){
            case 0:
                //what child 1 does
                if(fork() == 0){
                    close(thirdFD[0]);
                    close(thirdFD[1]);
                    close(firstFD[1]);
                    close(secondFD[0]);
                    read_child1(firstFD[0], secondFD[1]);
                    close(firstFD[0]);
                    close(secondFD[1]);
                    
                    return EXIT_SUCCESS;
                }
                break;
            case 1:
                //what child 2 does
                if(fork() == 0){
                    close(firstFD[0]);
                    close(firstFD[1]);
                    close(secondFD[1]);
                    close(thirdFD[0]);
                    read_child2(secondFD[0], thirdFD[1]);
                    close(secondFD[0]);
                    close(thirdFD[1]);

                    return EXIT_SUCCESS;
                }
                break;
        }
    }

    int ch;
    close(secondFD[0]);
    close(secondFD[1]);
    close(firstFD[0]);
    for(int i = 0; (ch = getchar()) != EOF; ++i){
        if(i >= 10){
            i = 0;
            write(firstFD[1], buf, MAX);
            // sleep(1);
        }
        buf[i] = ch;
    }
    close(firstFD[1]);

    char stats[100];
    close(thirdFD[1]);
    while(read(thirdFD[0], stats, 100)){
        printf("%s\n", stats);
    }
    close(thirdFD[0]);
    while(wait(NULL) != -1);

    return 0;
}