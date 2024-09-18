#ifndef FILE_SYS
#define FILE_SYS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


const int BUFER_SIZE = 1000;

/*!
Возвращает длину файла
*/
size_t file_size_strings(FILE *fp);

/*!
Открывает файл
*/
int file_open(FILE **fp, const char *file_name);

/*!
Закрывает файл
*/
int file_close(FILE **fp);

/*!
Находит число байтов в файле
*/
size_t file_bytes(FILE *fp);

/*!
Пишет строку, которая заканчивается \n
*/
void my_fputs(FILE *stream, const char *onegin);

/*!
Считывает файл и записывает в буфер
*/
size_t read_file(FILE *stream, char *bufer);
#endif
