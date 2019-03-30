#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


static int *vector = NULL;
static unsigned size;


static void GenerateMan()
{
    if(vector)
    {
        free(vector);
        vector = NULL;
    }

    printf("\nIntroduceti marimea vectorului:\n");
    printf("(size): ");
        scanf("%u", &size);
        getchar();

    vector = (int*) malloc(size * sizeof(int));

    static int temp;
    printf("\nIntroduceti elementele vectorului:\n");
    for(unsigned i=0; i<size; ++i)
    {
        printf("[%u] = ", i+1);
        scanf("%u", &temp);

        for(unsigned j=i; j>=0; --j)
        {
            if (!j)
            {
                vector[j] = temp;
                break;
            }
            
            if (temp < vector[j-1])
                vector[j] = vector[j-1];
            else
            {
                vector[j] = temp;
                break;
            }
        }

    }
    getchar();
    printf("\nVectorul a fost creat cu Succes!\n");
}

static void GenerateAuto()
{
    if(vector)
    {
        free(vector);
        vector = NULL;
    }

    printf("\nIntroduceti marimea vectorului:\n");
    printf("(size): ");
        scanf("%u", &size);
        getchar();

    vector = (int*) malloc(size * sizeof(int));

    time_t t;
    srand((unsigned) time(&t));
    
    static int temp;
    for(unsigned i=0; i<size; ++i)
    {
        temp = rand() % INT_MAX + INT_MIN;

        for(unsigned j=i; j>=0; --j)
        {
            if (!j)
            {
                vector[j] = temp;
                break;
            }
            
            if (temp < vector[j-1])     vector[j] = vector[j-1];
            else
            {
                vector[j] = temp;
                break;
            }
        }
    }

    printf("\nVectorul a fost creat cu Succes!\n");
}

static void Print()
{
    printf("\nVectorul este:\n");
        for(unsigned i=0; i<size; ++i)
            printf("%d ", vector[i]);
        puts("");
}

static int BinarySearch(int key)
{
    int low=0, high=size-1;
    
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if      (vector[mid] < key)     low = mid + 1;
        else if (vector[mid] > key)     high = mid - 1;
        else
        {
            printf("\nElementul [%d] a fost gasit pe pozitia [%d]\n", key, mid+1);

            return 0;
        }
    }

    printf("\nElementul [%d] NU a fost gasit!\n", key);
    return -1;
}

static void Return()
{
    free(vector);
}

void ControlOB(int option, int key)
{
    switch (option)
    {
        case 1:
            GenerateMan();
            break;
        case 2:
            GenerateAuto();
            break;
        case 3:
            Print();
            break;
        case 4:
            BinarySearch(key);
            break;
        case 5:
            Return();
            break;
        default:
            printf("\nSomething went Wrong with ControlOB!\n");
            break;
    }
}