/* Mejía Martínez, Ramón    372099                                    */
/* 22 de agosto de 2023                                               */
/* Manejo de arreglos, lectura, asignacion, concatenacion, mostrar    */
/* MMR_ACT1_1_932                                                     */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STR 30      //Longitud de cadena pra validar
#define M 10        //Dimension de vectores 1,2
#define MM 20       //Dimension de vector 3
#define NM 4        //Dimension de matriz cuadrada

int validarlim(char txt[],int limi,int lims);
int msgs(void);
void menu(void);
int llenaVector(int vect1[]);
int randVector(int vect2[]);
void printVector(int vect[],int m);
int unirVector1_2(int vect1[],int vect2[],int vect3[],int v1,int v2);
int llenaMatriz(int vect1[],int vect2[],int matriz[][NM],int v1,int v2);
void printMatriz(int matriz[][NM],int m1);

int main()
{
    menu();
    return 0;
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
        if(rint<limi || rint>lims)
        {
            printf("Valor invalido, ingresalo de nuevo\n");
        }
    }while(rint<limi || rint>lims);
 
    return rint;
}

int msgs(void)
{
    printf(" Menu\n");
    printf("1) Llenar vector 1 manual\n");
    printf("2) Lenar vector 2 aleatorio\n");
    printf("3) Unir vector 1 y 2\n");
    printf("4) Imprimir vectores \n");
    printf("5) Llenar matriz 4x4\n");
    printf("6) Imprimir matriz\n");
    printf("7) Salir\n");
    return (validarlim("Escoge una opcion: ",1,7));
}

void menu(void)
{
    int op,vect1[M],vect2[M],vect2_2[M],vect3[M],matriz[NM][NM],v1=0,v2=0,v3=0,m1=0;
    do
    {
        system("cls");
        op=msgs();
        switch(op)
        {
            case 1:
                system("cls");
                printf("\nLlenar el vector 1\n");
                printf("\nValores del 30 al 70\n");
                v1=llenaVector(vect1);
                //printVector(vect1,M);
                break;
            case 2:
                v2=randVector(vect2);
                //printVector(vect2,M);
                break;
            case 3:
                system("cls");
                printf("\nUnir vector 1 y 2\n");
                v3=unirVector1_2(vect1,vect2,vect3,v1,v2);
                break;
            case 4:
                system("cls");
                printf("\nMostrar vectores\n");

                if(v1==1)
                {
                    printf("\nVector 1\n");
                    printVector(vect1,M);
                }
                else
                {
                    printf("\nEl vector 1 esta vacio\n");
                }
                if(v2==1)
                {
                    printf("\nVector 2\n");
                    printVector(vect2,M);
                }
                else
                {
                    printf("\nEl vector 2 esta vacio\n");
                }

                if(v3==1)
                {
                    printf("\nVector 3\n");
                    printVector(vect3,MM);
                }
                else
                {
                    printf("\nEl vector 3 esta vacio\n");
                }
                break;
            case 5:
                m1=llenaMatriz(vect1,vect2,matriz,v1,v2);
                break;
            case 6:
                system("cls");
                printf("Mostrar matriz\n\n");
                printMatriz(matriz,m1);
                break;
            case 7:
                printf("\nSaliendo del programa\n");
                break;
        }
        printf("\n");
        system("pause");
    }while(op!=7);
}

int llenaVector(int vect1[])
{
    int i;
    for(i=0;i<M;i++)
    {
        printf("Ingresa el valor de la posicion: %d\n",i+1);
        vect1[i]=validarlim("",30,70);
    }
    return 1;
}

int randVector(int vect2[])
{   
    int i;
    srand(time(NULL));
    for(i=0;i<M;i++)
    {
        vect2[i]=(rand()%20)+1;
    }
    printf("\nSe lleno el vector 2\n");
    return 1;
}

void printVector(int vect[],int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        printf(" %d",vect[i]);
    }
}

int unirVector1_2(int vect1[],int vect2[],int vect3[],int v1,int v2)
{
    int i;
    if(v1==1)
    {
        if(v2==1)
        {
            for(i=0;i<M;i++)
            {
                vect3[i]=vect1[i];
                vect3[i+M]=vect2[i];
            }
            printf("\nSe unieron los vectores\n");
            return 1;
        }
        else
        {
            printf("\nEl vector 2 esta vacio\n");
            return 0;
        }
    }
    else
    {
        printf("\nEl vector 1 esta vacio\n");
        return 0;
    }
}

int llenaMatriz(int vect1[],int vect2[],int matriz[][NM],int v1,int v2)
{
    int j;
    if(v1==1)
    {
        if(v2==1)
        {
            for(j=0;j<NM;j++)
            {
                matriz[0][j]=vect1[j];
                matriz[1][j]=vect1[j+NM];
                if(j<2)
                {
                    matriz[2][j]=vect1[j+NM*2];
                }
                else
                {
                    matriz[2][j]=vect2[j-2];
                }
                matriz[3][j]=vect2[j+2];
            }
            printf("\nLa matriz 4x4 se lleno\n");
            return 1;
        }
        else
        {
            printf("\nEl vector 2 esta vacio\n");
            return 0;
        }
    }
    else
    {
        printf("\nEl vector 1 esta vacio\n");
        return 0;
    }
}

void printMatriz(int matriz[][NM],int m1)
{
    int i,j;
    if(m1==1)
    {
        for(i=0;i<NM;i++)
        {
            for(j=0;j<NM;j++)
            {
                printf(" %4d",matriz[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nLa matriz esta vacia\n");
    }
}