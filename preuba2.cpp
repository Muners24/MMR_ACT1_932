#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    char c[2];
    int i=0;
    do
    {
        fflush(stdin);
        gets(c);
        fflush(stdin);
        printf("c = %d  ;   c = %c \n",c[0],c[0]);
        i++;
    }while(c[0]!=13);
    system("cls");
    return 0;
}
