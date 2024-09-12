#ifndef SORT
#define SORT
#include "../Onegin/Onegin.h"
#include <ctype.h>
/*!
Группирует массив по пивоту
*/
size_t group_by_pivot(char **a, size_t left, size_t right);

/*!
Компаратор
*/
int compare(const void *a, const void *b);

/*!
Компаратор наоборот
*/
int compare_1(const void *a, const void *b);

/*!
Свапает значения
*/
void my_swap(char **a, char **b);

/*!
Быстрая сортировка строк
*/
void quick_sort(char **a, size_t left, size_t right);

/*!
Быстрая сортировка строк
*/
void quick_sort2(char **a, int first, int last);

/*!
Сортировка пузырьком
*/
void bubble_sort(char **a, size_t left, size_t right);

#endif
