#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void help() {
    printf("Programul ia urmatoarele argumente:\n");
    printf("\t- numar   +   numar\n");
    printf("\t- numar   -   numar\n");
    printf("\t- numar \"*\" numar\n");
    printf("\t- numar   /    numar\n");
}

int isNumber(char *str) {
    for(int i=0; i<strlen(str); ++i) {
        if ((str[i] >= 65 && str[i] <= 90) || 
                (str[i] >= 97 && str[i] <= 122))
            return 0;
    }

    return 1;
}

int main (int argc, char **argv) {
    int opt = 0,
        nr1,
        nr2;

    // check whether there is no argument, if not jump to switch case,
    // which prints help in this case
    if (argc == 1) {
        goto OPT;
    }

    if (argc == 4) {
        // check whether there are more than 1 character in the 2nd argument
        //  if yes, jump to switch case and print help
        if(strlen(*(argv+2)) != 1){
            goto OPT;
        }

        opt = *(*(argv+2));
        if (isNumber(*(argv+1)) && isNumber(*(argv+3))) {
            // transform the strings into ints so we can use them in computations
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