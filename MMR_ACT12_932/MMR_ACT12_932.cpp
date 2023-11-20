/* Mejía Martínez, Ramón    372099                                                                              */
/* 12 de noviembre de 2023                                                                                      */
/* Programa de gestion de alumnos usando structs, distintos metodos de busqueda, ordenacion y uso de archivos   */
/* MMR_ACT12_932                                                                                                */
#include "C:\Users\ramon\OneDrive\Escritorio\MMR_ACT1_932\MMRLIB.h"

#define REG 1500
#define L 30
#define LN 50

typedef struct _alum
{
    int status;
    int matricula;
    char apPat[L];
    char apMat[L];
    char nombre[LN];
    int edad;
    char sexo;
}StructAlum;

void menu(void);
int msgs(void);

int cargArchivo(StructAlum alumnos[],int i,int datos);

int agregarAlum(StructAlum alumnos[],int i);
void generarAlumno(StructAlum alumnos[],int i);
int genMatri(StructAlum alumnos[],int i);
void genH_Name(StructAlum alumnos[],int i);
void genM_Name(StructAlum alumnos[],int i);
void genAp(StructAlum alumnos[],int i);

int eliminarAlum(StructAlum alumnos[],int i,int orden);
void archivoDelAlum(StructAlum alumnos);

void printAlumReg(StructAlum alumnos);
void buscarAlum(StructAlum alumnos[],int i,int orden);
int buscarAlumSec(StructAlum alumnos[],int i,int num);
int buscarAlumBin(StructAlum alumnos[],int i,int num);

void ordenAlum(StructAlum alumnos[],int i);
void mergeSort(StructAlum alumnos[],int izq,int derch);
void fusionMergeSort(StructAlum alumnos[],int izq,int medio,int derch);
void swap(StructAlum *x,StructAlum *y);
void adjustHeap(StructAlum alumnos[],int n,int raiz);
void heapSort(StructAlum alumnos[], int n) ;

void printTAlum(StructAlum alumnos[],int i);
void printAlumTab(StructAlum alumnos);

void genArchivo(StructAlum alumnos[],int i);

void printDelAlum(StructAlum alumnos[],int del);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int msgs(void)
{
    printf("\nMenu\n");
    printf("1) Cargar Archivo\n");
    printf("2) Agregar\n");
    printf("3) Eliminar\n");
    printf("4) Buscar\n");
    printf("5) Ordenar\n");
    printf("6) Mostrar todo\n");
    printf("7) Generar archivo\n");
    printf("8) Cantidad de registros en Archivo\n");
    printf("9) Mostrar Borrados\n");
    printf("10) Salir\n");
    return(validNum("Escoge una opcion: ",1,10));
}

void menu(void)
{
    int op;
    int i=0,del=0;
    int orden=0,datos=1;
    StructAlum alumnos[REG];

    FILE *fa;
    fa=fopen("regEliminado.txt","r");
    if(fa)
    {
        fclose(fa);
        remove("regEliminado.txt");
    }

    fa=fopen("registros.txt","r");
    if(fa)
    {
        fclose(fa);
        remove("registros.txt");
    }

    do
    {
        system("cls");
        op=msgs();
        system("cls");
        
        switch(op)
        {
            case 1:
                i=cargArchivo(alumnos,i,datos);
                datos=0;
                orden=0;
                break;
            case 2:
                i=agregarAlum(alumnos,i);
                orden=0;
                break;
            case 3:
                del+=eliminarAlum(alumnos,i,orden);
                break;
            case 4:
                buscarAlum(alumnos,i,orden);
                break;
            case 5:
                if(!orden)
                {
                    ordenAlum(alumnos,i);
                    orden=1;
                }
                else
                {
                    printf("\nLos registros ya estan ordenados\n");
                }
                break;
            case 6:
                printTAlum(alumnos,i);
                break;
            case 7:
                if(i>0)
                {
                    genArchivo(alumnos,i);
                }
                else
                {
                    printf("\nAun no hay alumnos registrados\n");
                }
                break;
            case 9:
                if(i>0)
                {
                    printDelAlum(alumnos,del);
                }
                else
                {
                    printf("\nAun no hay alumnos registrados\n");
                }
                break;
        }
        printf("\n");
        system("pause");
    }while(op!=10);
    
}

