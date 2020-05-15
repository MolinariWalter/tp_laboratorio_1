#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ArraysEployees.h"
#include "Functions.h"

#define TRUE 1
#define FALSE -1



int initEmployees(Employee* list, int len)
{
    int i;
    int result = -1;
    if(list!=NULL)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty = TRUE;
            result = 0;
        }
    }
    return result;
}

int addEmployee(Employee* list,int len,int* id,char name[],char lastName[],float salary,int sector)
{
    int result = -1;
    int i;
    if(list != NULL)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==TRUE)
            {
                list[i].id=*id;
                strcpy(list[i].name,name);
                strcpy(list[i].lastName,lastName);
                list[i].salary=salary;
                list[i].sector=sector;
                list[i].isEmpty=FALSE;
                result = 0;
                (*id)++;
                break;
            }
            result = -1;
        }
    }

    return result;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int index = -1;
    int i;
    if(list!=NULL)
    {
        for(i=0;i<len;i++)
            {
                if((list[i].id == id) && (list[i].isEmpty != TRUE))
                {
                    index=i;
                    break;
                }
            }
    }
    return index;
}

int findFree(Employee* list,int len)
{
    int result = -1;
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty == TRUE)
        {
            result = i;
            break;
        }
    }

    return result;
}

int findEmployeeByName(Employee* list,int len, char* name)
{
    int index = -1;
    int i;
    if(list!=NULL)
    {
        for(i=0;i<len;i++)
            {
                if( stricmp(list[i].name,name) == 0)
                {
                    index=i;
                    break;
                }
            }
    }
    return index;
}

int findEmployeeByLastName(Employee* list, int len, char* lastName)
{
    int index = -1;
    int i;
    if(list!=NULL)
    {
        for(i=0;i<len;i++)
            {
                if( stricmp(list[i].lastName,lastName) == 0)
                {
                    index=i;
                    break;
                }
            }
    }
    return index;
}
int printEmployeeBySalary(Employee* list,int len,float salaryAux)
{
    int result = -1;
    int i;
    if(list != NULL)
    {
        printf("Empledos con salario maximo:\n");
        printf("%4s%15s%15s%15s%8s\n","ID","NAME","LASTNAME","SALARY","SECTOR");

        for(i=0;i<len;i++)
        {
            if(list[i].salary == salaryAux)
            {
                printEmployeeById(list,len,list[i].id);
                result = 0;
            }
        }

    }

    return result;
}

int findEmployeeBySector(Employee* list, int len, int sector)
{
     int index = -1;
    int i;
    if(list!=NULL)
    {
        for(i=0;i<len;i++)
            {
                if( list[i].sector == sector)
                {
                    index=i;
                    break;
                }
            }
    }
    return index;
}
int removeEmployeeById(Employee* list,int len,int id)
{
    int idAux;
    int resultId;
    int findId;
    int result = 0;
    char Confirm;


    system("cls");
    printf("BORRAR DATOS DE UN EMPLEADO\n");
    printEmployees(list,len);
    do
        {
            resultId = UTN_getNumberInt(&idAux,"\ningrese el id del empleado :","Error con el id",0,id,1);
            if(resultId != 0)
                {
                    findId = findEmployeeById(list,len,idAux);///busco que el empleado no este dado de baja o sin cargar empleados
                     if(findId == -1 )
                        {
                            printf("Error el id no existe.");
                            resultId = -1;
                        }
                }

        }while(resultId != 1);


            printEmployeeById(list,len,idAux);
            printf("\nEsta seguro que desea borrar los datos del empleado? s/n: ");/// pregunto si esta seguro de eliminar
            fflush(stdin);
            scanf("%c",&Confirm);
            if (Confirm == 's' || Confirm == 'S')
            {
                removeEmployee(list,len,idAux);
                result = 1;
            }else
                {
                    result = -1;
                }

    return result;
}


