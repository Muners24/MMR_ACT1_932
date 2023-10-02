/* Mejía Martínez, Ramón    372099            */
/* 31 de agosto de 2023                       */
/* Pedra papel y tijera vs la computadora     */
/* MMR_ACT4_9_932                             */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int ptj,num;
    srand(time(NULL));
    num=rand()%(3-1+1)+1;
    printf(" Ingresa tu jugada: \n 1) Piedra\n 2) Papel\n 3) Tijeras\n ");
    scanf("%d",&ptj);
    printf(" Jugada de la computadora: %d\n\n",num);

    /*
    aux=pow(ptj,num);

    if(aux!=1)
    {
        switch(aux)
        {
            case 2:
                printf(" Perdiste, papel cubre piedra ");
            break;

            case 4:
            case 27:
                printf(" Empate ");
            break;

            case 8:
                printf(" Perdiste, tijeras cortan papel ");
            break;

            case 3:
                printf(" Ganaste, piedra rompe tijeras ");
            break;

            case 9:
                printf(" Ganaste, tijeras cortan papel ");
            break;

            default:
                printf(" Tu eleccion no es valida ");
            break;
        }
    }

    if(aux==1)
    {
        switch(ptj)
        {
            case 1:
                printf(" Empate ");
            break;

            case 2:
                printf(" Perdiste, papel cubre piedra");
            break;

            case 3:
                printf(" Ganaste, piedra rompe tijeras ");
            break;

            default:
                printf(" Tu eleccion no es valida ");
            break;
        }
    }
    */
    if(ptj!=num)
    {
        switch(ptj)
        {
            case 1:
                switch(num)
                {
                    case 2:
                        printf(" Perdiste \n Papel cubre piedra");
                    break;

                    case 3:
                        printf(" Ganaste \n Piedra rompe tijeras");
                    break;

                    default:
                    break;
                }
            break;

            case 2:
                switch(num)
                {
                    case 1:
                        printf(" Ganaste \n Papel cubre piedra");
                    break;

                    case 3:
                        printf(" Perdiste \n Tijeras cortan papel");
                    break;

                    default:
                    break;
                }
            break;

            case 3:
                switch(num)
                {
                    case 1:
                        printf(" Perdiste \n Piedra rompe tijeras");
                    break;

                    case 2:
                        printf(" Ganaste \n Tijeras cortan papel");
                    break;
                    
                    default:
                    break;
                }
            break;

            default:
            break;

        } 
    }
    else
    {
        printf(" Empate ");
    }    
    return 0;
}