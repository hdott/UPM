#include <stdio.h>
#include <stdlib.h>

void help() {
    printf("Programul ia urmatoarele argumente: \n");
    printf("\t- number + number\n");
    printf("\t- number - number\n");
    printf("\t- number \"*\" number\n");
    printf("\t- number / number\n");
}

int isNumber(int x) {
    if ((x >= 65 && x <= 90) || (x >= 97 && x <= 122))
            return 0;
    else    return 1;
}

int main (int argc, char **argv) {
    int opt = 0,
        nr1,
        nr2;

    // check whether there is no argument, if not jump to switch,
    // which prints help in this case
    if (argc == 1) {
        goto OPT;
    }

    // transform the strings into ints so we can use them in computations
    if (argc == 4) {
        opt = *(*(argv+2));
        if (isNumber(*(*argv+1)) || isNumber(*(*argv+2))) {
            nr1 = atoi (*(argv+1));
            nr2 = atoi (*(argv+3));   
        } else  opt = 0;
    }

    // arguments management
    if (!strcmp(*(argv+1), "--help")) {
        help();
    } else {
        OPT: switch (opt) {
            case '+' :  printf("%d %c %d = %d\n", nr1, opt, nr2, nr1+nr2);
                        break;
            case '-' :  printf("%d %c %d = %d\n", nr1, opt, nr2, nr1-nr2);
                        break;
            case '*' :  printf("%d %c %d = %d\n", nr1, opt, nr2, nr1*nr2);
                        break;
            case '/' :  printf("%d %c %d = %d\n", nr1, opt, nr2, nr1/nr2);
                        break;
            default:    // printf("Optiunea %c nu este disponibila!\n", opt);
                        help();
                        break;
        }
    }

    return 0;
}