int removeEmployee(Employee* list, int len, int id)
{
    int i;
    int result = -1;
    for(i=0;i<len;i++)
    {
        if(id == list[i].id)
        {
            list[i].isEmpty = TRUE;
            result = 0;
        }
    }

    return result;
}

int sortEmployees(Employee* list, int len, int order)
{
    int result = -1;

    if(list != NULL)// si el puntero es NULL
        {
            switch(order)
                {
                    case 0:
                        sortEmployeesDown(list,len);
                        result = 0;
                    break;
                    case 1:
                        sortEmployeesDown(list,len);
                        result = 0;
                break;
             }
        }
    return result;
}


void sortEmployeesUp(Employee* list, int len)
{
    Employee eAux;
    int i;
    int j;
    for(i=0 ; i<len-1 ; i++)
    {
        for(j=i+1 ; j<len ; j++)
        {
            if(list[i].isEmpty == FALSE && list[j].isEmpty == FALSE)
            {
                if( strcmp(list[i].lastName,list[j].lastName) > 0 || (strcmp(list[i].lastName,list[j].lastName) == 0 && list[i].sector > list[j].sector)  )
                {
                    eAux=list[i];
                    list[i]=list[j];
                    list[j]=eAux;
                }
            }
        }
    }
}
void sortEmployeesDown(Employee* list, int len)
{
    Employee eAux;
    int i;
    int j;

    for(i=0 ; i<len-1 ; i++)
    {
        for(j=i+1 ; j<len ; j++)
        {
            if(list[i].isEmpty == FALSE && list[j].isEmpty == FALSE)
            {
                if( strcmp(list[i].lastName,list[j].lastName) < 0 || (strcmp(list[i].lastName,list[j].lastName) == 0 && list[i].sector < list[j].sector) )
                {
                    eAux=list[i];
                    list[i]=list[j];
                    list[j]=eAux;
                }
            }
        }
    }
}




int printEmployees(Employee* list, int len)
{
    int i;
    int result = -1; // si el puntero es NULL
    if(list!=NULL)
    {
        printf("%4s%15s%15s%15s%8s\n","ID","NAME","LASTNAME","SALARY","SECTOR");

          for(i=0;i<len;i++)
            {
                if(list[i].isEmpty == FALSE)
                {
                    printEmployeeById(list,len,list[i].id);

                    result = 0; /// si hay datos cargados

                }
            }
    }

    return result;
}


int loadEmployee(Employee* list, int len,char message[],char errorMessage[],int retries,int* id)
{
    int nameExist = 0;
    int free = -1;
    int i;
    Employee EmpAux;

    if(list != NULL)
    {
        free = findFree(list,len);

        if ( free == -1)
            {
                printf("Error, no hay lugar disponible.");
                return -1;
            }

        do{
                nameExist = 0;
                printf("CARGA DE DATOS\n");
                printEmployees(list,len);

                if( setName(EmpAux.name,sizeof(EmpAux.name),"\nIngrese el nombre del empleado: ","Error al cargar el nombre..",retries)==0 || setLastName(EmpAux.lastName,sizeof(EmpAux.lastName),"Ingrese el apellido del empleado: ","Error al cargar el epellido..\n",retries)==0 )
                {
                    return -1;
                }

                for(i=0;i<len;i++)
                {
                    if (  stricmp(list[i].lastName, EmpAux.lastName) == 0  &&  stricmp(list[i].name, EmpAux.name) == 0 )
                    {
                        system("cls");
                        printf("* Error, el empleado ya existe.\n\n");
                        nameExist = 1; // el epleado ya existe
                        break;
                    }

                }

        }while(nameExist == 1);

        if( setSalary(&EmpAux.salary,"Ingrese el salario del empleado: ","Error al cargar el salario..\n",100.0,100000.0,retries)==0 || setSector(&EmpAux.sector,"Ingrese el sector del empleado: ","Error al cargar el sector..\n",1,9,retries)==0 )
        {
            return -1;
        }

    }

    return addEmployee(list,len,id,EmpAux.name,EmpAux.lastName,EmpAux.salary,EmpAux.sector);
}


