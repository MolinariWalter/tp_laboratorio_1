#include <stdio.h>
#include <stdlib.h>
#include "ArraysEployees.h"

#include "menu.h"
#define T 1000
#define EXIT 9
int main()
{
    int ID = 100;
    int opcion = 0;
    int flagSort = 0;

    Employee emps[T];
    initEmployees(emps,T);

    /// aqui se harcodean los datos, pero si comentamos esta linea no ingresara a MODIFICAR, BAJA, INFORMAR hasta que se cargen datos
    harcoderEmployees(emps,5,&ID);

    do
    {
        system("cls");

        opcion = menu(" 1.ALTAS\n 2.MODIFICAR\n 3.BAJAS\n 4.INFORMAR\n 5.SALIR\n Ingrese una opcion : ","Error.\n",1,5,5);

        switch(opcion)
        {
            case 1:
                //loadEmployee retorna 0 si se cargaron los datos, -1 si hubo un error

                if( loadEmployee(emps,T,"\nCargar empleados.","\nError.",3,&ID) == 0 )
                {
                    printf("\nSe cargaron los datos correctamente.\n");
                    flagSort = 1;
                }else
                    {
                        printf("\nError al cargar los datos.\n");
                    }
            break;

            case 2:
                //modifyEmployee retorna 0 en caso de error, 1 si la modificacion fue correcta, -1 operacion cancelada
                //countEmployee cuenta los empleados cargados. no ejecuta esta opcion si no se cargaron empleados
                if(countEmployee(emps,T) == 0)
                {
                    printf("Primero debe cargar empleados para poder modificar.\n");
                }else
                    {
                         switch( modifyEmployee(emps,T))
                            {
                                case -1:
                                    printf("\nOperacion cancelada.\n");
                                break;
                                case 0:
                                    printf("\nNo se encontraron los datos del empleado.\n");
                                break;
                                case 1:
                                    printf("\nLos datos se modificaron correctamente.\n");
                                    flagSort = 1;
                                break;
                            }
                    }


            break;

            case 3:
                // retorna 0 si no encuentra id, 1 si confirma borrar datos, -1 operacion cancelada
                //countEmployee cuenta los empleados cargados. no ejecuta esta opcion si no se cargaron empleados
                 if(countEmployee(emps,T) == 0)
                {
                    printf("Primero debe cargar empleados para poder borrar datos.\n");
                }else
                    {
                         switch( removeEmployeeById(emps,T,ID))
                            {
                                case 0:
                                    printf("\nNo se encontraron los datos del empleado.\n");
                                break;
                                case 1:
                                    printf("\nLos datos se borraron correctamente.\n");
                                break;
                                case -1:
                                    printf("\nOperacion cancelada.\n");
                                break;
                            }
                    }
            break;

            case 4:
                //retorna -1 si no pudo informar correctamente (si no hay datos cargados,etc.) , retorna 0 si informo correctamente
                if( inform(emps,T,flagSort) == -1 )
                {
                    printf("\nError al informar.\n");
                }else
                    {
                        printf("\nInforme completado.\n");
                    }
                flagSort = 0;
            break;

            case 5:
                opcion = EXIT;
                printf("Saliendo del programa\n");

            break;
            default:

            break;
        }

        system("pause");
    }while(opcion != EXIT);

    return 0;
}
