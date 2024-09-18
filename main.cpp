#include "file_sys/file_work.h"
#include "Onegin/Onegin.h"
#include "sorting/sort.h"
#include "Bred/bred.h"

int main()
{
    text_t onegin = {.file_name = "files/Onegin_input"};
    create_onegin(&onegin);
    // qsort(onegin.text, onegin.text_size, sizeof(char *), compare_1);
    // bubble_sort(onegin.text, 0, onegin.text_size);
    quick_sort2(onegin.text, (int)onegin.text_size - 1, sizeof(char *), compare);
    printf("excellent\n");
    output_onegin((const char **)onegin.text, "files/Onegin_output2", onegin.text_size);
    //output_onegin(norm_text, "files/Onegin_input2", onegin.text_size);
    printf("excellent");
}
