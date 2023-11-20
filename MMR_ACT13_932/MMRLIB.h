#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define NM 4
#define STR 100

#define L 30
#define LN 50

//** Structs    ******************************************************************************************************


typedef int Tkey;

typedef struct _empleado{
    Tkey key;
    int NoEmpleado;
    char nombre[LN];
    char apPat[L];
    char apMat[L];
    char sexo;
    int status;
    char puesto[L];
    double telefono;
}Tdato;

//** Validacion ***************************************************************************************************

//Valida un numero entero
//Parametros:
//-txt  Cadena a mostrar antes de leer la varia
//-limi Limite inferior aceptado
//-lims Limite superior aceptado
int validNum(char txt[],int limi,int lims);

//Valida una cadena
//Parametros:
//-str  Cadena a validar
//Devuelve:
//-invalido     Numero de errores
//Solo permite letras
//No permite empezar ni terminar con espacios
//No permite dobles pesacios
//Muestra los errores
int validStr(char str[]);

//** Cadenas ******************************************************************************************************

//Concatena una cadena con otra
//Parametros:
//-str2 Cadena donde se juntaran las cadenas
//-str1 Cadena que se juntara a la anterior
void strConcat(char str2[],char str1[]);

//Convierte una cadena a mayusculas
//Parametros:
//-str  Cadena a convertir a mayusculas
void strM(char str[]);

//Convierte una cadena a minusculas
//Paramestros:
//-str  Cadena a convertir a minusculas
void strm(char str[]);

//Regresa la longitud de la cadena
//Parametros:
//-str  Cadena de la que se quiere saber su longitud
int strlen(char str[]);

//Imprime una cadena
//Parametros:
//-str  Cadena que se quiere imprimir
void strprint(char str[]);

//Copia la cadena en la cadena 2
//Parametros:
//-str  Cadena original
//-str2 Cadena que en la que se copiara str
void strcopy(char str2[],char str[]);

//Valida un numero entero
//Parametros:
//-txt Texto a mostrar al leer el numero
//Devuelve:
//Numero validado
//No requiere un limite para funcionar
int validNumUnLimit(char txt[]);

//** Arreglos *******************************************************************************************************

//** Asignacion **
//Regresan 1, indica que se lleno

//LLena un vector
//Parametros:
//-vect     Vector a llenar
//-n        Tamaño
//-limi     Limite inferior aceptable     
//-lims     Limite superior aceptable
int scanVector(int vect[],int n,int limi,int lims);

//Llena un vector con numeros aleatorios sin repetir
//Parametros:
//-vect     Vector a llenar
//-n        Tamaño
//-ri       Rango inicial
//-rf       Rango final  
int randVector(int vect[],int n,int ri,int rf);

//LLena una matriz
//Parametros:
//-matriz   Matriz a llenar
//-r        Numero de renglones
//-c        Numero de columnas
//-limi     Limite inferior aceptable
//-lims     Limte superior aceptable
int scanMatriz(int matriz[][NM],int r,int c,int limi,int lims);

//Llena una matriz con numeros aleatorios sin repetir
//Parametros:
//-matriz   Matriz a llenar
//-r        Numero de renglones
//-c        Numero de columnas
//-ri       Rango inicial
//-rf       Rango final  
int randMatriz(int matriz[][NM],int r,int c,int ri,int rf);

//Imprimir vector
//Parametros:
//-vect     Vector a imprimir
//-n        Tamaño        
void printVector(int vect[],int n);

//Imprimir matriz
//Parametros:
//-matriz   Matriz a imprimir
//-r        Numero de renglones
//-c        Numero de columnas
void printMatriz(int matriz[][NM],int r,int c);

//Busca un valor en el vector
//Parametros:
//-vect     Vector en el que se buscara
//-n        Tamaño
//-num      Numero a buscar
//Devuelve:
//Posicion si encontro el numero
//-1 Si no encontro el numero
int searchVector(int vect[],int n,int num);

//Busca un valor en una matriz
//Parametros:
//-matriz   Matriz en la que se buscara
//-pos      Guarda la posicion en i y j
//-r        Numero de renglones
//-c        Numero de columnas
//-num      Numero a buscar
//Devuelve:
//Renglon en que se encontro el numero
//-1 Si no encontro el numero
int searchMatriz(int matriz[][NM],int pos[],int r,int c, int num);

//** Metodos de ordenacion ***************************************************************************************

void improvedBubbleSort(int vect[],int n);

//** Manejo de structs **********************************************************************************************

