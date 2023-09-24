/* Mejía Martínez, Ramón    372099                          */
/* 19 de semptiembre de 2023                                */
/* Programa para imprimir cadenas de distintas formas       */
/* MMR_ACT7_1_932                                           */

#include <stdio.h>
#include <stdlib.h>

#define STR 40  //Longitud para validar
#define C 30    //Longitud de cadena
void menu(void);
int msgs(void);
int validarlim(char txt[],int limi,int lims);

void cadM(char cad[]);
int cadlen(char cad[]);
void cadcopy(char cad2[],char cad[]);
void cadprint(char cad[]);
void cadvoltear(char cad[]);
void cadprintA_B(char cad[]);
void cadprintPiramide(char cad[]);
void cadprintPiramideR(char cad[]);
void cadSepararVocales(char cad[]);

int main()
{
    menu();
    return 0;
}

void menu(void)
{
    int op;
    char cad[C],cad2[C];
    do
    {
        system("cls");
        printf("Menu\n\nIngresa la cadena: ");
        fflush(stdin);
        gets(cad);
        cadcopy(cad2,cad);
        cadM(cad2);
        op=msgs();
        printf("\n");
        switch(op)
        {
            case 1:
                cadprint(cad2);
                break;
            case 2:
                cadvoltear(cad2);
                cadprint(cad2);
                break;
            case 3:
                cadprintA_B(cad2);
                break;
            case 4:
                cadvoltear(cad2);
                cadprintA_B(cad2);
                break;
            case 5:
                cadprintPiramide(cad2);
                break;
            case 6:
                cadvoltear(cad2);
                cadprintPiramide(cad2);
                break;
            case 7:
                cadprintPiramideR(cad2);
                break;
            case 8:
                cadvoltear(cad2);
                cadprintPiramideR(cad2);
                break;
            case 9:
                cadSepararVocales(cad2);
        }
        printf("\n\n");
        system("pause");
    }while(op!=10);   
}
    
int msgs(void)
{
    int op;
    printf(" Todo pasara a mayusculas\n");
    printf("1) Normal\n");
    printf("2) Voltear\n");
    printf("3) Como arreglo\n");
    printf("4) Como arreglo voletado\n");
    printf("5) Piramide\n");
    printf("6) Piramide al reves\n");
    printf("7) Piramide recorriendo letra\n");
    printf("8) Piramide recorriendo letra al reves\n");
    printf("9) Separar vocales\n");
    printf("10) Salir\n");
    op=validarlim("Escoge una opcion: ",1,10);
    return op;
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

void cadM(char cad[])
{
    int i;
    for(i=0;cad[i]!='\0';i++)
    {
        if(cad[i]>=97)
        {
            if(cad[i]<=122)
            {
                cad[i]-=32;
            }
        }
    }
}

int cadlen(char cad[])
{
    int i=0;
    while(cad[i]!='\0')
    {
        i++;
    }
    i--;
    return i;
}

void cadcopy(char cad2[],char cad[])
{
    int i=0;
    for(i=0;cad[i]!='\0';i++)
    {
        cad2[i]=cad[i];
    }
    cad2[i]='\0';
}

void cadprint(char cad[])
{
    int i;
    for(i=0;cad[i]!='\0';i++)
    {
        printf("%c",cad[i]);
    }
}

void cadvoltear(char cad[])
{
    int i,j,len;
    char cad2[C];
    len=cadlen(cad);
    cadcopy(cad2,cad);
    j=0;
    for(i=len;i>=0;i--)
    {
        cad[j]=cad2[i];
        j++;
    }   
    cad[j]='\0';
}

void cadprintA_B(char cad[])
{
    int i;
    for(i=0;cad[i]!='\0';i++)
    {
        printf("%c\n",cad[i]);
    }
}

void cadprintPiramide(char cad[])
{
    int i,j,len;
    len=cadlen(cad);

    for(i=len;i>=0;i--)
    {
        for(j=0;j<=i;j++)
        {
            printf("%c",cad[j]);
        }
        printf("\n");
    }
}

//Imprime una cadena en forma de piramide recorriendo un caracter
void cadprintPiramideR(char cad[])
{
    int i,j,len,c=0;
    len=cadlen(cad);

    for(i=len;i>=0;i--)
    {
        for(j=c;j<=len;j++)
        {
            printf("%c",cad[j]);
        }
        printf("\n");
        c++;
    }
}

// A 65     E 69    I 73    O 79    U 85
void cadSepararVocales(char cad[])
{
    int i,con=0,voc=0;
    char cadvoc[C],cadcon[C];
    for(i=0;cad[i]!='\0';i++)
    {
        switch(cad[i])
        {
            case 65:
            case 69:
            case 73:
            case 79:
            case 85:
                cadvoc[voc]=cad[i];
                voc++;
                break;
            default:
                cadcon[con]=cad[i];
                con++;
        }
    }
    cadvoc[voc]='\0';
    cadcon[con]='\0';
    cadprint(cadcon);
    printf("\n\n");
    cadprint(cadvoc);
}