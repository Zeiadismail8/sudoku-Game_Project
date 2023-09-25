#include "student_struct.h"

void student_struct_swap(student_t* ptr1, student_t* ptr2)
{
    student_t temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void student_struct_print(const student_t* ptr, int index)
{
    printf("\033[32m%d\033[0m\n\n",index);
    printf("\033[36mStudent Name  : %-30s\nStudent Age   : %d\nStudent ID    : %d\nStudent Level : %c\nStudent Phone : %s\nStudent Grade : %d\033[0m\n",ptr->name,ptr->age,ptr->id,ptr->level,ptr->phone,ptr->grade);
    printf("\033[36m-------------------------------------------------\033[0m\n");
}

void student_struct_scan(student_t* ptr, student_t* ptr2, int current_position)
{
    printf("\033[33mEnter student name                : \033[0m");
    string_scan(ptr->name, 30);
    fflush(stdin);
    int flag = 1;

    while(flag)
    {
        int age;
        flag = 0;
        printf("\033[33mEnter student age (12 , 13 or 14) : \033[0m");
        scanf("%d", &age);
        if(age<12 || age>14)
        {
            printf("\n\033[31mAge must be 12 , 13 or 14\033[0m\a\n\n");
            flag=1;
        }
        else
        {
            ptr->age = age;
        }
    }

    flag=1;
    while(flag)
    {
        int id = 1;
        flag = 0;
        printf("\033[33mEnter student ID (1 to 50)        : \033[0m");
        scanf("%d",&id);
        if(id <= 0)
        {
            printf("\n\033[31mIDs starts from 1 to 50\033[0m\a\n\n");
            flag = 1;
        }
        else if(id >50)
        {
            printf("\n\033[31mIDs starts from 1 to 50\033[0m\a\n\n");
            flag = 1;
        }
        else
        {
            for(int counter = 0; counter < current_position; counter++)
            {
                if(ptr2[counter].id == id)
                {
                    system("cls");
                    printf("\n\033[31mThis ID already exist addtion failed\nChoose ID out of those\033[0m\a\n");
                    for(int counter2 = 0; counter2 < current_position; counter2++)
                    {
                        printf(" %d ", ptr2[counter2].id);
                    }
                    printf("\n\n");
                    flag = 1;
                    break;
                }
            }
            if(!flag)
            {
                ptr->id = id;
            }
        }

    }

    flag = 1;
    while(flag)
    {
        char level;
        flag = 0;
        printf("\033[33mEnter student level (1 , 2 or 3)  : \033[0m");
        fflush(stdin);
        scanf("%c", &level);
        if(level<'1' || level>'3')
        {
            printf("\n\033[31mlevel must be 1 , 2 or 3\033[0m\a\n\n");
            flag=1;
        }
        else
        {
            ptr->level = level;
        }
    }

    printf("\033[33mEnter student phone               : \033[0m");
    string_scan(ptr->phone,11);

    flag = 1;
    while(flag)
    {
        int grade;
        flag = 0;
        printf("\033[33mEnter student grade (0:100)       : \033[0m");
        scanf("%d", &grade);

        if(grade < 0 || grade > 100)
        {
            printf("\n\033[31mGrade starts from 0 to 100\033[0m\a\n\n");
            flag = 1;
        }
        else
        {
            ptr->grade = grade;
        }
    }
}

void student_struct_remove(student_t *ptr, int size)
{
    for(int counter = 0; counter < 1; counter++)
    {
        student_struct_swap(ptr, ptr + 1);
    }
    printf("\033[32mRemove done\033[0m\n");
    sleep(1);
}

void student_struct_edit_data(student_t *ptr, student_t *ptr2, int current_position)
{
    int choice = 0;
    system("cls");
    printf("\033[32mChoose data that you want edit: \033[0m\n\n");
    printf("\033[36m1- Student name\n2- Student age\n3- Student ID\n4- Student level\n5- Student phone\n6- Student garde\n7- Change all data\033[0m\n\n");
    printf("\033[32mEnter your choice 1,2,3,4,5,6 or 7 : \033[0m");
    scanf("%d", &choice);
    int flag = 0;
    switch(choice)
    {

    case 1:
        system("cls");
        printf("\033[33mEnter new name: \033[0m");
        string_scan(ptr->name, 30);
        printf("\033[32mEdition done\033[0m\n");
        sleep(1);
        break;

    case 2:
        flag=1;
        while(flag)
        {
            flag=0;
            int age;
            system("cls");
            printf("\033[33mEnter new age (12 , 13 or 14): \033[0m");
            scanf("%d", &age);
            if(age<12 || age>14)
            {
                printf("\n\033[31mAge must be 12 , 13 or 14\033[0m\a\n\n");
                flag=1;
            }
            else
            {
                ptr->age = age;
            }
        }
        printf("\033[32mEdition done\033[0m\n");
        sleep(1);
        break;

    case 3:
        flag=1;
        while(flag)
        {
            flag=0;
            int id;
            system("cls");
            printf("\033[33mEnter new ID: \033[0m");
            scanf("%d",&id);
            if(id <= 0)
            {
                printf("\n\033[31mIDs starts from 1 to 50\033[0m\a\n\n");
                sleep(1);
                flag = 1;
            }
            else if(id > 50)
            {
                printf("\n\033[31mIDs starts from 1 to 50\033[0m\a\n\n");
                sleep(1);
                flag = 1;
            }
            else
            {
                for(int counter = 0; counter < current_position; counter++)
                {
                    if(ptr2[counter].id == id)
                    {
                        system("cls");
                        printf("\n\033[31mThis ID already exist addtion failed\nChoose ID out of those\033[0m\a\n");
                        for(int counter2 = 0; counter2 < current_position; counter2++)
                        {
                            printf(" %d ", ptr2[counter2].id);
                        }
                        printf("\n\n");
                        flag = 1;
                        break;
                    }
                }
                if(!flag)
                {
                    ptr->id = id;
                }
            }
        }
        printf("\033[32mEdition done\033[0m\n");
        sleep(1);
        break;

    case 4:
        flag = 1;
        while(flag)
        {
            flag = 0;
            char level;
            system("cls");
            printf("\033[33mEnter student level (1 , 2 or 3)  : \033[0m");
            fflush(stdin);
            scanf("%c", &level);
            if(level<'1' || level>'3')
            {
                printf("\n\033[31mlevel must be 1 , 2 or 3\033[0m\a\n\n");
                sleep(1);
                flag=1;
            }
            else if(level==(ptr->level))
            {
                printf("\033[31mIt's the same level\033[0m\a");
                sleep(1);
                flag=1;
            }
            else
            {
                ptr->level = level;
            }
        }
        printf("\033[32mEdition done\033[0m\n");
        sleep(1);
        break;

    case 5:
        system("cls");
        printf("\033[33mEnter A New Number : \033[0m");
        string_scan(ptr->phone,11);
        printf("\033[32mEdition done\033[0m\n");
        sleep(1);
        break;

    case 6:
        flag = 1;
        while(flag)
        {
            flag = 0;
            int grade;
            system("cls");
            printf("\033[33mEnter student grade (0:100) : \033[0m");
            scanf("%d", &grade);

            if(grade < 0 || grade > 100)
            {
                printf("\n\033[31mGrade starts from 0 to 100\033[0m\a\n\n");
                sleep(1);
                flag = 1;
            }
            else if(grade==(ptr->grade))
            {
                printf("\033[31mIt's the same grade\033[0m\a");
                sleep(1);
                flag=1;
            }
            else
            {
                ptr->grade = grade;
            }
        }
        printf("\033[32mEdition done\033[0m\n");
        sleep(1);
        break;

    case 7:
        system("cls");
        student_struct_scan(ptr, ptr2, current_position);
        printf("\033[32mEdition done\033[0m\n");
        sleep(1);
        break;

    default:
        printf("\033[31minvalid input\033[0m\a\n");
        sleep(1);
    }
}

void student_struct_sort_by_ID(student_t *arr_school, int size)
{
    int choice = 0, counter1, counter2, flag = 1;
    printf("\n\033[36m1- Ascending.\n2- Descending.\033[0m\n\n\033[33mEnter your choice: \033[0m");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        for(counter1 = 0; counter1 < size && flag; counter1++)
        {
            flag = 0;
            for(counter2 = 0; counter2 < size - 1 - counter1; counter2++)
            {
                if(arr_school[counter2 + 1].id < arr_school[counter2].id)
                {
                    student_struct_swap(&arr_school[counter2], &arr_school[counter2 + 1]);
                    flag = 1;
                }
            }
        }
        printf("\033[32mThe students were sorted in ascending order according to their IDs\033[0m\n");
        sleep(1);
        break;
    case 2:
        for(counter1 = 0; counter1 < size && flag; counter1++)
        {
            flag = 0;
            for(counter2 = 0; counter2 < size - 1 - counter1; counter2++)
            {
                if(arr_school[counter2 + 1].id > arr_school[counter2].id)
                {
                    student_struct_swap(&arr_school[counter2], &arr_school[counter2 + 1]);
                    flag = 1;
                }
            }
        }
        printf("\033[32mThe students were sorted in descending order according to their IDs\033[0m\n");
        sleep(1);
        break;
    default:
        printf("\033[31minvalid input\033[0m\a\n");
        sleep(1);
    }
}

