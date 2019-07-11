int x;
int *p = &x;

const int *cp = p;

cp = NULL;
*cp = 1;



int *const p2 = &x;

*p2 = 0;
p2 = NULL;