/* Mejía Martínez, Ramón    372099                                                    */
/* 12 de semptiembre de 2023                                                          */
/*  Serie Fibonacci, Factorial, y numero de digitos con cada tipo de ciclo repetitivo */
/* MMR_ACT6_1_932                                                                     */
/*PARTE 1*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR 30  //Longitud de cadena para validar
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
int msgesciclos(void);
int validarlim(char txt[],int limi,int lims);
int validar(char txt[]);

void Fibonacci(void);
void menufib(void);
void forFibonacci(void);
void whileFibonacci(void);
void doFibonacci(void);

void Factorial(void);
void menuFactorial(void);
void forFactorial(void);
void whileFactorial(void);
void doFactorial(void);

void Digitos(void);
void menuDigitos(void);
void forDigitos(void);
void whileDigitos(void);
void doDigitos(void);
//****  main   *********
int main()
{
    menu();

    return 0;
}
//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************
int msges(void)
{
    int op;
    system("CLS");
    printf("   M  E   N   U \n");
    printf("1.- FIBONACCI \n");
    printf("2.- FACTORIAL \n");
    printf("3.- DIGITOS \n");
    printf("0.- SALIR  \n");
    op=validarlim("ESCOGE UNA OPCION: ",0,3);
    return op;
}
int msgesciclos(void)
{
    int op;
    printf("1) FOR\n");
    printf("2) WHILE\n");
    printf("3) DOWHILE\n");
    op=validarlim("ESCOGE UNA OPCION: ",1,3);
    return op;
}
//****************
void menu()
{
    int op;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            Fibonacci();
            break;
        case 2:
            Factorial();
            break;
        case 3:
            Digitos();
            break;
        }

    } while (op != 0);
}

int validarlim(char txt[],int limi,int lims)
{
    char r[STR];
    int rint;
    do
    {
        printf("%s",txt);
        fflush(stdin);
        gets(r);
        rint=atoi(r);
    }while(rint<limi || rint>lims);
    return rint;
}
int validar(char txt[])
{
    char r[STR];
    int rint;
    printf("%s",txt);
    fflush(stdin);
    gets(r);
    rint=atoi(r);
    return rint;
}
//*********************
void Fibonacci(void)
{   
    system("cls");
    printf(" FIBONACCI\n\n");
    menufib();
    printf("\n");
    system("PAUSE");
}
void menufib(void)
{
    int ciclo;
    ciclo=msgesciclos();

    switch(ciclo)
    {
        case 1:
            forFibonacci();
            break;
        case 2:
            whileFibonacci();
            break;
        case 3:    
            doFibonacci();
            break;   
    }
}


void forFibonacci(void)
{
    //  VARIALES LOCALES
    int i,a=-1,s=1,r,num;
    //  AQUI DESARROLLO PROGRAMA
    num=validarlim("HASTA QUE TERMINO QUIERES DESPLEGAR: ",1,5000);
    for(i=0;i<num;i++)
    {
        r=a+s;
        printf(" %d",r);
        a=s;
        s=r;
    }
    printf("\n");
}


void whileFibonacci(void)
{
    //  VARIALES LOCALES
    int i,a=-1,s=1,r,num;
    //  AQUI DESARROLLO PROGRAMA
    num=validarlim("HASTA QUE TERMINO QUIERES DESPLEGAR: ",1,5000);
    i=0;
    while(i<num)
    {
        r=a+s;
        printf(" %d",r);
        a=s;
        s=r;
    i++;    
    }
    printf("\n");

}


void doFibonacci(void)
{
    //  VARIALES LOCALES
    int i,a=-1,s=1,r,num;
    //  AQUI DESARROLLO PROGRAMA
    num=validarlim("HASTA QUE TERMINO QUIERES DESPLEGAR: ",1,5000);
    i=0;
    do
    {
        r=a+s;
        printf(" %d",r);
        a=s;
        s=r;
    i++;  
    }while(i<num);
    printf("\n");
}
//*************************
void Factorial(void)
{
    system("cls");
    printf(" FACTORIAL\n\n");
    menuFactorial();
    system("PAUSE");
}

void menuFactorial(void)
{
    int ciclo;
    ciclo=msgesciclos();

    switch(ciclo)
    {
        case 1:
            forFactorial();
            break;
        case 2:
            whileFactorial();
            break;
        case 3:    
            doFactorial();
            break;  
    }
}

void forFactorial(void)
{
     //  VARIALES LOCALES
    int i,num,fact=1;
    //  AQUI DESARROLLO PROGRAMA
    num=validarlim("FACTORIAL DEL NUMERO: ",0,12);
    //for
    for (i = 2; i <= num; i++)
    { 
        fact*=i;
    }
    printf("EL FACTORIAL DE %d ES: %d\n\n",num,fact);
}


void whileFactorial(void)
{
    //  VARIALES LOCALES
    int i, num,fact=1;
    //  AQUI DESARROLLO PROGRAMA
    num=validarlim("FACTORIAL DEL NUMERO: ",0,12);
    i=2;
    fact=1;
    while(i<=num)
    {
        fact*=i;
    i++;    
    }
    printf("EL FACTORIAL DE %d ES: %d\n\n",num,fact);
}
void doFactorial(void)
{
    //  VARIALES LOCALES
    int i, num,fact=1;
    //  AQUI DESARROLLO PROGRAMA
    num=validarlim("FACTORIAL DEL NUMERO: ",0,12);
    fact=1;
    i=1;
    do
    {
            fact*=i;
    i++;
    }while(i<=num);
    printf("EL FACTORIAL DE %d ES: %d\n\n",num,fact);
}
//****************************
void Digitos(void)
{
    system("CLS");
    printf(" DIGITOS\n");
    menuDigitos();

    system("PAUSE");
}
void menuDigitos(void)
{
    int ciclo;
    ciclo=msgesciclos();

    switch(ciclo)
    {
        case 1:
            forDigitos();
            break;
        case 2:
            whileDigitos();
            break;
        case 3:    
            doDigitos();
            break;
        default:
            printf("ESE CICLO NO ESTA EN EL MENU\n");    
    }
}

void forDigitos(void)
{
    //  VARIALES LOCALES
    int i,num,aux;
    //  AQUI DESARROLLO PROGRAMA
    num=validar("INGRESA UN NUMERO: ");
    aux=num;
    for(i=0;aux!=0;i++)
    {
        aux/=10;
    }
    printf("EL NUMERO %d TIENE %d DIGITOS\n\n",num,i);
}
void whileDigitos(void)
{
    //  VARIALES LOCALES
    int num,aux,nd=0;
    //  AQUI DESARROLLO PROGRAMA
    num=validar("INGRESA UN NUMERO: ");
    aux=num;
    
    while(aux!=0)
    {
        aux/=10;
        nd++;
    }
    printf("EL NUMERO %d TIENE %d DIGITOS\n\n",num,nd);    
}
void doDigitos(void)
{
    //  VARIALES LOCALES
    int num,aux,nd=0;
    //  AQUI DESARROLLO PROGRAMA
    num=validar("INGRESA UN NUMERO: ");
    aux=num;
    do
    {
        aux/=10;
        nd++;
    }while(aux!=0);
    printf("EL NUMERO %d TIENE %d DIGITOS\n\n",num,nd);
}