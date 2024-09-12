#include "bred.h"

char **riphm_creator(text_t *onegin, const char *pattern, size_t from)
{
    const char pass_symbols[25] = "[]()'\"\\,;:?!.— \n\0";
    char **p_text = (char **) calloc(MAX_LEN, sizeof(char *));
    size_t put_pointer = 0;

    size_t pattern_len = my_strlen(pattern);
    size_t pointer_pat = 0, pointer_text = from, pointer_p_text = 0;
    //printf("%d", pattern_len);
    print_string(onegin->text[pointer_text]);
    while (onegin->text[pointer_text][pointer_p_text] != '\n')
    {
        while (symbol_in(pass_symbols, onegin->text[pointer_text][pointer_p_text])) pointer_p_text++;
        while (onegin->text[pointer_text][pointer_p_text] != '\n' and onegin->text[pointer_text][pointer_p_text] != pattern[pointer_pat])
        {
            pointer_p_text++;
        }
        while (onegin->text[pointer_text][pointer_p_text] == pattern[pointer_pat])
        {
            pointer_p_text++;
            pointer_pat++;
            if (pointer_pat == pattern_len)
            {
                p_text[put_pointer++] = onegin->text[pointer_text];
                pointer_text++;
                pointer_pat = 0;
                pointer_p_text = 0;
                break;
            }
        }
    }

    return p_text;
}
