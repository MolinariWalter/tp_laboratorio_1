#include <stdio.h>
#include <stdlib.h>

/** \brief realiza la suma de dos numeros enteros
 *
 * \param a int primer operando
 * \param b int segundo operando
 * \return int resultado es el resultado de la operacion
 *
 */
int utn_sumar(int a, int b)
{
    int resultado;
    resultado=a+b;
    return resultado;
}

/** \brief realiza la resta de dos numeros enteros
 *
 * \param a int primer operando
 * \param b int segundo operando
 * \return int resultado es el resultado de la operacion
 *
 */
int utn_restar(int a, int b)
{
    int resultado;
    resultado=a-b;
    return resultado;
}

/** \brief realiza la multiplicacion de dos numeros enteros
 *
 * \param a int primer operando
 * \param b int segundo operando
 * \return int resultado es el resultado de la operacion
 *
 */
int utn_multiplicar(int a, int b)
{
    int resultado;
    resultado=a*b;
    return resultado;
}

/** \brief realiza la division entre dos numeros enteros
 *
 * \param a int primer operando
 * \param b int segundo operando
 * \return float resultado es el resultado de la operacion
 *
 */
float utn_dividir(int a, int b)
{
    float resultado;
    resultado=(float)a/b;
    return resultado;
}


/** \brief calcula el factorial de un numero entero
 *
 * \param valor int valor a ser calculado
 * \return int resultado es el factorial obtenido
 *
 */
int utn_factorialFor(int valor)
{
    int resultado=1;
    if(valor==0)
    {
        resultado=1;
    }else
        {
            for(int i=valor ; i>0 ; i--)
            {
                resultado=i*(resultado);
            }
        }

    return resultado;
}
