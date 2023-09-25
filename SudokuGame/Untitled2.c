void array2D_print(int row,int column,int arr[row][column])
{
    int i,i2,j;

    for(i=0; i<row; i++)
    {
        if(i==3 || i==6)
        {
            printf(" ");
        }
        printf("\033[35m      %d\033[0m",i);
    }
    printf("\n");

    printf("  \033[32m-------------------------------------------------------------------\n\033[0m");

    for(i=0; i<row; i++)
    {
        printf("\033[35m%d\033[0m \033[32m|\033[0m",i);
        for(j=0; j<column; j++)
        {
            if(arr[i][j]==' ')
            {
                printf("  \033[33m%2c   \033[0m",arr[i][j]);
            }
            else
            {
                printf("   %d   ",arr[i][j]);
            }

            if(j==2 || j==5 || j==8)
            {
                printf("\033[32m|\033[0m");
            }
        }
        printf("\n");
        if(i==2 || i==5)
        {
            printf("  \033[32m-------------------------------------------------------------------\n\033[0m");
        }
    }
    printf("  \033[32m-------------------------------------------------------------------\n\033[0m");
    printf("\n");
}

void array2D_print_soduko(int row,int column,int arr[row][column],int arr2[row][column],int r,char c)
{
    int i,j;
    for(i=0; i<row; i++)
    {
        if(i==3 || i==6)
        {
            printf(" ");
        }
        printf("\033[35m      %d\033[0m",i);
    }
    printf("\n");
        printf("  \033[32m-------------------------------------------------------------------\n\033[0m");

    for(i=0; i<row; i++)
    {
        printf("\033[35m%d\033[0m \033[32m|\033[0m",i);
        for(j=0; j<column; j++)
        {
            if(arr2[i][j]==' ' && arr[i][j]==' ')
            {
                printf("  \033[33m%2c   \033[0m",arr[i][j]);
            }
            else if(arr2[i][j]==' ' && arr[i][j]!=' ')
            {
                printf("   \033[33m%d   \033[0m",arr[i][j]);
            }
            else
            {
                 printf("   %d   ",arr[i][j]);
            }

            if(j==2 || j==5 || j==8)
            {
                printf("\033[32m|\033[0m");
            }
        }
        printf("\n");
        if(i==2 || i==5)
        {
                printf("  \033[32m-------------------------------------------------------------------\n\033[0m");

        }
    }
        printf("  \033[32m-------------------------------------------------------------------\n\033[0m");

    printf("\n");
}
