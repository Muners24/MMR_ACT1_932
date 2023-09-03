/* Mejía Martínez, Ramón    372099 */
/* 31 de agosto de 2023            */
/* Conversion de unidades          */
/* MMR_ACT4_2_932                  */

#include <stdio.h>
#include <stdlib.h>

#define E1 2.54     //pulgada  a cm
#define E2 30.48    //pies a cm  
#define E3 1.6093   //millas a km 

int main()
{
    int medida,op;
    float convr;
    printf(" Conversion de unidades \n 1) cm a pulgadas\n 2) cm a pies\n 3) Km a millas\n 4) pulgadas a cm\n 5) pies a cm\n 6) millas a km\n");
    scanf("%d",&op);
    
    printf(" Ingresa la magnitud: ");
    scanf("%d",&medida);
   /*
    if(op==1)
    {
        convr=medida*0.383701;
    }
    else
    {
        if(op==2)
        {
            convr=medida*0.0328084;
        }
        else
        {
            if(op==3)
            {
                convr=medida*0.621371;
            }
            else
            {
                if(op==4)
                {
                    convr=medida*2.54;
                }
                else
                {
                    if(op==5)
                    {
                        convr=medida*30.48;
                    }
                    else
                    {
                        if(op==6)
                        {
                            convr=medida*1.609;
                        }
                        else
                        {
                            printf(" Esta opcion no esta en el menu ");
                            op=0;
                        }
                    }
                }    
            }
        }
    }
    */
    if(op==1)
    {
        convr=medida*1/E1;
    }
    else
    {
        if(op==2)
        {
            convr=medida*1/E2;
        }
        else
        {
            if(op==3)
            {
                convr=medida*1/E3;
            }
            else
            {
                if(op==4)
                {
                    convr=medida*E1;
                }
                else
                {
                    if(op==5)
                    {
                        convr=medida*E2;
                    }
                    else
                    {
                        if(op==6)
                        {
                            convr=medida*E3;
                        }
                        else
                        {
                            printf(" Esta opcion no esta en el menu ");
                            op=0;
                        }
                    }
                }    
            }
        }
    }
    if(op!=0)
    {
        printf(" La conversion es: %.4f",convr);
    }
    return 0;
}