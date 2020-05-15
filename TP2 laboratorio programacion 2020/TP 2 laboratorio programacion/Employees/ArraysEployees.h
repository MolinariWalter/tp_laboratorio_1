#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;


/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);


/** \brief add in a existing list of employees the values received as parameters in the first empty position
*
* \param list employee* Pointer to array of employees
* \param len int Array length
* \param id int Pointer to autoincremental id
* \param name[] char name of employee
* \param lastName[] char lastname of employee
* \param salary float salary of employee
* \param sector int sector of employee
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
**/
int addEmployee(Employee* list, int len, int* id, char name[],char lastName[],float salary,int sector);


/** \brief find an Employee by Id and returns the index position in array.
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param id int Pointer to autoincremental id
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id);


/** \brief find a free place in the list of employees
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return Return free index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findFree(Employee* list,int len);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param id int Pointer to autoincremental id
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);


/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
*
* \param list Employee* Pointer to array employees
* \param len int Array length
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);


/** \brief Sort the elements in the array of employees (ascending)
 *
 * \param list Employee* Pointer to array employees
 * \param len int Array length
 *
 */
void sortEmployeesUp(Employee* list, int len);


/** \brief Sort the elements in the array of employees (descending)
 *
 * \param list Employee* Pointer to array employees
 * \param len int Array length
 *
 */
void sortEmployeesDown(Employee* list, int len);


/** \brief print the content of employees array
*
* \param list Employee* Pointer to array employees
* \param length int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int printEmployees(Employee* list, int length);


/** \brief request and upload the data of a new employee to the array
 *
 * \param list Employee* Pointer to array employees
 * \param len int array length
 * \param id int Pointer to autoincremental id
 * \param message[] char message requesting data
 * \param errorMessage[] char  error message
 * \param retries int retries in case of error
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int loadEmployee(Employee* list, int len,char message[],char errorMessage[],int retries,int* id);


/** \brief fint an employee by name
 *
 * \param list Employee* Pointer to array employees
 * \param len int array length
 * \param name char* name to be searched
 * \return Return the index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeByName(Employee* list,int len, char* name);


/** \brief fint an employee by lastname
 *
 * \param list Employee* Pointer to array employees
 * \param len int array length
 * \param lastName char* lastname to be searched
 * \return Return the index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeByLastName(Employee* list, int len, char* lastName);


/** \brief fint an employee by sector
 *
 * \param list Employee* Pointer to array employees
 * \param len int array length
 * \param sector int sector to be searched
 * \return Return the index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeBySector(Employee* list, int len, int sector);


/** \brief find an employee by salary
 *
 * \param list Employee* Pointer to array employees
 * \param len int array length
 * \param salaryAux float salary to be searched
 * \return return the index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int printEmployeeBySalary(Employee* list,int len,float salaryAux);


/** \brief print the employee by the entered id
 *
 * \param list Employee* Pointer to array employees
 * \param len int size of the employee list
 * \param id int id of employee
 *
 */
void printEmployeeById(Employee* list,int len, int id);


/** \brief test data entry
 *
 * \param list Employee* Pointer to array employees
 * \param len int size of the employee list
 *
 */
void harcoderEmployees(Employee* list,int len,int* id);


/** \brief remove an employee of the array by id
 *
 * \param list Employee* Pointer to array employees
 * \param len int array length
 * \param id int id of employee
 * \return int Return ( 0 ) if Error [Invalid length or NULL pointer] - ( -1 ) if the operation is cancel, or ( 1 ) if Ok
 *
 */
int removeEmployeeById(Employee* list,int len,int id);


/** \brief set the name of an employee
 *
 * \param nameAux char* pointer to the name of employee
 * \param tam int name length
 * \param message char* message requesting data
 * \param errorMessage char* error message
 * \param retries int retries in case of error
 * \return int Return ( 0 ) if Error [Invalid length or NULL pointer] - ( 1 ) if ok
 *
 */
int setName(char* nameAux,int tam,char* message,char* errorMessage,int retries);


