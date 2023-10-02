/* Mejía Martínez, Ramón    372099  */
/* 26 de agosto de 2023             */
/* Salario segun horas trabajadas   */
/* MMR_ACT1_10_932                  */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int horas;
    float salh,saln,salex,salt;

    printf(" Introduce las horas trabajadas: ");
    scanf("%d",&horas);
    printf(" Introduce el salario por hora: ");
    scanf("%f",&salh);

    if(horas > 49)
    {
        saln=40*salh;
        salex=18*salh+(horas-49)*salh*3;
        salt=saln+salex;
    }
    else
    {
        if(horas > 40)
        {
            saln=40*salh;
            salex=(horas-40)*salh*2;
            salt=saln+salex;
        }
        else
        {
            saln=horas*salh;
            salex=0;
            salt=saln;
        } 
    }
    printf(" Salario por hora: \t%.2f\n Horas trabajadas: \t%d\n Salario normal: \t%.2f\n Salario extra: \t%.2f\n Salario total: \t%.2f",salh,horas,saln,salex,salt);
    return 0;


}