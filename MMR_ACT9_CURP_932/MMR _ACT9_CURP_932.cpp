#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "C:\Users\ramon\OneDrive\Escritorio\MMR_ACT1_932\MMRLIB.h"

#define STRING 100

int datos(char name[],int born[],char state[]);
int dayValid(int month,bool leap);
int nameCount(char name1[],char name[]);
int name(char name[],char name1[],char name2[],char lastanem1[],char lastname2[]);
void curp(void);
int main()
{
    curp();
    return 0;
}

int dayValid(int month,bool leap)
{
    int dayLimit;
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dayLimit=31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            dayLimit=30;
            break;
        case 2:
            if(leap==true)
            {
                dayLimit=29;
            }
            else
            {
                dayLimit=28;
            }
            break;
    }
    return dayLimit;
}

int nameCount(char name1[],char name[],int countname)
{//Continuar aqui***************************************************************************************
    int i;
    bool band;
    i=0;
    band=true;
    do
    {
        name1[i]=name[i];
        if(name[i]==' ')
        {
            band=false;
            countname++;
        }
        else
        {
            if(name[i]!='\0')
            {
                band=false;
                return countname;
            }
        }
        i++;
    }while(band);
    
}

int name(char name[],char name1[],char name2[],char name3[],char name4[])
{
    int countname=0;
    
}

int datos(char name[],int born[],char state[])
{
    //born[0]   Dia
    //born[1]   Mes
    //born[2]   Año
    int sex;
    bool leap=false;
    printf("\nIngresa tu nombre: ");
    validStr(name);                 //Leemos y validamos nombre

    born[2]=validNumUnLimit("\nIngresa tu año de nacimiento: ");    //Leemos y validamos año de nacimeitno
    born[1]=validNum("\nIngresa tu mes de nacimiento: ",1,12);      //Leemos y validamos mes de nacimiento
    if(born[1]==2)              //Comprobamos si el mes es febrero
    {   
        if(born[2]%4==0)       
        {
            leap=true;          //El año de nacimiento es bisiesto
        }
    }
    born[0]=validNum("\nIngresa tu dia de nacimiento: ",1,dayValid(born[1],leap));  //Leemos y validamos el dia de nacimiento
    printf("\nIngresa tu estado: ");
    validStr(state);
    sex=validNum("\nIngresa tu sexo\n1) Masculino\n2) Femenino\nElige una opcion: ",1,2);   //Leemos el sexo

    return sex;
}

void curp(void)
{
    //datos
    char curp[18];
    char name[STRING],state[STRING];
    int sex,born[3];
    //Separacion de nombre
    char _1stName[STRING],_2ndName[STRING],_1stLastName[STRING],_2ndLastName[STRING];
    sex=datos(name,born,state);
    
}

