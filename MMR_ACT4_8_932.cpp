/* Mejía Martínez, Ramón    372099            */
/* 31 de agosto de 2023                       */
/* Pedra papel y tijera vs la computadora     */
/* MMR_ACT4_8_932                             */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int ptj,num;
    srand(time(NULL));
    num=rand()%(3-1+1)+1;
    printf(" Ingresa tu jugada: \n 1) Piedra\n 2) Papel\n 3) Tijeras\n ");
    scanf("%d",&ptj);
    printf(" Jugada de la computadora: %d\n",num);
    if(ptj!=num)
    {
        if(ptj==1)
        {
            if(num==2)
            {
                printf("\n** Perdiste **\n Papel cubre piedra");
            }
            else
            {
                printf("\n** Ganaste **\n Piedra rompe tijeras");
            }
        }
        else
        {
                    
            if(ptj==2)
            {
                if(num==1)
                {
                    printf("\n** Ganaste **\n Papel cubre piedra");
                }
                else
                {
                    printf("\n** Perdiste **\n Tijeras cortan papel");
                }
            }
            else
            {
                if(ptj==3)
                {
                    if(num==1)
                    {
                        printf("\n** Perdiste **\n Piedra rompe tijeras");
                    }
                    else
                    {
                        printf("\n** Ganaste **\n Tijeras cortan papel");
                    }
                }
            }
        }
    }
    else
    {
        printf(" Empate ");
    }
    
    return 0;
}