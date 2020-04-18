#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "comandosSys.h"
#include "validar.h"
#include "calcular.h"


int main()
{
    char seguir='s';
    int opcion=0;
    int operando_A_int=0;
    int operando_B_int=0;
    char operando_A_char[10];
    char operando_B_char[10];

    int suma_int;
    int resta_int;
    float division_float;
    int multiplicacion_int;
    int factorial_A_int;
    int factorial_B_int;

    char suma_char[10];
    char resta_char[10];
    char division_char[10];
    char multiplicacion_char[10];
    char factorial_A_char[10];
    char factorial_B_char[10];

    int flag_A=0;
    int flag_B=0;
    int flag_operaciones=0;
    int flag_Division_cero=0;
    int flag_factorial_A=0;
    int flag_factorial_B=0;

    while(seguir=='s')
    {


        utn_imprimirMenu();
        opcion = utn_pedirInt("\nElija una operacion: ","\nError.Reintente...",1,9);

        switch(opcion)
        {
            case 1:
                ///pedir dato
                ///validar dato entero ---> sino reingresar
                ///setear el dato para imprimir en pantalla
                ///convertir dato a entero
                ///limpiar la pantalla
                ///contar la bandera de dato ingresado

                do
                {
                    utn_pedirCadena("\nIngrese el primer operando :",operando_A_char);
                    if( utn_validarInt(operando_A_char) )
                    {
                        utn_setValor_A(operando_A_char);
                        operando_A_int = atoi(operando_A_char);
                        printf("\nDatos cargados correctamente.\n");
                        flag_A=1;
                    }else
                        {
                            printf("\nError, el rango de valores es entre -1000 y 1000. Reingrese..\n");
                        }

                }while(flag_A != 1);

                break;
            case 2:

                do
                {
                    utn_pedirCadena("\nIngrese el segundo operando :",operando_B_char);
                    if( utn_validarInt(operando_B_char) )
                    {
                        utn_setValor_B(operando_B_char);
                        operando_B_int = atoi(operando_B_char);
                        printf("\nDatos cargados correctamente.\n");
                        flag_B=1;
                    }else
                        {
                            printf("\nError, el rango de valores es entre -1000 y 1000. Reingrese..\n");
                        }

                }while(flag_B != 1);

                break;
            case 3:
                ///solo si bandera_a=1 y bandera_b=1
                ///dividir solo si operando b no es cero
                ///factorial de a solo si es positivo
                ///factorial de b solo si es positivo
                ///---> bandera operaciones=1
                if(flag_A==1 && flag_B==1)
                {
                    suma_int = utn_sumar(operando_A_int,operando_B_int);

                    resta_int = utn_restar(operando_A_int,operando_B_int);

                    if(operando_B_int!=0)
                    {
                         division_float = utn_dividir(operando_A_int,operando_B_int);
                    }else
                        {
                            flag_Division_cero=1;
                        }

                    multiplicacion_int = utn_multiplicar(operando_A_int,operando_B_int);

                    if(operando_A_int>0)
                    {
                        factorial_A_int = utn_factorialFor(operando_A_int);
                    }else
                        {
                            flag_factorial_A=1;
                        }
                    if(operando_B_int>0)
                    {
                        factorial_B_int = utn_factorialFor(operando_B_int);
                    }else
                        {
                            flag_factorial_B=1;
                        }
                    printf("\nOperaciones calculadas.\n");
                    flag_operaciones=1;
                }else
                    {
                        printf("\nError, ingrese los dos operando para realizar las operaciones.\n");
                    }

                break;
            case 4:
                /// solo si bandera operaciones=1
                if(flag_operaciones==1)
                {
                    itoa(suma_int,suma_char,10);
                    utn_setSuma(suma_char);

                    itoa(resta_int,resta_char,10);
                    utn_setResta(resta_char);

                    if(flag_Division_cero!=1)
                    {
                        sprintf(division_char,"%.2f",division_float);
                        utn_setDivision(division_char);
                    }else
                        {
                            utn_setDivision("Error, no es posible dividir por cero");
                        }

                    itoa(multiplicacion_int,multiplicacion_char,10);
                    utn_setMultiplicacion(multiplicacion_char);

                    if(flag_factorial_A!=1)
                    {
                        itoa(factorial_A_int,factorial_A_char,10);
                        utn_setFactorial_1(factorial_A_char);
                    }else
                        {
                            utn_setFactorial_1("Error. No es posible calcular.");
                        }

                    if(flag_factorial_B!=1)
                    {
                        itoa(factorial_B_int,factorial_B_char,10);
                        utn_setFactorial_2(factorial_B_char);
                    }else
                        {
                            utn_setFactorial_2("Error. No es posible calcular.");
                        }
                    printf("\nResultados cargados.\n");
                }else
                    {
                        printf("\nError, ingrese los dos operando y realice las operaciones para \nmostrar los resultados.\n");
                    }

                break;
            case 5:
                seguir = 'n';
                printf("\nIngreso salir del programa.\n");
                break;

        }

    system("pause");
    utn_limpiarPantalla();
    }
    return 0;
}
