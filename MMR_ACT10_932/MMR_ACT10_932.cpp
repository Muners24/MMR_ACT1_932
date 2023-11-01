/* Mejía Martínez, Ramón    372099                                    */
/* 15 de octubre de 2023                                              */
/* Programa de gestion de alumnos usando structs                      */
/* MMR_ACT10_932                                                      */

#include "C:\Users\ramon\OneDrive\Escritorio\MMR_ACT1_932\MMRLIB.h"
#include "NAMES.h"

#define L 30
#define LN 50
#define STC 500

typedef struct _alum
{
    int status;
    int matricula;
    char apPat[L];
    char apMat[L];
    char nombre[LN];
    int edad;
    int sexo;
}StructAlum;

int msgs(void);
void menu(void);
int buscarAlum(StructAlum alumnos[],int i,int num);
int genMatri(StructAlum alumnos[],int i);
void strConcat(char str2[],char str1[]);
void genH_Name(StructAlum alumnos[],int i);
void genM_Name(StructAlum alumnos[],int i);
void randAlum(StructAlum alumnos[],int i);
void scanAlum(StructAlum alumnos[],int i);
void delAlum(StructAlum alumnos[],int i,int pos);
void ordenarAlum(StructAlum alumnos[],int n);
void printAlum(StructAlum alumnos[],int j);


int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int msgs(void)
{
    int op;
    printf(" MENU\n");
    printf("1) AGREGAR AUTOMATICO\n");
    printf("2) AGREGAR MANUAL\n");
    printf("3) ELIMINAR REGISTRO\n");
    printf("4) BUSCAR\n");
    printf("5) ORDENAR\n");
    printf("6) IMPRIMIR\n");
    printf("7) SALIR\n");
    op=validNum("ESCOGE UNA OPCION: ",1,7);
    return op;
}

void menu(void)
{
    StructAlum alumnos[STC];
    int op;
    int i=0,j;
    int pos,del;
    do
    {   
        system("cls");
        op=msgs();
        system("cls");
        switch(op)
        {
            case 1:
                printf("\nSE GENERARON 10 ALUMNOS\n");
                for(j=0;j<10;j++)
                {
                    randAlum(alumnos,i++);
                }
                break;
            case 2:
                printf("AGREGAR UN ALUMNO\n\n");
                scanAlum(alumnos,i++);
                break;
            case 3:
                printf("ELIMINAR ALUMNO\n\n");
                del=buscarAlum(alumnos,i,validNum("INGRESA LA MATRICULA DEL ALUMNO: ",300000,399999));
                if(del!=-1)
                {
                    printf("\nSE ELIMINO EL ALUMNO: \n");
                    printf("| No  | Status  | Matricula | Apellido Paterno | Apellido Materno | Nombre              | Edad |  Sexo  |\n");
                    printAlum(alumnos,del);
                    delAlum(alumnos,i--,del);
                }
                else
                {
                    printf("\nESE ALUMNO NO EXISTE\n");
                }
                break;
            case 4:
                printf("BUSCAR ALUMNO\n\n");
                pos=buscarAlum(alumnos,i,validNum("INGRESA LA MATRICULA DEL ALUMNO: ",300000,399999));
                if(pos!=-1)
                {
                    printf("| No  | Status  | Matricula | Apellido Paterno | Apellido Materno | Nombre              | Edad |  Sexo  |\n");
                    printAlum(alumnos,pos);
                }
                else
                {
                    printf("\nESE ALUMNO NO EXISTE\n");
                }
                break;
            case 5:
                printf("SE ORDENARON LOS ALUMNOS POR MATRICUAL\n\n");
                switch(i)
                {
                    case 0:
                        printf("\nAUN NO HAY ALUMNOS\n");
                        break;
                    case 1:
                        printf("\nSOLO HAY UN ALUMNO\n");
                        break;
                    default:
                        ordenarAlum(alumnos,i);
                }
                break;
            case 6:
                if(i>0)
                {
                    printf("| No  | Status  | Matricula | Apellido Paterno | Apellido Materno | Nombre              | Edad |  Sexo  |\n");
                    for(j=0;j<i;j++)
                    {
                        printAlum(alumnos,j);
                    }
                }
                else
                {
                    printf("\nAUN NO HAY ALUMNOS\n");
                }
                break;
            case 7:
                printf("\nSALIENDO DEL PROGRAMA\n");
                break;
        }
        system("PAUSE");
    }while(op!=7);
}

int buscarAlum(StructAlum alumnos[],int i,int num)
{
    int j;
    for(j=0;j<i;j++)    //Recorre el vector de alumnos
    {
        if(num==alumnos[j].matricula)   //Compara la matricula buscada con las existentes
        {
            return j;   //Si la encuentra regresa la posicion
        }
    }
    return -1;  //Si no la encontro regresa -1
}

