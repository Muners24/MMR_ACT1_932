/* Mejía Martínez, Ramón    372099 */
/* 31 de agosto de 2023            */
/* Numero menor de 6 numeros       */
/* MMR_ACT4_3_932                  */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[6],mayor;

    printf(" Ingresa el numero 1: ");
    scanf("%d",&num[0]);
    printf(" Ingresa el numero 2: ");
    scanf("%d",&num[1]);
    printf(" Ingresa el numero 3: ");
    scanf("%d",&num[2]);
    printf(" Ingresa el numero 4: ");
    scanf("%d",&num[3]);
    printf(" Ingresa el numero 5: ");
    scanf("%d",&num[4]);
    printf(" Ingresa el numero 6: ");
    scanf("%d",&num[5]);

    mayor=num[0];
    if(num[1]>mayor)
    {
        mayor=num[1];
    }
    if(num[2]>mayor)
    {
        mayor=num[2];
    }
    if(num[3]>mayor)
    {
        mayor=num[3];
    }
    if(num[4]>mayor)
    {
        mayor=num[4];
    }
    if(num[5]>mayor)
    {
        mayor=num[5];
    }

    printf(" El numero mayor es: %d",mayor);
    return 0;
}