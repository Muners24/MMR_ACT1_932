/* Mejía Martínez, Ramón    372099                 */
/* 22 de agosto de 2023                            */
/* Calcular promedio, saber si aprobo o reprobo    */
/* MMR_ACT1_1_932                                  */
 
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int calif[4],i;
    float prom=0;

    printf(" Introduce calificacion 1: ");
    scanf("%d",&calif[1]);
    printf(" Introduce calificacion 1: ");
    scanf("%d",&calif[1]);
    printf(" Introduce calificacion 1: ");
    scanf("%d",&calif[1]);
    printf(" Introduce calificacion 1: ");
    scanf("%d",&calif[1]);
    
    printf(" Su promedio es: %f\n",prom);
    if(prom >= 60)
    {
        printf(" APROBADO ");
    }
    if(prom < 60)
    {
        printf(" REPROBADO ");
    }
    return 0;

}