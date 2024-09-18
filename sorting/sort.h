#ifndef SORT
#define SORT
#include "../Onegin/Onegin.h"
#include <ctype.h>

struct pair
{
    int left, right;
};
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
Partition
*/
pair partition(void *a, int last, int size, int (*comp)(const void *a, const void *b));

/*!
Быстрая сортировка строк
*/
void quick_sort(char **a, size_t left, size_t right);

/*!
Быстрая сортировка строк
*/
void quick_sort2(void *a, int last, size_t size, int (*compare)(const void *a, const void *b));

/*!
Быстрая сортировка строк
*/
void quick_sort_1_5(char **a, int first, int last);

/*!
Сортировка пузырьком
*/
void bubble_sort(char **a, size_t left, size_t right);

/*!
Ещё одна быстрая сортировка
*/
void quick_sort_1_8(char **a, int last, int (*comp)(const void *a, const void *b));

#endif
