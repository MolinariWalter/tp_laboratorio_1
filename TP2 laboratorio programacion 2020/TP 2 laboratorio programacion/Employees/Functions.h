#include <stdio.h>
#include <stdlib.h>


/** \brief get an integer and validate it
 *
 * \param number int* pointer to number
 * \param message char* message requesting data
 * \param errorMessage char* error message
 * \param min int minimun number
 * \param max int maximun number
 * \param retries int retries in case of error
 * \return int return ( 0 ) if error or ( 1 ) if ok
 *
 */
int UTN_getNumberInt(int* number, char* message, char* errorMessage, int min, int max, int retries);

/** \brief get an string and validate it
 *
 * \param name char* string name
 * \param tam int length of string
 * \param message char* message requesting data
 * \param errorMessage char* error message
 * \param retries int retries in case of error
 * \return int return ( 0 ) if error or ( 1 ) if ok
 *
 */
int UTN_getStringName(char* name,int tam, char* message, char* errorMessage, int retries);

/** \brief get an float and validate it
 *
 * \param salary float* float number
 * \param message char* message requesting data
 * \param errorMessage char* error message
 * \param min float minimun number
 * \param max float maximun number
 * \param retries int retries in case of error
 * \return int return ( 0 ) if error or ( 1 ) if ok
 *
 */
int UTN_getNumberFloat(float* salary, char* message, char* errorMessage, float min, float max, int retries);

/** \brief get an string and puts it the final line ( without '\n')
 *
 * \param str char* string
 * \param tam int string length
 * \return int return ( 0 ) if error or ( 1 ) if ok
 *
 */
int UTN_getString(char* str,int tam);

/** \brief get an integer (string) and puts it the final line ( without '\n')
 *
 * \param number int* number integer
 * \return int return ( 0 ) if error or ( 1 ) if ok
 *
 */
int UTN_getInt(int* number);

/** \brief puts the final line in the string ( without '\n' )
 *
 * \param str char* string to change
 * \param len int string length
 * \return int return ( 0 ) if error or ( 1 ) if ok
 *
 */
int UTN_myGets(char* str, int len);

/** \brief verify if an string is integer
 *
 * \param str char* string
 * \return int return ( 0 ) if error or ( 1 ) if ok
 *
 */
int UTN_isNumber(char* str);

/** \brief get an float (string) and puts it the final line ( without '\n')
 *
 * \param number float* number float
 * \return int return ( 0 ) if error or ( 1 ) if ok
 *
 */
int UTN_getFloat(float* number);

/** \brief verify if an string is float
 *
 * \param str char* string
 * \return int return ( 0 ) if error or ( 1 ) if ok
 *
 */
int UTN_isFloat(char* str);

/** \brief verify if an string is only afabetic string
 *
 * \param str char* string
 * \param tam int string length
 * \return int return ( 0 ) if error or ( 1 ) if ok
 *
 */
int UTN_isString(char* str,int tam);
