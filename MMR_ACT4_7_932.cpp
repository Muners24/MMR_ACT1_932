/* Mejía Martínez, Ramón    372099            */
/* 31 de agosto de 2023                       */
/* Promedio quitando la calificacion mas baja */
/* MMR_ACT4_7_932                             */

#include <stdio.h>


int main()
{
    int cal[5],men;

    printf(" Ingresa la calificacion 1: ");
    scanf("%d",&cal[0]);
    printf(" Ingresa la calificacion 2: ");
    scanf("%d",&cal[1]);
    printf(" Ingresa la calificacion 3: ");
    scanf("%d",&cal[2]);
    printf(" Ingresa la calificacion 4: ");
    scanf("%d",&cal[3]);
    printf(" Ingresa la calificacion 5: ");
    scanf("%d",&cal[4]);

    men=cal[0];
    if(cal[1]<men)
    {
        men=cal[1];
    }
    if(cal[2]<men)
    {
        men=cal[2];
    }
    if(cal[3]<men)
    {
        men=cal[3];
    }
    if(cal[4]<men)
    {
        men=cal[4];
    }

    printf(" El promedio final es: %.2f",float((cal[0]+cal[1]+cal[2]+cal[3]+cal[4]-men)/4.0));
    return 0;
}   