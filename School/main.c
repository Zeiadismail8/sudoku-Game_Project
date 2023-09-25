#include "school.h"


int main(void)
{
    int flag = 1;

    school_data_read_from_file();

    while(flag)
    {
        system("cls");
        printf("\033[32m                                        WELCOME                                        \033[0m\n\n");
        int choice = 0;
        printf("\033[36m1- Add student\n2- Edit student data\n3- Remove student\n4- Call student\n5- Print all student in school\n6- Sort data\n7- delete all data\n8- School capacity and student number\n9- exit\033[0m\n\n");
        printf("\033[33mEnter choice: \033[0m");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            school_add_student();
            school_data_save_in_file();
            break;
        case 2:
            system("cls");
            printf("\033[36mEdit by:\n\n1-ID\n2-Student name\033[0m\n\n");
            printf("\033[33mEnter choice: \033[0m");
            scanf("%d", &choice);
            switch(choice)
            {
            case 1:
                school_edit_student_data_by_id();
                school_data_save_in_file();
                break;
            case 2:
                school_edit_student_data_by_name();
                school_data_save_in_file();
                break;
            default:
                printf("\033[31minvalid input\033[0m\a\n");
                sleep(1);
            }
            break;

        case 3:
            system("cls");
            printf("\033[36mRemove by:\n\n1-ID\n2-Student name\033[0m\n\n");
            printf("\033[33mEnter choice: \033[0m");
            scanf("%d", &choice);
            switch(choice)
            {
            case 1:
                school_remove_student_by_id();
                school_data_save_in_file();
                break;
            case 2:
                school_remove_student_by_name();
                school_data_save_in_file();
                break;
            default:
                printf("\033[31minvalid input\033[0m\a\n");
                sleep(1);
            }
            break;
        case 4:
            student_calling();
        case 5:
            school_print();
            break;
        case 6:
            school_sort();
            school_data_save_in_file();
            break;
        case 7:
            school_clear();
            school_data_save_in_file();
            break;
        case 8:
            school_current_size();
            break;
        case 9:
            flag = 0;
            break;
        default:
            printf("\033[31minvalid input\033[0m\a\n");
            sleep(1);
        }
    }
    return 0;
}

