#include "file_work.h"


size_t file_size(FILE *fp)
{
    assert(fp != NULL);

    size_t lines_counter = 0;

    while (!feof(fp))
    {
        if(fgetc(fp)== '\n')
        {
            ++lines_counter;
        }
    }

    fseek(fp, 0, SEEK_SET);
    return lines_counter + 1;
}

size_t file_bytes(FILE *fp)
{
    assert(fp != NULL);

    size_t byte_counter = 0;

    fseek (fp, 0, SEEK_END);

    byte_counter = ftell(fp);

    fseek(fp, 0, SEEK_SET);
    return byte_counter;
}

void file_open(FILE **fp, const char *file_name)
{
    assert(fp != NULL);

    assert(fp != NULL);

    if ((*fp = fopen(file_name, "rb+")) == NULL)
    {
        perror("File open error");
    }

}

void file_close(FILE **fp)
{
    assert(fp != NULL);

    if (fclose(*fp) != 0)
        perror("File close error");
    *fp = NULL;
}

void my_fputs(FILE *stream, const char *onegin)
{
    assert(stream != NULL);
    assert(onegin != NULL);

    size_t pointer = 0;
    while (onegin[pointer] != '\n' and onegin[pointer] != '\0' and onegin[pointer] != EOF)
    {
        fputc(onegin[pointer++], stream);
    }
    if (onegin[pointer] != '\n')
        fputc(onegin[pointer], stream);
}

size_t read_file(FILE *stream, char *bufer)
{
    size_t pointer = 0;

    int file_c = fgetc(stream);

    while (file_c != '\0' and !feof(stream))
    {
        bufer[pointer++] = (char)file_c;
        file_c = fgetc(stream);
    }

    return pointer;
}
