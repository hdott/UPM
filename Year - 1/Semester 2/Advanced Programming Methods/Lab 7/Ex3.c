#include <stdio.h>

double CombinariRecursive(int n, int k)
{
    if(!k)      return 1;
    if(k>n)     return 0;
    
    return (CombinariRecursive(n-1,k)+CombinariRecursive(n-1,k-1));
}

int main(void)
{
    int n, k;

    printf("Introduceti 2 numere naturale pentru a afla Combinari de n luate cate k (n k):\n");
        scanf("%d%d", &n, &k);

    printf("Combinari de n luate cate k = %.2lf\n",
            CombinariRecursive(n,k));
    
    return 0;
}