void harcoderEmployees(Employee* list,int len,int* id)
{
    char nameAux[5][20] = {"walter","ana","pedro","mariel","jorge"};
    char lastNameAux[5][20] = {"araoz","mendoza","casas","mendoza","del piero"};
    float salaryAux[5] = {10000.5,10000.5,1000.5,10000.5,2000.5};
    int sectorAux[5] = {9,5,9,2,6};

    int free = -1;

    for(int i=0;i<len;i++)
    {
        free = findFree(list,len);
        if(free != -1)
        {
            addEmployee(list,len,id,nameAux[i],lastNameAux[i],salaryAux[i],sectorAux[i]);
        }

    }
}


void printEmployeeById(Employee* list,int len, int id)
{
    int index;
    index = findEmployeeById(list,len,id);
    if(index != -1)
    {
        printf("%4d", list[index].id);
        printf("%15s",list[index].name);
        printf("%15s",list[index].lastName);
        printf("%15.2f",list[index].salary);
        printf("%8d\n",list[index].sector);
    }
}

int setName(char* nameAux,int tam,char* message,char* errorMessage,int retries)
{
    int result = 0;

    result = UTN_getStringName(nameAux,tam,message,errorMessage,retries);

    return result;
}

int setLastName(char* nameAux,int tam,char* message,char* errorMessage,int retries)
{
    int result = 0;

    result = UTN_getStringName(nameAux,tam,message,errorMessage,retries);

    return result;
}

int setSalary(float* fNumber, char* message, char* errorMessage, float min, float max, int retries)
{
    int result = 0;

    result = UTN_getNumberFloat(fNumber,message,errorMessage,min,max,retries);

    return result;
}

int setSector(int* number, char* message, char* errorMessage, int min, int max, int retries)
{
    int result = 0;

    result = UTN_getNumberInt(number,message,errorMessage,min,max,retries);

    return result;
}

int modifyEmployee(Employee* list,int len)
{
    int result = 0;
    int opcion = 0;
    int idAux;
    int searchId;
    char Confirm;
    int isValidId;

    system("cls");
    printf("MODIFICAR EMPLEADO\n");
    printEmployees(list,len);

    searchId = UTN_getNumberInt(&idAux,"\nIngrese el id del empleado que quiere modificar :","\nError con el id.",list[0].id,list[len].id,1);
    isValidId = findEmployeeById(list,len,idAux);
    if(searchId == 0 || isValidId == -1)
        {
            return result;
        }

    system("cls");
    do
    {


    printf("%4s%15s%15s%15s%8s\n","ID","NAME","LASTNAME","SALARY","SECTOR");
    printEmployeeById(list,len,idAux);
    printf("\n1. Modificar Nombre.\n2. Modificar Apellido.\n3. Modificar Salario.\n4. Modificar Sector.");
    UTN_getNumberInt(&opcion,"\nIngrese una de las opciones para modificar un dato :","\nError, opcion incorrecta.\n",1,4,1);

    switch(opcion)
        {
            case 1:

            printf("Esta seguro que desea modificar el nombre del empleado? s/n: ");
            fflush(stdin);
            scanf("%c",&Confirm);
            if (Confirm == 's' || Confirm == 'S')
            {
                result = setNameById(list,len,idAux);

            }else
                {
                    result = -1;
                }

            break;
            case 2:

            printf("Esta seguro que desea modificar el apellido del empleado? s/n: ");
            fflush(stdin);
            scanf("%c",&Confirm);
            if (Confirm == 's' || Confirm == 'S')
            {
                result = setLastNameById(list,len,idAux);
            }else
                {
                    result = -1;
                }

            break;
            case 3:

            printf("Esta seguro que desea modificar el salario del empleado? s/n: ");
            fflush(stdin);
            scanf("%c",&Confirm);
            if (Confirm == 's' || Confirm == 'S')
            {
                result = setSalaryById(list,len,idAux);
            }else
                {
                    result = -1;
                }

            break;
            case 4:

            printf("Esta seguro que desea modificar el sector del empleado? s/n: ");
            fflush(stdin);
            scanf("%c",&Confirm);
            if (Confirm == 's' || Confirm == 'S')
            {
                result = setSectorById(list,len,idAux);
            }else
                {
                    result = -1;
                }

            break;
        }

    }while(opcion == 0);

    return result;
}

