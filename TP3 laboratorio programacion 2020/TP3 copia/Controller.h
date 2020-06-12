
/** \brief carga los datos de los empleados y los agrega a una lista ligada
 *
 * \param path char* ruta del archivo desde donde se cargaran los datos
 * \param pArrayListEmployee LinkedList* puntero a la lista ligada
 * \return int 0 si no pudo cargar desde el archivo [null pointer], 1 si la carga fue exitosa
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief carga los datos de los empleados y los agrega a una lista ligada
 *
 * \param path char* ruta del archivo desde donde se cargaran los datos
 * \param pArrayListEmployee LinkedList* puntero a la lista ligada
 * \return int 0 si no pudo cargar desde el archivo [null pointer], 1 si la carga fue exitosa
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief agrega un empleado a la lista
 *
 * \param pArrayListEmployee LinkedList* puntero a la lista ligada
 * \return int 0 si no pudo agregar el empleado [null pointer], 1 si la carga fue exitosa
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief edita los datos de un empleado
 *
 * \param pArrayListEmployee LinkedList* puntero a la lista ligada
 * \return int 0 error al editar [null pointer], -1 si la operacion fue cancelada, 1 si modifico los datos con exito
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief remueve a un empleado de la lista
 *
 * \param pArrayListEmployee LinkedList* puntero a la lista ligada
 * \return int 0 error al remover [null pointer], 1 si la operacion fue exitosa
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief muestra por consola la lista de los empleados
 *
 * \param pArrayListEmployee LinkedList* puntero a la lista ligada
 * \return int 0 error al mostrar [null pointer], 1 si la operacion fue exitosa
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief ordena la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* puntero a la lista ligada
 * \return int 0 si la operacion fue exitosa
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief guarda los cambio realizados en el archivo en modo texto
 *
 * \param path char* ruta del archivo desde donde se cargaran los datos
 * \param pArrayListEmployee LinkedList* puntero a la lista ligada
 * \return int 0 error al gurdar [null pointer], 1 si la operacion fue exitosa
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief guarda los cambio realizados en el archivo en modo binario
 *
 * \param path char* ruta del archivo desde donde se cargaran los datos
 * \param pArrayListEmployee LinkedList* puntero a la lista ligada
 * \return int 0 error al remover [null pointer], 1 si la operacion fue exitosa
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


