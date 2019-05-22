#include <stdio.h>

int st[100], height, level;

int absol(int k)
{
    if(k<0) return -k;

    return k;
}

void Init() {st[level] = 0;}

int Am_Succesor()
{
    if(st[level] < height)
    {
        st[level]++;
        return 1;
    }

    return 0;
}

int E_Valid()
{
    for(int i=1; i<level; ++i)
        if(st[level]==st[i] || (absol(st[level]-st[i]) == absol(level-i)))
            return 0;

    return 1;
}

int Solutie()   {return level == height;}

void Tipar()
{
    for(int i=1; i<=height; ++i)
    {
        for(int j=1; j<=height; ++j)
        {
            if(st[i] == j)
                printf("D ");
            else
                printf("* ");
        }
        puts("");
    }
    puts("");
}

void back()
{
    int AS;
    level = 1;
    Init();

    while(level>0)
    {
        do{}    while((AS = Am_Succesor()) && !E_Valid());

        if(AS)
            if(Solutie())   Tipar();
            else
            {
                level++;
                Init();
            }
        else    level--;
    }
}

int main(void)
{
    printf("Introduceti un numar = ");
    scanf("%d", &height);
    back();

    return 0;
}