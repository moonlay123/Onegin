#include "sort.h"

void bubble_sort(char **a, size_t left, size_t right)
{
    for (size_t i = 0; i < right - left; i ++)
    {
        for (size_t j = left; j < right - i - 1; j ++)
        {
            if (compare(&a[j], &a[j+1]) > 0)
            {
                my_swap(&a[j], &a[j+1]);
            }
        }
    }
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
void quick_sort(char **a, size_t left, size_t right)
{
    int fl = 0;

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

void quick_sort2(char **a, int first, int last)
{
    if (first < last)
    {
        //int fl = 0;
        int left = first, right = last, middle = (first + last) / 2;
        char *mid = a[middle];
        do
        {
            //printf("%d %d\n", left, right);
            while (left != middle and compare(&a[left], &mid) < 0) left++;
            //printf("%d %d\n", left, right);
            while (right != middle and compare(&a[right], &mid) > 0) right--;
            if (left <= right)
            {
                my_swap(&a[left], &a[right]);
                left++;
                right--;
                //fl = 1;
            }
            //printf("%d %d\n", left, right);
        } while (left <= right);
        //if (fl == 1)
        //{
            quick_sort2(a, first, right);
            quick_sort2(a, left, last);
        //}
    }
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

int compare_1(const void *a, const void *b)
{
    const char pass_symbols[25] = "[]()'\"\\,;:?!.— \n\0";

    const char *a1 = *(const char* const *) a;
    const char *b1 = *(const char* const *) b;

    size_t pointer_a = 0, pointer_b = 0;
    while (a1[pointer_a++] != '\n');
    while (b1[pointer_b++] != '\n');

    while(pointer_a >= 0 and pointer_b >= 0)
    {
        while (symbol_in(pass_symbols, a1[pointer_a])) pointer_a--;
        while (symbol_in(pass_symbols, b1[pointer_b])) pointer_b--;

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

        pointer_a--;
        pointer_b--;
    }
    return -1;
}
