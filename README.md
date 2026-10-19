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
Para este proyecto se utiliza el algoritmo MergeSort para ordenar la lista de boxeadores según su efectividad de KO o su peso en kg. Se eligió este algoritmo debido a su complejidad de O(n log n) en el caso promedio para que se puedan procesar grandes volúmenes de datos en menor tiempo.

### Selecciona una estructura de datos adecuada al problema
Se utiliza una Linked List para tener los datos de todos los boxeadores.


## SICT0301B: Evalúa los componentes
### Análisis de complejidad de algoritmos y componentes
- Linked List:
  - Get: O(n) por el recorrido secuencial desde head.
  - Add: O(n) ya que recorre los nodos hasta encontrar el último enlace.
  - Eliminación por índice: O(n) en el peor caso para colocarse en el nodo previo.
- Búsqueda por ID y filtrado: O(n) por el recorrido lineal de la lista enlazada.
- MergeSort (Ordenamiento por % de KO): O(n \log n) utilizando un arreglo auxiliar para hacer el merge.
- Lectura y escritura de archivos: O(n) respecto al número de registros en el archivo txt.


## SICT0303B: Implementa acciones científicas 
### Consultas, Lectura y Escritura
- Lectura de archivos.
- Escritura de archivos.

## SEG0701: Cultura digital
El programa optimiza la toma de decisiones dentro de una comisión de boxeo al automatizar el proceso de selección de rivales y nos permite prevenir combates desproporcionados y ahorrar tiempo operativo.
