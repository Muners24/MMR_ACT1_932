/* Mejía Martínez, Ramón    372099     */
/* 22 de agosto de 2023                */
/* Saludar al usuario segun su sexo    */
/* MMR_ACT1_4_932                      */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sx;
    printf(" ¿Cual es tu sexo?\n\n 1) HOMBRE\n 2) MUJER ");
    scanf("%d",&sx);

    if(sx==1)
    {
        printf(" HOLA, ERES HOMBRE ");
    }
   else
   {
        printf(" HOLA, ERES MUJER ");
   }
   return 0;
}