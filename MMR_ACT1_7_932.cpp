/* Mejía Martínez, Ramón    372099 */
/* 26 de agosto de 2023            */
/* Numero menor de tres numeros    */
/* MMR_ACT1_7_932                  */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,num3,menor,c;

    printf(" Introduce el primer numero: ");
    scanf("%d",&num1);
    printf(" Introduce el segundo numero: ");
    scanf("%d",&num2);
    printf(" Introduce el tercer numero: ");
    scanf("%d",&num3);
 
   if(num1 < num2)
   {
        if(num1 < num3)
        {
            printf(" El numero menor es el primero y su valor es: %d",num1);
        }
        else
        {
            printf(" El numero menor es el tercero y su valor es: %d",num3);
        }
   }
    else
    {
        if(num2 < num3)
        {
            printf(" El numero menor es el segundo y su valor es: %d",num2);
        }
        else
        {
            printf(" El numero menor es el tercero y su valor es: %d",num3);
        }
    }

    return 0;
}

