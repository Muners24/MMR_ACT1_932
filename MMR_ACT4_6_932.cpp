/* Mejía Martínez, Ramón    372099                */
/* 31 de agosto de 2023                           */
/* Total a pagar segun metros cubicos consumidos  */
/* MMR_ACT4_6_932                                 */

#include <stdio.h>
#define IVA 0.16

int main()
{
    int m3,subt;
    float total;
    printf(" Ingresa los metros cubicos de agua: ");
    scanf("%d",&m3);
/*
    if(m3>0)
    {
        subt=50;
        if(m3>4)
        {
            if(m3>15)
            {
                subt+=88;
                if(m3>50)
                {
                    subt+=(m3-50)*11+350;
                }
                else
                {
                    subt+=(m3-15)*10;
                }
            }
            else
            {
                subt+=(m3-4)*8;
            }
        }
    }
*/
    if(m3>0)
    {
        subt=50;
        if(m3>15)
        {
            subt+=88;
            if(m3>50)
            {
                subt+=(m3-50)*11+350;
            }
            else
            {
                subt+=(m3-15)*10;
            }
        }
        else
        {
            if(m3>4)
            {
                subt+=(m3-4)*8;
            }
        }
        total=subt*(1+IVA);
        printf(" Subtotal: \t%d\n IVA: \t\t%.0f\%\n Total: \t%.2f\n",subt,IVA*100,total);
    }
    else
    {
        printf(" Este valor de metros cubicos no es valido ");
    }

    return 0;
}