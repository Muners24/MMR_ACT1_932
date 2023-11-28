/* Mejía Martínez, Ramón    372099                                                                                                                                                           */
/* 28 de noviembre de 2023                                                                                                                                                                   */
/* Programa de gestion de empleados usando structs, distintos metodos de busqueda, ordenacion y uso de archivos de texto y binarios, usando como almacenamiento un archivo binario indeaxo   */
/* MMR_ACT13_932                                                                                                                                                                             */

#include "C:\Users\ramon\OneDrive\Escritorio\MMR_ACT1_932\MMR_ACT14_932\MMRLIB.h"
#include <stddef.h>
#include <string.h>

#define ELIMINAR 1
#define BUSCAR 0
#define ENCABEZADO "| NO   | NO EMP | PUESTO                 | APELLIDO PATERNO | APELLIDO MATERNO  | NOMBRE               | TELEFONO   | EDAD | SEXO       | EST |"
typedef int Tkey;

typedef struct _Wrkr{
    int status;
    Tkey key;
    char name[L];
    char apPat[LN];
    char apMat[LN];
    char sexo[15];
    char puesto[L];
    char estado[L];
    int edad;
    Tkey telefono;
}TWrkr;


typedef struct _index{
    Tkey key;
    Tkey indice;
    Tkey Telefono;
}Tindex;

int msgs(void);

void menu(int REG);
void GenWrkr(Tindex vect[],int i);
int GenKey(Tindex vect[],int i,int ri,int rf);
void GenH_Name(char str[]);
void GenM_Name(char str[]);
void GenAp(char str[],char str1[]);
void GenEst(char estado[]);
void GenPuesto(char str[]);
int BuscarWrkr(Tindex vect[],int i,int orden);
int BuscarSecIndex(Tindex vect[],int i,Tkey num);
int BuscarBinIndex(Tindex vect[],int i,Tkey num);
int BuscarSecTelIndex(Tindex vect[],int i,int num);
void DelWrkr(Tindex vect[],int i,int orden);
void PrintRegReg(int indice,int razon);
void OrdenarIndex(Tindex vect[],int i,int MetodoOrden);
void BubbleSortIndex(Tindex vect[],int n);
void HeapSortIndex(Tindex vect[],int n);
void AdjustHeapIndex(Tindex vect[],int n,int raiz);
void SwapIndex(Tindex *x,Tindex *y);
void MergeSortIndex(Tindex vect[],int izq,int derch);
void FusionMergeSortIndex(Tindex vect[],int izq,int medio,int derch);
void PrintRegTab(Tindex vect[],int i,int &orden,int MetodoOrden);
void PrintArchBin(void);
void PrintBinIndex(Tindex vect[],int i);
void GenArchivoTxt(Tindex vect[],int i,int &orden,int MetodoOrden);
void GenArchTxtNormal(char name[]);
void GenArchTxtOrden(Tindex vect[],int i,char name[]);
void PrintArchTxt(char name[]);
void empaquetar(Tindex vect[],int i,int resplado);

int main()
{
    srand(time(NULL));
    FILE *fa;
    int REG;
    system("C:\\Users\\ramon\\OneDrive\\Escritorio\\MMR_ACT1_932\\MMR_ACT14_932\\SizeArchivo.exe");
    fa=fopen("NumeroRegistros.txt","r");
    if(fa)
    {
        fscanf(fa,"%d",&REG);
        fclose(fa);
        menu(REG);
    }
    else
    {
        printf("\nEl archivo binario de registros no existe\n");
        system("pause");
    }
    
    return 0;
}

int msgs(void)
{
    printf("   Menu\n\n");
    printf("1) Agregar\n");
    printf("2) Eliminar\n");
    printf("3) Buscar\n");
    printf("4) Ordenar\n");
    printf("5) Mostrar Todo\n");
    printf("6) Generar Archivo de Texto\n");
    printf("7) Empaquetar\n");
    printf("8) Salir\n");
    return(validNum("Escoge una opcion: ",1,9));
}

