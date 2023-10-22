

#include "C:\Users\ramon\OneDrive\Escritorio\MMR_ACT1_932\MMRLIB.h"

#define STRING 100

void validStrCurp(char str[]);
int datos(char name[],char appat[],char apmat[],char anio[],char mes[],char dia[],char estado[]);
void fecha(char anio[],char mes[],char dia[]);
void Est(char estado[]);
int dayValid(int month,bool leap);
char vocalInterna(char appat[]);
char consInterna(char str[]);

void curp(void);
char curp16(char anio[]);

int main()
{
    int op;
    do
    {
        system("cls");
        printf("Curp\n\n");
        printf("1) Generar curp\n");
        printf("2) Salir\n");
        op=validNum("Escoge una opcion: ",1,2);
        if(op==1)
        {
            curp();
        }
        printf("\n");
        system("pause");
    }while(op!=2);
    return 0;
}

int dayValid(int month,bool leap)
{
    int dayLimit;
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dayLimit=31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            dayLimit=30;
            break;
        case 2:
            if(leap==true)
            {
                dayLimit=29;
            }
            else
            {
                dayLimit=28;
            }
            break;
    }
    return dayLimit;
}

int datos(char name[],char appat[],char apmat[],char anio[],char mes[],char dia[],char estado[])
{
    //born[0]   Dia
    //born[1]   Mes
    //born[2]   Año
    
    int nap;
    int sex;
    system("cls");
    printf(" Datos\n\n");
    printf("Ingresa tu nombre: ");
    validStr(name);
    strM(name);

    printf("\nTiene apellido paterno?\n");
    printf("1) Si\n");
    printf("2) No\n");
    nap=validNum("Escoge una opcion: ",1,2);
    printf("\nIngresa tu apellido paterno: ");
    if(nap==1)
    {   
        printf("\nIngresa tu apelliddo materno: ");
        validStr(appat);
        strM(appat);
    }
    else
    {
        appat[0]='X';
        appat[1]='\0';
    }

    printf("\nTiene apellido materno?\n");
    printf("1) Si\n");
    printf("2) No\n");
    nap=validNum("Escoge una opcion: ",1,2);
    if(nap==1)
    {   
        printf("\nIngresa tu apelliddo materno: ");
        validStr(apmat);
        strM(apmat);
    }
    else
    {
        apmat[0]='X';
        apmat[1]='\0';
    }
    
    system("cls");
    printf("Fecha de nacimiento\n\n");
    fecha(anio,mes,dia);

    Est(estado);
    
    system("cls");
    sex=validNum("\nIngresa tu sexo\n1) Masculino\n2) Femenino\nElige una opcion: ",1,2);   

    return sex;
}

void curp(void)
{
    srand(time(NULL));
    //datos
    char rnd[2];
    char curp[19];
    char name[STRING],appat[STRING],apmat[STRING];
    char anio[4],mes[2],dia[2],estado[2],sex;
    char s;

    s=datos(name,appat,apmat,anio,mes,dia,estado);
    if(s==1)
    {
        sex='H';
    }
    else
    {
        sex='M';
    }
    
    curp[0]=appat[0];
    curp[1]=vocalInterna(appat);
    curp[2]=apmat[0];
    curp[3]=name[0];
    curp[4]=anio[2];
    curp[5]=anio[3];
    curp[6]=mes[0];
    curp[7]=mes[1];
    curp[8]=dia[0];
    curp[9]=dia[1];
    curp[10]=sex;
    curp[11]=estado[0];
    curp[12]=estado[1];
    curp[13]=consInterna(appat);
    curp[14]=consInterna(apmat);
    curp[15]=consInterna(name);
    curp[16]=curp16(anio);
    itoa(rand()%10,rnd,10);
    curp[17]=rnd[0];
    curp[18]='\0';
    system("cls");
    printf("\n");
    printf("Curp: ");
    strprint(curp);
}

void fecha(char anio[],char mes[],char dia[])
{
    int born[3];
    bool leap=false;
    born[2]=validNum("\nIngresa tu año de nacimiento: ",1900,2023);    
    itoa(born[2],anio,10);

    born[1]=validNum("\nIngresa tu mes de nacimiento: ",1,12);
    itoa(born[1],mes,10);
    if(born[1]>=10)
    {
        itoa(born[1],mes,10);
    }
    else
    {
        itoa(born[1],mes,10);
        mes[1]=mes[0];
        mes[0]=mes[1];
    }

    if(born[1]==2)   //mes           
    {   
        if(born[2]%4==0)   //año  
        {
            leap=true;        
        }
    }
    born[0]=validNum("\nIngresa tu dia de nacimiento: ",1,dayValid(born[1],leap));  //dia
    if(born[0]>=10)
    {
        itoa(born[0],dia,10);
    }
    else
    {
        itoa(born[0],dia,10);
        dia[1]=dia[0];
        dia[0]=dia[1];
    }
}

