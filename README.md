# Boxing Ranking

Una comisión de boxeo necesita clasificar, filtrar y analizar a los boxeadores registrados para programar emparejamientos justos sin revisar listas manuales. Estos se registran con:
- ID
- Nombre
- Categoría
- Peso
- Victorias
- Derrotas
- Knockouts

## SICT0302B: Toma decisiones 
### Selecciona un algoritmo de ordenamiento adecuado al problema
Para este proyecto se utiliza el algoritmo MergeSort para ordenar la lista de boxeadores según su efectividad de KO. Se eligió este algoritmo debido a su complejidad de O(n log n) en el mejor, promedio y peor caso para que se puedan procesar grandes volúmenes de datos en menor tiempo.

### Selecciona una estructura de datos adecuada al problema
Se utiliza una linked list porque el registro de boxeadores crece y se reduce mientras corre el programa. Así, no se define un tamaño fijo del registro; pero gracias a esto, cuando el usuario quiera acceder a un dato por posicion será de complejidad O(n).

## SICT0301B: Evalúa los componentes
### Análisis de complejidad de algoritmos y componentes
- Linked List:
  - get: O(n) por el recorrido secuencial desde head.
  - add: O(n) ya que recorre los nodos hasta encontrar el último enlace.
  - remove: O(n) en el peor caso para colocarse en el nodo previo.
  - addFirst: O(1), ya que solo cambia el head.
  - contains: O(n), porque va recorriendo cada uno de los nodos.
  - clear y constructor copia: O(n), ya que igualmente visitan cada nodo.
  - length y empty: O(1).

- MergeSort:
  - O(n log n) utilizando un arreglo auxiliar para hacer el merge.

- leerBoxeadores: O(n²), ya que tiene n llamadas a add, que recorre hasta el final.
- guardarBoxeadores: O(n²), porque se tiene un "get" dentro de un ciclo for.
- buscarBoxeador / existeId: O(n²), ya que se tiene igualmente un "get" dentro de un ciclo for.
- filtrarPorCategoria: O(n²), ya que se hace uso de get y add.
- opcionRanking: O(n²), porque se hace un vector temporal con get y hace uso del MergeSort.
- add (menú): O(n²), ya que existeId es O(n²) y después add es O(n).
- remove (menú): O(n²), ya que la búsqueda con get es O(n²) y después remove es O(n).

Complejidad final del programa: O(n²) por las operaciones del menú.

## SICT0303B: Implementa acciones científicas 
### Consultas, Lectura y Escritura
- Consulta: Las opciones 1, 2 y 3 del menú (ordenar boxeadores por % de KO, buscar por ID, y filtrar por categoría)
- Lectura de archivos: leerBoxeadores carga los datos de Datos.txt a la linked list.
- Escritura de archivos: Las opciones 4, 5 y 6 del menú (agregar boxeador, eliminar boxeador, y guardar cambios). Cabe destacar que si el usuario no guarda los cambios antes de cerrar el programa, en Datos.txt no se reescribirá ningún dato ni se guardará ninguún cambio. 

## SEG0701: Cultura digital
El programa optimiza la toma de decisiones dentro de una comisión de boxeo al automatizar el proceso de selección de rivales y nos permite prevenir combates desproporcionados y ahorrar tiempo operativo.
