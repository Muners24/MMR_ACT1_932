/* Mejía Martínez, Ramón    372099                 */
/* 22 de agosto de 2023                            */
/* Programa para saber si un número es par o impar */
/* MMR_ACT1_2_932                                  */  

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf(" Introduce un numero entero: ");
    scanf("%d",&num);

    if(num%2==0)
    {
        printf(" El numero %d es PAR ",num);
    }
    else
    {
        printf(" El número %d es IMPAR ",num);
    }
    return 0;
}
