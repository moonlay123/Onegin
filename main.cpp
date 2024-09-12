#include "file_sys/file_work.h"
#include "Onegin/Onegin.h"

/*!
Компаратор
*/
int compare(const void *a, const void *b);

int main()
{
    /*char **text2 = (char **) calloc(10, sizeof(char *));

    for (int i = 0 ; i < 10; i ++)
        text2[i] = (char *) calloc(10, sizeof(char));

    *(*(text2 + 0) + 0) = 'v';
    *(*(text2 + 0) + 1) = '\0';
    *(*(text2 + 1) + 0) = 'a';
    *(*(text2 + 1) + 1) = '\0';
    *(*(text2 + 2) + 0) = 'e';
    *(*(text2 + 2) + 1) = '\0';
    *(*(text2 + 3) + 0) = 'a';
    *(*(text2 + 3) + 1) = '\0';
    *(*(text2 + 4) + 0) = 'b';
    *(*(text2 + 4) + 1) = '\0';
    *(*(text2 + 5) + 0) = 'r';
    *(*(text2 + 5) + 1) = '\0';
    *(*(text2 + 6) + 0) = 't';
    *(*(text2 + 6) + 1) = '\0';
    *(*(text2 + 7) + 0) = 'c';
    *(*(text2 + 7) + 1) = '\0';
    *(*(text2 + 8) + 0) = 'e';
    *(*(text2 + 8) + 1) = '\0';
    *(*(text2 + 9) + 0) = 'u';
    *(*(text2 + 9) + 1) = '\0';
    for (int i = 0; i < 10; i ++)
    {
        printf("%x ", text2[i]);
    }
    qsort(text2, 10, sizeof (char *), compare);
    for (int i = 0; i < 9; i ++)
    {
        printf("%s %d\n", text2[i], compare(text2[i], text2[i+1]));
    }*/
    text_t onegin = {.file_name = "files/Onegin_input"};
    create_onegin(&onegin);
    qsort(onegin.text, onegin.text_size, sizeof(char *), compare);
    output_onegin((const char **) onegin.text, "files/Onegin_output", onegin.text_size);

}

int compare(const void *a, const void *b)
{
    const char pass_symbols[12] = "[]()' \\,;\0";
    //printf("1\n");
    const char *a1 = *(const char* const *) a;
    const char *b1 = *(const char* const *) b;
    //printf("2\n");
    size_t pointer_a = 0, pointer_b = 0;
    //printf("2.5\n");
    if ((long long)a1 < 1000 or (long long)b1 < 1000)
        return 0;
    //printf("%lld %lld \n", a1, b1);
    while(a1[pointer_a] != '\n' and b1[pointer_b] != '\n')
    {
        //printf("3\n");
        while (symbol_in(pass_symbols, a1[pointer_a])) pointer_a++;
        while (symbol_in(pass_symbols, b1[pointer_b])) pointer_b++;
        //printf("4\n");
        if (a1[pointer_a] != b1[pointer_b])
        {
            return a1[pointer_a] - b1[pointer_b];
        }
        //printf("5\n");
        if (a1[pointer_a] == '\n' and b1[pointer_b] == '\n' or a1[pointer_a] == '\0' and b1[pointer_b] == '\0')
            return 0;
        else if (a1[pointer_a] =='\n' or a1[pointer_a] =='\0')
            return -1;
        else if (b1[pointer_b] == '\n' or b1[pointer_b] =='\0')
            return 1;
        //printf("6\n");
        pointer_a++;
        pointer_b++;
    }
   // printf("7\n");
    return -1;
}