//** Ordenar structs

//Ordena un vector de structs
//Parametros:
//-vect     El vector a ordenar
//-izq      Debe recibir un 0
//-derch    Debe recibir n-1, n=tamaño
//No devuelve nada
void mergeSortT(Tdato vect[],int izq,int derch);
void fusionMergeSortT(Tdato vect[],int izq,int medio,int derch);

//Ordena un vector de structs
//Parametros:
//-n Tamaño del vector
//No devuelve nada
void heapSortT(Tdato vect[], int n);
void swapT(Tdato *x,Tdato *y);
void adjustHeapT(Tdato vect[],int n,int raiz);

//** Buscar structs

//Busca por campo key un registro del vector
//El vector debe estar ordenado
//Parametros:
//-vect     Vector de registros
//-i        Numero de registros ocupados
//-num      Numero de key que se desea buscar
//Retorno:
//-i        Posicion si se encontro
//-1        Si no se encontro
int buscarTBin(Tdato vect[],int i,int num);

//Busca por campo key un registro del vector
//Parametros:
//-vect     Vector de registros
//-i        Numero de registros ocupados
//-num      Numero de key que se desea buscar
//Retorno:
//-i        Posicion si se encontro
//-1        Si no se encontro
int buscarTSec(Tdato vect[],int i,int num);

//** Generación automatica

//Genera un campo key sin repetir aleatoriamente
//Parametros:
//-vect     Vector de registros
//-i        Numero de registros ocupados
//-ri       Rango inicial
//-rf       Rango final
//Retorno:
//Matricula generada
int genKey(Tdato vect[],int i,int ri,int rf);

//Genera un nombre de hombre aleatoriamente
//Parametros:
//-vect     Vector de registros
//-i        Numero de registros ocupados
//No retorna nigun valor
void genH_Name(Tdato vect[],int i);

//Genera un nombre de mujer aleatoriamente
//Parametros:
//-vect     Vector de registros
//-i        Numero de registros ocupados
//No retorna nigun valor
void genM_Name(Tdato vect[],int i);

//Genera un apellido aleatoriamente
//Parametros:
//-vect     Vector de registros
//-i        Numero de registros ocupados
//No retorna nigun valor
void genAp(Tdato vect[],int i);

int validNum(char txt[],int limi,int lims)
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

int validStr(char str[])
{
    int i=0,invalido=0;
    fflush(stdin);
    gets(str);
    do
    {
        if(str[i]>90)
        {
            if(str[i]<97)
            {
                printf("\nEl simbolo %c no es valido \n",str[i]);
                invalido++;
            }
        }
        else
        {
            if(str[i]>122)
            {
                printf("\nEl simbolo %c no es valido \n",str[i]);
                invalido++;
            }
            else
            {
                if(str[i]<65)
                {
                    if(str[i]==' ')
                    {
                        if(i==0)
                        {
                            printf("\nLa cadena no debe empezar con espacio\n");
                            invalido++;
                        }
                        else
                        {
                            if(str[i-1]==' ')
                            {
                                printf("\nLa cadena no debe llevar dos espacios seguidos\n");
                                invalido++;
                            }
                        }
                    }
                    else
                    {
                        if(str[i]=='\0')
                        {
                            if(str[i-1]==' ')
                            {
                                printf("\nLa cadena no debe terminar en espacio\n");
                                invalido++;
                            }
                        }
                        else
                        {
                            printf("\nEl simbolo %c no es valido \n",str[i]);
                            invalido++;
                        }
                    }
                }
            }
        }
        i++;
    }while(str[i-1]!='\0');
    return invalido;
}

int validNumUnLimit(char txt[])
{
    char r[STR];
    int rint;
    printf("%s",txt);
    fflush(stdin);
    gets(r);
    rint=atoi(r);
    return rint;
}

void strM(char str[])
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>=97)
        {
            if(str[i]<=122)
            {
                str[i]-=32;
            }
        }
    }
}

void strm(char str[])
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>=65)
        {
            if(str[i]<=90)
            {
                str[i]+=32;
            }
        }
    }
}

int strlen(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        i++;
    }
    return i;
}

void strprint(char str[])
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        printf("%c",str[i]);
    }
}

void strcopy(char str2[],char str[])
{
    int i=0;
    for(i=0;str[i]!='\0';i++)
    {
        str2[i]=str[i];
    }
    str2[i]='\0';
}

int scanVector(int vect[],int n,int limi,int lims)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Ingresa el valor de la posicion: %d\n",i+1);
        vect[i]=validNum("",limi,lims);
    }
    return 1;
}

