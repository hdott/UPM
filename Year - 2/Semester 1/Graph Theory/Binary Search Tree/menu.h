#pragma once
#define MAXL 100

// use 1 for int and 0 for str
typedef struct key{
    int opt;
    union{
        int nr;
        char str[MAXL];
    };
} KEY;


void menu();