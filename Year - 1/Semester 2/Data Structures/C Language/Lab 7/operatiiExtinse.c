#include <stdio.h>
#include <stdlib.h>
#include <time.h>


static unsigned char *vectorSecvential = NULL;
static unsigned char *vectorSortat = NULL;
static unsigned size;


static void GenerateVect()
{
    printf("\nIntroduceti marimea vectorului:\n");
    printf("(size): ");
        scanf("%u", &size);
        getchar();
        puts("");

    vectorSecvential = (char*) malloc(size);
    vectorSortat = (char*) malloc(size);

    time_t t;
    srand(time(&t));

    for(int i=0; i<size; ++i)
        vectorSecvential[i] = random() % 255;

    fputs("\e[?25l", stdout);
    static unsigned char temp;
    for(int i=0; i<size; ++i)
    {
        float y=i, x=size, nr;
        nr = y * 100 / x;
        printf("Loading %.2f%%\r", nr);

        for(int k=0; k<100; ++k)
            temp = rand() % 255;

        for(int j=i; j>=0; --j)
        {
            if (!j)
            {
                vectorSortat[j] = temp;
                break;
            }

            if (temp < vectorSortat[j-1])   vectorSortat[j] = vectorSortat[j-1];
            else
            {
                vectorSortat[j] = temp;
                break;
            }
        }
    }

    fputs("\e[?25h", stdout);
    printf("\n\nVectorii au fost generati cu Succes!\n");
}

static void PrintElemePoz()
{
    printf("\nVectorSecvential[%d] -> %c\n", size/4, vectorSecvential[size/4]);
    printf("VectorSortat[%d]     -> %c\n", size/4, vectorSortat[size/4]);

    printf("\nVectorSecvential[%d] -> %c\n", size/2, vectorSecvential[size/2]);
    printf("VectorSortat[%d]     -> %c\n", size/2, vectorSortat[size/2]);

    printf("\nVectorSecvential[%d] -> %c\n", size-1, vectorSecvential[size-1]);
    printf("VectorSortat[%d]     -> %c\n", size-1, vectorSortat[size-1]);
}

static void TimeN4()
{
    clock_t t;
    t = clock();

    for(int i=0; i<size; ++i)
        if (i == size/4)    break;

    t = clock() - t;
    printf("\nTimpul Cautarii Secventiale -> %f seconds\n",((float) t) / CLOCKS_PER_SEC);

    t = clock();

    int low=0, high=size-1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if      (mid < size/4)  low = mid + 1;
        else if (mid > size/4)  high = mid - 1;
        else    break;
    }

    t = clock() - t;
    printf("\nTimpul Cautarii Binare -> %f seconds\n", ((float) t) / CLOCKS_PER_SEC);
}

static void TimeN2()
{
    clock_t t;
    t = clock();

    for(int i=0; i<size; ++i)
        if (i == size/2)    break;

    t = clock() - t;
    printf("\nTimpul Cautarii Secventiale -> %f seconds\n",((float) t) / CLOCKS_PER_SEC);

    t = clock();

    int low=0, high=size-1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if      (mid < size/2)  low = mid + 1;
        else if (mid > size/2)  high = mid - 1;
        else    break;
    }

    t = clock() - t;
    printf("\nTimpul Cautarii Binare -> %f seconds\n", ((float) t) / CLOCKS_PER_SEC);
}

static void TimeN()
{
    clock_t t;
    t = clock();

    for(int i=0; i<size; ++i)
        if (i == size-1)    break;

    t = clock() - t;
    printf("\nTimpul Cautarii Secventiale -> %f seconds\n",((float) t) / CLOCKS_PER_SEC);

    t = clock();

    int low=0, high=size-1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if      (mid < size-1)  low = mid + 1;
        else if (mid > size-1)  high = mid - 1;
        else    break;
    }

    t = clock() - t;
    printf("\nTimpul Cautarii Binare -> %f seconds\n", ((float) t) / CLOCKS_PER_SEC);
}

static void Return()
{
    free(vectorSecvential);
    free(vectorSortat);
}

void ControlOE(int option)
{
    switch (option)
    {
        case 1:
            GenerateVect();
            break;
        case 2:
            PrintElemePoz();
            break;
        case 3:
            TimeN4();
            break;
        case 4:
            TimeN2();
            break;
        case 5:
            TimeN();
            break;
        case 6:
            Return();
            break;
        default:
            printf("\nSomething went Wrong with ControlOE!\n");
            break;
    }
}