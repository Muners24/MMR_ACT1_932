/* Mejía Martínez, Ramón    372099                          */
/* 21 de semptiembre de 2023                                */
/* Programa para imprimir cadenas de distintas formas       */
/* MMR_ACT7_2_932                                           */

#include <stdio.h>
#include <stdlib.h>

#define STR 30  //Longitud para validar numeros
#define C 30    //Longitud de cadena
void menu(void);
int msgs(void);
int validarlim(char txt[],int limi,int lims);

void cadcopy(char cad2[],char cad[]);
void cadprint(char cad[]);

void cadM(char cad[]);
void cadm(char cad[]);
void cadCap(char cad[]);
int cadlen(char cad[]);
void cadvoltear(char cad[]);
void cadNoEspacios(char cad[]);
int cadvalidar(char cad[]);
void cad8(char cad[]);
void cadplaindormo(char cad[]);

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
        op=msgs();
        if(op!=7)
        {
            while(cadvalidar(cad))
            {
            }
            cadcopy(cad2,cad);
        }
        switch(op)
        {
            case 1:
                cadM(cad2);
                printf("\nMayusculas\n");
                cadprint(cad2);
                break;
            case 2:
                cadm(cad2);
                printf("\nMinusculas\n");
                cadprint(cad2);
                break;
            case 3:
                cadCap(cad2);
                printf("\nCapital\n");
                cadprint(cad2);
                break;
            case 4:
                printf("\n La cadena \"");
                cadprint(cad2);
                printf("\" tiene %d caracteres\n",cadlen(cad2));
                break;
            case 5:
                cadvoltear(cad2);
                printf("\nAl reves\n");
                cadprint(cad2);
                break;
            case 6:
                cadNoEspacios(cad2);
                printf("\nSin espacios\n");
                cadprint(cad2);
                break;
            case 7:
                if(cadvalidar(cad2)==0)
                {
                    cadprint(cad2);
                }
                break;
            case 8:
                cad8(cad2);
                break;
            case 9:
                cadplaindormo(cad2);
        }
        printf("\n");
        system("pause");
    }while(op!=10);
}

int msgs(void)
{   
    int op;
    printf(" Menu\n\n");
    printf("1) Mayusculas\n");
    printf("2) Minusculas\n");
    printf("3) Capital\n");
    printf("4) Cantidad de caracteres\n");
    printf("5) Cadena al reves\n");
    printf("6) Cadena sin espacios\n");
    printf("7) Leer cadena A-Z y espacio\n");
    printf("8) Mayusculas, minusculas, capital, sin espacios, al reves\n");
    printf("9) Palindromo\n");
    printf("10) Salir");
    op=validarlim("Escoge una opcion: ",1,10);
    return op;
}

int validarlim(char txt[],int limi,int lims)
{
    char r[STR];
    int rint;
    do
    {
        printf("\n%s",txt);
        fflush(stdin); 
        gets(r);
        rint=atoi(r);
 
    }while(rint<limi || rint>lims);
    return rint;
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

void cadm(char cad[])
{
    int i;
    for(i=0;cad[i]!='\0';i++)
    {
        if(cad[i]>=65)
        {
            if(cad[i]<=90)
            {
                cad[i]+=32;
            }
        }
    }
}

void cadCap(char cad[])
{
    int i=0;
    if(cad[i]>=97)
    {
        if(cad[i]<=122)
        {
            {
                cad[i]-=32;
            }
        }
    }
    for(i=1;cad[i]!='\0';i++)
    {
        if(cad[i]==' ')
        {
            if(cad[i+1]>=97)
            {
                if(cad[i+1]<=122)
                {
                    cad[i+1]-=32;
                }
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
    return i;
}

void cadvoltear(char cad[])
{
    int i,j,len;
    char cad2[C];
    len=cadlen(cad);
    len--;
    cadcopy(cad2,cad);
    j=0;
    for(i=len;i>=0;i--)
    {
        cad[j]=cad2[i];
        j++;
    }   
    cad[j]='\0';
}

void cadNoEspacios(char cad[])
{
    int i,j;
    char cad2[C];

    for(i=0;cad[i]!='\0';i++)
    {
        cadcopy(cad2,cad);
        if(cad[i]==' ')
        {
            for(j=i;cad[j]!='\0';j++)
            {
                cad[j]=cad2[j+1];
            }
        }
    }
}

int cadvalidar(char cad[])
{
    int i=0,invalido=0;
    printf("Ingresa la cadena: ");
    fflush(stdin);
    gets(cad);
    do
    {
        if(cad[i]>90)
        {
            if(cad[i]<97)
            {
                printf("\nEl simbolo %c no es valido \n",cad[i]);
                invalido++;
            }
        }
        else
        {
            if(cad[i]>122)
            {
                printf("\nEl simbolo %c no es valido \n",cad[i]);
                invalido++;
            }
            else
            {
                if(cad[i]<65)
                {
                    if(cad[i]==' ')
                    {
                        if(i==0)
                        {
                            printf("\nLa cadena no debe empezar con espacio\n");
                            invalido++;
                        }
                        else
                        {
                            if(cad[i-1]==' ')
                            {
                                printf("\nLa cadena no debe llevar dos espacios seguidos\n");
                                invalido++;
                            }
                        }
                    }
                    else
                    {
                        if(cad[i]=='\0')
                        {
                            if(cad[i-1]==' ')
                            {
                                printf("\nLa cadena no debe terminar en espacio\n");
                                invalido++;
                            }
                        }
                        else
                        {
                            printf("\nEl simbolo %c no es valido \n",cad[i]);
                            invalido++;
                        }
                    }
                }
            }
        }
        i++;
    }while(cad[i-1]!='\0');
    return invalido;
}

void cad8(char cad[])
{
    char cad2[C];
    printf("\nMayusculas\n");
    cadcopy(cad2,cad);
    cadM(cad2);
    cadprint(cad2);

    printf("\n\nMinusculas\n");
    cadcopy(cad2,cad);
    cadm(cad2);
    cadprint(cad2);

    printf("\n\nCapital\n");
    cadcopy(cad2,cad);
    cadCap(cad2);
    cadprint(cad2);

    printf("\n\nSin espacios\n");
    cadcopy(cad2,cad);
    cadNoEspacios(cad2);
    cadprint(cad2);

    printf("\n\nAl reves\n\n");
    cadcopy(cad2,cad);
    cadvoltear(cad2);
    cadprint(cad2);
}

void cadplaindormo(char cad[])
{
    int i,j,palindromo=0;
    j=cadlen(cad);
    j--;
    for(i=0;cad[i]!='\0';i++)
    {
        if(cad[i]==cad[j])
        {
            palindromo++;
        }
        j--;
    }
    if(palindromo==i)
    {
        printf("\nLa cadena ");
        cadprint(cad);
        printf(" es un palindromo \n");
    }
    else
    {
        printf("\nLa cadena ");
        cadprint(cad);
        printf(" no es un palindromo \n");
    }
}