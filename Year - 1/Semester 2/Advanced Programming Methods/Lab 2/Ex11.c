/* Fie un text dat intr-un fisier. Sa se numere cate cuvinte, cate propozitii si cate
 *  litere contine textul. Sa se foloseasca instructiunea continue.
 */

#include <stdio.h>
#include <ctype.h>


int main(void)
{
    FILE *ozy = fopen("ozymandias.txt", "r");
    char ch;

    int words, sentences, letters;

    words = sentences = letters = 0;

    while(!feof(ozy))
    {
        ch = fgetc(ozy);
        
        if(isalpha(ch)) 
        {
            ++letters;
            continue;
        }

        if(ch == ' ')
        {
            ++words;
            continue;
        }

        if(ch == '.')
        {
            ++words;
            ++sentences;
        }
    }

    printf("There are:\n");
    printf("word        -> %d\n", words);
    printf("sentences   -> %d\n", sentences);
    printf("letters     -> %d\n", letters);

    fclose(ozy);
    return 0;
}