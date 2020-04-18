#include <stdio.h>
#include <stdlib.h>
#include "comandosSys.h"


/** \brief solicita un entero al usuario en un rango especificado
 *
 * \param mensaje[] char mensaje que pide el dato
 * \param mensajeError[] char mensaje de error
 * \param minimo int valor minimo del rango
 * \param maximo int valor maximo del rango
 * \return int entero es el entero ingresado por el usuario
 *
 */
int utn_pedirInt(char mensaje[], char mensajeError[], int minimo, int maximo)
{
    int entero;
    printf("%s",mensaje);
    scanf("%d",&entero);
    while(entero < minimo || entero > maximo)
    {
        printf("%s",mensajeError);
        scanf("%d",&entero);
    }

    return entero;
}

/** \brief valida si una cadena de caracteres recibida representa un numero entero
 *
 * \param dato[] char dato a ser validado
 * \return int respuesta devuelve 1 si la cadena representa un entero, y 0 si la cadena no representa un entero
 *
 */
int utn_validarInt(char dato[])
{
    int respuesta=1;

    for(int i=0 ; dato [i]!='\0' ; i++ )
        {
            if(dato[0]=='-')
                {
                    i++;
                }
            if(dato[i] < '0' || dato[i] > '9' )
            {
                respuesta = 0;
            }

        }

    return respuesta;
}


/** \brief solicita al usuario que ingrese una cadena de caracteres
 *
 * \param mensaje[] char mensaje que pide el dato
 * \param pCadena[] char puntero donde se gurdara lo ingresado por el usuario
 *
 */
void utn_pedirCadena(char mensaje[], char pCadena[] )
{
        printf("%s",mensaje);
        scanf("%s",pCadena);
}


/** \brief solicita al usuario que ingrese un caracter en un rango especificado
 *
 * \param mensaje[] char mensaje que pide el dato
 * \param mensajeError[] char mensaje en caso de error
 * \param desde char valor minimo del rango
 * \param hasta char valor maximo del rango
 * \return char caracter es el caracter ingresado
 *
 */
char utn_pedirChar(char mensaje[], char mensajeError[],char desde,char hasta)
{
    char caracter;
    printf("%s",mensaje);

    utn_limpiarBuffer();

    scanf("%c",&caracter);

    while(caracter < desde || caracter > hasta)
    {
        printf("%s",mensajeError);

        utn_limpiarBuffer();

        scanf("%c",&caracter);

    }
    return caracter;
}


/** \brief solicita al usuario que ingrese una cadena de caraceres que represente un numero entero
 *
 * \param mensaje[] char mensaje que solicita el dato
 * \return int retorno devuelve 1 si lo ingresado representa un numero entero, y 0 si lo ingresado no representa un entero
 *
 */
int utn_esEntero(char mensaje[])
{
    int retorno=1;
    char dato[20];

    printf("%s",mensaje);
    scanf("%s",dato);

    for(int i=0 ; dato [i]!='\0' ; i++ )
        {
            if(dato[0]=='-')
                {
                    i++;
                }
            if(dato[i] < '0' || dato[i] > '9' )
            {
                retorno = 0;
            }

        }

    return  retorno;
}








