#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Tkey;

typedef struct _Wrkr{
    int status;
    Tkey key;
    char name[30];
    char apPat[50];
    char apMat[50];
    char sexo[15];
    char puesto[30];
    char estado[30];
    int edad;
    Tkey telefono;
}TWrkr;

void leerbin(char name[]);

int main()
{
  
    char name[50];

    rename("datos.dat","datos.tmp");
    strcpy(name,"datos.dat");
    leerbin(name);
    printf("\n");
    system("pause");
    strcpy(name,"datos.bak");
    leerbin(name);
    printf("\n");
    system("pause");
    strcpy(name,"datosdel.bak");
    leerbin(name);
    printf("\n");
    system("pause");

         //332692
    return 0;
}

void leerbin(char name[])
{
    FILE *fa;
    TWrkr reg;
    int k=0;
    fa=fopen(name,"rb");
    if(fa)
    {
        while(fread(&reg,sizeof(TWrkr),1,fa)==1)
        {
            printf(" %-4d ",++k);
            //getch();
            printf("| %6d | %-22s | %-16s | %-17s | %-20s | 646%-7d | %-4d | %-10s | %s |\n",reg.key,reg.puesto,reg.apPat,reg.apMat,reg.name,reg.telefono,reg.edad,reg.sexo,reg.estado);
        }
        fclose(fa);
    }
}