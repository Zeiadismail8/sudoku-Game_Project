#include "string.h"

typedef struct student
{
    int                 age;
    int                  id;
    char          phone[11];
    int               grade;
    char          name [30];
    char              level;
} student_t;

void student_struct_swap(student_t* ptr1, student_t* ptr2);

void student_struct_print(const student_t* ptr, int index);

void student_struct_scan(student_t* ptr, student_t* ptr2, int current_position);

void student_struct_remove(student_t *ptr, int size);

void student_struct_edit_data(student_t *ptr, student_t *ptr2, int current_position);

void student_struct_sort_by_ID(student_t *arr_school, int size);

void student_struct_sort_by_grade(student_t *arr_school, int size);

void student_struct_sort_by_name(student_t *arr_school, int size);

void student_struct_call_by_name(student_t* arr_school,int size);

void student_struct_call_by_ID(student_t* arr_school,int size);

void student_struct_call(student_t* arr_school,int size);


