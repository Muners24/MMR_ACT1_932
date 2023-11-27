#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fa;
    int j=0;
    char c;
    fa=fopen("datos.dat","rb");

    while(!feof(fa))
    {
        fread(&c,sizeof(char),1,fa);
        printf("%c",c);
        if(j%80==0)
        {
            printf("\n");
        }
        j++;
    }
        
    return 0;
}