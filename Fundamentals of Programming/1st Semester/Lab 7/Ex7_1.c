
/*
Se citeste un șir de n numere întregi de la tastatură. 
Scrieți un program care implementează următoarele: 
- Determina maxim și minim 
- Suma și produsul numerelor 
- Eliminarea elementului din poziția k dată (1 <= k <= n) 
- Inserarea unui element y în poziția k dată (1 <= k <= n) 
- Permutarea circulară cu o poziție spre stânga 
- Permutarea circulară cu o poziție spre dreapta
*/

#include <stdio.h>
#include <stdlib.h>
#define min(a,b) a < b ? a : b
#define max(a,b) a > b ? a : b

void read_size(int *elem)
{
    printf("Introduceti numarul de elemente al sirului:\n");
        printf("elemente = "), scanf("%d", elem), system("clear");
}

void read_vector(int V[], int elem, char s[])
{
    printf("Introduceti elementele %s:\n", s);
    for(int i = 0; i < elem; ++i)
        printf("V[%d] = ", i+1), scanf("%d", &V[i]);
    system("clear");
}

void print_vector(int V[], int elem, char s[])
{
    printf("%s este: ", s);
    for(int i = 0; i < elem; ++i)
        printf("%d ", V[i]);
    printf("\n");
}

int maxim(int V[], int elem)
{
    int maxim = V[0];
    for(int i = 1; i < elem; ++i)
        maxim = max(maxim, V[i]);

    return maxim;
}

int minim(int V[], int elem)
{
    int minim = V[0];
    for(int i = 1; i < elem; ++i)
        minim = min(minim, V[i]);

    return minim;
}

int suma_elem(int V[], int elem)
{
    int sum = V[0];
    for(int i = 1; i < elem; ++i)
        sum += V[i];

    return sum;
}

int prod_elem(int V[], int elem)
{
    int prod = V[0];
    for(int i = 1; i < elem; ++i)
        prod *= V[i];

    return prod;
}

void elimina_elem(int V[], int elem, int poz)
{
    for(int i = poz-1; i < elem-1; ++i)
        V[i] = V[i+1];
    elem -= 1;

    print_vector(V,elem,"Sirul modificat");
}

void insert_elem(int V[], int elem, int value, int poz)
{
    for(int i = elem-1; i >= poz; --i)
    {
        int aux = V[i];
        V[i] = V[i-1];
        V[i-1] = aux;
    }
    V[poz-1] = value;

    print_vector(V, elem,"Sirul modificat");
}

void permutare_stanga(int V[], int elem)
{
	for (int i = elem-1; i > 0; --i)
		for (int j = i-1; j >=0; --j)
			if (V[i] > V[j])
			{
				int aux = V[j];
				V[j] = V[i];
				V[i] = aux;
			}

    print_vector(V,elem,"Sirul modificat");
}

void permutare_dreapta(int V[], int elem)
{
	for (int i = 0; i < elem-1; ++i)
		for (int j = i+1; j < elem; ++j)
			if (V[i] > V[j])
			{
				int aux = V[i];
				V[i] = V[j];
				V[j] = aux;
			}

    print_vector(V,elem,"Sirul modificat");
}

void main()
{
    int elemente;

    read_size(&elemente);

    int *V = (int*) malloc(elemente*sizeof(int));

    read_vector(V,elemente,"Sirului");

    print_vector(V,elemente,"Sirul initial"), printf("\n");    
    printf("~Determina maxim si minim~\n");
        printf("Maximul este: %d\n", maxim(V,elemente));
        printf("Minimul este: %d\n\n", minim(V,elemente));

    printf("~Suma si produsul elementelor~\n");
        printf("Suma\t este: %4d\n", suma_elem(V,elemente));
        printf("Produsul este: %4d\n\n", prod_elem(V,elemente));

    int k, y;
    printf("~Eliminarea elementului din pozitia k data (1<=k<=n)~\n");
        printf("k = "), scanf("%d", &k);
        elimina_elem(V,elemente,k), printf("\n");
        
    printf("~Inserarea unui element y in pozitia k data (1<=k<=n)~\n");
        printf("k = "), scanf("%d", &k);
        printf("y = "), scanf("%d", &y);
        insert_elem(V,elemente,y,k), printf("\n");  

    printf("~Permutarea circulara cu o pozitie spre stanga~\n");
        permutare_stanga(V,elemente), printf("\n");

    printf("~Permutarea circulara cu o pozitie spre dreapta~\n");
        permutare_dreapta(V,elemente); 

    free(V);
}
