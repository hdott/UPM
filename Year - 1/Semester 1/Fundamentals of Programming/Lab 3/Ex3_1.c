/*
Să se afișeze dimensiunea în octeți (bytes) și în biți a următoarelor tipuri de date: 
- char 
- unsigned char 
- short int 
- int
- unsigned int 
- signed int 
- long int 
- float 
- double 
- long double
*/

#include <stdio.h>

void main()
{
    char a; 
    unsigned char b; 
    short int c; 
    int d; 
    unsigned int e; 
    signed int f; 
    long int g; 
    float h; 
    double i; 
    long double j; 

    printf("%10s %10s %10s\n", "Type", "Bytes", "Bits"); 
    printf("--------------------------------\n"); 

    printf("%10s %8d %10d \n", "char", sizeof(a), (sizeof(a) * 8)); 
    printf("%14s %4d %10d \n", "unsigned char", sizeof(b), (sizeof(b) * 8)); 
    printf("%12s %6d %11d \n", "short int", sizeof(c), (sizeof(c) * 8)); 
    printf("%9s %9d %11d \n", "int", sizeof(d), (sizeof(d) * 8)); 
    printf("%14s %4d %11d \n", "unsigned int", sizeof(e), (sizeof(e) * 8)); 
    printf("%13s %5d %11d \n", "signed int", sizeof(f), (sizeof(f) * 8)); 
    printf("%12s %6d %11d \n", "long int", sizeof(g), (sizeof(g) * 8)); 
    printf("%10s %8d %11d \n", "float", sizeof(h), (sizeof(h) * 8)); 
    printf("%11s %7d %11d \n", "double", sizeof(i), (sizeof(i) * 8)); 
    printf("%14s %5d %11d \n", "long double", sizeof(j), (sizeof(j) * 8));
}