int randVector(int vect[],int n,int ri,int rf)
{
    int i,num,range;
    srand(time(NULL));
    range=(rf-ri)+1;
    for(i=0;i<n;i++)
    {
        do
        {
            num=(rand()%range)+ri;
        }while(searchVector(vect,n,num)!=-1);
        vect[i]=num;
    }
    return 1;
}

int scanMatriz(int matriz[][NM],int r,int c,int limi,int lims)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("Ingresa el valor de la posicion: [%d][%d]\n",i+1,j+1);
            matriz[i][j]=validNum("",limi,lims);
        }
    }
    return 1;
}

int randMatriz(int matriz[][NM],int r,int c,int ri,int rf)
{
    int i,j,k;
    int n;
    n=r*c;
    int vect[n];
    randVector(vect,n,ri,rf);
    k=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<r;j++)
        {
            matriz[i][j]=vect[k];
            k++;
        }    
    }
    return 1;
}

void printVector(int vect[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",vect[i]);
    }
}

void printMatriz(int matriz[][NM],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%4d ",matriz[i][j]);
        }
        printf("\n");
    }
}

int searchVector(int vect[],int n,int num)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(vect[i]==num)
        {
            return i;
        }
    }
    return -1;
}

int searchMatriz(int matriz[][NM],int pos[],int r,int c,int num)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(matriz[i][j]==num)
            {
                pos[0]=i;
                pos[1]=j;
                return i;
            }
        }
    }
    return -1;
}

