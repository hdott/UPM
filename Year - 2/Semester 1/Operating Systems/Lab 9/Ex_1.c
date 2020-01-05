#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

const int MAX = 255;

void read_from_shm(char * shm_ptr);
void write_to_shm(FILE * file, char * shm_ptr);


int main(void){
    int shm_id;

    shm_id = shmget(IPC_PRIVATE, MAX, IPC_CREAT | 0777);
    if(shm_id < 0){
        fprintf(stderr, "Unable to get shared memory!\n");
        exit(EXIT_FAILURE);
    }

    char * shm_ptr;
    shm_ptr = (char *) shmat(shm_id, NULL, 0);
    if((int) shm_ptr == -1){
        fprintf(stderr, "Unable to attach shared memory to address space!\n");
        exit(EXIT_FAILURE);
    } 
    shm_ptr[0] = '0';

    // process 2
    int pid;
    if(fork() == 0){
        read_from_shm(shm_ptr);
        shmdt(shm_ptr);
    }

    // process 1
    FILE * file;
    if(!(file = fopen("text.txt", "r"))){
        fprintf(stderr, "Unable to open file!\n");
        exit(EXIT_FAILURE);
    }

    write_to_shm(file, shm_ptr);
    shmdt(shm_ptr);
    shmctl(shm_id, IPC_RMID, NULL);
    fclose(file);

    while(wait(NULL) != -1);


    return 0;
}


void read_from_shm(char * shm_ptr){
    char opt;
    while((opt = (char) shm_ptr[0]) != 'F'){
        if(opt == '0')    continue;

        if(opt == 'D'){
            char * string = (char *) malloc(MAX);
            char ch;
            int i;
            for(i = 1; (ch = shm_ptr[i]) != '0'; ++i){
                string[i-1] = shm_ptr[i];
            }
            string[i-1] = '\0';

            shm_ptr[0] = 'T';

            puts(string);
            free(string);
        }
    }
    fflush(stdout);
    fclose(stdout);
}

void write_to_shm(FILE * file, char * shm_ptr){
    char opt;
    int finished = 0;
    while((!feof(file)) && ((opt = (char) shm_ptr[0]) == 'T' ||
                            opt == 'D'  ||
                            opt == '0')){

        if(opt == 'D')  continue;

        if(opt == 'T' || opt == '0'){
            char * string = (char *) malloc(MAX);

            // in case of max block read
            // -3   -> one for \0
            //      -> two for the added 0 for shm
            //      -> three for the first byte in shm
            fgets(string, MAX-3, file);

            int i;
            for(i = 1; i <= strlen(string); ++i){
                if(string[i-1] == '\n'){
                    shm_ptr[i] = '\0';
                    break;
                }
                shm_ptr[i] = string[i-1];
            }
            shm_ptr[i] = '0';

            shm_ptr[0] = 'D';

            free(string);
        }
    }

    // wait for the other process to finish reading the last line
    while(shm_ptr[0] != 'T')    ;

    shm_ptr[0] = 'F';
}