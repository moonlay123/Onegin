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

pair partition(void *a, int last, int size, int (*comp)(const void *a, const void *b))
{
    size_t extra_a = (size_t) a;
    int left = 0, right = last, middle = (0 + last) / 2;
    size_t mid = (extra_a + middle * size);
    do
    {
        while (left != middle and comp((const void *)(extra_a + left * size), (const void *) mid) < 0) left++;
        while (right != middle and comp((const void *)(extra_a + right * size), (const void *) mid) > 0) right--;

        if (left <= right)
        {
            my_swap((char **)(extra_a + left * size), (char **)(extra_a + right * size));
            left++;
            right--;
        }
    } while (left <= right);
    pair p = {left, right};
    return p;
}

void quick_sort2(void *a, int last, size_t size, int (*comp)(const void *a, const void *b))
{
    if (0 < last)
    {
        pair p = partition(a, last, size, comp);
        size_t extra_a = (size_t) a;
        quick_sort2((void *)(extra_a), p.right, size, compare);
        quick_sort2((void *)(extra_a + (p.left) * size), last - p.left, size, compare);
    }
}

void quick_sort_1_8(char **a, int last, int (*comp)(const void *a, const void *b))
{
    if (0 < last)
    {
        int left = 0, right = last, middle = (0 + last) / 2;
        char *mid = a[middle];
        do
        {
            while (left != middle and comp(&a[left], &mid) < 0) left++;
            while (right != middle and comp(&a[right], &mid) > 0) right--;
            if (left <= right)
            {
                my_swap(&a[left], &a[right]);
                left++;
                right--;
            }
        } while (left <= right);
        quick_sort_1_8(a, right, comp);
        quick_sort_1_8(a + left, last - left, comp);
    }
}

void quick_sort_1_5(char **a, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = (first + last) / 2;
        char *mid = a[middle];
        do
        {
            while (left != middle and compare(&a[left], &mid) < 0) left++;
            while (right != middle and compare(&a[right], &mid) > 0) right--;
            if (left <= right)
            {
                my_swap(&a[left], &a[right]);
                left++;
                right--;
            }
        } while (left <= right);

        quick_sort_1_5(a, first, right);
        quick_sort_1_5(a, left, last);
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

        if ((a1[pointer_a] == '\n' && b1[pointer_b] == '\n') || (a1[pointer_a] == '\0' && b1[pointer_b] == '\0'))
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

    while(pointer_a > 0 and pointer_b > 0)
    {
        while (symbol_in(pass_symbols, a1[pointer_a])) pointer_a--;
        while (symbol_in(pass_symbols, b1[pointer_b])) pointer_b--;

        if (tolower(a1[pointer_a]) != tolower(b1[pointer_b]))
        {
            return tolower(a1[pointer_a]) - tolower(b1[pointer_b]);
        }

        if ((a1[pointer_a] == '\n' && b1[pointer_b] == '\n') || (a1[pointer_a] == '\0' && b1[pointer_b] == '\0'))
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
