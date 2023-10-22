/* Mejía Martínez, Ramón    372099                                    */
/* 30 de septiembre de 2023                                           */
/* Manejo de arreglos imprecion, asignacion, ordenacion, busqueda     */
/* MMR_ACT9_932                                                     */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "C:\Users\ramon\OneDrive\Escritorio\MMR_ACT1_932\MMRLIB.h"

#define M 15
#define NM 4

int msgs(void);
void menu(void);
void printVectorACT9(int vect[],int n,int v1,char name[]);
void printMatrizACT9(int matriz[][NM],int r, int c,int m1,char name[]);
void searchVectorACT9(int vect[],int n,int v1);

int main()
{
    menu();
    return 0;
}

int msgs(void)
{
    int op;
    printf(" Menu\n\n");
    printf("1) Llenar vector\n");
    printf("2) Llenar matriz\n");
    printf("3) Imrpimir vector\n");
    printf("4) Imprimir matriz\n");
    printf("5) Ordenar vector\n");
    printf("6) Buscar un valor en vector\n");
    printf("7) Salir\n");
    op=validNum("Escoge una opcion: ",1,7);
    return op;
}

void menu(void)
{
    int op;
    //Vecotr y matriz
    int vect[M],matriz[NM][NM];
    //Banderas de llenado
    int v1=0,m1=0;
    //Numero para busqueda en vector, posicion en el vector
    do
    {
        system("cls");
        op=msgs();
        switch(op)
        {
            case 1:
                v1=randVector(vect,M,100,200);
                printf("\nSe lleno el vector aletorio\n");
                break;
            case 2:
                m1=randMatriz(matriz,NM,NM,1,16);
                printf("\nSe lleno la matriz aleatoria\n");
                break;
            case 3:
                printVectorACT9(vect,M,v1,"Vector Aleatorio");
                break;
            case 4:
                printMatrizACT9(matriz,NM,NM,m1,"Matriz Aleatoria");
                break;
            case 5:
                if(v1==1)
                {
                    improvedBubbleSort(vect,M);
                    printf("\nSe ordeno el vector aleatorio\n");
                }
                else
                {
                    printf("\nEl vector esta vacio\n");
                }
                break;
            case 6:
                searchVectorACT9(vect,M,v1);
                break;
        }
        printf("\n");
        system("pause");
    }while(op!=7);
}

void printVectorACT9(int vect[],int n,int v1,char name[])
{
    if(v1==1)
    {   
        printf("\n%s\n\n",name);
        printVector(vect,n);
    }
    else
    {
        printf("\n%s esta vacio",name);
    }
    printf("\n");
}

void printMatrizACT9(int matriz[][NM],int r, int c,int m1,char name[])
{
    if(m1==1)
    {
        printf("\n%s\n\n",name);
        printMatriz(matriz,r,c);
    }
    else
    {
        printf("\n%s esta vacia\n",name);
    }
}

void searchVectorACT9(int vect[],int n,int v1)
{
    int num,pos;
    if(v1==1)
    {
        num=validNum("Ingresa el numero a buscar: ",100,200);
        pos=searchVector(vect,n,num);
        if(pos!=-1)
        {
            printf("\nEl valor %d esta en la posicion %d del vector\n",num,pos);
        }
        else
        {
            printf("\nEl valor %d no esta en el vector\n",num);
        }
    }
    else
    {
        printf("\nEl vector esta vacio\n");
    }
}

