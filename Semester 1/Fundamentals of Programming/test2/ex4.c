#include <stdio.h>
#include <stdlib.h>

void print_binar(unsigned x)
{
    for(int i=sizeof(unsigned)*8-1; i>=0; --i)
        if(x&(1<<i))
            printf("%d",1);
        else
            printf("%d",0);
    printf("\t");
}

void print_cerinta(unsigned *vector, int size)
{
    for(int i=0; i<size; ++i)
        if(!((*(vector+i))%2))
        {
            printf("%u\t",*(vector+i));
            print_binar(*(vector+i));
            for(int j=0; j<size; ++j)
                if(*(vector+i)&(1<<j))
                {
                    print_binar(*(vector+i)&~(1<<j));
                    printf("%u\n",*(vector+i)&~(1<<j));
                    break;
                }
        }
}

void read_vector(int V[], int elem, char s[])
{
    printf("Introduceti elementele %s:\n", s);
    for(int i = 0; i < elem; ++i)
        printf("V[%d] = ", i+1), scanf("%d", &V[i]);
    system("clear");
}

void main()
{
    int size;
    puts("Introduceti marimea unui vector");
        printf("size = "),scanf("%d",&size);

    unsigned *vector=(unsigned*)malloc(size*sizeof(unsigned));
    read_vector(vector,size,"Vector");
    print_cerinta(vector,size);

    free(vector);    
}
