/* Mejía Martínez, Ramón    372099       */
/* 26 de agosto de 2023                  */
/* Ordenar 3 numeros en orden ascendente */
/* MMR_ACT1_9_932                        */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[3],c,c2,cm,menor,mayor;

    printf(" Introduce el primer numero: ");
    scanf("%d",&num[0]);
    printf(" Introduce el segundo numero: ");
    scanf("%d",&num[1]);
    printf(" Introduce el tercer numero: ");
    scanf("%d",&num[2]);

    menor = num[0];
    c=0;
    if(num[1] < menor)
    {
        menor = num[1];
        c=1;
    }
    if(num[2] < menor)
    {
        c=2;
    }
    
    mayor = num[0];
    cm=0;
    if(num[1] > mayor)
    {
        mayor = num[1];
        cm=1;
    }
    if(num[2] > mayor)
    {
        cm=2;
    }

    c2=c+cm;
    if(c2==1)
    {
        c2=2;
    }
    else
    {
        if(c2==2)
        {
            c2=1;
        }
        else
        {
            if(c2==3)
            {
                c2=0;
            }
        }
    }
    printf(" Numeros ordenados:\n %d %d %d ",num[c],num[c2],num[cm]);

    return 0;
}