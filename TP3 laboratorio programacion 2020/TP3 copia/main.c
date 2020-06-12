#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

#include "Functions.h"



/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = -1;
    char path_text[]="data.csv";
    char path_binario[]="data.bin";

    LinkedList* miLista = ll_newLinkedList();


    do
    {
        printf("%s%s%s%s%s%s%s%s%s%s",
               "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n",
               "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n",
               "3. Alta de empleado\n",
               "4. Modificar datos de empleado\n",
               "5. Baja de empleado\n",
               "6. Listar empleados\n",
               "7. Ordenar empleados\n",
               "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n",
               "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n",
               "10. Salir\n");

        UTN_getNumberInt(&option,"Ingrese una opcion: ","\nError.\n",1,10,1);

        switch(option)
        {
            case 1:// cargar desde archivo data.csv modo texto
                    system("cls");
                    printf("CARGAR EMPLEADOS DESDE EL ARCHIVO MODO TEXTO\n");
                    if (controller_loadFromText(path_text,miLista))
                    {
                        printf("\nCarga correcta.\n");
                    }else
                        {
                            printf("\nError al cargar los datos.");
                        }
            break;
            case 2://cargar desde archivo data.csv modo binario
                    system("cls");
                    printf("CARGAR EMPLEADOS DESDE EL ARCHIVO MODO BINARIO\n");
                     if (controller_loadFromBinary(path_binario,miLista))
                    {
                        printf("\nCarga correcta.\n");
                    }else
                        {
                            printf("\nError al cargar los datos.");
                        }
            break;
            case 3://alta empleado
                    system("cls");
                    printf("ALTA DE EMPLEADOS\n");
                     if (controller_addEmployee(miLista))
                    {
                        printf("Alta");
                    }else
                        {
                            printf("error");
                        }
            break;
            case 4://modificar empleado
                    system("cls");
                    printf("MODIFICAR EMPLEADO\n");

                    switch(controller_editEmployee(miLista))
                    {
                        case 0:
                                printf("Error al modificar.\n");
                        break;
                        case 1:
                                printf("Cambios gurdados.\n");
                        break;
                        case -1:
                                printf("Operacion cancelada.\n");
                        break;
                    }
            break;
            case 5://baja empleado
                    system("cls");
                    printf("BAJA DE EMPLEADO\n");

                    if(controller_removeEmployee(miLista))
                    {
                        printf("Baja de empleado correctamente.\n");
                    }else
                        {
                            printf("Error al dar de baja.\n");
                        }
            break;
            case 6://listar empleado
                    system("cls");
                    printf("LISTAR EMPLEADOS\n");
                    if(controller_ListEmployee(miLista))
                    {
                        printf("listar empleados correcto.\n");
                    }else
                    {
                        printf("error.\n");
                    }
            break;
            case 7://ordenar empleado
                    system("cls");
                    printf("ORDENAR EMPLEADOS\n");

                    if ( controller_sortEmployee(miLista) == 0 )
                    {
                        printf("lista ordenada.\n");
                    }else
                    {
                        printf("error al ordenar.\n");
                    }


            break;
            case 8://gurdar modo texto
                    system("cls");
                    printf("GUARDAR LOS DATOS EN MODO TEXTO\n");
                    if (controller_saveAsText(path_text,miLista))
                    {
                        printf("Guardado modo texto\n");
                    }else
                        {
                            printf("error\n");
                        }
            break;
            case 9://gurdar modo binario
                    system("cls");
                    printf("GUARDAR LOS DATOS EN MODO BINARIO\n");
                    if (controller_saveAsBinary(path_binario,miLista) == -1)
                    {
                        printf("Guedado modo binario y -1");
                    }else
                        {
                            printf("error\n");
                        }
            break;
        }
        system("pause");
        system("cls");


    }while(option != 10);











 /*


    //int size;
    Employee* aux;
    int id;
    char nombre[50];
    int horas;
    int sueldo;
    //int i;


    char array[100];
    //itoa(2000000000,array,10);

    printf("int to array :%s\n",array);
    system("pause");



    //FILE* pFile;
    //pFile = fopen("data.csv","r");

    //parser_EmployeeFromText(pFile,miLista);
    printf("tamaño de la lista : %d\n", ll_len(miLista) );

    aux = ll_get(miLista,5);

    printf("print 1: %d----%s----%d----%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);

    employee_getId(aux,&id);
    employee_getNombre(aux,nombre);
    employee_getHorasTrabajadas(aux,&horas);
    employee_getSueldo(aux,&sueldo);


    printf("print 2: %d----%s----%d----%d\n",id,nombre,horas,sueldo);


  */

    /*size = ll_len(miLista);


    //ll_sort(miLista,employee_CompareById,0);

    for(i=0; i<size; i++)
    {
        aux =(Employee*) ll_get(miLista, i);
        printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);

    }
*/




/*
    Employee* e1 = (Employee*) malloc(sizeof(Employee));
    Employee* e2 = (Employee*) malloc(sizeof(Employee));
    Employee* e3 = (Employee*) malloc(sizeof(Employee));

    e1->id = 5;
    e1->horasTrabajadas = 10;
    strcpy(e1->nombre,"Juan");
    e1->sueldo = 10000;

    e2->id = 1;
    e2->horasTrabajadas = 15;
    strcpy(e2->nombre,"Martin");
    e2->sueldo = 15000;

    e3->id = 3;
    e3->horasTrabajadas = 10;
    strcpy(e3->nombre,"Aria");
    e3->sueldo = 20000;

    ll_add(miLista, e1);
    ll_add(miLista, e2);
    ll_add(miLista, e3);



    size = ll_len(miLista);


    ll_sort(miLista,employee_CompareById,0);

    for(i=0; i<size; i++)
    {
        aux =(Employee*) ll_get(miLista, i);
        printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);

    }

    printf("Remuevo 1\n");

    ll_remove(miLista, 1);

    size = ll_len(miLista);
    for(i=0; i<size; i++)
    {
        aux =(Employee*) ll_get(miLista, i);
        printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);

    }

    printf("El indice de e2 es: %d\n", ll_indexOf(miLista,e3));
    */



    return 0;
}
