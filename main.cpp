#include "file_sys/file_work.h"
#include "Onegin/Onegin.h"
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
Свапает значения
*/
void my_swap(char **a, char **b);

/*!
Быстрая сортировка строк
*/
void quick_sort(char **a, size_t left, size_t right);

int main()
{
    text_t onegin = {.file_name = "files/Onegin_input"};
    create_onegin(&onegin);
    //qsort(onegin.text, onegin.text_size, sizeof(char *), compare);
    quick_sort(onegin.text, 0, onegin.text_size);
    printf("excellent");
    output_onegin((const char **) onegin.text, "files/Onegin_output2", onegin.text_size);
}

void my_swap(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

size_t group_by_pivot(char **a, size_t left, size_t right)
{
    char *pivot = a[left];
    right--;

    while(left <= right)
    {
        int comp = compare(&a[left], &pivot);
        if(comp > 0)
            my_swap(&a[left], &a[right--]);
        else if(comp < 0)
            my_swap(&a[left++], &a[right]);
        else
            left++;
    }
    return left;
}
void quick_sort(char **a, size_t left, size_t right){
    int fl = 0;

    //printf("a");

    for(size_t i = left; i < right - 1; i++)
    {
        if (compare(&a[i], &a[i+1]) > 0)
        {
            fl = 1;
            break;
        }
    }

    if(fl==0)
        return;

    size_t mid = group_by_pivot(a, left, right);
    quick_sort(a, left, mid);
    quick_sort(a, mid, right);
}

int compare(const void *a, const void *b)
{
    const char pass_symbols[25] = "[]()'\"\\,;:?!.— \0";

    const char *a1 = *(const char* const *) a;
    const char *b1 = *(const char* const *) b;

    size_t pointer_a = 0, pointer_b = 0;

    while(a1[pointer_a] != '\n' and b1[pointer_b] != '\n')
    {
        while (symbol_in(pass_symbols, a1[pointer_a])) pointer_a++;
        while (symbol_in(pass_symbols, b1[pointer_b])) pointer_b++;

        if (tolower(a1[pointer_a]) != tolower(b1[pointer_b]))
        {
            return tolower(a1[pointer_a]) - tolower(b1[pointer_b]);
        }

        if (a1[pointer_a] == '\n' && b1[pointer_b] == '\n' || a1[pointer_a] == '\0' && b1[pointer_b] == '\0')
            return 0;
        else if (a1[pointer_a] =='\n' or a1[pointer_a] =='\0')
            return -1;
        else if (b1[pointer_b] == '\n' or b1[pointer_b] =='\0')
            return 1;

        pointer_a++;
        pointer_b++;
    }
    return -1;
}
