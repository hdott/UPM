#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX 10


void read_from_pipe1(int file, char *buf2){
    FILE *stream;
    int c, i = 0, j = 0;
    stream = fdopen(file, "r");
    while((c = fgetc(stream)) != EOF && j < 10){
        // putchar(c);
        if(isalpha(c) && islower(c)){
            buf2[i++] = c;
        }
        ++j;
    }
    fclose(stream);
}

void read_from_pipe2(int file, char *buf2){
    FILE *stream;
    int c, i = 0, j = 0;
    stream = fdopen(file, "r");
    int countVowels,
        countConsonants;
    countVowels = countVowels = 0;
    while((c = fgetc(stream)) != EOF && j < 10){
        printf("%d", j);
        putchar(c);
        switch(c){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                countVowels++;
                break;
            default:
                countConsonants++;
                break;
        }
        j++;
    }
    fclose(stream);
    char str[100];
    sprintf(str, "echo vowels = %d consonants = %d >> out.txt", countVowels, countConsonants);
    system(str);
}

int main(void){

    int firstpipe[2],
        secondpipe[2];
    int pid1,
        pid2;
    char buf[MAX];

    if(pipe(firstpipe) < 0){
        fprintf(stderr, "Pipe failed!\n");
        return EXIT_FAILURE;
    }
    if(pipe(secondpipe) < 0){
        fprintf(stderr, "Pipe2 failed!\n");
        return EXIT_FAILURE;
    }

    if((pid1 = fork()) == (pid_t) 0){
        char buf2[MAX];
        close(firstpipe[1]);
        read_from_pipe1(firstpipe[0], buf2);
        printf("%s\n", buf2);
        
        close(secondpipe[0]);
        write(secondpipe[1], buf2, MAX);
        // close(secondpipe[1]);

        return EXIT_SUCCESS;
    } else if((pid2 = fork()) == (pid_t) 0){

    printf("ERR");
        close(secondpipe[1]);
        char buf2[MAX];
        read_from_pipe2(secondpipe[0], buf2);
    puts("ERRR");
        printf("%s\n", buf2);
        // close(secondpipe[0]);

        return EXIT_SUCCESS;
    } else if(pid1 < (pid_t) 0 || pid2 < (pid_t) 0){
        fprintf(stderr, "Fork Failed!\n");
        return(EXIT_FAILURE);
    } else{
        //what the parent does

        int ch;
        close(firstpipe[0]);
        for(int i = 0; (ch = getchar()) != EOF; ++i){
            if(i == 10){
                i = 0;
                write(firstpipe[1], buf, MAX);
                // sleep(1);
            }
            buf[i] = ch;
        }
        close(firstpipe[1]);
        pid_t pid;
        while((pid = wait(NULL)) != -1);
    }


    // fclose(pf);
    return 0;
}