//case 1
int cargArchivo(StructAlum alumnos[],int i,int datos)
{
    FILE *fa;
    char indice[5];
    char sexo[10];
    if(datos)
    {
        fa=fopen("datos.txt","r");
        if(fa)
        {     
            while(!feof(fa))
            {
                fscanf(fa,"%s%d%s%s%s%d%s ",indice,&alumnos[i].matricula,alumnos[i].nombre,alumnos[i].apPat,alumnos[i].apMat,&alumnos[i].edad,sexo);
                if(strlen(sexo)==9)
                {
                    alumnos[i].sexo='H';
                }
                else
                {
                    alumnos[i].sexo='M';
                }
                alumnos[i].status=1;
                i++;
            }  
            fclose(fa);
            printf("\nSe cargaron los registros del archivo datos\n");
        }
        else
        {
            printf("\nEl archivo de registros a cargar no existe\n");
        }
    }
    else
    {
        printf("\nSolo se puede cargar el archivo una vez\n");
    }
    return i;
}

//case 2
int agregarAlum(StructAlum alumnos[],int i)
{
    FILE *fa;
    int j;
    fa=fopen("registros.txt","r");
    if(fa)
    {
        fclose(fa);
        fa=fopen("registros.txt","a");
        if(i+10<=REG)
        {
            for(j=0;j<10;j++)
            {
                generarAlumno(alumnos,i++);
            }
            printf("\nSe generaron %d alumnos\n",j);
        }
        else
        {
            if(i+10>REG)
            {
                for(j=i;j<=1500;j++)
                {
                    generarAlumno(alumnos,i++);
                    printf("\nSe generaron %d alumnos\n",j);
                }
            }
            else
            {
                if(i>=REG)
                {
                    printf("\nNo se pueden generar mas alumnos\n");
                }
            }
        }
        fclose(fa);
    }
    else
    {
        fa=fopen("registros.txt","a");
        if(i+10<=REG)
        {
            for(j=0;j<10;j++)
            {
                generarAlumno(alumnos,i++);
            }
            printf("\nSe generaron %d alumnos\n",j);
        }
        else
        {
            if(i+10>REG)
            {
                for(j=i;j<=1500;j++)
                {
                    generarAlumno(alumnos,i++);
                    printf("\nSe generaron %d alumnos\n",j);
                }
            }
            else
            {
                if(i>=REG)
                {
                    printf("\nNo se pueden generar mas alumnos\n");
                }
            }
        }
        fclose(fa);
    }
    return i;
}

//Generar Alumno
void generarAlumno(StructAlum alumnos[],int i)
{
    int s;
    int j;
    alumnos[i].status=1;
    alumnos[i].matricula=genMatri(alumnos,i);
    genAp(alumnos,i);
    //sexo
    for(j=0;j<10;j++)
    {
        s=rand()%2;
    }
    if(s)
    {
        alumnos[i].sexo='H';
        genH_Name(alumnos,i);
    }
    else
    {
        alumnos[i].sexo='M';
        genM_Name(alumnos,i);
    }

    //edad
    for(j=0;j<10;j++)
    {
        s=(rand()%90)+1;
    }
    alumnos[i].edad=s;

}

int genMatri(StructAlum alumnos[],int i)
{
    int num;
    do
    {
        num=(rand()%100000)+300000;
    }while(buscarAlumSec(alumnos,i,num)!=-1);
    return num;
}

