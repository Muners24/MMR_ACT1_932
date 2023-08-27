/* Mejía Martínez, Ramón    372099               */
/* 26 de agosto de 2023                          */
/* Mostrar una palabra de acuerdo al promedio    */
/* MMR_ACT1_6_932                                */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cal1,cal2,cal3;
    float prom;

    printf(" Introduce la calificacion 1: ");
    scanf("%d",&cal1);
    printf(" Introduce la calificacion 2: ");
    scanf("%d",&cal2);
    printf(" Introduce la calificacion 3: ");
    scanf("%d",&cal3);

    prom=(cal1+cal2+cal3)/3.0;

    if(prom > 100)
    {
        printf(" Error en promedio ");
    }
    else
    {
        if(prom > 97)
        {
            printf(" Excelente ");
        }
        else
        {
            if(prom > 89)
            {
                printf(" Muy bien ");
            }
            else
            {
                if(prom > 79)
                {
                    printf(" Bien ");
                }
                else
                {
                    if(prom > 69)
                    {
                        printf(" Regular ");
                    }
                    else
                    {
                        if(prom > 59)
                        {
                            printf(" Suficiente ");
                        }
                        else
                        {
                            if(prom > 29)
                            {
                                printf(" Extraordinario ");
                            }
                            else
                            {
                                printf(" Repetir ");
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}