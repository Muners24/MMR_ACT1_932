/* Mejía Martínez, Ramón    372099                                                                                          */
/* 1 de noviembre de 2023                                                                                                    */
/* Programa de gestion de alumnos usando structs, implementacion de curp y distintos metodos de busqueda y ordenacion       */
/* MMR_ACT11_932                                                                                                            */

#include "CURPLIB.h"

#define STR 100
#define L 30
#define LN 50
#define STC 2000

typedef struct _name
{
    char appat[L];
    char apmat[L];
    char nombre[LN];
}StructName;

typedef struct _edad
{
    char anio[5];
    char mes[3];
    char dia[3];
}StructEdad;

typedef struct _alum
{
    int status;
    int matricula;
    StructName FullNombre;
    StructEdad FechaNacim;
    char estado[3];
    char sexo;
    int edad;
    char curp[18];
}StructAlum;

int msgs(void);
void menu(void);

int agregarMenu(StructAlum alumnos[],int i);
void menuBusc(StructAlum alumnos[],int i,bool orden);
int buscarAlumSec(StructAlum alumnos[],int i,int num);
int buscarAlumBin(StructAlum alumnos[],int i,int num);
void printAlum(StructAlum alumnos);

int genMatri(StructAlum alumnos[],int i);
void genM_Name(StructAlum alumnos[],int i);
void genH_Name(StructAlum alumnos[],int i);
void genAp(StructAlum alumnos[],int i);
void randAlum(StructAlum alumnos[],int i);
void genEst(char estado[]);
int calcularEdad(int anio,int mes,int dia);
int archivoTxt(StructAlum alumnos[],int i,int band);
void mergeSort(StructAlum alumnos[],int izq,int derch);
void fusionMergeSort(StructAlum alumnos[],int izq,int med,int derch);
void heapSort(StructAlum alumnos[],int n);
void adjustHeap(StructAlum alumnos[],int n,int raiz);
void swap(StructAlum *x,StructAlum *y);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int msgs(void)
{
    printf("Menu \n\n");
    printf("1) Agregar\n");
    printf("2) Eliminar Registro\n");
    printf("3) Buscar\n");
    printf("4) Ordenar\n");
    printf("5) Imprimir\n");
    printf("6) Archivo Texto\n");
    printf("7) Salir\n");
    return validNum("Escoge una opcion: ",1,7);
}

