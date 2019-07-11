#include <stdio.h>


int SumNumbersVectors(int *vector1, int *vector2, int s1, int s2, int suma, int power)
{
    if(s1>=0 && s2>=0)  return SumNumbersVectors(vector1, vector2, s1-1, s2-1,
                                            suma+((vector1[s1]+vector2[s2])*power), power*10);

    if(s1>=0)           return SumNumbersVectors(vector1, vector2, s1-1, s2,
                                            suma+vector1[s1]*power, power*10);

    if(s2>=0)           return SumNumbersVectors(vector1, vector2, s1, s2-1,
                                            suma+vector2[s2]*power, power*10);

    return suma;
}

int main(void)
{
    int vector1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(vector1)/sizeof(vector1[0]);
    int vector2[] = {1, 2, 3, 4};
    int size2 = sizeof(vector2)/sizeof(vector2[0]);

    printf("Suma -> %d\n", SumNumbersVectors(vector1, vector2, size1-1, size2-1, 0, 1));

    return 0;
}