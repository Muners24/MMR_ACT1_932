/* Mejía Martínez, Ramón    372099                  */
/* 31 de agosto de 2023                             */
/* Salario segun horas trabajadas y sueldo por hora */
/* MMR_ACT4_4_932                                   */

#include <stdio.h>
#include <stdlib.h>

#define J 40

int main()
{
    int horas;
    float sh,sueldn,sueldex,sueldt;

    printf(" Ingresa las horas trabajadas: ");
    scanf("%d",&horas);
    printf(" Ingresa el salario por hora: ");
    scanf("%f",&sh);

    if(horas>J)
    {
        if(horas>J+9)
        {
            sueldex=(horas-(J+9))*3*sh+18*sh;
        }
        else
        {
            sueldex=(horas-J)*2*sh;
        }
        sueldn=J*sh;
    }
    else
    {
        sueldn=horas*sh;
        sueldex=0;
    }

    sueldt=sueldn+sueldex;

    printf(" Salario por hora: \t%.2f\n Horas trabajadas: \t%d\n Salario normal: \t%.2f\n Salario extra: \t%.2f\n Salario total: \t%.2f",sh,horas,sueldn,sueldex,sueldt);
    return 0;
}