void genH_Name(StructAlum alumnos[],int i)
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
        strcopy(alumnos[i].nombre,h_name[rand()%100]);
    }
    else
    {
        strcopy(alumnos[i].nombre,h_name[rand()%100]);
        strConcat(alumnos[i].nombre,h_name[rand()%100]);
    }
}

void genM_Name(StructAlum alumnos[],int i)
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
        strcopy(alumnos[i].nombre,m_name[rand()%100]);
    }
    else
    {
        strcopy(alumnos[i].nombre,m_name[rand()%100]);
        strConcat(alumnos[i].nombre,m_name[rand()%100]);
    }
}

void genAp(StructAlum alumnos[],int i)
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
    if(prob<8)
    {
        strcopy(alumnos[i].apPat,ap[rand()%99]);
        strcopy(alumnos[i].apMat,ap[rand()%99]);
    }
    else
    {
        strcopy(alumnos[i].apPat,ap[rand()%99]);
        alumnos[i].apMat[0]='X';
        alumnos[i].apMat[1]='\0';
    }
}

//case 3
int eliminarAlum(StructAlum alumnos[],int i,int orden)
{
    int pos;
    int del;
    if(i>0)
    {
        pos=validNum("Ingresa que matricula desea eliminar: ",300000,399999);
        if(orden)
        {
            pos=buscarAlumBin(alumnos,i,pos);
            if(alumnos[pos].status)
            {
                if(pos!=-1)
                {
                    printAlumReg(alumnos[pos]);
                    printf("\nDesea eliminar el alumno? (1:Si 2:No)\n");
                    del=validNum("Escoge una opcion: ",1,2);
                    if(del==1)
                    {
                        alumnos[pos].status=0;
                        archivoDelAlum(alumnos[pos]);
                        return 1;
                    }
                }
                else
                {
                    printf("\nNo se encontro al alumno\n");
                }
            }
            else
            {
                printf("\nEste alumno ya fue eliminado\n");
            }  
        }
        else
        {
            pos=buscarAlumSec(alumnos,i,pos);
            if(alumnos[pos].status)
            {
                if(pos!=-1)
                {
                    printAlumReg(alumnos[pos]);
                    printf("\nDesea eliminar el alumno? (1:Si 2:No)\n");
                    del=validNum("Escoge una opcion: ",1,2);
                    if(del==1)
                    {
                        alumnos[pos].status=0;
                        archivoDelAlum(alumnos[pos]);
                        return 1;
                    }
                }
                else
                {
                    printf("\nNo se encontro al alumno\n");
                }
            }
            else
            {
                printf("\nEste alumno ya fue eliminado\n");
            }  
        }
    }
    else
    {
        printf("\nAun no hay alumnos registrados\n");
    }   
    return 0;
}