/** \brief set the lastname of an employee
 *
 * \param nameAux char* pointer to the lastname of employee
 * \param tam int lastname length
 * \param message char* message requesting data
 * \param errorMessage char* error message
 * \param retries int retries in case of error
 * \return int Return ( 0 ) if Error [Invalid length or NULL pointer] - ( 1 ) if ok
 *
 */
int setLastName(char* nameAux,int tam,char* message,char* errorMessage,int retries);


/** \brief set salary of an employee
 *
 * \param fNumber float* pointer to the salary of employee
 * \param message char* message requesting data
 * \param errorMessage char* error message
 * \param min float minimum salary
 * \param max float maximum salary
 * \param retries int retries in case of error
 * \return int Return ( 0 ) if Error [Invalid length or NULL pointer] - ( 1 ) if ok
 *
 */
int setSalary(float* fNumber, char* message, char* errorMessage, float min, float max, int retries);


/** \brief set sector of an employee
 *
 * \param number int* pointer to the sector of employee
 * \param message char* message requesting data
 * \param errorMessage char* error message
 * \param min int minimum sector
 * \param max int maximum sector
 * \param retries int retries in case of error
 * \return int Return ( 0 ) if Error [Invalid length or NULL pointer] - ( 1 ) if ok
 *
 */
int setSector(int* number, char* message, char* errorMessage, int min, int max, int retries);


/** \brief modify an employee's data
 *
 * \param list Employee* pointer to array employees
 * \param len int array length
 * \return int Return ( 0 ) if Error [Invalid length or NULL pointer] - ( -1 ) if the operation is cancel, or ( 1 ) if Ok
 *
 */
int modifyEmployee(Employee* list,int len);


/** \brief set the name of an employee by id
 *
 * \param list Employee* pointer to array employees
 * \param len int array length
 * \param id int id of employee
 * \return int Return ( 0 ) if Error [Invalid length or NULL pointer] - ( 1 ) if ok
 *
 */
int setNameById(Employee* list,int len,int id);


/** \brief set the lastname of an employee by id
 *
 * \param list Employee* pointer to array employees
 * \param len int array length
 * \param id int id of employee
 * \return int Return ( 0 ) if Error [Invalid length or NULL pointer] - ( 1 ) if ok
 *
 */
int setLastNameById(Employee* list,int len,int id);


/** \brief set the salary of an employee by id
 *
 * \param list Employee* pointer to array employees
 * \param len int array length
 * \param id int id of employee
 * \return int Return ( 0 ) if Error [Invalid length or NULL pointer] - ( 1 ) if ok
 *
 */
int setSalaryById(Employee* list,int len,int id);


/** \brief set the sector of an employee by id
 *
 * \param list Employee* pointer to array employees
 * \param len int array length
 * \param id int id of employee
 * \return int Return ( 0 ) if Error [Invalid length or NULL pointer] - ( 1 ) if ok
 *
 */
int setSectorById(Employee* list,int len,int id);


/** \brief get the total sum of salaries
 *
 * \param list Employee* pointer to array employees
 * \param len int array length
 * \return float total salaries
 *
 */
float totalSalaries(Employee* list,int len);


/** \brief get the average salaries
 *
 * \param list Employee* pointer to array employees
 * \param len int array length
 * \return float average salaries
 *
 */
float promSalaries(Employee* list,int len);


/** \brief get the maximum salary
 *
 * \param list Employee* pointer to array employees
 * \param len int array length
 * \return float maximum salary
 *
 */
float getMaxSalary(Employee* list,int len);


/** \brief count the employees on the list
 *
 * \param list Employee* pointer to array employees
 * \param len int array length
 * \return int return number of employees on the list
 *
 */
int countEmployee(Employee* list,int len);


/** \brief reports on employees
 *
 * \param list Employee* pointer to array employees
 * \param len int array length
 * \param flagSort int to indicate that you have already informed
 * \return int ( -1 ) if Error or ( 0 ) if ok
 *
 */
int inform(Employee* list,int len,int flagSort);

