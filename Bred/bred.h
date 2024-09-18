#ifndef BRED
#define BRED
#include "../file_sys/file_work.h"
#include "../Onegin/Onegin.h"
#include "../sorting/sort.h"

const int MAX_LEN = 100;
/*!
Создает массив всех строк, оканчивающихся на заданную строку(исключая символы)
*/
char **riphm_creator(text_t *onegin, const char *pattern, size_t from);

/*!
Создает массив массивов рифм
*/
char ***all_riphm_creator(text_t *onegin);

#endif
