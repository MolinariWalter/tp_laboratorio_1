


/** \brief carga en un arrayList los datos desde un archivo de texto
 *
 * \param pFile FILE* puntero al archivo
 * \param pArrayListEmployee LinkedList* puntero al arrayList
 * \return int retorna 1 si cargo los empleados desde el archivo o 0 si hubo error
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief carga en un arrayList los datos desde un archivo binario
 *
 * \param pFile FILE* puntero al archivo
 * \param pArrayListEmployee LinkedList* puntero al arrayList
 * \return int 1 si cargo los empleados desde el archivo o 0 si hubo error
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
