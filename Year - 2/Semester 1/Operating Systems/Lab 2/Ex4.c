/* Sa se scrie comenzile inlantuite care:
    - afiseaza toate detaliile fisierelor (FARA directoare) de configurare 
        (extensia.conf) din /etc/
    - afiseaza toate fisierele (cu directoare) fara detalii, care au propritarul root
*/

// Programul se ruleaza cu comanda:
// ./Ex4 | bash
#include <stdio.h>

int main(int argc, char **argv){
    // printf("ls -al /etc/ | grep .conf");
    printf("ls -al /etc/ | grep root | awk \'{print $9}\'");

    return 0;
}