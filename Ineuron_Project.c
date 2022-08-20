

    //  you can directly run this project by pasting this code on code blocks or vs code....

#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
                                    //function declarations
HANDLE console_color;

int win(int arr[][4]);
void printgame(int arr[][4]);
void swap(int *p,int *q);
void makegame(int arr[][4]);
int ArrowUp(int arr[][4]);
int ArrowDown(int arr[][4]);
int ArrowRight(int arr[][4]);
int ArrowLeft(int arr[][4]);
void rules(int arr[][4]);
int keypress();


int main()
{

    int arr[4][4];
    char name[50],ch;
    int rem=300;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    printf("\n\n\nPlayer Name: ");
    scanf("%s",name);
    while(1)
    {
        makegame(arr);
        rules(arr);
        while(!win(arr))
        {
            system("cls");
            if(!rem)
                break;
            printf("\n\n  Player Name:  %s  ,  Move remaining : %d\n\n",name,rem);
            printgame(arr);
            int key=keypress();
            switch(key)
            {
               case 72:
                            if(ArrowUp(arr))
                            rem--;
                            break;
                case 80:
                            if(ArrowDown(arr))
                            rem--;
                            break;
                case 77:
                            if(ArrowRight(arr))
                            rem--;
                            break;
                case 75:
                            if(ArrowLeft(arr))
                            rem--;
                            break;
                case 69:
                case 101:
                            printf("\a\a\a\a\n     Thanks for Playing ! \n\a");
                            printf("\nHit Enter to exit the game \n");
                            key=keypress();
                            exit(0);
                default:
                     printf("\n\n\a\a Not Allowed \a");
            }
        }
        if(!rem)
        {
            SetConsoleTextAttribute(console_color, 4);
            printf("\n\a       YOU LOSE !       \a\a\n");
        }
        else
        {
            SetConsoleTextAttribute(console_color, 2);
            printf("\n\a!!!!!!!!!!!!!!!!Congratulations!!!!!!!!!!!!!!!!\n\a");
            printf("\a          You have Won    \a\a\a ");
        }

        SetConsoleTextAttribute(console_color, 2);
        printf("\nwant to play again ? \n");
        SetConsoleTextAttribute(console_color, 7);
        printf("enter 'y' to play again:  ");
        fflush(stdin);
        scanf("%c",&ch);
        if(!(ch=='y' || ch=='Y'))
        {
            break;
        }
        rem=300;
    }
    return 0;
}

int win(int arr[][4])
{
   int i, j, k=1;
   for(i=0; i<4; i++)
   {
        for(j=0; j<4; j++,k++)
            if( arr[i][j]!=k  &&  k!=16 )
            break;
        if(j<4)
        break;
   }
   if(j<4)
   return 0;
   return 1;
}

void printgame(int arr[][4])
{
    int i,j;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("--------------------\n");

    for(i=0;i<4;i++)
    {
        printf("|");
        for(j=0;j<4;j++)
        {
            if(arr[i][j]!=0)
            printf("%-2d | ",arr[i][j]);
            else
            printf("   | ");
        }
        printf("\n");
    }
    printf("--------------------\n");
}

void swap(int *p,int *q)
{
    *p=*p+*q;
    *q=*p-*q;
    *p=*p-*q;
    printf("");
}

void  makegame(int arr[][4])
{
    int n = 15;
    int num[n];
    int li=n-1;
    int index,i,j;
    for(i=0; i<15; i++)
    num[i] = i+1;
    srand(time(NULL));
    for(i=0; i<4; i++)
    for(j=0; j<4; j++)
    {
        if(li>=0)
        {  index=rand()%(li+1);
           arr[i][j]=num[index];
           num[index]=num[li--];
        }
    }
       arr[i-1][j-1]=0;
}

int ArrowUp(int arr[][4])
{
    int i, j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        if(arr[i][j]==0)
            break;

        if(j<4)
        break;
    }
      if(i==3)
      return 0;
      swap(&arr[i][j],&arr[i+1][j]);
      return 1;
}

int ArrowDown(int arr[][4])
{
    int i, j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(i==0)
      return 0;
      swap(&arr[i][j],&arr[i-1][j]);
      return 1;
}

int ArrowRight(int arr[][4])
{
    int i, j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(j==0)
      return 0;
      swap(&arr[i][j],&arr[i][j-1]);
      return 1;
}

int ArrowLeft(int arr[][4])
{
    int i, j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(j==3)
      return 0;
      swap(&arr[i][j], &arr[i][j+1]);
      return 1;
}

void rules(int arr[][4])
{
    system("cls");
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    int i, j, k=1;
    printf("                  MATRIX PUZZLE                \n\n");
    SetConsoleTextAttribute(console_color, 4);
    printf("                 RULES OF THIS GAME                 \n");
    printf("\n1.You can move only 1 step at a time by arrow key");
    SetConsoleTextAttribute(console_color, 7);
    printf("\n\tMove Up   : by Up arrow key ");
    printf("\n\tMove Down : by Down arrow key");
    printf("\n\tMove Left : by Left arrow key");
    printf("\n\tMove Right: by Right arrow key");
    SetConsoleTextAttribute(console_color, 4);
    printf("\n2.You can move number at empty position only ");
    printf("\n");
    printf("\n3.For each valid move : your total number of move will decreased by 1 ");
    printf("\n4.Wining situation : ");
    printf("number in a 4*4 matrix should be in order from 1 to 15 ");
    SetConsoleTextAttribute(console_color, 7);
    printf("\n\n            winning situation:         \n");
    SetConsoleTextAttribute(console_color, 6);
    printf("---------------------\n");
    for(i=0; i<4; i++)
    {
       printf("| ");
       for(j=0;j<4;j++)
        {
            if(arr[i][j]!=0)
            printf("%-2d | ",4*i+j+1);
            else
            printf("   |");
        }
        printf("\n");
   }
    printf("---------------------\n");
    SetConsoleTextAttribute(console_color, 7);
    printf("\n5.You can exit the game at any time by pressing 'E' or 'e' ");
    printf("\nSo Try to win in minimum no of move \n");
    printf("\nEnter any key to start.....   ");
    int x=keypress();
}

int keypress()
{
    char ch;
    ch=_getch();
    if(ch==-32)
    ch=_getch();
    return ch;
}
