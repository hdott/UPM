#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


int main(void){
    int N,
        M,
        O;

    scanf("%d %d %d", &N, &M, &O);
    int *vect = (int*) malloc(N * sizeof(int));
    for(int i = 0; i < N; ++i){
        int x;
        scanf("%d", &x);
        vect[i] = x;
    }
    for(int i = 0; i < N; ++i){
        printf("%d ", vect[i]);
    }
    putchar('\n');

    
    // partitioneaza
    int **arr = (int**) malloc(O * sizeof(int*));
    for(int i = 0; i < O; ++i){
        arr[i] = (int*) malloc((N/O) * sizeof(int));
    }

    int *start = vect;
    for(int i = 0, j = 0; i < O; ++i){
        for(int k = 0; k < N/O; ++k, ++j){
            arr[i][k] = vect[j];
        }
    }
    // for(int i = 0; i < O; ++i){
    //     for(int j = 0; j < N/O; ++j){
    //         printf("%d ", arr[i][j]);
    //     }
    //     putchar('\n');
    // }

    //pipes
    int pipe_1[2],
        pipe_2[2];

    if(pipe(pipe_1) || pipe(pipe_2)){
        perror("Unable to open Pipe!\n");
        exit(EXIT_FAILURE);
    }


    //childs
    for(int i = 0; i < O; ++i){
        if(fork() == 0){
            int size = N/O;
            int buf[size+1];
            
            close(pipe_1[1]);
            close(pipe_2[0]);
            read(pipe_1[0], buf, (size+1) * sizeof(int));

            for(int j = 1; j < size+1; ++j){
                if(buf[j] == M){
                    int bufO[2];
                    bufO[0] = buf[0];
                    bufO[1] = j;
                    write(pipe_2[1], bufO, 2 * sizeof(int));
                }
            }
            close(pipe_1[0]);
            close(pipe_2[1]);

            return EXIT_SUCCESS;
        }
    }


    //parent
    close(pipe_1[0]);
    close(pipe_2[1]);
    for(int i = 0; i < O; ++i){
        int buf[N/O + 1];
        buf[0] = i;
        for(int j = 1, k = 0; j < (N/O) + 1; ++j, ++k){
            buf[j] = arr[i][k];
            
        }
        write(pipe_1[1], buf, ((N/O)+1)*sizeof(int));
    }
    close(pipe_1[1]);

    int buf[2];
    while(read(pipe_2[0], buf, 2 * sizeof(int))){
        printf("[%d]Numarul %d gasit pe pozitia %d\n", buf[0], M, buf[0]*(N/O) + buf[1]);
    }
    close(pipe_2[0]);


    while(wait(NULL) != -1);



    // free resources
    free(vect);
    for(int i = 0; i < O; ++i){
        free(arr[i]);
    }
    free(arr);
    return 0;
}