void menu(void)
{
    StructAlum alumnos[STC];
    int op;
    int pos;
    int i=0,j;
    int txtband=1;
    bool orden=false;
    do
    {
        system("cls");
        op=msgs();
        system("cls");
        switch(op)
        {
            case 1:
                i=agregarMenu(alumnos,i);
                orden=false;
                break;
            case 2:
                printf("Eliminar alumno\n\n");
                if(i>0)
                {

                    pos=buscarAlumSec(alumnos,i,validNum("Ingresa la matricula del alumno que desea eliminar: ",300000,399999));
                    if(pos!=-1)
                    {
                        printf("Numero: %d\n",pos); 
                        printf("Lugar de nacimiento: %s\n",alumnos[pos].estado);
                        printf("Apellido Paterno: %s\n",alumnos[pos].FullNombre.appat);
                        printf("Apellido Materno: %s\n",alumnos[pos].FullNombre.apmat);
                        printf("Nombre: %s\n",alumnos[pos].FullNombre.nombre);
                        printf("Fecha de nacimiento: %d-%d-%d\n",atoi(alumnos[pos].FechaNacim.dia),atoi(alumnos[pos].FechaNacim.mes),atoi(alumnos[pos].FechaNacim.anio));
                        printf("Edad: %d\n",alumnos[pos].edad);
                        printf("Sexo: ");
                        if(alumnos[pos].sexo=='H')
                        {
                            printf(" HOMBRE\n");
                        }
                        else
                        {
                            printf(" MUJER\n");
                        }
                        printf("Curp: %s\n",alumnos[pos].curp);
                        printf("\nDesea eliminar a este alumno?\n");
                        printf("1) Si\n");
                        printf("2) No\n");
                        if(validNum("Escoge una opcion: ",1,2)==1)
                        {
                            alumnos[pos].status=0;
                            printf("\nSe elimino este alumno\n");
                        }
                    }
                    else
                    {
                        printf("\nEse alumno no existe\n");
                    }
                }
                else
                {
                    printf("\nAun no hay alumnos registrados\n");
                }
                break;
            case 3:
                if(i>0)
                {
                    menuBusc(alumnos,i,orden);
                }
                else
                {
                    printf("\nAun no hay alumnos registrados\n");
                }
                break;
            case 4:
                if(!orden)
                {
                    if(i>=1000)
                    {
                        mergeSort(alumnos,0,i-1);
                    }
                    else
                    {
                        heapSort(alumnos,i);
                    }
                    printf("Se ordenaron los registros\n");
                    orden=true;
                }
                break;
            case 5:
                printf("Imprimir alumnos\n\n");
                if(i>0)
                {
                    printf("| No  | Est | Matri  | Apellido Paterno | Apellido Materno | Nombre              | Ed  | Sex |        CURP        |\n");
                    for(j=0;j<i;j++)
                    {
                        printf("| %3d ",j);
                        printAlum(alumnos[j]);
                        if((j+1)%40==0)
                        {
                            printf("\n");
                            system("pause");
                            printf("\n");
                        }
                    }
                }
                else
                {
                    printf("\nAun no hay alumnos registrados\n");
                }
                break;
            case 6:
                if(i>0)
                {
                    txtband=archivoTxt(alumnos,i,txtband);
                    printf("Se genero un archivo de texto de los registros\n");
                }
                else
                {
                    printf("\nAun no hay alumnos registrados\n");
                }
                break;
        }
        printf("\n");
        system("pause");
    }while(op!=7);
}
//case 1
int agregarMenu(StructAlum alumnos[],int i)
{
    int op,s;
    int j;
    int band=1;
    int validmatri,matri;
    printf("Agregar alumno\n\n");
    printf("a) Manual\n");
    printf("b) Automatico\n");
    printf("c) Regresar\n");
    printf("Escoge una opcion: ");
    do
    {
        op=getch();
        if(op>96)
        {
            if(op<100)
            {
                printf("%c",op);
                getch();
                band=0;
            }
        }
    }while(band);

    switch(op)
    {
        case 97:
            system("cls");
            printf("Agregar alumno manual\n\n");
            alumnos[i].status=1;
            do
            {
                matri=validNum("\nIngrese su matricula: ",300000,399999);
                validmatri=buscarAlumSec(alumnos,i,matri);
                if(validmatri!=-1)
                {
                    printf("\nEsa matricula ya existe\n");
                }
            }while(validmatri!=-1);
            alumnos[i].matricula=matri;
            s=datos(alumnos[i].FullNombre.nombre,alumnos[i].FullNombre.appat,alumnos[i].FullNombre.apmat,alumnos[i].FechaNacim.anio,alumnos[i].FechaNacim.mes,alumnos[i].FechaNacim.dia,alumnos[i].estado);
            if(s==1)
            {
                alumnos[i].sexo='H';
            }
            else
            {
                alumnos[i].sexo='M';
            }
            curpGen(alumnos[i].FullNombre.nombre,alumnos[i].FullNombre.appat,alumnos[i].FullNombre.apmat,alumnos[i].FechaNacim.anio,alumnos[i].FechaNacim.mes,alumnos[i].FechaNacim.dia,alumnos[i].estado,alumnos[i].curp,alumnos[i].sexo);
            alumnos[i].edad=calcularEdad(atoi(alumnos[i].FechaNacim.anio),atoi(alumnos[i].FechaNacim.mes),atoi(alumnos[i].FechaNacim.dia));
            i++; 
            break;
        case 98:
            if(i+100<=2000)
            {
                for(j=0;j<100;j++)
                {
                    randAlum(alumnos,i++);
                }
                printf("\n\nSe agregaron 100 alumnos\n");
            }
            else
            {
                if(i!=2000)
                {
                    printf("\nEl limite se sobrepasara si se generan todos los registros\nSe generaran hasta que llegue al limite de 2000 alumnos");
                    for(i=0;i<2000;i++)
                    {
                        randAlum(alumnos,i);
                    }
                }
                else
                {
                    printf("\nNo se pueden generar mas registros\n");
                }
            }
            break;
    }
    return i;
}
//case5
void printAlum(StructAlum alumnos)
{
    printf("| %s  | %d | %-16s | %-17s| %-19s | %3d |  %c  |",alumnos.estado,alumnos.matricula,alumnos.FullNombre.appat,alumnos.FullNombre.apmat,alumnos.FullNombre.nombre,alumnos.edad,alumnos.sexo);
    printf(" %s |\n",alumnos.curp);
}
//case 3
void menuBusc(StructAlum alumnos[],int i,bool orden)   
{
    int pos;
    printf("Busqueda\n\n");
    
    if(orden)
    {
        pos=buscarAlumBin(alumnos,i,validNum("Ingresa la matricula del alumno que desea buscar: ",300000,399999));
        if(pos!=-1)
        {
            printf("Numero: %d\n",pos); 
            printf("Lugar de nacimiento: %s\n",alumnos[pos].estado);
            printf("Apellido Paterno: %s\n",alumnos[pos].FullNombre.appat);
            printf("Apellido Materno: %s\n",alumnos[pos].FullNombre.apmat);
            printf("Nombre: %s\n",alumnos[pos].FullNombre.nombre);
            printf("Fecha de nacimiento: %d-%d-%d\n",atoi(alumnos[pos].FechaNacim.dia),atoi(alumnos[pos].FechaNacim.mes),atoi(alumnos[pos].FechaNacim.anio));
            printf("Edad: %d\n",alumnos[pos].edad);
            printf("Sexo: ");
            if(alumnos[pos].sexo=='H')
            {
                printf(" HOMBRE\n");
            }
            else
            {
                printf(" MUJER\n");
            }
            printf("Curp: %s\n",alumnos[pos].curp);
        }
        else
        {
            printf("\nNo se encontro al alumno\n");
        }
    }
    else
    {
        pos=buscarAlumSec(alumnos,i,validNum("Ingresa la matricula del alumno que desea buscar: ",300000,399999));
        if(pos!=-1)
        {
            printf("Numero: %d\n",pos); 
            printf("Lugar de nacimiento: %s\n",alumnos[pos].estado);
            printf("Apellido Paterno: %s\n",alumnos[pos].FullNombre.appat);
            printf("Apellido Materno: %s\n",alumnos[pos].FullNombre.apmat);
            printf("Nombre: %s\n",alumnos[pos].FullNombre.nombre);
            printf("Fecha de nacimiento: %d-%d-%d\n",atoi(alumnos[pos].FechaNacim.dia),atoi(alumnos[pos].FechaNacim.mes),atoi(alumnos[pos].FechaNacim.anio));
            printf("Edad: %d\n",alumnos[pos].edad);
            printf("Sexo: ");
            if(alumnos[pos].sexo=='H')
            {
                printf(" HOMBRE\n");
            }
            else
            {
                printf(" MUJER\n");
            }
            printf("Curp: %s\n",alumnos[pos].curp);
        }
        else
        {
            printf("\nNo se encontro al alumno\n");
        }
    }
        
}

