#include"school.h"

static student_t arr_school[SCHOOL_CAPACITY];

static unsigned int real_size;

static FILE *School_data = NULL;

void school_print(void)
{
    system("cls");
    if(real_size==0)
    {
        printf("\033[31mNo students yet\033[0m\a\n");
    }
    else
    {
        printf("\033[36m-------------------------------------------------\033[0m\n");
        for(int counter = 0; counter < real_size; counter++)
        {
            student_struct_print(&arr_school[counter], counter+1);
        }
    }
    printf("\n\033[33mPress any key to return: \033[33m");

    fflush(stdin);
    getchar();
}


void school_add_student(void)
{
    system("cls");
    if(real_size<SCHOOL_CAPACITY)
    {
        student_struct_scan(&arr_school[real_size++], arr_school, real_size);
    }
    else
    {
        printf("\033[31mSchool is full\033[0m\a\n");
        sleep(1);
    }
}

void school_remove_student_by_id(void)
{
    system("cls");
    if(real_size>0)
    {
        int id = 0, flag = 1;
        printf("\033[33mEnter ID: \033[0m");
        scanf("%d", &id);
        for(int counter = 0; counter < real_size; counter++)
        {
            if(arr_school[counter].id == id)
            {
                student_struct_remove(&arr_school[counter], real_size--);
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            printf("\033[31mNOT FOUND\n\033[0m\a");
            sleep(1);
        }
    }
    else
    {
        printf("\033[31mSchool is empty\033[0m\a");
        sleep(1);
    }
}

void school_remove_student_by_name(void)
{
    system("cls");
    if(real_size>0)
    {
        char str[30], flag = 1;
        printf("\033[33mEnter Name : \033[0m");
        string_scan(str, 30);
        for(int counter = 0; counter < real_size; counter++)
        {
            if(string_compare_for_search(str, arr_school[counter].name))
            {
                student_struct_remove(&arr_school[counter], --real_size);
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            printf("\033[31mNOT FOUND\nBe aware the program is case sensitive\033[0m\a\n");
            sleep(1);
        }
    }
    else
    {
        printf("\033[31mSchool is empty\033[0m\a");
        sleep(1);
    }
}

void school_edit_student_data_by_id(void)
{
    system("cls");
    if(real_size>0)
    {
        int id, flag = 1;
        printf("\033[33mEnter ID: \033[0m");
        scanf("%d", &id);
        for(int counter = 0; counter < real_size; counter++)
        {
            if(arr_school[counter].id == id)
            {
                student_struct_edit_data(&arr_school[counter], arr_school, real_size);
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            printf("\033[31mThis ID not exist\033[0m\a\n");
            sleep(1);
        }
    }
    else
    {
        printf("\033[31mSchool is empty\033[0m\a");
        sleep(1);
    }
}

void school_edit_student_data_by_name(void)
{
    system("cls");
    if(real_size>0)
    {
        char str[21], flag = 1;
        printf("\033[33mEnter Name: \033[0m");
        string_scan(str, 30);
        for(int counter = 0; counter < real_size; counter++)
        {
            if(string_compare_for_search(str,arr_school[counter].name))
            {
                student_struct_edit_data(&arr_school[counter], arr_school, real_size);
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            printf("\033[31mNOT FOUND\nBe aware the program is case sensitive\033[0m\a\n");
            sleep(1);
        }
    }
    else
    {
        printf("\033[31mSchool is empty\033[0m\a");
        sleep(1);
    }
}

void school_sort(void)
{
    system("cls");
    int choice = 0;
    printf("\033[36m1- Sort all student by ID\n2- Sort all student by degree\n3- all student by name\033[0m\n\n");
    printf("\033[33mEnter your choice: \033[0m");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        student_struct_sort_by_ID(arr_school,real_size);
        break;
    case 2:
        student_struct_sort_by_grade(arr_school,real_size);
        break;
    case 3:
        student_struct_sort_by_name(arr_school,real_size);
        break;
    default:
        printf("\033[31minvalid input\033[0m\a\n");
        sleep(1);
    }
}

void school_clear(void)
{
    system("cls");
    real_size = 0;
    printf("\033[32mALL DATA DELETED\033\n");
    sleep(2);
}

void school_current_size(void)
{
    system("cls");
    printf("\033[32mNumber of students in school = %d\033[0m\n\n",real_size);
    printf("\033[32mSchool capacity = %d\033[0m\n",SCHOOL_CAPACITY);
    sleep(2);
}

void student_calling(void)
{
    system("cls");
    student_struct_call(arr_school,real_size);
}

void school_data_save_in_file(void)
{
    School_data = fopen("School_data.txt", "w");
    fprintf(School_data,"\033[36m-------------------------------------------------\033[0m\n");
    for(int counter = 0; counter < real_size; counter++)
    {
        fprintf(School_data,"\033[32m%d\033[0m\n\n",counter+1);
        fprintf(School_data,"\033[36mStudent Name  : %-30s\nStudent Age   : %d\nStudent ID    : %d\nStudent Level : %c\nStudent Phone : %s\nStudent Grade : %d\033[0m\n",arr_school[counter].name,arr_school[counter].age,arr_school[counter].id,arr_school[counter].level,arr_school[counter].phone,arr_school[counter].grade);
        fprintf(School_data,"\033[36m-------------------------------------------------\033[0m\n");
    }
    fclose(School_data);
}

void school_data_read_from_file(void)
{
    School_data = fopen("School_data.txt", "r");

    if(School_data!=NULL)
    {
        char arr_read[46] = {0};

            fgets(arr_read, 45, School_data);
            fgets(arr_read, 45, School_data);
        //  string_copy_charTOint(&arr_read[27], &real_size, 2);

        for(int counter = 0; counter < real_size; counter++)
        {
            fgets(arr_read, 46, School_data);
            fgets(arr_read, 46, School_data);

            string_copy(&arr_read[16], arr_school[counter].name, 30);
            string_copy_charTOint(&arr_read[16], &arr_school[counter].age, 2);
            string_copy_charTOint(&arr_read[16], &arr_school[counter].id, 4);
            string_copy(&arr_read[16], &arr_school[counter].level, 1);
            string_copy(&arr_read[16], arr_school[counter].phone, 11);
            string_copy_charTOint(&arr_read[16], &arr_school[counter].grade, 3);
        }
    }
    fclose(School_data);
}


