/* Mejía Martínez, Ramón    372099               */
/* 22 de agosto de 2023                          */
/* Mostrar una palabra de acuerdo al promedio    */
/* MMR_ACT1_5_932                                */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int calif[3];
    float prom;

    printf(" Introduce la calificacion 1: ");
    scanf("%d",&calif[0]);
    printf(" Introduce la calificacion 2: ");
    scanf("%d",&calif[1]);
    printf(" Introduce la calificacion 3: ");
    scanf("%d",&calif[2]);
    
    prom=calif[0];
    prom+=calif[1];
    prom+=calif[2];
    prom=prom/3.0;
    scanf("%f",&prom);
    if(prom >= 30 )
    {
        if( prom >= 60)
        {
            if(prom >= 70)
            {
                if(prom >= 80)
                {
                        if(prom >= 90)
                        {
                            if(prom >= 98)
                            {
                                if(prom > 100)
                                {
                                    printf(" Error en promedio");
                                }
                                else
                                {
                                    printf(" Excelente");
                                }
                            }
                            else
                            {
                                printf(" Muy bien ");
                            }
                        }
                        else
                        {
                            printf(" Bien ");
                        }
                }
                else
                {
                    printf(" Regular ");
                }
            }
            else
            {
                printf(" Suficiente ");
            }
        }
        else
        {
            printf(" Extraordianrio ");
        }
    }
    else
    {
        printf(" Repetir ");
    }
    return 0;
}