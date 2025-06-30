# untref-ayp3-sigma-
Repositorio del grupo SigmaΣ para la cursada de Programación de Bajo nivel, 1er cuatrimestre 2025.
# Informe del Trabajo Práctico Grupal

**Integrantes Del Grupo:**

- Barreriro Walter     - 76260
- Palacios Laureano    - 74301
- Riccio Diamela       - 76761
- Ruiz Diaz Lucas      - 77302

**Fecha de entrega:** 29/06/2025

---

## 1. Introducción
El trabajo práctico final de la materia es sobre el desarrollo de un sistema de gestión de estudiantes, implementado en lenguaje C. El sistema también incluye mecanismos de búsqueda por nombre y por rango de edad, lo que mejora la accesibilidad y la organización de la información. A su vez, se permite la inscripción de estudiantes en múltiples materias y la posibilidad de rendirlas.

Este trabajo pone en práctica conceptos fundamentales del lenguaje C, como punteros, estructuras y manejo de memoria.

---

## 2. Objetivos
El objetivo principal del sistema es permitir la administración eficiente de un conjunto de estudiantes y sus materias, incorporando funcionalidades clave como el alta, modificación, eliminación y listado tanto de estudiantes como de materias.

---

## 3. Consignas implementadas

**ALUMNOS** 
---
Se desarrollaron funciones como:
- altaAlumno(Nodo** listaAlumnos): para dar de alta alumnos se crea un nuevo alumno, se reserva la memoria y pide nombre y edad.
- modificarAlumno(Nodo** listaAlumnos): busca un alumno ya existente por nombre y nos permite modificar sus datos.
- eliminarAlumno(Nodo** listaAlumnos): busca y elimina alumnos por nombre del sistema y libera memoria del nodo.
- listarAlumnos(Nodo** listaAlumnos): recorre la lista de alumnos e imprime todos los estudiantes registrados, mostrando sus datos.
- anotarAlumnoEnMateria(Nodo* listaAlumnos, Nodo* listaMaterias): se asocia un alumno con una materia que ya existe a través del código de ésta, se copian los datos de la materia y los guarda en alumno.
- rendirMateria(Nodo* listaAlumnos): permite ingresar la nota de una materia rendida y marca si fue aprobada si la nota es superior o igual a 4.

**Búsquedas de estudiantes:**
- buscarAlumnoPorNombre(Nodo* listaAlumnos): se implementó una búsqueda por nombre, que permite localizar rápidamente un alumno ingresando su nombre.
- buscarAlumnosPorEdad(Nodo* listaAlumnos): también se desarrolló una búsqueda por rango de edad que imprime los datos del alumno.
- buscarAlumnosPorMateria(Nodo* listaAlumnos): por último creamos la funcion de buscar alumnos anotados en una materia por código.

**MATERIAS** 
---
- altaMateria(Nodo** listaMaterias): se crea una nueva materia con nombre y código para agregar a la lista.
- listarMaterias(Nodo** listaMaterias): se muestra un listado de todas las materias registradas.
- modificarMateria(Nodo** listaMaterias): se busca una materia por código y se permite su modificación.
- eliminarMateria(Nodo** listaMaterias): se busca y se elimina una materia por código y se libera memoria del nodo.

**Inscripción:**
    Cada estudiante puede anotarse en un máximo de 8 materias.
    Se implementó una función para que los estudiantes puedan rendir materias.

---
## 4. Estructura base
- **Nodo**: se utiliza una lista simplemente enlazada con void* valor para almacenar Alumno* o Materia*-
- Tenemos un manejo dinámico de memoria (malloc, free).
- Utilizamos strcmp para comparar cadenas de texto y strcpy para copiar una cadena de caracteres en otra.
## 5. Puntos extra

- **Carga masiva de datos**: A traves de archivos txt se desarrollo una funcion para evitar cargar datos de manera manual.

- **Calculo de promedios**: Funciones para calcular promedios tanto de un estudiante individual como de la totalidad de los estudiantes de una materia.

- **Paginado**: Al imprimir largas cantidades de datos en pantalla, se implementa el paginado para una mejor lectura de los datos.

- **Mejoras en menu**: Implementacion de varios menus para una mejor experiencia de usuario.