void student_struct_sort_by_grade(student_t *arr_school, int size)
{
    int choice = 0, counter1, counter2, flag = 1;
    printf("\n\033[36m1- Ascending.\n2- Descending.\033[0m\n\n\033[33mEnter your choice: \033[0m");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        for(counter1 = 0; counter1 < size && flag; counter1++)
        {
            flag = 0;
            for(counter2 = 0; counter2 < size - 1 - counter1; counter2++)
            {
                if(arr_school[counter2 + 1].grade > arr_school[counter2].grade)
                {
                    student_struct_swap(&arr_school[counter2], &arr_school[counter2 + 1]);
                    flag = 1;
                }
            }
        }
        printf("\033[32mThe students were sorted in ascending order according to their degrees\033[0m\n");
        sleep(1);
        break;
    case 2:
        for(counter1 = 0; counter1 < size && flag; counter1++)
        {
            flag = 0;
            for(counter2 = 0; counter2 < size - 1 - counter1; counter2++)
            {
                if(arr_school[counter2 + 1].grade < arr_school[counter2].grade)
                {
                    student_struct_swap(&arr_school[counter2], &arr_school[counter2 + 1]);
                    flag = 1;
                }
            }
        }
        printf("\033[32mThe students were sorted in descending order according to their degrees\033[0m\n");
        sleep(1);
        break;
    default:
        printf("\033[31minvalid input\033[0m\a\n");
    }
}