int genMatri(StructAlum alumnos[],int i)
{
    int num;
    do
    {
        num=(rand()%100000)+300000;
    }while(buscarAlum(alumnos,i,num)!=-1);
    return num;
}

void strConcat(char str2[],char str1[])
{
    int j,k=0;
    j=strlen(str2); 
    str2[j++]=' '; 
    while(str1[k]!='\0')    
    {
        str2[j]=str1[k];    
        k++;
        j++;
    }
    str2[j]='\0';  
}

void genH_Name(StructAlum alumnos[],int i)
{
    if(rand()%2)
    {
        strcopy(alumnos[i].nombre,m_name[rand()%28]);   
    }
    else
    {
        strcopy(alumnos[i].nombre,m_name[rand()%28]);   
        strConcat(alumnos[i].nombre,m_name[rand()%28]); 
    }
}

void genM_Name(StructAlum alumnos[],int i)
{
    if(rand()%2)
    {
        strcopy(alumnos[i].nombre,m_name[rand()%28]);   
    }
    else
    {
        strcopy(alumnos[i].nombre,m_name[rand()%28]);   
        strConcat(alumnos[i].nombre,m_name[rand()%28]); 
    }
}

void randAlum(StructAlum alumnos[],int i)
{
    int prob;   
    alumnos[i].status=rand()%2;
    alumnos[i].matricula=genMatri(alumnos,i);
    alumnos[i].sexo=(rand()%2)+1;
    alumnos[i].edad=(rand()%150)+1;
    if(alumnos[i].sexo==1)
    {
        genH_Name(alumnos,i);
    }
    else
    {
        genM_Name(alumnos,i);
    }

    prob=rand()%10;
    switch(prob)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            strcopy(alumnos[i].apPat,ap[rand()%48]);
            strcopy(alumnos[i].apMat,ap[rand()%48]);
            break;
        case 7:
        case 8:
        case 9:
            strcopy(alumnos[i].apPat,ap[rand()%48]);
            strcopy(alumnos[i].apMat,"  ");
            break;
    }
}

void scanAlum(StructAlum alumnos[],int i)
{
    int matri,validmatri;
    alumnos[i].status=validNum("Ingresa su status (0 o 1): ",0,1);
    do
    {
        matri=validNum("Ingresa su matricula: ",300000,399999);
        validmatri=buscarAlum(alumnos,i,matri);
        if(validmatri!=-1)
        {
            printf("\nEsa matricula ya existe\n");
        }
    }while(validmatri!=-1);
    alumnos[i].matricula=matri;
    printf("\nIngresa su apellido paterno: ");
    matri=validStr(alumnos[i].apPat);
    strM(alumnos[i].apPat);
    printf("\nIngresa su apellido materno: ");
    matri=validStr(alumnos[i].apMat);
    strM(alumnos[i].apMat);
    printf("\nIngresa su nombre: ");
    matri=validStr(alumnos[i].nombre);
    strM(alumnos[i].nombre);
    alumnos[i].edad=validNum("\nIngresa su edad ",1,150);
    alumnos[i].sexo=validNum("\nIngresa su sexo\n1) Hombre\n2) Mujer\nEscoge una opcion: ",1,2);
}

void delAlum(StructAlum alumnos[],int i,int pos)
{
    int j;
    for(j=pos;j<i;j++)     //Recorre las posiciones de los alumnos
    {
        alumnos[j]=alumnos[j+1];   //La posición del alumno actual es remplazada por el siguiente alumno
    }
}

void printAlum(StructAlum alumnos[],int j)
{
    printf("| %3d |    %d    | %9d | %-16s | %-17s| %-19s | %4d |",j+1,alumnos[j].status,alumnos[j].matricula,alumnos[j].apPat,alumnos[j].apMat,alumnos[j].nombre,alumnos[j].edad);
    if(alumnos[j].sexo==1)
    {
        printf(" HOMBRE |\n");
    }
    else
    {
        printf(" MUJER  |\n");
    }
}

void ordenarAlum(StructAlum alumnos[],int n)
{
    int i,j,swap;   
    StructAlum temp;   //guarda la posicion del alumno para intercambiarla con otro
    for(i=0;i<n-1;i++)
    {
        swap=0; //Se asigna 0 a la bandera de intercambios
        for(j=0;j<n-i-1;j++)
        {
            if(alumnos[j].matricula>alumnos[j+1].matricula) //Si la matricula siguiente es menor a la actual se intercambian
            {
                temp=alumnos[j];    //guarda los datos del alumno actual
                alumnos[j]=alumnos[j+1];    //asigna los datos del siguiente alumno al actual
                alumnos[j+1]=temp;  //asgina los datos guardados del primer alumno al segundo alumno alumno
                swap=1; //asigna 1 a la bandera de intercambios
            }
        }
        if (swap==0)    
        {
            i=n;    //Si no se hicieron intercambios i se iguala a n para que termine el ciclo
        }
    }
}