void menu(int REG)
{
    int i=0,j=0,respaldo=0;
    REG;
    int op;
    int orden=0,MetodoOrden=0;
    Tindex trabajadores[REG];
    TWrkr reg;
    FILE *fa;
    fa=fopen("datos.dat","rb");
    if(fa)
    {
        //carga de archivo binario al arreglo indexado
        while(fread(&reg,sizeof(TWrkr),1,fa)==1)
        {
            if(reg.status)
            {
                trabajadores[i].indice=j;
                trabajadores[i].key=reg.key;
                trabajadores[i].Telefono=reg.telefono;
                i++;
            }
            j++;
        }
        fclose(fa);
        if(i>3500)
        {
            if(i>3750)
            {
                MetodoOrden=2;
            }
            else
            {
                MetodoOrden=1;
            }
        }
        printf("\nSe cargo el archivo binario\n");
        system("pause");
        do
        {
            system("cls");
            op=msgs();
            system("cls");
            switch(op)
            {
                case 1:
                    if(i+1<REG)
                    {
                        GenWrkr(trabajadores,i++);
                        orden=0;
                        if(i>3500)
                        {
                            if(i>3750)
                            {
                                MetodoOrden=2;
                            }
                            else
                            {
                                MetodoOrden=1;
                            }
                        }
                    }
                    else
                    {
                        printf("\nLa capacidad de registros llego al limite\n");
                    }
                    break;
                case 2: 
                    DelWrkr(trabajadores,i,orden);
                    break;
                case 3:
                    BuscarWrkr(trabajadores,i,orden);
                    break;
                case 4:
                    if(!orden)
                    {
                        OrdenarIndex(trabajadores,i,MetodoOrden);
                        orden=1;
                    }
                    else
                    {
                        printf("\nEl arreglo indexado ya esta ordenado\n");
                    }
                    break;
                case 5:
                    PrintRegTab(trabajadores,i,orden,MetodoOrden);
                    break;
                case 6:
                    GenArchivoTxt(trabajadores,i,orden,MetodoOrden);
                    break;
                case 7:
                    empaquetar(trabajadores,i,respaldo++);
                    break;
            }
            printf("\n");
            system("pause");
        }while(op!=8);
    }
    else
    {
        printf("\nEl archivo binario de registros no existe\n");
    }
}

//case 1
void GenWrkr(Tindex vect[],int i)   
{
    FILE *fa;
    TWrkr reg;
    int s,num;
    int j;
    reg.status=1;
    reg.key=GenKey(vect,i,300000,399999);
    vect[i].key=reg.key;
    vect[i].indice=i;
    reg.edad=(rand()%53)+18;
    GenEst(reg.estado);
    
    s=rand()%2;

    if(s)
    {
        strcopy(reg.sexo,"HOMBRE");
        GenH_Name(reg.name);
    }
    else
    {
        strcopy(reg.sexo,"MUJER");
        GenM_Name(reg.name);
    }

    GenAp(reg.apPat,reg.apMat);

    do
    {
        num=(rand()%100000)+(rand()%99)*100000;
    }while(BuscarSecTelIndex(vect,i,num)!=-1);
    reg.telefono=num;

    GenPuesto(reg.puesto);

    fa=fopen("datos.dat","rb");
    if(fa)
    {
        fclose(fa);
        fopen("datos.dat","ab");
        fwrite(&reg,sizeof(TWrkr),1,fa);
        fclose(fa);
        printf("\nSe genero un trabajador y se guardo en el archivo\n");
    }
    else
    {
        printf("\nNo se pudo guardar el registro en el archivo\n");
        printf("\nEl archivo binario no existe\n");
    }
}

void GenPuesto(char str[])
{
    char pst[12][L]={
        "OPERADOR","SUPERVISOR","MANTENIMIENTO","INGENIERO DE PROCESOS","INGENIERO DE CALIDAD",
        "OPERADOR DE MAQUINARIA", "ALMACENISTA", "JEFE DE ALMACEN", "INSPECTOR DE CALIDAD", 
        "GERENTE DE PRODUCCION", "TECNICO EN SEGURIDAD", "RECURSOS HUMANOS"
    };
    strcopy(str,pst[(rand()%12)]);
}