//case 3-1
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
//case 3-2
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

//Generar Alumno
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
        strcopy(alumnos[i].FullNombre.nombre,h_name[rand()%100]);
    }
    else
    {
        strcopy(alumnos[i].FullNombre.nombre,h_name[rand()%100]);
        strConcat(alumnos[i].FullNombre.nombre,h_name[rand()%100]);
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
        strcopy(alumnos[i].FullNombre.nombre,m_name[rand()%100]);
    }
    else
    {
        strcopy(alumnos[i].FullNombre.nombre,m_name[rand()%100]);
        strConcat(alumnos[i].FullNombre.nombre,m_name[rand()%100]);
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
        strcopy(alumnos[i].FullNombre.appat,ap[rand()%99]);
        strcopy(alumnos[i].FullNombre.apmat,ap[rand()%99]);
    }
    else
    {
        strcopy(alumnos[i].FullNombre.appat,ap[rand()%99]);
        alumnos[i].FullNombre.apmat[0]='X';
        alumnos[i].FullNombre.apmat[1]='\0';
    }
}

void randAlum(StructAlum alumnos[],int i)
{ 
    int born[3];
    int s;
    int ri=1900,rf=2023,rango=(rf-ri+1);
    char estadoN[3];
    alumnos[i].status=1;
    alumnos[i].matricula=genMatri(alumnos,i);

    s=rand()%2;
    if(s)
    {
        alumnos[i].sexo='H';
    }
    else
    {
        alumnos[i].sexo='M';
    }

    if(s)
    {
        genH_Name(alumnos,i);
    }
    else
    {
        genM_Name(alumnos,i);
    }
    
    genAp(alumnos,i);
    
    genEst(alumnos[i].estado);
    strcopy(estadoN,alumnos[i].estado);

    //fecha nacimiento
    {
        bool leap=false;
        born[2]=(rand()%rango)+ri; 
        itoa(born[2],alumnos[i].FechaNacim.anio,10);

        born[1]=(rand()%12)+1;
        itoa(born[1],alumnos[i].FechaNacim.mes,10);
        if(born[1]>=10)
        {
            itoa(born[1],alumnos[i].FechaNacim.mes,10);
        }
        else
        {
            itoa(born[1],alumnos[i].FechaNacim.mes,10);
            alumnos[i].FechaNacim.mes[1]=alumnos[i].FechaNacim.mes[0];
            alumnos[i].FechaNacim.mes[0]='0';
        }

        if(born[1]==2)   //mes           
        {   
            if(born[2]%4==0)   //año  
            {
                leap=true;        
            }
        }
        born[0]=(rand()%diaValid(born[1],leap))+1;
        if(born[0]>=10)
        {
            itoa(born[0],alumnos[i].FechaNacim.dia,10);
        }
        else
        {
            itoa(born[0],alumnos[i].FechaNacim.dia,10);
            alumnos[i].FechaNacim.dia[1]=alumnos[i].FechaNacim.dia[0];
            alumnos[i].FechaNacim.dia[0]='0';
        }

        alumnos[i].edad=calcularEdad(born[2],born[1],born[0]);
    }

    
    curpGen(alumnos[i].FullNombre.nombre,alumnos[i].FullNombre.appat,alumnos[i].FullNombre.apmat,alumnos[i].FechaNacim.anio,alumnos[i].FechaNacim.mes,alumnos[i].FechaNacim.dia,alumnos[i].estado,alumnos[i].curp,alumnos[i].sexo);
    
    alumnos[i].curp[11]=estadoN[0];
    alumnos[i].curp[12]=estadoN[1];

}

