void sodukogame(int row,int column,int arr[row][column],int arr2[row][column],int level)
{
    int r,c,num,i,j,flag=0,ss=0,level_continue;
    int sum=0;

    while(1)
    {
        flag=0;
        ss=0;
        printf("\033[36mEnter row not more than 9 = \033[0m");
        scanf("%d",&r);
        while(r>9 && r!=100)
        {
            printf("\033[31mWrong Enter row\a\033[0m\n");
            printf("\033[36mEnter row not more than 9 = \033[0m");
            scanf("%d",&r);
        }

        printf("\033[36mEnter column not more than 9 = \033[0m");
        scanf("%d",&c);
        while(c>9 && r!=100)
        {
            printf("\033[31mWrong Enter column\a\033[0m\n");
            printf("\033[36mEnter column not more than 9 = \033[0m");
            scanf("%d",&c);
        }

        if(r==100 && c==100)
        {
            int Solution_puzzel_level1[9][9]=
            {
                {4,3,5,2,6,9,7,8,1},
                {6,8,2,5,7,1,4,9,3},
                {1,9,7,8,3,4,5,6,2},
                {8,2,6,1,9,5,3,4,7},
                {3,7,4,6,8,2,9,1,5},
                {9,5,1,7,4,3,6,2,8},
                {5,1,9,3,2,6,8,7,4},
                {2,4,8,9,5,7,1,3,6},
                {7,6,3,4,1,8,2,5,9}
            };

            int Solution_puzzel_level2[9][9]=
            {
                {8,7,6,4,9,3,2,5,1},
                {3,4,5,7,1,2,9,6,8},
                {2,9,1,5,6,8,4,7,3},
                {9,8,2,1,3,5,7,4,6},
                {7,5,4,8,2,6,3,1,9},
                {1,6,3,9,4,7,8,2,5},
                {4,1,7,3,5,9,6,8,2},
                {6,3,8,2,7,1,5,9,4},
                {5,2,9,6,8,4,1,3,7}
            };

            system("cls");
            if(level==1)
            {
                printf("\e[33m                              LEVEL ONE                              \e[m\n\n");
                printf("\e[33m                       This is Solution Of Level One                              \e[m\n\n");
                array2D_print_soduko(row,column,Solution_puzzel_level1,arr2,r,c);
                printf("\e[33m                   Press 2 to continue for Level Two                              \e[m\n\n");
                scanf("%d",&level_continue);
                if(level_continue==2)
                {
                    system("cls");
                    return ;
                }
            }
            else if (level==2)
            {
                printf("\e[33m                              LEVEL TWO                              \e[m\n\n");
                printf("\e[33m                       This is Solution Of Level Two                              \e[m\n\n");
                array2D_print_soduko(row,column,Solution_puzzel_level2,arr2,r,c);
                printf("\e[33m                   Press 3 to continue for Level Two                              \e[m\n\n");
                scanf("%d",&level_continue);
                if(level_continue==3)
                {
                    system("cls");
                    return ;
                }
            }
        }

        if(arr[r][c]==' ')
        {
            printf("\033[36mEnter number not more than 9 = \033[0m");
            scanf("%d",&num);
            while(num>9)
            {
                printf("\033[36mEnter number not more than 9 = \033[0m");
                printf("Enter number not more than 9 : \n");
                scanf("%d",&num);
            }

            if(num==0)
            {
                printf("\033[31mThis place is really empty\a\033[0m\n");
                num=' ';
            }
            else
            {


                for(i=0; i<row; i++)
                {
                    if(i!=r)
                    {
                        if(arr[i][c]==num)
                        {
                            flag=1;
                            ss++;
                            break;
                        }
                    }
                }

                for(i=0; i<column; i++)
                {
                    if(i!=c)
                    {
                        if(arr[r][i]==num)
                        {
                            flag=2;
                            ss++;
                            break;
                        }
                    }
                }

                if(flag==2 && ss==2)
                {
                    printf("\033[31mNumber exists in row and column\a\033[0m\n");
                }
                else if(flag==1)
                {
                    printf("\033[31mNumber exists in column\a\033[0m\n");
                }
                else if(flag==2 && ss==1)
                {
                    printf("\033[31mNumber exists in row\a\033[0m\n");
                }


                if(flag==0)
                {
                    arr[r][c]=num;

                    system("cls");
                    if(level==1)
                        printf("\e[33m                              LEVEL ONE                              \e[m\n\n");
                    else if(level==2)
                        printf("\e[33m                              LEVEL TWO                              \e[m\n\n");
                    printf("\e[32m# You are allowed to modify the space and \e[33morange\e[m \e[32mnumber only (numbers between 1 to 9)\e[m\e[m\n\n");
                    printf("\e[32m# If you don't know solution enter 100 in row and column \e[m\n\n");
                    printf("\e[32m# You can make the place empty by entering a number 0 \e[m\n\n");
                    array2D_print_soduko(row,column,arr,arr2,r,c);
                }
            }
        }
        else
        {
            if(arr2[r][c]==' ')
            {
                printf("\033[36mEnter number not more than 9 = \033[0m");
                scanf("%d",&num);
                while(num>9)
                {
                    printf("\033[31mWrong Enter Number\a\033[0m\n");
                    printf("\033[36mEnter number not more than 9 = \033[0m");
                    scanf("%d",&num);
                }

                if(num==0)
                {
                    arr[r][c]=' ';
                    system("cls");
                    if(level==1)
                        printf("\e[33m                              LEVEL ONE                              \e[m\n\n");
                    else if(level==2)
                        printf("\e[33m                              LEVEL TWO                              \e[m\n\n");
                    printf("\e[32m# You are allowed to modify the space and \e[33morange\e[m \e[32mnumber only (numbers between 1 to 9)\e[m\e[m\n\n");
                    printf("\e[32m# If you don't know solution enter 100 in row and column \e[m\n\n");
                    printf("\e[32m# You can make the place empty by entering a number 0 \e[m\n\n");
                    array2D_print_soduko(row,column,arr,arr2,r,c);
                }
                else
                {
                    for(i=0; i<row; i++)
                    {
                        if(i!=r)
                        {
                            if(arr[i][c]==num)
                            {
                                flag=1;
                                ss++;
                                break;
                            }
                        }
                    }

                    for(i=0; i<column; i++)
                    {
                        if(i!=c)
                        {
                            if(arr[r][i]==num)
                            {
                                flag=2;
                                ss++;
                                break;
                            }
                        }
                    }

                    if(flag==2 && ss==2)
                    {
                        printf("\033[31mNumber exists in row and column\a\033[0m\n");
                    }
                    else if(flag==1)
                    {
                        printf("\033[31mNumber exists in column\a\033[0m\n");
                    }
                    else if(flag==2 && ss==1)
                    {
                        printf("\033[31mNumber exists in row\a\033[0m\n");
                    }


                    if(flag==0)
                    {
                        arr[r][c]=num;

                        system("cls");
                        if(level==1)
                            printf("\e[33m                              LEVEL ONE                              \e[m\n\n");
                        else if(level==2)
                            printf("\e[33m                              LEVEL TWO                              \e[m\n\n");
                        printf("\e[32m# You are allowed to modify the space and \e[33morange\e[m \e[32mnumber only (numbers between 1 to 9)\e[m\e[m\n\n");
                        printf("\e[32m# If you don't know solution enter 100 in row and column \e[m\n\n");
                        printf("\e[32m# You can make the place empty by entering a number 0 \e[m\n\n");
                        array2D_print_soduko(row,column,arr,arr2,r,c);
                    }
                }
            }
            else
            {
                printf("\033[31mYou entered a constant row and a constant column\a\033[0m\n");
            }

        }
        for(i=0; i<1; i++)
        {
            sum=0;
            for(j=0; j<column; j++)
            {
                sum=sum+arr[i][j];
            }

            if(sum==45)
            {
                break;
            }
        }
        if(sum==45)
        {
            printf("               \033[31mCo\033[0m\033[32mng\033[0m\033[33mrat\033[0m\033[34mula\033[0m\033[35mtions\033[0m               \n");
            break;
        }
    }
}