void archivoDelAlum(StructAlum alumnos)
{
    FILE *fa;
    fa=fopen("regEliminado.txt","r");
    if(fa)
    {
        fclose(fa);
        fa=fopen("regEliminado.txt","a");
        fprintf(fa,"| %9d | %-16s | %-17s| %-19s | %4d |",alumnos.matricula,alumnos.apPat,alumnos.apMat,alumnos.nombre,alumnos.edad);
        if(alumnos.sexo=='H')
        {
            fprintf(fa," MASCULINO |");
        }
        else
        {
            fprintf(fa," FEMENINO  |");
        }
        fclose(fa);
        
    }
    else
    {
        fa=fopen("regEliminado.txt","a");
        fprintf(fa,"| Matricula | Apellido Paterno | Apellido Materno | Nombre              | Edad |  Sexo     |\n");
        fprintf(fa,"| %9d | %-16s | %-17s| %-19s | %4d |",alumnos.matricula,alumnos.apPat,alumnos.apMat,alumnos.nombre,alumnos.edad);
        if(alumnos.sexo=='H')
        {
            fprintf(fa," MASCULINO |");
        }
        else
        {
            fprintf(fa," FEMENINO  |");
        }
        fclose(fa);
    }
}
//case 4
int buscarAlumBin(StructAlum alumnos[],int i,int num)
{
    int izq,drcha;
    int med;
    izq=0;
    drcha=i-1;
    while(izq<=drcha) 
    {
        med=izq+(drcha-izq)/2;
        if(alumnos[med].matricula==num)
        {
            return med;
        }
        
        if(alumnos[med].matricula<num)
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

int buscarAlumSec(StructAlum alumnos[],int i,int num)
{
    int j;
    for(j=0;j<i;j++)    
    {
        if(num==alumnos[j].matricula)  
        {
            return j; 
        }
    }
    return -1;  
}

void printAlumReg(StructAlum alumnos)
{
    printf("\nMatricula: %d\n",alumnos.matricula);
    printf("Apellido Paterno: %s\n",alumnos.apPat);
    printf("Apellido Materno: %s\n",alumnos.apMat);
    printf("Nombre: %s\n",alumnos.nombre);
    printf("Edad: %d\n",alumnos.edad);
    printf("Sexo: ");
    if(alumnos.sexo=='H')
    {
        printf("MASCULINO");
    }
    else
    {
        printf("FEMENINO");
    }
    printf("\n");
}  

void buscarAlum(StructAlum alumnos[],int i,int orden)
{
    int pos;
    if(i>0)
    {
        pos=validNum("Ingresa que matricula desea buscar: ",300000,399999);
        if(orden)
        {
            pos=buscarAlumBin(alumnos,i,pos);
            if(alumnos[pos].status)
            {
                if(pos!=-1)
                {
                    printAlumReg(alumnos[pos]);                }
                else
                {
                    printf("\nNo se encontro al alumno\n");
                }
            }
            else
            {
                printf("\nEste alumno fue eliminado\n");
            }  
        }
        else
        {
            pos=buscarAlumSec(alumnos,i,pos);
            if(alumnos[pos].status)
            {
                if(pos!=-1)
                {
                    printAlumReg(alumnos[pos]);
                }
                else
                {
                    printf("\nNo se encontro al alumno\n");
                }
            }
            else
            {
                printf("\nEste alumno fue eliminado\n");
            }  
        }
    }
    else
    {
        printf("\nAun no hay alumnos registrados\n");
    }   
}
//case 5
void ordenAlum(StructAlum alumnos[],int i)
{
    if(i>0)
    {
        if(i>750)
        {
            mergeSort(alumnos,0,i-1);
        }
        else
        {
            heapSort(alumnos,i);
        }
        printf("\nSe ordenaron los registros\n");
    }  
    else
    {
        printf("\nAun no hay alumnos registrados\n");
    }
}

//MergeSort
void mergeSort(StructAlum alumnos[],int izq,int derch)
{
    int med;
    
    if(izq<derch) 
    {
        med=izq+(derch-izq)/2;
        mergeSort(alumnos,izq,med);
        mergeSort(alumnos,med+1,derch);
        fusionMergeSort(alumnos,izq,med,derch);
    }
}

void fusionMergeSort(StructAlum alumnos[],int izq,int medio,int derch)
{
    int i,j,k;
    int n1=medio-izq+1;
    int n2=derch-medio;
    StructAlum Lf[n1], R[n2];
    
    for (i=0;i<n1;i++)
    {
        Lf[i]=alumnos[izq+i];
    }
    for (j=0;j<n2;j++) 
    {
        R[j]=alumnos[medio+1+j];
    }

    i=0;
    j=0; 
    k=izq;
    while (i<n1)
    {
        if(j<n2)
        {
            if(Lf[i].matricula<=R[j].matricula) 
            {
                alumnos[k]=Lf[i];
                i++;
            }
            else
            {
                alumnos[k]=R[j];
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
        alumnos[k]=Lf[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        alumnos[k]=R[j];
        j++;
        k++;
    }
}

//HeapSort
void swap(StructAlum *x,StructAlum *y) 
{
    StructAlum temp = *x;
    *x = *y;
    *y = temp;
}

void adjustHeap(StructAlum alumnos[],int n,int raiz) 
{
    int may=raiz;
    int izq =2 *raiz+1;
    int derch =2*raiz+2;

    if(izq<n)
    {
        if(alumnos[izq].matricula>alumnos[may].matricula)
        {
            may=izq;
        }
    }

    if(derch<n) 
    {
        if(alumnos[derch].matricula>alumnos[may].matricula)
        {
            may=derch;
        }
        
    }

    if(may!=raiz) 
    {
        swap(&alumnos[raiz],&alumnos[may]);
        adjustHeap(alumnos,n,may);
    }
}

void heapSort(StructAlum alumnos[], int n) 
{
    int i;
    for (i=n/2-1;i>=0;i--) 
    {
        adjustHeap(alumnos,n,i);
    }

    for (i=n-1;i>0;i--) 
    {
        swap(&alumnos[0],&alumnos[i]);
        adjustHeap(alumnos,i,0);
    }
}
//case 6
void printTAlum(StructAlum alumnos[],int i)
{
    int j,k=0;
    if(i>0)
    {
        printf("| No   | Matricula | Apellido Paterno | Apellido Materno | Nombre              | Edad |  Sexo     |\n");
        for(j=0;j<i;j++)
        {
            if(alumnos[j].status)
            {
                if(j!=0)
                {
                    if(j%40==0)
                    {
                        printf("\n");
                        system("pause");
                        printf("\n");
                    }
                }
                printf("| %4d ",k);
                printAlumTab(alumnos[j]);
                printf("\n");
                k++;
            }
        }
        printf("\nSe mostraron todos los alumnos\n");
    }
    else
    {
        printf("\nAun no hay alumnos registrados\n");
    }
}

//case 7
void genArchivo(StructAlum alumnos[],int i)
{
    char nameFile[50];
    FILE *fa;
    int len;
    int j;
    printf("Ingresa el nombre del archivo: ");
    gets(nameFile);

    len=strlen(nameFile);
    nameFile[len]='.';
    nameFile[len+1]='t';
    nameFile[len+2]='x';
    nameFile[len+3]='t';
    
    fa=fopen(nameFile,"w");
    fprintf(fa,"| Matricula | Apellido Paterno | Apellido Materno | Nombre              | Edad |  Sexo     |\n");
    for(j=0;j<i;j++)
    {
        if(alumnos[j].status)
        {
            fprintf(fa,"| %9d | %-16s | %-17s| %-19s | %4d |",alumnos[j].matricula,alumnos[j].apPat,alumnos[j].apMat,alumnos[j].nombre,alumnos[j].edad);
            if(alumnos[j].sexo=='H')
            {
                fprintf(fa," MASCULINO |\n");
            }
            else
            {
                fprintf(fa," FEMENINO  |\n");
            }
        }
    }
    fclose(fa);

}

void printAlumTab(StructAlum alumnos)
{
    printf("| %9d | %-16s | %-17s| %-19s | %4d |",alumnos.matricula,alumnos.apPat,alumnos.apMat,alumnos.nombre,alumnos.edad);
    if(alumnos.sexo=='H')
    {
        printf(" MASCULINO |");
    }
    else
    {
        printf(" FEMENINO  |");
    }
}
//case 9
void printDelAlum(StructAlum alumnos[],int del)
{
    FILE *fa;
    int i;
    char reng[100];
    fa=fopen("regEliminado.txt","r");
    if(fa)
    {   
        for(i=0;i<del;i++)
        {
            while(!feof(fa))
            {
                fgets(reng,100,fa);
                printf("%s",reng);
            }
            fclose(fa);
        }
    }
    else
    {
        printf("El archivo de alumnos eliminados no existe");
    }
}