void improvedBubbleSort(int vect[],int n)
{
    int i,j;
    int temp,swap;
    for(i=0;i<n-1;i++)
    {
        swap=0; 
        for(j=0;j<n-i-1;j++)
        {
            if(vect[j]>vect[j+1])
            {
                temp=vect[j];
                vect[j]=vect[j+1];
                vect[j+1]=temp;
                swap=1;
            }
        }
        if (swap==0)
        {
            i=n;
        }
    }
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

void mergeSortT(Tdato vect[],int izq,int derch)
{
    int med;
    
    if(izq<derch) 
    {
        med=izq+(derch-izq)/2;
        mergeSortT(vect,izq,med);
        mergeSortT(vect,med+1,derch);
        fusionMergeSortT(vect,izq,med,derch);
    }
}

void fusionMergeSortT(Tdato vect[],int izq,int medio,int derch)
{
    int i,j,k;
    int n1=medio-izq+1;
    int n2=derch-medio;
    Tdato Lf[n1], R[n2];
    
    for (i=0;i<n1;i++)
    {
        Lf[i]=vect[izq+i];
    }
    for (j=0;j<n2;j++) 
    {
        R[j]=vect[medio+1+j];
    }

    i=0;
    j=0; 
    k=izq;
    while (i<n1)
    {
        if(j<n2)
        {
            if(Lf[i].key<=R[j].key) 
            {
                vect[k]=Lf[i];
                i++;
            }
            else
            {
                vect[k]=R[j];
                j++;
            }
            k++;
        }
        else
        {
            break;
        }
    }
    while(i<n1) 
    {
        vect[k]=Lf[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        vect[k]=R[j];
        j++;
        k++;
    }
}

void swapT(Tdato *x,Tdato *y) 
{
    Tdato temp = *x;
    *x = *y;
    *y = temp;
}

void adjustHeapT(Tdato vect[],int n,int raiz) 
{
    int may=raiz;
    int izq =2 *raiz+1;
    int derch =2*raiz+2;

    if(izq<n)
    {
        if(vect[izq].key>vect[may].key)
        {
            may=izq;
        }
    }

    if(derch<n) 
    {
        if(vect[derch].key>vect[may].key)
        {
            may=derch;
        }
        
    }

    if(may!=raiz) 
    {
        swapT(&vect[raiz],&vect[may]);
        adjustHeapT(vect,n,may);
    }
}

void heapSortT(Tdato vect[],int n) 
{
    int i;
    for (i=n/2-1;i>=0;i--) 
    {
        adjustHeapT(vect,n,i);
    }

    for (i=n-1;i>0;i--) 
    {
        swapT(&vect[0],&vect[i]);
        adjustHeapT(vect,i,0);
    }
}

int buscarTBin(Tdato vect[],int i,int num)
{
    int izq,drcha;
    int med;
    izq=0;
    drcha=i-1;
    while(izq<=drcha) 
    {
        med=izq+(drcha-izq)/2;
        if(vect[med].key==num)
        {
            return med;
        }
        
        if(vect[med].key<num)
        {
            izq=med+1;
        } 
        else
        {
            drcha=med-1;
        }
    }
    return -1;
}

int buscarTSec(Tdato vect[],int i,int num)
{
    int j;
    for(j=0;j<i;j++)    
    {
        if(num==vect[j].key)  
        {
            return j; 
        }
    }
    return -1;  
}

int genKey(Tdato vect[],int i,int ri,int rf)
{
    int num;
    int rango=rf-ri;
    do
    {
        num=(rand()%rango+1)+ri;
    }while(buscarTSec(vect,i,num)!=-1);
    return num;
}

void genH_Name(Tdato vect[],int i)
{
    char h_name[100][LN]={
        "JOSE",
        "JUAN",
        "LUIS",
        "MANUEL",
        "ANTONIO",
        "JESUS",
        "CARLOS",
        "FRANCISCO",
        "ALBERTO",
        "JORGE",
        "MIGUEL",
        "ANGEL",
        "JAVIER",
        "ALEJANDRO",
        "ENRIQUE",
        "VICTOR",
        "ARTURO",
        "CESAR",
        "FERNANDO",
        "PEDRO",
        "MARTIN",
        "ROBERTO",
        "EDUARDO",
        "MARIO",
        "ARMANDO",
        "SERGIO",
        "RAUL",
        "ALFREDO",
        "RAFAEL",
        "RICARDO",
        "HECTOR",
        "OSCAR",
        "GERARDO",
        "DAVID",
        "DANIEL",
        "HUGO",
        "JAIME",
        "JULIO",
        "RUBEN",
        "RAMON",
        "MARCO",
        "GABRIEL",
        "EDGAR",
        "GUADALUPE",
        "ALFONSO",
        "GUILLERMO",
        "SALVADOR",
        "OMAR",
        "IVAN",
        "HUMBERTO",
        "FELIPE",
        "ERNESTO",
        "PABLO",
        "IGNACIO",
        "GUSTAVO",
        "ANDRES",
        "ADRIAN",
        "JOEL",
        "AGUSTIN",
        "RODOLFO",
        "GILBERTO",
        "ROGELIO",
        "RENE",
        "TOMAS",
        "SAUL",
        "ISRAEL",
        "OCTAVIO",
        "VICENTE",
        "NOE",
        "GREGORIO",
        "ISMAEL",
        "NICOLAS",
        "BENJAMIN",
        "MOISES",
        "SANTIAGO",
        "EFRAIN",
        "ALONSO",
        "ABEL",
        "WILBERT",
        "ALVARO",
        "FELIX",
        "MARCOS",
        "ADOLFO",
        "RODRIGO",
        "RAMIRO",
        "SAMUEL",
        "JOAQUIN",
        "ABRAHAM",
        "ESTEBAN",
        "ULISES",
        "RAYMUNDO",
        "FIDEL",
        "LORENZO",
        "GERMAN",
        "MAURICIO",
        "LEONARDO",
        "JOSUE",
        "EMMANUEL",
        "JULIAN",
        "SANTOS",
    };
    int prob;
    prob=rand()%10;
    if(prob<=7)
    {
        strcopy(vect[i].nombre,h_name[rand()%100]);
    }
    else
    {
        strcopy(vect[i].nombre,h_name[rand()%100]);
        strConcat(vect[i].nombre,h_name[rand()%100]);
    }
}

void genM_Name(Tdato vect[],int i)
{
    char m_name[100][LN]={
        "MARIA",
        "GUADALUPE",
        "ROSA",
        "MARTHA",
        "ANA",
        "PATRICIA",
        "LETICIA",
        "ELENA",
        "LAURA",
        "ELIZABETH",
        "ISABEL",
        "ALICIA",
        "MARGARITA",
        "LUZ",
        "ANGELICA",
        "CLAUDIA",
        "SILVIA",
        "NORMA",
        "JUANA",
        "GABRIELA",
        "ADRIANA",
        "VERONICA",
        "TERESA",
        "ALEJANDRA",
        "ALMA",
        "BEATRIZ",
        "YANET",
        "YOLANDA",
        "BLANCA",
        "SANDRA",
        "ARACELI",
        "IRMA",
        "GLORIA",
        "CARMEN",
        "LUISA",
        "ROCIO",
        "CONCEPCION",
        "CRISTINA",
        "EDITH",
        "ESTHER",
        "LILIA",
        "LORENA",
        "MAGDALENA",
        "CECILIA",
        "JOSEFINA",
        "DOLORES",
        "KARINA",
        "LUCIA",
        "ESTELA",
        "SUSANA",
        "MARIBEL",
        "LUCINA",
        "LOURDES",
        "ERIKA",
        "MONICA",
        "AGUSTINA",
        "DIANA",
        "EUGENIA",
        "ALEJANDRINA",
        "PILAR",
        "FRANCISCA",
        "VIRGINIA",
        "LILIANA",
        "GRACIELA",
        "BERTHA",
        "OLGA",
        "MIRIAM",
        "FABIOLA",
        "DELIA",
        "CAROLINA",
        "KARLA",
        "HILDA",
        "ANTONIA",
        "MARICELA",
        "SONIA",
        "NANCY",
        "BERENICE",
        "YADIRA",
        "MAYRA",
        "JUDITH",
        "MARISOL",
        "ROSARIO",
        "REYNA",
        "AURORA",
        "OLIVIA",
        "RAQUEL",
        "IRENE",
        "ELVIRA",
        "CATALINA",
        "LIDIA",
        "VICTORIA",
        "DULCE",
        "ISELA",
        "SARA",
        "MARCELA",
        "ELVIA",
        "ESPERANZA",
        "GUILLERMINA",
        "DORA",
        "EVA",

    };
    int prob;
    prob=rand()%10;
    if(prob<=7)
    {
        strcopy(vect[i].nombre,m_name[rand()%100]);
    }
    else
    {
        strcopy(vect[i].nombre,m_name[rand()%100]);
        strConcat(vect[i].nombre,m_name[rand()%100]);
    }
}

void genAp(Tdato vect[],int i)
{
    char ap[100][L]={
        "HERNANDEZ",
        "GARCIA",
        "MARTINEZ",
        "LOPEZ",
        "GONZALEZ",
        "RODRIGUEZ",
        "PEREZ",
        "SANCHEZ",
        "RAMIREZ",
        "FLORES",
        "CRUZ",
        "GOMEZ",
        "MORALES",
        "VAZQUEZ",
        "JIMENEZ",
        "REYES",
        "DIAZ",
        "TORRES",
        "GUTIERREZ",
        "RUIZ",
        "AGUILAR",
        "MENDOZA",
        "CASTILLO",
        "ORTIZ",
        "MORENO",
        "RIVERA",
        "RAMOS",
        "ROMERO",
        "JUAREZ",
        "ALVAREZ",
        "MENDEZ",
        "CHAVEZ",
        "HERRERA",
        "MEDINA",
        "DOMINGUEZ",
        "CASTRO",
        "GUZMAN",
        "VARGAS",
        "VELAZQUEZ",
        "SALAZAR",
        "ROJAS",
        "ORTEGA",
        "CORTES",
        "SANTIAGO",
        "GUERRERO",
        "CONTRERAS",
        "BAUTISTA",
        "ESTRADA",
        "LUNA",
        "LARA",
        "RIOS",
        "AVILA",
        "ALVARADO",
        "DE LA CRUZ",
        "SILVA",
        "DELGADO",
        "CARRILLO",
        "SOLIS",
        "SOTO",
        "LEON",
        "FERNANDEZ",
        "CERVANTES",
        "MARQUEZ",
        "ESPINOSA",
        "MEJIA",
        "VEGA",
        "SANDOVAL",
        "CAMPOS",
        "NAVA",
        "CABRERA",
        "IBARRA",
        "ESPINOZA",
        "SANTOS",
        "ACOSTA",
        "CAMACHO",
        "VALDEZ",
        "FUENTES",
        "VARELA",
        "MIRANDA",
        "MALDONADO",
        "ROBLES",
        "ROSAS",
        "MEZA",
        "MOLINA",
        "TREJO",
        "ROSALES",
        "PACHECO",
        "NAVARRO",
        "SALGADO",
        "AGUIRRE",
        "SALAS",
        "VELASCO",
        "CARDENAS",
        "PINEDA",
        "OROZCO",
        "SERRANO",
        "RANGEL",
        "VALENCIA",
        "SOSA",
        "VASQUEZ"
    };
    int prob;
    prob=rand()%10;
    if(prob<9)
    {
        strcopy(vect[i].apPat,ap[rand()%99]);
        strcopy(vect[i].apMat,ap[rand()%99]);
    }
    else
    {
        strcopy(vect[i].apPat,ap[rand()%99]);
        vect[i].apMat[0]='X';
        vect[i].apMat[1]='\0';
    }
}