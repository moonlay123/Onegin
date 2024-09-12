#ifndef ONEGIN
#define ONEGIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../file_sys/file_work.h"

struct text_t
{
    char *bufer;
    size_t bufer_size;

    char **text;
    size_t text_size;

    char *file_name;
};

/*!
Си реализация гетлайна
*/
size_t getline(char **lineptr, char *bufer, FILE *stream);

/*!
Создает массив строк из файла
*/
void create_onegin(text_t *onegin);

/*!
Записывает массив строк в файл
*/
void output_onegin(const char **onegin, const char *file_name, size_t onegin_size);

/*!
Печатает строку до \n
*/
void print_string(const char *str);

/*!
находит длину строки
*/
size_t my_strlen(const char *str);

/*!
Проверяет, что символ является частью строки
*/
bool symbol_in(const char *pass, char proof);

#endif
