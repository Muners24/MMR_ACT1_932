/* Mejía Martínez, Ramón    372099                 */
/* 26 de agosto de 2023                            */
/* Costo de llamada segun tiempo y tipo de llamada */
/* MMR_ACT1_10_932                                 */

#include <stdio.h>
#include <stdlib.h>

#define IVA 0.16

int main()
{
    int min,tipo;
    float subt,total;

    printf(" Introduce los minutos de la llamada: ");
    scanf("%d",&min);
    printf(" Introduce el tipo de llamada:\n 1) Local\n 2) Nacional\n 3) Internacional\n ");
    scanf("%d",&tipo);

    if(tipo==1)
    {
        subt=min*3;
    }
    else
    {
        if(tipo==2)
        {
            if(min > 3)
            {
                subt=21+(min-3)*2;
            }
            else
            {
                subt=min*7;
            }
        }
        else 
        {       
            if(tipo==3)  
            {
                if(min > 2)
                {
                    subt=18+(min-2)*4;
                }
                else
                {
                    subt=min*9;
                }
            }
        }        
    }
    total=subt+subt*IVA;

    printf(" Subtotal: \t%.2f\n IVA: \t\t%.0f\%\n Total: \t%.2f",subt,IVA*100,total);
    
    return 0;
}