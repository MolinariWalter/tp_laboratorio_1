#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief crea una entidad de tipo Empleado de manera dinamica (sin campos cargados)
 *
 * \return Employee* el puntero a la entidad
 *
 */
Employee* employee_new();

/** \brief crea una entidad de tipo Empleado de manera dinamica (cargando los campos)
 *
 * \param idStr char* campo id de la entidad
 * \param nombreStr char* campo nombre de la entidad
 * \param horasTrabajadasStr char* campo horas trabajadas de la entidad
 * \param sueldoStr char* campo sueldo de la entidad
 * \return Employee* el puntero a la entidad
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief remueve un empleado de la lista
 *
 * \param pArrayListEmployee LinkedList* puntero a la lista ligada
 * \param index int indice en el cual se encuentra el empleado
 *
 */
void employee_delete(LinkedList* pArrayListEmployee,int index);

/** \brief setea el campo id
 *
 * \param this Employee* entidad empleado
 * \param id int dato a setear
 * \return int 0 si hubo un error [null pointer], 1 operacion exitosa
 *
 */
int employee_setId(Employee* this,int id);

/** \brief obtiene el id del empleado
 *
 * \param this Employee* entidad empleado
 * \param id int* puntero id donde se guardara el dato obtenido
 * \return int 0 si hubo un error [null pointer], 1 operacion exitosa
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief setea el nombre del empleado
 *
 * \param this Employee* entidad empleado
 * \param nombre char* dato a setear
 * \return int 0 si hubo un error [null pointer], 1 operacion exitosa
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief obtiene el nombre del empleado
 *
 * \param this Employee* entidad empleado
 * \param nombre char* puntero nombre donde se gurdara el dato obtenido
 * \return int 0 si hubo un error [null pointer], 1 operacion exitosa
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief setea las horas trabajadas del empleado
 *
 * \param this Employee* entidad empleado
 * \param horasTrabajadas int dato a setear
 * \return int 0 si hubo un error [null pointer], 1 operacion exitosa
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief obtiene las oras trabajadas del empleado
 *
 * \param this Employee* entidad empleado
 * \param horasTrabajadas int* puntero horas trabajadas donde se gurdara el dato obtenido
 * \return int 0 si hubo un error [null pointer], 1 operacion exitosa
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief setea el sueldo del empleado
 *
 * \param this Employee* entidad empleado
 * \param sueldo int dato a setear
 * \return int 0 si hubo un error [null pointer], 1 operacion exitosa
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief obtiene el sueldo del empleado
 *
 * \param this Employee* entidad empleado
 * \param sueldo int* puntero sueldo donde se gurdara el dato obtenido
 * \return int 0 si hubo un error [null pointer], 1 operacion exitosa
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief compara alfabeticamente a dos empleados por nombre
 *
 * \param e1 void* puntero a un empleado
 * \param e2 void* puntero a otro empleado
 * \return int 0 si los nombres son iguales, positivo si el primero es mayor al segundo, negativo si el primero es menor al segundo
 *
 */
int employee_CompareByName(void* e1, void* e2);

/** \brief compara a dos empleados por su id
 *
 * \param e1 void* puntero a un empleado
 * \param e2 void* puntero a otro empleado
 * \return int -10 si hubo un error [null pointer], 1 si el primero es mayor al segundo, 0 si el primero es menor al segundo
 *
 */
int employee_CompareById(void* e1, void* e2);

/** \brief crea un nuevo empleado seteando los campos
 *
 * \param pArrayListEmployee LinkedList* puntero a la lista ligada
 * \return Employee* el empleado creado
 *
 */
Employee* employee_load(LinkedList* pArrayListEmployee);

/** \brief calcula el id para un nuevo empleado
 *
 * \param pArrayListEmployee LinkedList* puntero a la lista ligada
 * \return int el id creado
 *
 */
int employee_calcular_id(LinkedList* pArrayListEmployee);

/** \brief modifica los datos de un empleado
 *
 * \param this Employee* entidad empleado a modificar
 * \return int 0 si hubo un error [null pointer], 1 operacion exitosa
 *
 */
int modificar_empleado(Employee* this);

/** \brief verifica si existe un empleado con determinado id
 *
 * \param this Employee* entidad empleado
 * \param id int id a buscar
 * \return int 0 si hubo un error [null pointer], 1 si encontro el empleado segun el id
 *
 */
int employee_find_by_id(Employee* this, int id);


#endif // employee_H_INCLUDED
