#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    char str[30];
    int i,valido,band,espacio;
    char tr;
    do
    {
        fflush(stdin);
        gets(str);
        band=1;
        espacio=1;
        i=0;
        do
        {
            valido=0;
            fflush(stdin);
            //c=getch();
            if(str[i]>='A')
            {
                if(str[i]<='Z')
                {
                    //printf("%c",str);
                    //str[i]=str;
                    valido++;
                }
            }

            if(str[i]>='a')
            {
                if(str[i]<='z')
                {
                    //printf("%c",str);
                    //str[i]=str;
                    valido++;
                }
            }

            if(str[i]=='ñ')
            {
                //printf("%c",str);
                str[i]='X';
                valido++;
            }

            if(str[i]=='Ñ')
            {   
                //printf("%c",str);
                str[i]='X';
                valido++;
            }

            if(str[i]=='\'')
            {
                //printf("%c",str);
                str[i]='X';
                valido++;
            }

            if(str[i]>=45)
            {
                if(str[i]<=47)
                {
                    //printf("%c",str);
                    str[i]='X';
                    valido++;
                }
            }

            if(str[i]==129)
            {
                //printf("%c",str);
                str[i]='U';
                valido++;
            }
            if(str[i]==132)
            {
                //printf("%c",str);
                //str[i]='X';
                valido++;
            }
            if(str[i]==137)
            {
                //printf("%c",str);
                str[i]='X';
                valido++;
            }
            if(str[i]==139)
            {
                //printf("%c",str);
                str[i]='X';
                valido++;
            }
            if(str[i]==142)
            {
                //printf("%c",str);
                str[i]='X';
                valido++;
            }
            if(str[i]==148)
            {
                //printf("%c",str);
                //str[i]='X';
                valido++;
            }
            if(str[i]==153)
            {
                //printf("%c",str);
                //str[i]='X';
                valido++;
            }
            if(str[i]==154)
            {
                //printf("%c",str);
                //str[i]='U';
                valido++;
            }
            if(str[i]==211)
            {
                //printf("%c",str);
                //str[i]='X';
                valido++;
            }
            if(str[i]==216)
            {
                //printf("%c",str);
                //str[i]='X';
                valido++;
            }
            //dieresis
            //129 u     129
            //132 a     132
            //137 e     137
            //139 i     139
            //148 o     142
            //A 142     148
            //E 211     153
            //I 216     154
            //O 153     211
            //U 154     216
            if(str[i]==' ')
            {
                if(i==0)
                {
                    printf("\nla cadena no puede iniciar con espacio\n");
                    printf("\nVuela a ingresar la cadena: ");
                    espacio=0;  
                }
                else
                {
                    if(str[i-1]==' ')
                    {
                        printf("\nla cadena no tener dos espacios consecutivos\n");
                        printf("\nVuela a ingresar la cadena: ");
                        espacio=0;
                    }
                    else
                    {
                        valido++;
                    }
                    
                }
            }

        
            if(str[i]=='\0')   //'\0'
            {
                if(str[i-1]!=' ')
                {
                    //str[i]='\0';
                    //valido++;
                    band=0;
                }
                else
                {
                    printf("\nla cadena no puede acabar con espacio\n");
                    printf("\nVuela a ingresar la cadena: ");
                    espacio=0;
                }
            }
            if(valido!=0)
            {
                i++;
            }
            else
            {
                if(espacio)
                {
                    printf("\nla cadena tiene caracteres invalidos\n");
                    printf("\nVuela a ingresar la cadena: ");
                }
                band=0;
            }
        }while(band);

    }while(valido==0);

    system("cls");
    printf("%s\n",str);
    system("pause");
    
    return 0;
}

