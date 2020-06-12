#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

#include "Functions.h"


#define ASCENDENTE 0
#define DESCENDENTE 1


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int ret = 0;
    FILE* pFile;

    pFile = fopen(path,"r");

    if ( pFile != NULL)
    {
        if (pArrayListEmployee != NULL && parser_EmployeeFromText(pFile,pArrayListEmployee) )
        {
            ret = 1;
        }
        fclose(pFile);
    }
    return ret;
}
/// ok!!

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ret = 0;
    FILE* pFile;

    pFile = fopen(path,"rb");

    if ( pFile != NULL)
    {
        if (pArrayListEmployee != NULL && parser_EmployeeFromBinary(pFile,pArrayListEmployee) )
        {
            ret = 1;
        }
        fclose(pFile);
    }
    return ret;
}
/// ok!!

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret = 0;

    if ( pArrayListEmployee != NULL)
    {

        if (ll_add(pArrayListEmployee,employee_load(pArrayListEmployee)) == 0)
        {
            ret = 1;
        }
    }

    return ret;
}
/// ok!!

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ret = 0;
    int i;
    int index = -1;
    int id;

    Employee* empAux;
    Employee emp;

    /// tamaño de la lista
    int len = ll_len(pArrayListEmployee);

    /// pido id
    UTN_getNumberInt(&id,"\nIngrese el id del empleado que quiere modifiar: ","\nError, id fuera de rango..",0,len,3);

    /// busco index del id
    for ( i=0;i<len;i++)
    {
        if ( employee_find_by_id( ll_get(pArrayListEmployee,i) ,id) == 1 )
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {

        /// obtengo el empleado en ese index y lo copio en aux
        empAux = (Employee*)ll_get(pArrayListEmployee,index);

        /// si no obtengo NULL
        if (empAux != NULL)
        {
            printf("\n%4s%25s%20s%8s\n", "id", "nombre", "horas Trabajadas", "sueldo");
            printf("%4d%25s%20d%8d\n\n",empAux->id,empAux->nombre,empAux->horasTrabajadas,empAux->sueldo);

            emp = *empAux;
            /// modifico el empleado auxiliar
            ret = modificar_empleado(&emp);

            if (ret==1)
            {
                *empAux = emp ;
            }
        }
    }

    return ret;
}
/// ok!!

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ret = 0;
    int index = -1;
    int id;

    int i;
    int len;

    if (pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        UTN_getNumberInt(&id,"Ingrese el id del empleado que quiere remover: ","\nError,el id esta fuera de rango.\n",0,2000,3);///

        /// busco index del id
        for ( i=0;i<len;i++)
        {
            if ( employee_find_by_id( ll_get(pArrayListEmployee,i) ,id) == 1 )
            {
                index = i;
                break;
            }
        }

        ll_remove(pArrayListEmployee,index);
        ret = 1;

    }

    return ret;
}
/// ok!!

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int ret = 0;
    int i;
    int cont = 1;
    Employee* aux;

    if (pArrayListEmployee != NULL)
    {
        int size = ll_len(pArrayListEmployee);


        for(i=0; i<size; i++)
        {

            if ( cont %45 == 0)
            {
                system("pause");
                printf("%4s%25s%20s%8s\n", "id", "nombre", "horas Trabajadas", "sueldo");
            }
            cont++;

            if(i==0)
            {
                printf("%4s%25s%20s%8s\n", "id", "nombre", "horas Trabajadas", "sueldo");
            }

            aux =(Employee*) ll_get(pArrayListEmployee, i);
            printf("%4d%25s%20d%8d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
            ret = 1;
        }
    }

    return ret;
}
/// ok!!

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ret = 0;

    if(pArrayListEmployee != NULL)
    {
        ret = ll_sort(pArrayListEmployee,employee_CompareByName,1);
    }

    return ret;
}
/// ok!!

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int ret = 0;
    int i;
    Employee* aux;
    FILE* pFile;

    char idAux[50];
    char horasAux[50];
    char sueldoAux[50];

    int size = ll_len(pArrayListEmployee);

    pFile = fopen(path,"w");

    if ( pFile != NULL)
    {
        if( pArrayListEmployee != NULL)
        {
            fprintf(pFile,"%s,%s,%s,%s\n","id","nombre","horas trabajadas","sueldo");

            for( i=0 ; i<size ; i++)
            {
                aux =(Employee*) ll_get(pArrayListEmployee, i);
                itoa(aux->id,idAux,10);
                itoa(aux->horasTrabajadas,horasAux,10);
                itoa(aux->sueldo,sueldoAux,10);

                fprintf(pFile,"%s,%s,%s,%s\n",idAux ,aux->nombre ,horasAux ,sueldoAux);
            }
        }
        fclose(pFile);
        ret = 1;
    }

    return ret;
}
/// ok!!

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ret = 0;
    int i;
    Employee* aux;

    FILE* pFile;

    int size = ll_len(pArrayListEmployee);

    int size_load = 0;


    pFile = fopen(path,"wb");

    if ( pFile != NULL)
    {

        if( pArrayListEmployee != NULL)
        {

            for( i=0 ; i<size ; i++)
            {
                aux =(Employee*) ll_get(pArrayListEmployee, i);

                size_load += fwrite(aux,sizeof(Employee),1,pFile);

                ret = 1;

            }
            if(size_load != size)
            {
                ret = -1;
            }
        }

        fclose(pFile);
    }

    return ret;
}
/// ok!!