int setNameById(Employee* list,int len,int id)
{
    int result = 0;
    char nameAux[20];
    int name;
    int i;

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty == FALSE && list[i].id == id )
        {
            name = setName(nameAux,sizeof(nameAux),"Ingrese el nuevo nombre del empleado :","Error al cargar el nombre..\n",1);
            if(name != 0)
            {
                strcpy(list[i].name, nameAux);
                result = 1;
            }

        }
    }

    return result;
}

int setLastNameById(Employee* list,int len,int id)
{
    int result = 0;
    char lastNameAux[20];
    int lastName;
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty == FALSE && list[i].id == id)
        {
            lastName = setLastName(lastNameAux,sizeof(lastNameAux),"Ingrese el nuevo apellido del empleado :","Error al cargar el apellido..\n",1);
            if(lastName != 0)
            {
                strcpy(list[i].lastName, lastNameAux);
                result = 1;
            }

        }
    }

    return result;
}

int setSalaryById(Employee* list,int len,int id)
{
    int result = 0;
    float salaryAux;
    int salary;
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty == FALSE && list[i].id == id)
        {
            salary = setSalary(&salaryAux,"Ingrese el nuevo salario del empleado :","Error al cargar el salario..\n",100.0,100000.0,1);
            if(salary != 0)
            {
                list[i].salary = salaryAux;
                result = 1;
            }
        }
    }

    return result;
}

int setSectorById(Employee* list,int len,int id )
{
    int result = 0;
    int sectorAux;
    int sec;
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty == FALSE && list[i].id == id)
        {
            sec = setSector(&sectorAux,"Ingrese el nuevo sector del empleado :","Error al cargar el sector..\n",1,9,1);
            if(sec != 0)
            {
                list[i].sector = sectorAux;
                result = 1;
            }

        }
    }

    return result;
}

float totalSalaries(Employee* list,int len)
{
    float result = 0;
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==FALSE)
        {
            result+=list[i].salary;
        }
    }

    return result;
}

float promSalaries(Employee* list,int len)
{
    return (float)totalSalaries(list,len)/countEmployee(list,len);
}



float getMaxSalary(Employee* list,int len)
{
    float max = 0.0;
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==FALSE)
        {
            if(i == 0 || list[i].salary > max )
            {
                max = list[i].salary;
            }
        }
    }

    return max;
}
int countEmployee(Employee* list,int len)
{
    int cont = 0;
    int i;
    for(i=0;i<(len+1);i++)
    {
        if(list[i].isEmpty == FALSE)
        {
            cont++;
        }
    }

    return cont;
}
int inform(Employee* list,int len,int flagSort)
{
    float salaryMax;
    int result = 0;

    system("cls");
    if(countEmployee(list,len) == 0)
        {
            printf("Primero debe cargar empleados para poder informar.\n");
            result = -1;
        }else
            {
                printf("INFORMAR\n");

                if(flagSort == 1) // o los contadores: modificar apellido o sector/agregar estan en 1
                    {
                        if(sortEmployees(list,len,1) == -1)
                            {
                                printf("Error al ordenar la lista de empleados.\n");
                            }

                        }

                        printEmployees(list,len);
                        printf("\nSalarios totales: %.2f",totalSalaries(list,len));
                        printf("\nPromedio de los salarios: %.2f",promSalaries(list,len));

                        salaryMax = getMaxSalary(list,len);

                        printf("\nsalario maximo :%.2f\n\n",salaryMax);
                        printEmployeeBySalary(list,len,salaryMax);
            }

     return result;
}