void student_struct_sort_by_name(student_t *arr_school, int size)
{
    int choice = 0, counter1 = 0, counter2 = 0, flag = 1;
    printf("\n\033[36m1- Ascending.\n2- Descending.\033[0m\n\n\033[33mEnter your choice: \033[0m");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        for(int counter = 0; counter < size && flag; counter++)
        {
            flag = 0;
            for(int counter2 = 0; counter2 < size - counter - 1; counter2++)
            {
                if(string_compare_sort(arr_school[counter2].name, arr_school[counter2 + 1].name) == 1)
                {
                    flag = 1;
                    student_struct_swap(&arr_school[counter2], &arr_school[counter2 + 1]);
                }
            }
        }
        printf("\033[32mThe students were sorted in ascending order according to their names\033[0m\n");
        sleep(1);
        break;
    case 2:
        for(int counter = 0; counter < size && flag; counter++)
        {
            flag = 0;
            for(int counter2 = 0; counter2 < size - counter - 1; counter2++)
            {
                if(string_compare_sort(arr_school[counter2].name, arr_school[counter2 + 1].name) == -1)
                {
                    flag = 1;
                    student_struct_swap(&arr_school[counter2], &arr_school[counter2 + 1]);
                }
            }
        }
        printf("\033[32mThe students were sorted in descending order according to their names\033[0m\n");
        sleep(1);
        break;
    default:
        printf("\033[31minvalid input\033[0m\a\n");
    }
}

void student_struct_call_by_name(student_t* arr_school,int size)
{
    system("cls");
    if(0 < size)
    {
        char str[21], flag = 1;
        printf("\033[33mEnter student name: \033[0m");
        string_scan(str, 21);
        for(int counter = 0; counter < size; counter++)
        {
            if(string_compare_for_search(str, arr_school[counter].name))
            {
                for(int i=0; i<5; i++)
                {
                    printf("\033[32m~\033[0m\a");
                    sleep(1);
                }
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
    }
}

void student_struct_call_by_ID(student_t* arr_school,int size)
{
    system("cls");
    if(size>0)
    {
        int id, flag = 1;
        printf("\033[32mEnter student ID: \033[0m");
        scanf("%d", &id);
        for(int counter = 0; counter <size; counter++)
        {
            if(arr_school[counter].id == id)
            {
                for(int i=0; i<5; i++)
                {
                    printf("\033[32m~\033[0m\a");
                    sleep(1);
                }
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

void student_struct_call(student_t* arr_school,int size)
{
    system("cls");
    int choice = 0;
    printf("\033[36m1- Name\n2- ID\033[0m\n\n");
    printf("\033[33mEnter your choice: \033[0m");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        student_struct_call_by_name(arr_school,size);
        break;
    case 2:
        student_struct_call_by_ID(arr_school,size);
        break;
    default:
        printf("\033[31minvalid input\033[0m\a\n");
    }
}

