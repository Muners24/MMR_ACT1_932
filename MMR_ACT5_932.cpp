/* Mejía Martínez, Ramón    372099                       */
/* 10 de septiembre de 2023                              */
/* Estructuras de control repetitivas y funciones        */
/* MMR_ACT3_932                                          */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 35 //Cantidad de numeros aleatorios, problema 3

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void NumDescendente(void);
void RandParImpar(void);
void RandMayMen (void);
void Mult(void);
//****  main principal  *********
int main()
{
   menu();

	return 0;
}
//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************
int msges()
{ int op;
  system ("CLS");
  printf ("   M  E   N   U \n");
  printf("1.- NUMEROS DESCENTENTE     HASTA N \n");
  printf("2.- NUMEROS ALEATORIOS PARES E IMPARES \n");
  printf("3.- NUMEROS ALEATORIOS MENOR Y MAYOR \n");
  printf("4.- TABLA DE MULTIPLICAR \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
  scanf ("%d",&op);
  return op;
}
//****************
void menu()
{
  int op;
  do{
      op=msges();
      switch (op)
      {
        case 1:
              NumDescendente();
              break;
        case 2:
              RandParImpar();
              break;
        case 3:
              RandMayMen();
              break;
        case 4:
              Mult();
              break;      
        default:
              printf(" ESA OPCION NO ESTA EN EL MENU ");      
      }
      system("cls");
    }while (op != 0);


}

//Muestra los valores hasta n-1 de forma descendente
void NumDescendente(void)
{
    //  VARIALES LOCALES
    int n,i; 
    system ("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf(" NUMEROS DESCEDENTES HASTA N \n\n");
    printf(" INGRESA N: ");
    scanf("%d",&n);

    for(i=n-1;i>0;i--)
    {
        printf(" %d",i);
    }
    printf("\n"); 
    system("PAUSE");
    system("cls");
}

//Genera 40 numeros random entre 0 y 200 y verifica si son par o impar, y los suma
void RandParImpar(void)
{
    int num,npar=0,nimpar=0,sumpar=0,sumimpar=0,i;
    //  VARIALES LOCALES 
    system ("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf(" NUMEROS ALEATORIOS PARES E IMPARES\n\n");
    srand(time(NULL));
    for(i=0;i<40;i++)
    {
        num=rand()%201;
        if(num%2==0)
        {
            printf(" %d ES PAR\n",num);
            npar++;
            sumpar+=num;
        }
        else
        {
            printf(" %d ES IMPAR\n",num);
            nimpar++;
            sumimpar+=num;
        }
    }
    printf("\n HAY %d NUMEROS PARES Y SUMAN: %d\n HAY %d NUMEROS IMPARES Y SUMAN: %d\n",npar,sumpar,nimpar,sumimpar);
     
    system ("PAUSE");
}

//Genera N numeros aleatorios, encuentra el menor y el mayor
void RandMayMen(void)
{
    int i,num,men,may;
    //  VARIALES LOCALES 
    system ("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf(" NUMEROS ALREATORIOS MENOR Y MAYOR\n\n");
    srand(time(NULL));
    num=rand()%(200-100+1)+100;
    may=num;
    men=num;
    for(i=0;i<N-1;i++)
    {
        num=rand()%(200-100+1)+100;
        printf(" %d",num);
        if(num<men)
        {
            men=num;
        }
        if(num>may)
        {
            may=num;
        }
    }
    printf("\n EL NUMERO MAYOR ES: %d\n EL NUMERO MENOR ES: %d\n",may,men);
    system ("PAUSE");
}      

//muestra la tabla de mutiplicar del 1 al 20 de n
void Mult(void)
{
    system("cls");
    int i,num;
    printf(" TABLA DE MUTIPLICAR \n\n");
    printf(" INGRESA EL NUMERO DE LA TABLA: ");
    scanf("%d",&num);

    for(i=1;i<21;i++)
    {
        printf(" %d * %d = %d\n",num,i,num*i);
    }
    printf("\n");
    system("pause");
}