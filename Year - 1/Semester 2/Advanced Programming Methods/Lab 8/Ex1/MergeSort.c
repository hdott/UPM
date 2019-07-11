#include <stdio.h>
#include <stdlib.h>


static void merge(int *vector, int start, int mid, int end)
{
    int size1 = mid-start + 1;
    int size2 = end-mid;

    int *temp1 = (int*) malloc(size1 * sizeof(int));
    int *temp2 = (int*) malloc(size2 * sizeof(int));

    for(int i=0; i<size1; ++i)  temp1[i] = vector[start+i];
    for(int i=0; i<size2; ++i)  temp2[i] = vector[mid+i+1];

    int i=0,
        j=0,
        k=start;

    while(i<size1 && j<size2)
    {
        if(temp1[i] <= temp2[j])
        {
            vector[k++] = temp1[i++];
            continue;
        }

        vector[k++] = temp2[j++];
    }

    while(i<size1)  vector[k++] = temp1[i++];
    while(j<size2)  vector[k++] = temp2[j++];

    free(temp1);
    free(temp2);
}

void MergeSort(int *vector, int start, int end)
{
    if(start<end)
    {
        int mid = start + (end-start)/2;

        MergeSort(vector, start, mid);
        MergeSort(vector, mid+1, end);

        merge(vector, start, mid, end);
    }
}

// void printVector(int *vector, int size)
// {
//     for(int i=0; i<size; ++i)
//         printf("%d ", vector[i]);
//     puts("");
// }

// int main(void)
// {
//     int vector[] = {10, 7, 8, 9, 1, 5};
//     int size = sizeof(vector)/sizeof(vector[0]);

//     printVector(vector, size);
//     MergeSort(vector, 0, size-1);
//     printVector(vector, size);

//     return 0;
// }