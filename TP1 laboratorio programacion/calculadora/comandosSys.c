#include <stdio.h>
#include <stdlib.h>


/** \brief limpia la pantalla de consola segun se trate de windows o linux
 *
 */
void utn_limpiarPantalla(void)
{
    #ifdef _unix_
        system("clear");
    #else
        system("cls");
    #endif

}
/** \brief limpia el buffer de entrada standar de memoria segun se trate de windows o linux
 *
 */
void utn_limpiarBuffer(void)
{
    #ifdef _unix_
        __fpurge(stdin);
    #else
        fflush(stdin);
    #endif
}
