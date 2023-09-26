#include <stdio.h>
#include <stdlib.h>

int puzel_level1[9][9]=
{
    {' ',' ',' ',2,6,' ',7,' ',1},
    {6,8,' ',' ',7,' ',' ',9,' '},
    {1,9,' ',' ',' ',4,5,' ',' '},
    {8,2,' ',1,' ',' ',' ',4,' '},
    {' ',' ',4,6,' ',2,9,' ',' '},
    {' ',5,' ',' ',' ',3,' ',2,8},
    {' ',' ',9,3,' ',' ',' ',7,4},
    {' ',4,' ',' ',5,' ',' ',3,6},
    {7,' ',3,' ',1,8,' ',' ',' '}


};

int puzel2_level1[9][9]=
{
    {' ',' ',' ',2,6,' ',7,' ',1},
    {6,8,' ',' ',7,' ',' ',9,' '},
    {1,9,' ',' ',' ',4,5,' ',' '},
    {8,2,' ',1,' ',' ',' ',4,' '},
    {' ',' ',4,6,' ',2,9,' ',' '},
    {' ',5,' ',' ',' ',3,' ',2,8},
    {' ',' ',9,3,' ',' ',' ',7,4},
    {' ',4,' ',' ',5,' ',' ',3,6},
    {7,' ',3,' ',1,8,' ',' ',' '}

};

int puzel2_level2[9][9]=
{
    {' ',' ',6,' ',9,' ',2,' ',' '},
    {' ',' ',' ',7,' ',2,' ',' ',' '},
    {' ',9,' ',5,' ',8,' ',7,' '},
    {9,' ',' ',' ',3,' ',' ',' ',6},
    {7,5,' ',' ',' ',' ',' ',1,9},
    {1,' ',' ',' ',4,' ',' ',' ',5},
    {' ',1,' ',3,' ',9,' ',8,' '},
    {' ',' ',' ',2,' ',1,' ',' ',' '},
    {' ',' ',9,' ',8,' ',1,' ',' '}

};

int puzel_level2[9][9]=
{
    {' ',' ',6,' ',9,' ',2,' ',' '},
    {' ',' ',' ',7,' ',2,' ',' ',' '},
    {' ',9,' ',5,' ',8,' ',7,' '},
    {9,' ',' ',' ',3,' ',' ',' ',6},
    {7,5,' ',' ',' ',' ',' ',1,9},
    {1,' ',' ',' ',4,' ',' ',' ',5},
    {' ',1,' ',3,' ',9,' ',8,' '},
    {' ',' ',' ',2,' ',1,' ',' ',' '},
    {' ',' ',9,' ',8,' ',1,' ',' '}


};


int main()
{

    int row=sizeof(puzel_level1)/sizeof(puzel_level1[0]);
    int column= row;
    int level;

    while(1)
    {
        printf("\e[33m                              LEVEL ONE                              \e[m\n\n");
        printf("\e[32m# You are allowed to modify the space and orange number only (numbers between 1 to 9) \e[m\n\n");
        printf("\e[32m# If you don't know solution enter 100 in row and column \e[m\n\n");
        printf("\e[32m# You can make the place empty by entering a number 0 \e[m\n\n");
        array2D_print(row,column,puzel_level1);
        sodukogame(row,column,puzel_level1,puzel2_level1,1);

        system("cls");

        system("cls");
        printf("\e[33m                              LEVEL TWO                              \e[m\n\n");
        printf("\e[32m# You are allowed to modify the space and orange number only (numbers between 1 to 9) \e[m\n\n");
        printf("\e[32m# If you don't know solution enter 100 in row and column \e[m\n\n");
        printf("\e[32m# You can make the place empty by entering a number 0 \e[m\n\n");
        array2D_print(row,column,puzel_level2);
        sodukogame(row,column,puzel_level2,puzel2_level2,2);

        printf("\e[33mEnter 1 to continue   or   anywhere to exit\e[m\n\n");
        scanf("%d",&level);

        if(level!=1)
        {
            return;
        }

        system("cls");
    }

    return 0;
}