int GenKey(Tindex vect[],int i,int ri,int rf)
{
    int num;
    int rango=rf-ri;
    do
    {
        num=(rand()%rango+1)+ri;
    }while(BuscarSecIndex(vect,i,num)!=-1);
    return num;
}

void GenH_Name(char str[])
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
        strcopy(str,h_name[rand()%100]);
    }
    else
    {
        strcopy(str,h_name[rand()%100]);
        strConcat(str,h_name[rand()%100]);
    }
}

void GenM_Name(char str[])
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
        strcopy(str,m_name[rand()%100]);
    }
    else
    {
        strcopy(str,m_name[rand()%100]);
        strConcat(str,m_name[rand()%100]);
    }
}

void GenAp(char str[],char str1[])
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
        strcopy(str,ap[rand()%99]);
        strcopy(str1,ap[rand()%99]);
    }
    else
    {
        strcopy(str,ap[rand()%99]);
        str1[0]='X';
        str1[1]='\0';
    }
}

void GenEst(char estado[])
{
    char estList[33][3]={
    "AS","BC","BS","CC","CS","CH","CM","CL","MX","DG",
    "GT","GR","HG","JC","EM","MN","MS","NT","NL","OC",
    "PL","QT","QR","SP","SL","SR","TC","TS","TL","VZ",
    "YN","ZS","NE"
    };

    strcopy(estado,estList[rand()%33]);
    strM(estado);
}

int BuscarSecTelIndex(Tindex vect[],int i,int num)
{
    int j;
    for(j=0;j<i;j++)
    {
        if(vect[j].Telefono==num)
        {
            return j;
        }
    }
    return -1;
}

int BuscarSecIndex(Tindex vect[],int i,Tkey num)
{
    int j;
    for(j=0;j<i;j++)
    {
        if(vect[j].key==num)
        {
            return (vect[j].indice);
        }
    }
    return -1;
}

int BuscarBinIndex(Tindex vect[],int i,Tkey num)
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
            return (vect[med].indice);
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

//case 2
void DelWrkr(Tindex vect[],int i,int orden)
{
    int pos;
    int del;
    FILE *fa;
    printf("Eliminar empleado\n\n");
    pos=validNum("Ingresa el número de empleado que deseas eliminar: ",300000,399999);
    if(orden)
    {
        pos=BuscarBinIndex(vect,i,pos);
        if(pos!=-1)
        {
            PrintRegReg(pos,ELIMINAR);
        }
        else
        {
            printf("\nEl empleado no existe\n");
        }
    }
    else
    {
        pos=BuscarSecIndex(vect,i,pos);
        if(pos!=-1)
        {
            PrintRegReg(pos,ELIMINAR);
        }
        else
        {
            printf("\nEl empleado no existe\n");
        }
    }
}

void PrintRegReg(int indice,int razon)
{
    FILE *fa;
    TWrkr reg;
    int del;
    fa=fopen("datos.dat","rb+");
    if(fa)
    {
        fseek(fa,sizeof(TWrkr)*indice,SEEK_SET);
        if(fread(&reg,sizeof(TWrkr),1,fa)==1)
        {
            if(reg.status)
            {
                if(razon==ELIMINAR)
                {
                    printf("\nNumero de Empleado: %d\n",reg.key);
                    printf("Nombre: %s\n",reg.name);
                    printf("Apellido Paterno: %s\n",reg.apPat);
                    printf("Apellido Materno %s\n",reg.apMat);
                    printf("Sexo: %s\n",reg.sexo);
                    printf("Pueso: %s\n",reg.puesto);
                    printf("Estado: %s\n",reg.estado);
                    printf("Edad: %d\n",reg.edad);
                    printf("Telefono: %d\n",reg.telefono);
                    del=validNum("Deseas eliminar al empleado? (0:Si 1:No): ",0,1);
                    if(!del)
                    {
                        fseek(fa,-sizeof(TWrkr),SEEK_CUR);
                        fseek(fa,offsetof(TWrkr,status),SEEK_CUR);
                        fwrite(&del,sizeof(int),1,fa);
                        printf("\nSe elimino el empleado\n");
                    }
                }
                else
                {
                    if(razon==BUSCAR)
                    {
                        printf("\nNumero de Empleado: %d\n",reg.key);
                        printf("Nombre: %s\n",reg.name);
                        printf("Apellido Paterno: %s\n",reg.apPat);
                        printf("Apellido Materno %s\n",reg.apMat);
                        printf("Sexo: %s\n",reg.sexo);
                        printf("Pueso: %s\n",reg.puesto);
                        printf("Estado: %s\n",reg.estado);
                        printf("Edad: %d\n",reg.edad);
                        printf("Telefono: %d\n",reg.telefono);
                    }
                }
            }
            else
            {
                printf("\nEl empleado esta elimiando\n");
            }
        }
        else
        {
            printf("\nOcurrio un error al cargar el registro\n");
        }

        fclose(fa);
    }
    else
    {
        printf("\nEl archivo de registros no existe\n");
    }
}

