#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


#include <string.h>

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ret = 0;
    char idAux[50];
    char nombreAux[50];
    char horasAux[50];
    char sueldoAux[50];

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasAux,sueldoAux);

    if ( pFile != NULL && pArrayListEmployee != NULL)
    {
        while( !feof(pFile))
        {
            if ( pFile != NULL )
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasAux,sueldoAux);
                if (ll_add(pArrayListEmployee, employee_newParametros(idAux,nombreAux,horasAux,sueldoAux)) == 0 )
                {
                    ret = 1;
                }
            }
        }
    }
    return ret;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ret = 0;

    Employee* aux;
    int len;
    int leido = 0;
    int agregado = 0;

    if ( pFile != NULL && pArrayListEmployee != NULL)
    {

        while( !feof(pFile))
        {

            aux = employee_new();

            leido += fread(aux,sizeof(Employee),1,pFile);

            if (ll_add(pArrayListEmployee, aux) == 0)
            {
                agregado++;
                ret = 1;
            }

        }

        if ( leido != agregado)
        {
            len = ll_len(pArrayListEmployee);
            ll_remove(pArrayListEmployee,len);
        }

    }

    return ret;
}