void genEst(char estado[])
{
    int E;
    char estList[33][3]={
    "AS","BC","BS","CC","CS","CH","CM","CL","MX","DG",
    "GT","GR","HG","JC","EM","MN","MS","NT","NL","OC",
    "PL","QT","QR","SP","SL","SR","TC","TS","TL","VZ",
    "YN","ZS","NE"
    };


    E=rand()%33;

    estado[0]=estList[E][0];
    estado[1]=estList[E][1];
    estado[2]='\0';
}

int calcularEdad(int anio,int mes,int dia)
{
    int edad;
    time_t t;
    t=time(NULL);
    struct tm *fecha;
    fecha=localtime(&t);

    edad=(fecha->tm_year+1900)-anio;
    if(mes>fecha->tm_mon+1)
    {
        edad--;
    }
    else
    {
        if(mes==fecha->tm_mon+1)
        {
            if(dia>fecha->tm_mday)
            {
                edad--;
            }
        }
    }
    return edad;
}

int archivoTxt(StructAlum alumnos[],int i,int band)
{
    int j;
    FILE *pa;
    if(band)
    {
        pa=fopen("registros.txt","a");
        char str[119]={"| No   | Est | Matri  | Apellido Paterno | Apellido Materno | Nombre              | Ed  | Sex |        CURP        |\n"};
        fprintf(pa,"%s",str);

        for(j=0;j<i;j++)
        {
            if(alumnos[j].status)
            {
                fprintf(pa,"| %4d ",j);
                fprintf(pa,"| %s  | %d | %-16s | %-17s| %-19s | %3d |  %c  |",alumnos[j].estado,alumnos[j].matricula,alumnos[j].FullNombre.appat,alumnos[j].FullNombre.apmat,alumnos[j].FullNombre.nombre,alumnos[j].edad,alumnos[j].sexo);
                fprintf(pa," %s |\n",alumnos[j].curp);
            } 
        }
    }
    else
    {
        pa=fopen("registros.txt","w");
        char str[119]={"| No   | Est | Matri  | Apellido Paterno | Apellido Materno | Nombre              | Ed  | Sex |        CURP        |\n"};
        fprintf(pa,"%s",str);

        for(j=0;j<i;j++)
        {
            if(alumnos[j].status)
            {
                fprintf(pa,"| %4d ",j);
                fprintf(pa,"| %s  | %d | %-16s | %-17s| %-19s | %3d |  %c  |",alumnos[j].estado,alumnos[j].matricula,alumnos[j].FullNombre.appat,alumnos[j].FullNombre.apmat,alumnos[j].FullNombre.nombre,alumnos[j].edad,alumnos[j].sexo);
                fprintf(pa," %s |\n",alumnos[j].curp);
            } 
        }
    }
        
    fclose(pa);

    return 0;
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