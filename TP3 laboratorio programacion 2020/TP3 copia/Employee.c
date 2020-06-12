#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#include "Functions.h"


Employee* employee_new()
{
    Employee* emp = NULL;

    emp = (Employee*) malloc(sizeof(Employee));

    return emp;
}
/// ok!!

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* emp = employee_new();
    if ( emp != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        employee_setId(emp,atoi(idStr));
        employee_setNombre(emp,nombreStr);
        employee_setHorasTrabajadas(emp,atoi(horasTrabajadasStr));
        employee_setSueldo(emp,atoi(sueldoStr));
    }
    return emp;
}
/// ok!!

int employee_setNombre(Employee* this,char* nombre)
{
    int ret = 0;

    if ( this != NULL && nombre != NULL )
    {
        strcpy(this->nombre, nombre);
        ret = 1;
    }

    return ret;
}
/// ok!!

int employee_getNombre(Employee* this,char* nombre)
{
    int ret = 0;

    if ( this != NULL && strcmp(nombre, strcpy(nombre, this->nombre)    ) == 0 )
    {
        ret = 1;
    }

    return ret;
}
/// ok!!

int employee_setSueldo(Employee* this,int sueldo)
{
    int ret = 0;

    if ( this != NULL)
    {
        this->sueldo = sueldo;
        ret = 1;
    }

    return ret;
}
/// ok!!

int employee_getSueldo(Employee* this,int* sueldo)
{
    int ret = 0;

    if ( this != NULL)
    {
        *sueldo = this->sueldo;
        ret = 1;
    }

    return ret;
}
/// ok!!

int employee_setId(Employee* this,int id)
{
    int ret = 0;

    if ( this != NULL)
    {
        this->id = id;
        ret = 1;
    }
    return ret;
}
/// ok!!

int employee_getId(Employee* this,int* id)
{
    int ret = 0;

    if ( this != NULL)
    {
        *id = this->id;
        ret = 1;
    }
    return ret;
}
/// ok!!

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ret = 0;

    if ( this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        ret = 1;
    }

    return ret;
}
/// ok!!

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int ret = 0;

    if ( this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        ret = 1;
    }

    return ret;
}
/// ok!!

int employee_CompareByName(void* e1, void* e2)
{
    int ret = 0;
    Employee* emp1 = (Employee*)e1;
    Employee* emp2 = (Employee*)e2;

    if ( emp1 != NULL && emp2 != NULL)
    {
        ret = strcmp(emp1->nombre, emp2->nombre);
    }

    return ret;
}
/// ok!!

int employee_CompareById(void* e1, void* e2)
{
    int ret = -10;
    Employee* emp1 = (Employee*)e1;
    Employee* emp2 = (Employee*)e2;

    if (emp1 != NULL && emp2 != NULL)
    {
        if(emp1->id > emp2->id)
        {
            ret = 1;
        }else
            {
                if(emp1->id < emp2->id)
                {
                    ret = -1;
                } else
                    {
                        ret = 0;
                    }
            }
    }

    return ret;
}
/// ok!!

Employee* employee_load(LinkedList* pArrayListEmployee)
{
    Employee* empAux = NULL;
    char id[20];
    char nombre[50];
    char horas[50];
    char sueldo[50];

    int horasAux;
    int sueldoAux;
    int idAux;

    if (pArrayListEmployee != NULL)
    {
        if ( UTN_getStringName(nombre,sizeof(nombre),"Ingrese el nombre del empleado: ","Error.\n",3) &&
            UTN_getNumberInt(&horasAux,"Ingrese las horas trabajadas del empleado: ","Error.\n",1,100,3) &&
            UTN_getNumberInt(&sueldoAux,"Ingrese el sueldo del empleado: ","Error.\n",1000,100000,3) )
        {
            itoa(horasAux,horas,10);
            itoa(sueldoAux,sueldo,10);
            idAux = employee_calcular_id(pArrayListEmployee);
            itoa(idAux,id,10);

            empAux = employee_newParametros(id,nombre,horas,sueldo);
        }
    }
    return empAux;
}
/// ok!!

int employee_calcular_id(LinkedList* pArrayListEmployee)
{
    int len;
    int i;
    int max;
    Employee* aux;

    if ( pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        for(i=0;i<len;i++)
         {
             aux = ll_get(pArrayListEmployee,i);

             if(i==0 || aux->id > max)
             {
                 max = aux->id;
             }
         }

    }

    return max+1;
}
/// ok!!

void employee_delete(LinkedList* pArrayListEmployee,int index)
{
    ll_remove(pArrayListEmployee,index);
}
/// ok!!

int modificar_empleado(Employee* this)
{
    int ret = 0;

    char nombre[50];
    int horas;
    int sueldo;

    int opcion;
    char salir = 'n';
    char guardar;

    do
    {
        UTN_getNumberInt(&opcion,"1.Modificar nombre\n2.Modificar horas trabajadas\n3.Modificar sueldo\n4.Guardar cambios\nElija que dato desea modificar :","Error, opcion incorrecta\n",0,4,5);

        switch(opcion)
        {
            case 1:
                    if (UTN_getStringName(nombre,sizeof(nombre),"Ingrese el nombre :","Error.\n",3))
                    {
                        ret = employee_setNombre(this,nombre);
                    }
            break;
            case 2:
                    if (UTN_getNumberInt(&horas,"Ingrese las horas trabajadas: ","Error.\n",0,100,3))
                    {
                        ret = employee_setHorasTrabajadas(this,horas);
                    }
            break;
            case 3:
                    if (UTN_getNumberInt(&sueldo,"Ingrese el sueldo: ","Error.\n",1000,100000,3))
                    {
                        ret = employee_setSueldo(this,sueldo);
                    }
            break;
            case 4:

                    if (UTN_getOption_char(&guardar,"Desea gurdar los cambios realizados?: s/n","\nError, ingrese s/n.\n",'s','n',3) )
                    {
                        if (guardar=='s')
                        {
                            salir = 's';
                            ret = 1;

                        }else if (guardar=='n')
                            {
                                salir = 's';
                                ret = -1;
                            }
                    }

            break;
        }

    }while(salir != 's');

    return ret;
}
/// ok!!

int employee_find_by_id(Employee* this, int id)
{
    int ret = -1;

    if ( this->id == id)
    {
        ret = 1;
    }

    return ret;
}
/// ok!!




