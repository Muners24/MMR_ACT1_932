/* Mejía Martínez, Ramón    372099                                                    */
/* 16 de semptiembre de 2023                                                          */
/* Programa con menu de problemas resueltos con ciclos de distintos tipos y funciones */
/* MMR_ACT6_2_932                                                                     */
/*PARTE 2*/
#include <stdio.h>
#include <stdlib.h>

#define R 4    //Alumnos
#define C 2     //Materias

#define STR 40  //Longitud de cadena para validar 

#define P 700   //Peso embarcacion
#define SP 1.15 //Sobrepeso embarcacion

void menu(void);
int msgs(void);
int validarlim(char txt[],int limi,int lims);
int validar(char txt[]);
void derechoExamen(void);
void TablaMultiplicar(void);
void RangoNum(void);
void pesoTuristas(void);
void RepetirAprobarBaja(void);
float promedio(void);


int main()
{
    menu();

    return 0;
}

void menu(void)
{
    int op;
    do
    { 
        system("cls");
        op=msgs();
        switch(op)
        {
            case 1:
                derechoExamen();
                break;
            case 2:
                TablaMultiplicar();
                break;
            case 3:
                RangoNum();
                break;
            case 4:
                pesoTuristas();
                break;
            case 5:
                RepetirAprobarBaja();
                break;
            case 0:
                printf("Saliendo del programa\n");
                break;
        }
        system("pause");  
    } while (op!=0);
}

int msgs(void)
{
    int op;
    printf(" Menu \n\n");
    printf("1) Derecho a examen\n");
    printf("2) Tablas de multiplicar\n");
    printf("3) Rango de numeros\n");
    printf("4) Embarcacion\n");
    printf("5) Repetir, Aprobar o Baja\n");
    printf("0) Salir\n");
    op=validarlim("Escoge una opcion: ",0,5);
    return op;
}

void derechoExamen(void)
{
    int i,j,alumno,sd=0;
    float prom;
    system("cls");
    printf("Derecho a exmanen\n\n");
    for(i=1;i<=R;i++)
    {
        prom=0;
        for(j=1;j<=C;j++)
        {
            
            printf("Ingresa la calificacion del alumno %d en el parcial %d:",i,j);
            alumno=validarlim(" ",0,100);

            prom+=alumno;
        }
        printf("\n");
        prom/=float(C);
        if(prom<60)
        {
            sd++;
        }
    }
    printf("La cantidad de alumnos sin derecho a examen es: %d\n",sd);   
}

void TablaMultiplicar(void)
{
    int i,j;
    for(i=1;i<=10;i++)
    {   
        system("cls");
        printf("Tablas de multiplicar\n\n");
        printf(" Tabla del %d\n",i);
        for(j=1;j<=10;j++)
        {
            printf(" %d * %d = %d\n",i,j,i*j);
        }
        printf("\n");
        system("pause");
    }    
}

void RangoNum(void)
{
    int inf,sup,num,sum=0,c=0;
    system("cls");
    printf("Rango de numeros\n\n");
    printf("Determinas un intervalo e ingresa numeros, si estan en el intervalo se suman y se calcula su media\n\n");
    inf=validar("Ingresa el limite inferior: ");
    sup=validar("Ingresa el limite inferior: ");

    printf("\n%d) Para deja de ingresar numeros\n",inf-1);
    do
    {   
        printf("Ingresa un numero: ");
        scanf("%d",&num);
        
        if(num>=inf)
        {
            if(num<=sup)
            {
                sum+=num;
                c++;
            }
        }
    }while(num!=inf-1);
    printf("La suma de los numeros dentro del rango es: %d\n",sum);
    printf("La media de los numeros dentro del rango es: %.2f\n",float(sum/c));
}

void pesoTuristas(void)
{
    int band=0,tur=0,op;
    float tpeso=0,peso;
    system("cls");
    printf("Embarcacion\n\n");
    printf("La capacidad de la embarcacion son 10 pasajeros o 700 kilos\n");
    do
    {
        printf("\n1) Agregar pasajero\n");
        printf("0) Salir\n");
        op=validarlim("Escoge una opcion: ",0,1);
        if(op==1)
        {
            tur++;
            printf("Ingresa el peso del pasajero %d: ",tur);
            peso=validarlim("",0,5000);
            tpeso+=peso;
        }
        else
        {
            if(op==0)
            {
                band=1;
            }
        }

        if(tur==10)
        {
            band=1;
            printf("\nLa capacidad de pasajeros llego al limite");
        }
        else
        {
            if(peso>=P)
            {
                band=1;
                printf("\nLa capacidad de peso llego al limite");
            }
        }
    }while(band!=1);

    if(tpeso<=SP*P)
    {
        printf("\nLa embarcacion esta lista para partir\n");
        printf("El promedio del peso de los pasajeros es: %.2f\n\n",float(tpeso/tur));

    }
    else
    {
        printf("\nLa capacidad de sobre peso fue superada, la embarcacion no puede partir\n\n");
    }
}

void RepetirAprobarBaja()
{
    int i,band=0;
    float prom;
    system("cls");
    printf("Repetir, Aprobar o Baja\n\n");

    i=1;
    while(band!=1)
    {
        printf("Oportunidad %d\n\n",i);
        prom=promedio();
        if(prom>=60)
        {
            printf("Aprobado\n\n");
            band=1;
        }
        else
        {
            if(i<3)
            {
                printf("Repetir materia\n\n");
            }
            else
            {
                printf("Baja academica\n\n");
                band=1;
            }
        }
    i++;
    }
}

float promedio(void)
{
    int cal1,cal2,cal3;
    cal1=validarlim("Ingresa la calificacion del parcial 1: ",0,100);
    cal2=validarlim("Ingresa la calificacion del parcial 2: ",0,100);
    cal3=validarlim("Ingresa la calificacion del parcial 3: ",0,100);
    return float((cal1+cal2+cal3)/3); 
}

int validarlim(char txt[],int limi,int lims)
{
    char r[STR];
    int rint,i=0;
    do
    {
        if(i>=1)
        {
            printf("\nEsa respuesta no es valida\nIngresala de nuevo\n");
        }
        printf("%s",txt);
        fflush(stdin);
        gets(r);
        rint=atoi(r);
    i++;
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