//case 3
int BuscarWrkr(Tindex vect[],int i,int orden)
{
    int pos;
    FILE *fa;
    printf("Buscar empleado\n\n");
    pos=validNum("Ingresa el número de empleado que deseas buscar: ",300000,399999);
    if(orden)
    {
        pos=BuscarBinIndex(vect,i,pos);
        if(pos!=-1)
        {
            PrintRegReg(pos,BUSCAR);
        }
        else
        {
            printf("\nEl empleado no existe\n");
        }
    }
    else
    {
        pos=BuscarSecIndex(vect,i,pos);
        if(pos!=-1)
        {
            PrintRegReg(pos,BUSCAR);
        }
        else
        {
            printf("\nEl empleado no existe\n");
        }
    }
}

//case 4
void OrdenarIndex(Tindex vect[],int i,int MetodoOrden)
{
    switch(MetodoOrden)
    {
        case 0:
            BubbleSortIndex(vect,i);
        case 1:
            HeapSortIndex(vect,i);
        case 2:
            MergeSortIndex(vect,0,i-1);
            break;
    }
}

void BubbleSortIndex(Tindex vect[],int n)
{
    int i,j;
    int swap;
    for(i=0;i<n-1;i++)
    {
        swap=0; 
        for(j=0;j<n-i-1;j++)
        {
            if(vect[j].key>vect[j+1].key)
            {
                SwapIndex(&vect[j],&vect[j+1]);
                swap=1;
            }
        }
        if (swap==0)
        {
            i=n;
        }
    }
}

void HeapSortIndex(Tindex vect[],int n) 
{
    int i;
    for (i=n/2-1;i>=0;i--) 
    {
        AdjustHeapIndex(vect,n,i);
    }

    for (i=n-1;i>0;i--) 
    {
        SwapIndex(&vect[0],&vect[i]);
        AdjustHeapIndex(vect,i,0);
    }
}

void AdjustHeapIndex(Tindex vect[],int n,int raiz) 
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
        SwapIndex(&vect[raiz],&vect[may]);
        AdjustHeapIndex(vect,n,may);
    }
}

void SwapIndex(Tindex *x,Tindex *y) 
{
    Tindex temp = *x;
    *x = *y;
    *y = temp;
}

void MergeSortIndex(Tindex vect[],int izq,int derch)
{
    int med;
    
    if(izq<derch) 
    {
        med=izq+(derch-izq)/2;
        MergeSortIndex(vect,izq,med);
        MergeSortIndex(vect,med+1,derch);
        FusionMergeSortIndex(vect,izq,med,derch);
    }
}

