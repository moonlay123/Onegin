#include "Onegin.h"

void output_onegin(const char **onegin, const char *file_name, size_t onegin_size)
{
    FILE *fp = NULL;
    file_open(&fp, file_name);

    for (size_t i = 0; i < onegin_size; ++i)
        my_fputs(fp, (const char *) onegin[i]);

    file_close(&fp);
}

void create_onegin(text_t *onegin)
{
    assert(onegin != NULL);

    FILE *fp = NULL;

    file_open(&fp, onegin->file_name);

    onegin->text_size = file_size(fp);
    onegin->bufer_size = file_bytes(fp);

    onegin->text = (char **) calloc(onegin->text_size, sizeof(char *));
    assert (onegin->text != NULL);

    onegin->bufer = (char *) calloc(onegin->bufer_size, sizeof(char));
    assert (onegin->bufer != NULL);

    size_t red_size = read_file(fp, onegin->bufer);
    size_t pointer_bufer = 0, pointer_file = 0;

    onegin->text[pointer_file++] = &onegin->bufer[pointer_bufer];

    while (pointer_bufer < red_size)
    {
        if (onegin->bufer[pointer_bufer] == '\n')
        {
            ++pointer_bufer;
            onegin->text[pointer_file++] = &onegin->bufer[pointer_bufer];
        } else
        {
            ++pointer_bufer;
        }
    }
    return;
}

size_t getline(char **lineptr, char *bufer, FILE *stream)
{
    assert(lineptr != NULL);
    assert(bufer != NULL);
    assert(stream != NULL);

    if (stream == NULL or feof(stream))
    {
        return 0;
    }

    int file_c = '\0';
    *lineptr = bufer;
    size_t string_size = 1;

    while ((file_c = fgetc(stream)) != '\n' and file_c !='\0')
    {
        *bufer++ = file_c;
        string_size++;
    }
    if (file_c == '\0')
        return 0;
    *bufer++ = file_c;
    return string_size;
}

bool symbol_in(const char *pass, char proof)
{
    size_t pointer = 0;
    while (pass[pointer] != '\0')
    {
        if (proof == pass[pointer])
        {
            return 1;
        }
        pointer++;
    }
    return 0;
}

