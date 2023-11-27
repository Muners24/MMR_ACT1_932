#include <stdio.h>
#include <sys/stat.h>

#define L 30
#define LN 50

typedef int Tkey;

typedef struct _Wrkr{
    int status;
    Tkey NoEmpleado;
    char name[L];
    char apPat[LN];
    char apMat[LN];
    char sexo[15];
    char puesto[L];
    char estado[L];
    int age;
    Tkey telefono;
}TWrkr;

int main()
{
    FILE *fa;
    int cantidad;
    struct stat archivo;
    stat("datos.dat",&archivo);
    cantidad=archivo.st_size/sizeof(TWrkr);
    cantidad*=1.25;
    fa=fopen("NumeroRegistros.txt","w");
    fprintf(fa,"%d",cantidad);
    fclose(fa);
    return 0;
}

