/* Mejía Martínez, Ramón    372099                 */
/* 22 de agosto de 2023                            */
/* Calcular promedio, saber si aprobo o reprobo    */
/* MMR_ACT1_3_932                                  */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cal1,cal2,cal3,cal4;
    float prom;

    printf(" Introduce la calificacion 1: ");
    scanf("%d",&cal1);
    printf(" Introduce la calificacion 2: ");
    scanf("%d",&cal2);
    printf(" Introduce la calificacion 3: ");
    scanf("%d",&cal3);
    printf(" Introduce la calificacion 4: ");
    scanf("%d",&cal4);

    prom=(cal1+cal2+cal3+cal4)/4.0;

    printf(" Su promedio es: %f\n",prom);
    if(prom >= 60)
    {
        printf(" APROBADO ");
    }
    else
    {
        printf(" REPROBADO ");
    }
    return 0;
}