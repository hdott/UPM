/* Sa se citeasca numere intregi pana la 0. Sa se ordoneze numerele pozitive si
 *  numerele negative. Pentru oprirea generarii se va folosi break, iar pentru
 *  ordonare algoritmul de sortare prin selectie directa.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main(void)
{
    int *vector = NULL;
    int alloc = 0, maximum = 0, index = -1, temp;


    while(1)
    {
        if(index == maximum-1)
        {
            int *_aux = NULL;
            ++alloc;

            _aux = (int*) realloc(vector, (maximum = alloc * MAX) * sizeof(int));

            if(!_aux)
            {
                printf("\nSomething went Wrong resizing the Vector!\n");
                break;
            }
            else
            {
                ++index;
                vector = _aux;

                scanf("%d", &temp);
                if(!temp)   break;

                vector[index] = temp;
            }
        }
        else
        {
            ++index;

            scanf("%d", &temp);
            if(!temp)   break;

            vector[index] = temp;
        }
    }

    for(int i=0; i<index; ++i)
    {
        for(int j=i+1; j<index+1; ++j)
            if(*(vector+i) > *(vector+j))
            {
                int aux = *(vector+i);
                *(vector+i) = *(vector+j);
                *(vector+j) = aux;
            }
    }

    free(vector);
    return 0;
}