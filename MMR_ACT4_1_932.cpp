/* Mejía Martínez, Ramón    372099       */
/* 29 de agosto de 2023                  */
/* Calculadora de operaciones basicas    */
/* MMR_ACT4_1_932                        */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,op;
    float res;

    printf(" Calculadora \n ¿Que operacion quieres hacer?\n 1) Suma\n 2) Resta\n 3) Multiplicacion\n 4) Division\n ");
    scanf("%d",&op);
    printf(" Ingresa el primer numero: ");
    scanf("%d",&num1);
    printf(" Ingresa el segundo numero: ");
    scanf("%d",&num2);
    /*
    if(op==1)
    {
        res=num1+num2;
    }
    else
    {
        if(op==2)
        {
            res=num1-num2;
        }
        else
        {
            if(op==3)
            {
                res=num1*num2;
            }
            else
            {
                if(op==4)
                {
                    res=num1/num2;
                }
                else
                {
                    printf(" Esa operacion no esta en el menu ");
                    op=0;
                }
            }
        }
    }
    */

   /*
    if(op>0)
    {
        if(op>1)
        {
            if(op>2)
            {
                if(op>3)
                {
                    if(op>4)
                    {
                        printf(" Esta operacion no es valida ");
                        op=0;
                    }
                    else
                    {
                        res=num1/num2;
                    }
                }
                else
                {
                    res=num1*num2;
                }
            }
            else
            {
                res=num1-num2;
            }
        }
        else
        {
            res=num1+num2;
        }
    }
    else
    {
        printf(" Esta operacion no es valida ");
        op=0;
    }
    */

    if(op>2)
    {
        if(op>3)
        {
            if(op>4)
            {
                printf(" Esta operacion no es valida ");
                op=0;
            }
            else
            {
                res=num1/num2;
            }
        }
        else
        {
            res=num1*num2;
        }
    }
    else
    {
        if(op>0)
        {
            if(op>1)
            {
                res=num1-num2;
            }
            else
            {
                res=num1+num2;
            }
        }
        else
        {
            printf(" Esta operacion no es valida ");
            op=0;
        }
    }

    if(op!=0)
    {
        printf(" El resultado de la operacion es: %.2f",res);
    }
    return 0;
}