char vocalInterna(char appat[])
{
    int i;
    char vocal;
    for(i=1;appat[i]!='\0';i++)
    {
        if(appat[i]=='A')
        {
            vocal=appat[i];
            return vocal;
        }
        if(appat[i]=='E')
        {
            vocal=appat[i];
            return vocal;
        }
        if(appat[i]=='I')
        {
            vocal=appat[i];
            return vocal;
        }
        if(appat[i]=='O')
        {
            vocal=appat[i];
            return vocal;
        }
        if(appat[i]=='U')
        {
            vocal=appat[i];
            return vocal;
        }
    }
    return 'X';
}

char consInterna(char str[])
{
    int i;
    char cons;
    for(i=1;str[i]!='\0';i++)
    {
        if(str[i]!='A')
        {
            if(str[i]!='E')
            {
                if(str[i]!='I')
                {
                    if(str[i]!='O')
                    {
                        if(str[i]!='U')
                        {
                            cons=str[i];
                            return cons;
                        }
                    }
                }
            }
        }
    }
    return 'X';
}

void Est(char estado[])
{
    int E;
    char estList[33][3]={
    "AS","BC","BS","CC","CS","CH","CM","CL","CM","DG",
    "GT","GR","HG","JC","EM","MN","MS","NT","NL","OC",
    "PL","QT","QR","SP","SL","SR","TC","TS","TL","VZ",
    "YN","ZS","NE"
    };
    
    system("cls");
    printf("Estado\n\n");
    printf("1) Aguascalientes\n");
    printf("2) Baja California\n");
    printf("3) Baja California Sur\n");
    printf("4) Campeche\n");
    printf("5) Chiapas\n");
    printf("6) Chihuahua\n");
    printf("7) Ciudad de México\n");
    printf("8) Coahuila\n");
    printf("9) Colima\n");
    printf("10) Durango\n");
    printf("11) Guanajuato\n");
    printf("12) Guerrero\n");
    printf("13) Hidalgo\n");
    printf("14) Jalisco\n");
    printf("15) Estado de México\n");
    printf("16) Michoacán\n");
    printf("17) Morelos\n");
    printf("18) Nayarit\n");
    printf("19) Nuevo León\n");
    printf("20) Oaxaca\n");
    printf("21) Puebla\n");
    printf("22) Querétaro\n");
    printf("23) Quintana Roo\n");
    printf("24) San Luis Potosí\n");
    printf("25) Sinaloa\n");
    printf("26) Sonora\n");
    printf("27) Tabasco\n");
    printf("28) Tamaulipas\n");
    printf("29) Tlaxcala\n");
    printf("30) Veracruz\n");
    printf("31) Yucatán\n");
    printf("32) Zacatecas\n");
    printf("33) Extranjero\n");
    E=validNum("Escoge tu estado: ",1,33);

    estado[0]=estList[E-1][0];
    estado[1]=estList[E-1][1];
}

void validStrCurp(char str[])
{
    int i,valido,band=1;
    char c;
    i=0;
    do
    {
        valido=0;
        fflush(stdin);
        c=getch();
        if(c>='A')
        {
            if(c<='Z')
            {
                printf("%c",c);
                str[i]=c;
                valido++;
            }
        }
        if(c>='a')
        {
            if(c<='z')
            {
                printf("%c",c);
                str[i]=c;
                valido++;
            }
        }
        if(c=='ñ')
        {
            printf("%c",c);
            str[i]='X';
            valido++;
        }
        if(c=='Ñ')
        {   
            printf("%c",c);
            str[i]='X';
            valido++;
        }
        if(c=='\'')
        {
            printf("%c",c);
            str[i]='X';
            valido++;
        }
        if(c>=45)
        {
            if(c<=47)
            {
                printf("%c",c);
                str[i]='X';
                valido++;
            }
        }
        if(c==129)
        {
            printf("%c",c);
            str[i]='U';
            valido++;
        }
        if(c==132)
        {
            printf("%c",c);
            str[i]='X';
            valido++;
        }
        if(c==137)
        {
            printf("%c",c);
            str[i]='X';
            valido++;
        }
        if(c==139)
        {
            printf("%c",c);
            str[i]='X';
            valido++;
        }
        if(c==142)
        {
            printf("%c",c);
            str[i]='X';
            valido++;
        }
        if(c==148)
        {
            printf("%c",c);
            str[i]='X';
            valido++;
        }
        if(c==153)
        {
            printf("%c",c);
            str[i]='X';
            valido++;
        }
        if(c==154)
        {
            printf("%c",c);
            str[i]='U';
            valido++;
        }
        if(c==211)
        {
            printf("%c",c);
            str[i]='X';
            valido++;
        }
        if(c==216)
        {
            printf("%c",c);
            str[i]='X';
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
        if(c==' ')
        {
            if(i!=0)
            {
                if(str[i-1]!=' ')
                {
                    printf("%c",c);
                    str[i]=c;
                    valido++;
                }            
            }
        }

        
        if(c==13)   //'\0'
        {
            if(str[i-1]!=' ')
            {
                str[i]='\0';
                valido++;
                band=0;
            }
        }
        if(valido!=0)
        {
            i++;
        }
    }while(band);
}

char curp16(char anio[])
{
    if(anio[0]=='1')
    {
        return anio[2];
    }
    else
    {
        switch(anio[2])
        {
            case '0':
                return 'A';
                break;
            case '1':
                return 'B';
                break;
            case '2':
                return 'C';
                break;
        }
    }
}