void FusionMergeSortIndex(Tindex vect[],int izq,int medio,int derch)
{
    int i,j,k;
    int n1=medio-izq+1;
    int n2=derch-medio;
    Tindex Lf[n1], R[n2];
    
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

//case 5 y 6
void PrintRegTab(Tindex vect[],int i,int &orden,int MetodoOrden)
{
    int op;
    printf("Mostrar Registros\n\n");
    printf("1) Normal\n");
    printf("2) Ordenado\n");
    printf("3) Regresar\n");
    op=validNum("Escoge una opcion: ",1,3);
    
    switch(op)
    {
        case 1:
            printf("\n");
            PrintArchBin();
            break;
        case 2:
            if(orden)
            {
                printf("\n");
                PrintBinIndex(vect,i);
            }
            else
            {
                printf("\n");
                OrdenarIndex(vect,i,MetodoOrden);
                orden=1;
                PrintBinIndex(vect,i);
            }
            break;
        
    }
}

void PrintArchBin(void)
{
    FILE *fa;
    TWrkr reg;
    int k=0;
    fa=fopen("datos.dat","rb");
    if(fa)
    {
        printf("%s\n",ENCABEZADO);
        while(fread(&reg,sizeof(TWrkr),1,fa)==1)
        {
            if(reg.status)
            {
                printf("| %-4d ",++k);
                //getch();
                printf("| %6d | %-22s | %-16s | %-17s | %-20s | 646%-7d | %-4d | %-10s | %s  |\n",reg.key,reg.puesto,reg.apPat,reg.apMat,reg.name,reg.telefono,reg.edad,reg.sexo,reg.estado);
            }
        }
        fclose(fa);
    }
    else
    {
        printf("\nEl archivo de registros no existe\n");
    }
}

void PrintBinIndex(Tindex vect[],int i)
{
    FILE *fa;
    TWrkr reg;
    int j,k=0;
    fa=fopen("datos.dat","rb");
    if(fa)
    {
        for(j=0;j<i;j++)
        {
            fseek(fa,0,SEEK_SET);
            fseek(fa,sizeof(TWrkr)*vect[j].indice,SEEK_SET);
            if(fread(&reg,sizeof(TWrkr),1,fa)==1)
            {
                if(reg.status)
                {
                    printf("| %-4d ",++k);
                    printf("| %6d | %-22s | %-16s | %-17s | %-20s | 646%-7d | %-4d | %-10s | %s  |\n",reg.key,reg.puesto,reg.apPat,reg.apMat,reg.name,reg.telefono,reg.edad,reg.sexo,reg.estado);
                }
            }
        }
        fclose(fa);
    }
    else
    {
        printf("\nEl archivo de registros no existe\n");
    }
}

//case 7
void GenArchivoTxt(Tindex vect[],int i,int &orden,int MetodoOrden)
{
    FILE *fa;
    int bname;
    int op;
    char name[LN];
    int len;
    printf("Generar Archivo de Texto\n\n");
    printf("1) Normal\n");
    printf("2) Ordenado\n");
    printf("3) Regresar\n");
    op=validNum("Escoge una opcion: ",1,3);
    
    if(op<3)
    {
        do
        {
            bname=0;
            printf("\n\nIngresa el nombre del archivo de texto: ");
            validStr(name);
            len=strlen(name);
            name[len++]='.';
            name[len++]='t';
            name[len++]='x';
            name[len++]='t';
            name[len]='\0';
            fa=fopen(name,"r");
            if(fa)
            {
                printf("\nYa existe un archivo con ese nobmre\n");
                fclose(fa);
                bname=1;
            }
        }while(bname);
        fclose(fa);
        
        
    }
    switch(op)
    {
        case 1:
            printf("\n");
            GenArchTxtNormal(name);
            printf("\nArchivo %s\n\n",name);
            PrintArchTxt(name);
            break;
        case 2:
            if(orden)
            {
                printf("\n");
                GenArchTxtOrden(vect,i,name);
                PrintArchTxt(name);
            }
            else
            {
                printf("\n");
                OrdenarIndex(vect,i,MetodoOrden);
                orden=1;
                GenArchTxtOrden(vect,i,name);
                PrintArchTxt(name);
            }
            break;
    }
}

void GenArchTxtNormal(char name[])
{
    FILE *bin,*txt;
    TWrkr reg;
    int k=0;
    bin=fopen("datos.dat","rb");
    if(bin)
    {
        txt=fopen(name,"w");
        fprintf(txt,"%s\n",ENCABEZADO);
        while(fread(&reg,sizeof(TWrkr),1,bin)==1)
        {
            if(reg.status)
            {
                fprintf(txt,"| %-4d | %6d | %-22s | %-16s | %-17s | %-20s | 646%-7d | %-4d | %-10s | %s  |\n",++k,reg.key,reg.puesto,reg.apPat,reg.apMat,reg.name,reg.telefono,reg.edad,reg.sexo,reg.estado);
            }
        }
        fclose(txt);
        fclose(bin);
    }
    else
    {
        printf("\nEl archivo binario de registros no existe\n");
    }
}   

void GenArchTxtOrden(Tindex vect[],int i,char name[])
{
    FILE *bin,*txt;
    TWrkr reg;
    int j,k=0;
    bin=fopen("datos.dat","rb");
    if(bin)
    {
        txt=fopen(name,"w");
        fprintf(txt,"%s\n",ENCABEZADO);
        for(j=0;j<i;j++)
        {
            fseek(bin,0,SEEK_SET);
            fseek(bin,sizeof(TWrkr)*vect[j].indice,SEEK_SET);
            if(fread(&reg,sizeof(TWrkr),1,bin)==1)
            {
                if(reg.status)
                {
                    fprintf(txt,"| %-4d ",++k);
                    fprintf(txt,"| %6d | %-22s | %-16s | %-17s | %-20s | 646%-7d | %-4d | %-10s | %s  |\n",reg.key,reg.puesto,reg.apPat,reg.apMat,reg.name,reg.telefono,reg.edad,reg.sexo,reg.estado);
                }
            }
        }
        fclose(txt);
        fclose(bin);
    }
    else
    {
        printf("\nEl archivo binario de registros no existe\n");
    }
}

void PrintArchTxt(char name[])
{
    FILE *fa;
    char c;
    fa=fopen(name,"r");
    if(fa)
    {
        do
        {
            c=fgetc(fa);
            printf("%c",c);
        }while(c!=EOF);
        fclose(fa);
    }
    else
    {
        printf("\nEl archivo de texto %s no existe\n",name);
    }
}
//case 8
void empaquetar(Tindex vect[],int i,int resplado)
{
    FILE *bin,*binbak,*bindel,*tmp;
    TWrkr reg;
    char binBakName[30];
    char c[2];
    bin=fopen("datos.dat","rb");
    if(bin)
    {
        fclose(bin);
        rename("datos.dat","datos.tmp");
        tmp=fopen("datos.tmp","rb");
        if(tmp)
        {
            if(resplado==0)
            {
                bin=fopen("datos.dat","wb");
                binbak=fopen("datos.bak","wb");
                bindel=fopen("datosdel.bak","ab");
                //respaldo
                while(fread(&reg,sizeof(TWrkr),1,tmp))
                {
                    if(reg.status)
                    {
                        fwrite(&reg,sizeof(TWrkr),1,bin);
                        fwrite(&reg,sizeof(TWrkr),1,binbak);
                    }
                    else
                    {
                        fwrite(&reg,sizeof(TWrkr),1,bindel);
                        fwrite(&reg,sizeof(TWrkr),1,binbak);
                    }
                }
                printf("\nSe empaqueto correctamente\n");
                fclose(tmp);
                fclose(bindel);
                fclose(binbak);
                fclose(bin);
                
            }
            else
            {
                if(resplado>0)
                {
                    strcpy(binBakName,"datos");
                    strcat(binBakName,itoa(resplado,c,10));
                    strcat(binBakName,".bak");
                    bin=fopen("datos.dat","wb");
                    binbak=fopen(binBakName,"wb");
                    bindel=fopen("datosdel.bak","a");
                    //respaldo
                    while(fread(&reg,sizeof(TWrkr),1,tmp))
                    {
                        if(reg.status)
                        {
                            fwrite(&reg,sizeof(TWrkr),1,bin);
                            fwrite(&reg,sizeof(TWrkr),1,binbak);
                        }
                        else
                        {//332686
                            fwrite(&reg,sizeof(TWrkr),1,bindel);
                            fwrite(&reg,sizeof(TWrkr),1,binbak);
                        }
                    }
                    printf("\nSe empaqueto correctamente\n");
                    fclose(tmp);
                    fclose(bindel);
                    fclose(binbak);
                    fclose(bin);
                }
            }
            remove("datos.tmp");
        }
        else
        {
            printf("\nError al empaquetar\n");
        }
    }
    else
    {
        printf("\nEl archivo binario principal no existe\n");
    }
}