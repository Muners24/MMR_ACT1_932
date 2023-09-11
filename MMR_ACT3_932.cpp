/* Mejía Martínez, Ramón    372099                       */
/* 10 de septiembre de 2023                              */
/* Estructuras de control, optimizacion, if con && o ||  */
/* MMR_ACT3_932                                          */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ACUARIO  "Se despeja el horizonte para ti y ¡las cosas que no marchaban bien\ncomienzan a fluir! En el amor aprendes a disfrutar de las pequeñas cosas"
#define PISIS "Una agradable e importante charla con la familia repara tus fuerzas internas. Mantén firme tu fuerza interior para que\npuedas vencer a quienes en este momento desean hacerte daño"
#define ESCORPION "No pierdas el buen ánimo y aleja de ti el pesimismo. ¡Tu destino está en tus propias manos! Los astros contribuyen\nal fácil fluir de ideas brillantes que aumentan tu capacidad mental"
#define SAGITARIO "Cuida juiciosamente tu dinero. ¡Llegan momentos mucho más difíciles que los actuales! En lo laboral, te enfrentas a\nalgunos problemas derivados de la recurrencia en algunos errores"
#define LEO "Por estos días circunstancias inesperadas te someten a un gran exceso de trabajo. ¡Ten cuidado! Te\nagotas rápidamente y disminuye tu claridad mental"
#define VIRGO "Es hora de vencer y alejar de ti prejuicios y todo aquello que no contribuye a la estabilidad laboral. Enfrentas algunos\nconflictos familiares en los que eres malinterpretado. Aclara las cosas rápidamente"
#define CAPRICORNIO "Expulsa de ti los resentimientos y haz todo lo posible por alcanzar tu máximo\ndesarrollo espiritual. Cupido te reta con sus flechas. ¡Abre tu corazón y experimenta el amor!"
#define LIBRA "Hoy enfrentas una delicada situación familiar. ¡Pide a tu ángel guardián que te\nguíe por el mejor camino al tomar las decisiones que debes tomar!"
#define TAURO "La adquisición de nuevos conocimientos te brinda la oportunidad de crecer frente al mundo profesional y te llenas\nde nuevas e importantes perspectivas"
#define GEMINIS "Estás preparado para manejar con destreza tus capacidades y conocimientos, pero ¡confía en que eres\ncapaz de ello! Necesitas urgentemente salir a recrearte"
#define CANCER "Aléjate de las sombras del pasado que no te dejan avanzar hacia el mañana! Ten en cuenta que ¡de lo que hagas o\ndejes de hacer hoy depende tu mañana! No abandones el descanso y la buena alimentación"
#define ARIES "El exceso de sensibilidad que sientes en este día te lleva a tener reacciones sobredimensionadas\nen el trabajo que no te favorecen en absoluto. ¡Procura controlarte en todo momento!"
int main()
{
    int op;
    //problema 1
    int cal1,cal2,cal3;
    float prom;
    //problema 2,3
    int com,jug;
    srand(time(NULL));
    //problema 4,5,6
    int num1,num2,num3;
    //problema 7
    int dia,mes;
    do
    {
        printf("Menu\n");
        printf("1) Promedio y leyenda\n");
        printf("2) Piedra, papel o tijeras (if)\n");
        printf("3) Piedra, papel o tijeras (switch)\n");
        printf("4) Numero mayor\n");
        printf("5) Numero medio\n");
        printf("6) Numeros ascendentes\n");
        printf("7) Horoscopo\n");
        printf("8) Salir\n");
        printf("Elige una opcion: ");
        scanf("%d",&op);
        system("cls");

        switch(op)
        {
            case 1:
                printf("Promedio de 3 califiaciones y leyenda\n\n");
                printf("Ingresa la calificacion 1: ");
                scanf("%d",&cal1);
                printf("Ingresa la calificacion 2: ");
                scanf("%d",&cal2);
                printf("Ingresa la calificacion 3: ");
                scanf("%d",&cal3);
                
                prom=(cal1+cal2+cal3)/3.0;
                printf("Tu promedio es: %.2f\n",prom);
                if(prom>=80)
                {
                    if(prom>=98)
                    {
                        if(prom>100)
                        {
                            printf("Error en promedio");
                        }
                        else
                        {
                            printf("Excelente");
                        }
                    }
                    else
                    {
                        if(prom >= 90)
                        {
                            printf("Muy bien");
                        }
                        else
                        {
                            printf("Bien");
                        }
                    }
                }
                else
                {
                    if( prom >= 60)
                    {
                        if(prom >= 70)
                        {
                            printf("Regular");
                        }
                        else
                        {
                            printf("Suficiente");
                        }
                    }
                    else
                    {
                        if(prom>=30)
                        {
                            printf("Extraordinario");
                        }
                        else
                        {
                            printf("Repetir");
                        }
                    }
                }
                break;

            case 2:
                com=rand()%(3-1+1)+1;
                printf("Piedra, papel o tijeras\n\n");
                printf("1) Piedra\n");
                printf("2) Papel\n");
                printf("3) Tijeras\n");
                scanf("%d",&jug);
                printf("Jugada de la computadora: %d\n",com);
                if(jug!=com)
                {
                    if(jug==1)
                    {
                        if(com==2)
                        {
                            printf("\nPerdiste\nPapel cubre piedra");
                        }
                        else
                        {
                            printf("\nGanaste\nPiedra rompe tijeras");
                        }
                    }
                    else
                    {
                                
                        if(jug==2)
                        {
                            if(com==1)
                            {
                                printf("\nGanaste\nPapel cubre piedra");
                            }
                            else
                            {
                                printf("\nPerdiste\nTijeras cortan papel");
                            }
                        }
                        else
                        {
                            if(jug==3)
                            {
                                if(com==1)
                                {
                                    printf("\nPerdiste\nPiedra rompe tijeras");
                                }
                                else
                                {
                                    printf("\nGanaste\nTijeras cortan papel");
                                }
                            }
                        }
                    }
                }
                else
                {
                    printf(" Empate ");
                }
                break;

            case 3:
                com=rand()%(3-1+1)+1;
                printf("Piedra, papel o tijeras\n\n");
                printf("1) Piedra\n");
                printf("2) Papel\n");
                printf("3) Tijeras\n");
                scanf("%d",&jug);
                printf("Jugada de la computadora: %d\n",com);

                if(jug!=com)
                {
                    switch(jug)
                    {
                        case 1:
                            switch(com)
                            {
                                case 2:
                                    printf("Perdiste \nPapel cubre piedra");
                                break;

                                case 3:
                                    printf("Ganaste \nPiedra rompe tijeras");
                                break;

                                default:
                                break;
                            }
                        break;

                        case 2:
                            switch(com)
                            {
                                case 1:
                                    printf("Ganaste \nPapel cubre piedra");
                                break;

                                case 3:
                                    printf("Perdiste \nTijeras cortan papel");
                                break;

                                default:
                                break;
                            }
                        break;

                        case 3:
                            switch(com)
                            {
                                case 1:
                                    printf("Perdiste \nPiedra rompe tijeras");
                                break;

                                case 2:
                                    printf("Ganaste \nTijeras cortan papel");
                                break;
                                
                                default:
                                break;
                            }
                        break;

                        default:
                        break;

                    } 
                }
                else
                {
                    printf("Empate");
                }
                break;    

            case 4:
                printf("Numero mayor de 3\n\n");
                printf("Ingresa el primer numero: ");
                scanf("%d",&num1);
                printf("Ingresa el segundo numero: ");
                scanf("%d",&num2);
                printf("Ingresa el tercer numero: ");
                scanf("%d",&num3);

                if(num1>num2 && num1>num3)
                {
                    printf("El numero mayor es el primero, su valor es: %d",num1);
                }
                else
                {
                    if(num2>num1 && num2>num3)
                    {
                        printf("El numero mayor es el segundo, su valor es: %d",num2);
                    }
                    else
                    {
                        if(num3>num1 && num3>num2)
                        {
                            printf("El numero mayor es el tercero, su valor es: %d",num3);   
                        }
                    }
                }

                break;  

            case 5:
                printf("Numero medio de 3\n\n");
                printf("Ingresa el primer numero: ");
                scanf("%d",&num1);
                printf("Ingresa el segundo numero: ");
                scanf("%d",&num2);
                printf("Ingresa el tercer numero: ");
                scanf("%d",&num3);

                if(num1<num2 && num1>num3 || num1<num3 && num1>num2)
                {
                    printf("El numero medio es el primero, su valor es: %d",num1);
                }
                else
                {
                    if(num2<num1 && num2>num3 || num2<num3 && num2>num1)
                    {
                        printf("El numero medio es el segundo, su valor es: %d",num2);
                    }
                    else
                    {
                        if(num3<num2 && num3>num1 || num3<num1 && num3>num2)
                        {
                            printf("El numero medio es el tercero, su valor es: %d",num3);   
                        }
                    }
                }

                break;  

            case 6:
                printf("Tres numeros ascendentes\n\n");
                printf("Ingresa el primer numero: ");
                scanf("%d",&num1);
                printf("Ingresa el segundo numero: ");
                scanf("%d",&num2);
                printf("Ingresa el tercer numero: ");
                scanf("%d",&num3);

                if(num1<num2 && num2<num3)
                {
                    printf("Los numeros ordenados son: %d %d %d",num1,num2,num3);
                }
                else
                {
                    if(num1<num3 && num3<num2)
                    {
                        printf("Los numeros ordenados son: %d %d %d",num1,num3,num2);
                    }
                    else
                    {
                        if(num2<num1 && num1<num3)
                        {
                            printf("Los numeros ordenados son: %d %d %d",num2,num1,num3);   
                        }
                        else
                        {
                            if(num2<num3 && num3<num1)
                            {
                                printf("Los numeros ordenados son: %d %d %d",num2,num3,num1);
                            }
                            else
                            {
                                if(num3<num1 && num1<num2)
                                {
                                    printf("Los numeros ordenados son: %d %d %d",num3,num1,num2);
                                }
                                else
                                {
                                    if(num3<num2 && num2<num1)
                                    {
                                        printf("Los numeros ordenados son: %d %d %d",num3,num2,num1);
                                    }
                                }
                            }
                        }
                    }
                }

                break;  

            case 7:
                printf("Horoscopo\n\n");
                printf("Ingresa tu mes de nacimiento: ");
                scanf("%d",&mes);
                printf("Ingresa tu dia de nacimiento: ");
                scanf("%d",&dia);

                switch(mes)
                {
                    case 1:
                        if(dia>=20)
                        {
                            if(dia<=31)
                            {
                                printf("Acuario\n");
                                printf("%s",ACUARIO);
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }
                        else
                        {
                            if(dia>=1)
                            {
                                printf("Capricornio\n");
                                printf("%s",CAPRICORNIO);    
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }

                        break;

                    case 2:
                        if(dia>=19)
                        {
                            if(dia<=29)
                            {
                                printf("Pisis\n");
                                printf("%s",PISIS);
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }
                        else
                        {
                            if(dia>=1)
                            {
                                printf("Acuario\n");
                                printf("%s",ACUARIO);    
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }

                        break;

                    case 3:
                        if(dia>=21)
                        {
                            if(dia<=31)
                            {
                                printf("Aries\n");
                                printf("%s",ARIES);
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }
                        else
                        {
                            if(dia>=1)
                            {
                                printf("Pisis\n");
                                printf("%s",PISIS);    
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }

                        break;

                    case 4:
                        if(dia>=20)
                        {
                            if(dia<=30)
                            {
                                printf("Tauro\n");
                                printf("%s",TAURO);
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }
                        else
                        {
                            if(dia>=1)
                            {
                                printf("Aries\n");
                                printf("%s",ARIES);    
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }

                        break;

                    case 5:
                        if(dia>=21)
                        {
                            if(dia<=31)
                            {
                                printf("Geminis\n");
                                printf("%s",GEMINIS);
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }
                        else
                        {
                            if(dia>=1)
                            {
                                printf("Tauro\n");
                                printf("%s",TAURO);    
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }

                        break;

                    case 6:
                        if(dia>=21)
                        {
                            if(dia<=30)
                            {
                                printf("Cancer\n");
                                printf("%s",CANCER);
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }
                        else
                        {
                            if(dia>=1)
                            {
                                printf("Geminis\n");
                                printf("%s",GEMINIS);    
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }
                        break;

                    case 7:
                        if(dia>=23)
                        {
                            if(dia<=30)
                            {
                                printf("Leo\n");
                                printf("%s",LEO);
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }
                        else
                        {
                            if(dia>=1)
                            {
                                printf("Cancer\n");
                                printf("%s",CANCER);    
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }

                        break;

                    case 8:
                        if(dia>=23)
                        {
                            if(dia<=31)
                            {
                                printf("Virgo\n");
                                printf("%s",VIRGO);
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }
                        else
                        {
                            if(dia>=1)
                            {
                                printf("Leo\n");
                                printf("%s",LEO);    
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }
                        
                        break;

                    case 9:
                        if(dia>=23)
                        {
                            if(dia<=30)
                            {
                                printf("Libra\n");
                                printf("%s",LIBRA);
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }
                        else
                        {
                            if(dia>=1)
                            {
                                printf("Virgo\n");
                                printf("%s",VIRGO);    
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }
                        
                        break;

                    case 10:
                        if(dia>=23)
                        {
                            if(dia<=31)
                            {
                                printf("Escorpion\n");
                                printf("%s",ESCORPION);
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }
                        else
                        {
                            if(dia>=1)
                            {
                                printf("Libra\n");
                                printf("%s",LIBRA);    
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }

                        break;

                    case 11:
                        if(dia>=23)
                        {
                            if(dia<=30)
                            {
                                printf("Sagitario\n");
                                printf("%s",SAGITARIO);
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }
                        else
                        {
                            if(dia>=1)
                            {
                                printf("Escorpion\n");
                                printf("%s",ESCORPION);    
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }

                        break;

                    case 12:
                        if(dia>=22)
                        {
                            if(dia<=31)
                            {
                                printf("Capricornio\n");
                                printf("%s",CAPRICORNIO);
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }
                        else
                        {
                            if(dia>=1)
                            {
                                printf("Sagitario\n");
                                printf("%s",SAGITARIO);    
                            }
                            else
                            {
                                printf("Ese dia no es valido");
                            }
                        }

                        break;        

                    default:
                        printf("Ese mes no es valido");    
                }
                break;
                
            case 8:
                printf("Saliendo del programa");
                break;  

            default:
                printf("Esa opcion no esta en el menu");    
        }
        printf("\n");
        system("pause");
        system("cls");
    }while(op!=8);
    return 0;
}

