#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char valor_A[10]="X";
char valor_B[10]="y";

char suma[10]="r";
char resta[10]="r";
char division[100]="r";
char multiplicacion[10]="r";
char factorial_1[30]="r1";
char factorial_2[30]="r2";

char menu1[]="\n\n1. Ingresar el 1er operando (A = ";
char menu2[]="\n2. Ingresar 2do operando (B = ";
char menu3[]="\n3. Calcular todas las operaciones";
    char submenu1[]="\n\t a) Calcular la suma (A+B) \n\t b) Calcular la resta (A-B) \n\t c) Calcular la division (A/B) \n\t d) Calcular la multiplicacion (A*B) \n\t e) Calcular el factorial (A!) \n";
char menu4[]="\n4. Informar resultados";
    char submenu2_a[]="\n\t a) ''El resultado de A+B es: ";
    char submenu2_b[]="\n\t b) ''El resultado de A-B es: ";
    char submenu2_c[]="\n\t c) ''El resultado de A/B es: ";
    char submenu2_d[]="\n\t d) ''El resultado de A*B es: ";
    char submenu2_e_1[]="\n\t e) ''El factorial de A es: ";
    char submenu2_e_2[]="\n\t y el factoria de B es: ";
char menu5[]="\n5. Salir\n";

/** \brief imprime un menu
 *
 */
void utn_imprimirMenu()
{
    printf("%s%s )",menu1,valor_A);
    printf("%s%s )",menu2,valor_B);
    printf("%s",menu3);
    printf("%s",submenu1);
    printf("%s",menu4);
    printf("%s%s ''",submenu2_a,suma);
    printf("%s%s ''",submenu2_b,resta);
    printf("%s%s ''",submenu2_c,division);
    printf("%s%s ''",submenu2_d,multiplicacion);
    printf("%s%s ",submenu2_e_1,factorial_1);
    printf("%s%s ''",submenu2_e_2,factorial_2);
    printf("%s",menu5);
}


/** \brief setea un valor en el menu
 *
 * \param valor[] char es el valor
 */
void utn_setValor_A(char valor[])
{
    strcpy(valor_A,valor);
}

/** \brief setea un valor en el menu
 *
 * \param valor[] char es el valor
 */
void utn_setValor_B(char valor[])
{
    strcpy(valor_B,valor);
}

/** \brief setea un valor en el menu
 *
 * \param valor[] char es el valor
 */
void utn_setSuma(char valor[])
{
    strcpy(suma,valor);
}

/** \brief setea un valor en el menu
 *
 * \param valor[] char es el valor
 */
void utn_setResta(char valor[])
{
    strcpy(resta,valor);
}

/** \brief setea un valor en el menu
 *
 * \param valor[] char es el valor
 */
void utn_setDivision(char valor[])
{
    strcpy(division,valor);
}

/** \brief setea un valor en el menu
 *
 * \param valor[] char es el valor
 */
void utn_setMultiplicacion(char valor[])
{
    strcpy(multiplicacion,valor);
}

/** \brief setea un valor en el menu
 *
 * \param valor[] char es el valor
 */
void utn_setFactorial_1(char valor[])
{
    strcpy(factorial_1,valor);
}

/** \brief setea un valor en el menu
 *
 * \param valor[] char es el valor
 */
void utn_setFactorial_2(char valor[])
{
    strcpy(factorial_2,valor);
}
