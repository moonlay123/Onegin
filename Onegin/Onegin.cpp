#include "Onegin.h"

void output_onegin(const char **onegin, const char *file_name, size_t onegin_size)
{
    FILE *fp = NULL;

    int failure = file_open(&fp, file_name);

    if (failure)
    {
        printf("kind of cringe\n");
        return;
    }

    for (size_t i = 1; i < onegin_size; ++i)
        fprintf(fp, "%s\n", (const char *) onegin[i]);

    file_close(&fp);
}

void create_onegin(text_t *onegin)
{
    assert(onegin != NULL);

    FILE *fp = NULL;

    int failure = file_open(&fp, onegin->file_name);

    if (failure)
    {
        printf("kind of cringe\n");
        return;
    }

    onegin->text_size = file_size_strings(fp);
    onegin->bufer_size = file_bytes(fp);

    onegin->text = (char **) calloc(onegin->text_size, sizeof(char *));
    if (onegin->text == NULL)
    {
        printf("Calloc error in text ");
        return;
    }

    onegin->bufer = (char *) calloc(onegin->bufer_size, sizeof(char));
    if (onegin->bufer == NULL)
    {
        printf("Calloc error in bufer");
        return;
    }

    size_t read_size = fread(onegin->bufer, sizeof(char), onegin->bufer_size, fp);
    size_t pointer_bufer = 0, pointer_file = 0;

    onegin->text[pointer_file++] = &onegin->bufer[pointer_bufer];

    while (pointer_bufer < read_size)
    {
        if (onegin->bufer[pointer_bufer] == '\n')
        {
            onegin->bufer[pointer_bufer] = '\0';
            ++pointer_bufer;
            onegin->text[pointer_file++] = &onegin->bufer[pointer_bufer];
        } else
        {
            ++pointer_bufer;
        }
    }

    file_close(&fp);
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
        *bufer++ = (char) file_c;
        string_size++;
    }
    if (file_c == '\0')
        return 0;
    *bufer++ = (char) file_c;
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

void print_string(const char *str)
{
    assert(str != NULL);

    size_t pointer = 0;
    while(str[pointer] != '\n' and str[pointer] != '\0' )
    {
        printf("%c", str[pointer++]);
    }
    printf("%c", str[pointer++]);
}

size_t my_strlen(const char *str)
{
    size_t pointer = 0;
    while(str[pointer] != '\n' and str[pointer] != '\0' and str[pointer] != '\r')
        pointer++;
    return pointer;
}
