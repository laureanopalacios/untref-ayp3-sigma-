#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <funcionesYstructs.c>
#include <linkedListReal.c>

#define maximoMaterias 8

void altaAlumno(Nodo** listaAlumnos) {
    Alumno* nuevoAlumno = (Alumno*)malloc(sizeof(Alumno));

    if (nuevoAlumno == NULL) {
        printf("Memoria llena, no se pudo asignar memoria para el alumno.\n");
        return;
    }

    printf("Ingrese el nombre del alumno:\n");
    scanf("%s", nuevoAlumno->nombre);

    printf("Ingrese edad del alumno:\n");
    scanf("%d", &nuevoAlumno->edad);

    nuevoAlumno->cant_materias = 0;

    Nodo* nuevoNodo = nuevoNodoLista(nuevoAlumno); // función para crear nodo

    // Insertar al principio de la lista
    nuevoNodo->next = *listaAlumnos;
    *listaAlumnos = nuevoNodo;

    printf("Alta realizada con éxito.\n");
}

void modificarAlumno(Nodo** listaAlumnos){
    char nombre[20];
    printf("Ingrese el nombre del alumno a modificar:\n");
    scanf("%s", &nombre);
    
    Nodo* alumnoModificado = buscarNodo(listaAlumnos, nombre);
    if (alumnoModificado == NULL) {
        printf("El alumno no está en la lista.\n");
        return;
    }

    alumnoModificado -> nombre = nombre;
    printf("Alumno modificado con éxito.\n");
}

void eliminarAlumno(Nodo** listaAlumnos){
    char nombre[20];
    printf("Ingrese el nombre del alumno a eliminar");
    scanf("%s", &nombre);
    listaAlumnos.eliminarNodo(listaAlumnos, nombre);
}

void listarAlumnos(Nodo** listaAlumnos){
    imprimirLista(listaAlumnos);
}

void buscarAlumnoPorNombre(Nodo** listaAlumnos){
    char nombre[20];
    printf("Ingrese el nombre del alumno a buscar:\n");
    scanf("%s", &nombre);
    Nodo* alumno = buscarNodo(listaAlumnos, nombre);
    if (alumno == NULL) {
        printf("Alumno no encontrado.\n");
        return;
    }

    printf("Alumno encontrado.\n")
}

void buscarAlumnoPorEdad(Nodo** listaAlumnos){
    int edad;
    printf("Ingrese el nombre del alumno a buscar:\n");
    scanf("%s", &nombre);
    Nodo* alumno = buscarNodo(listaAlumnos, edad;
    if (alumno == NULL) {
        printf("Alumno no encontrado.\n");
        return;
    }

    printf("Alumno encontrado.\n")
}

void anotarAlumnoEnMateria (Nodo* listaAlumnos, Nodo* listaMaterias){

}


// void altaEstudiante(Nodo** listaEstudiantes); xxx
// void modificarEstudiante(Nodo* listaEstudiantes); xxx
// void eliminarEstudiante(Nodo** listaEstudiantes); xxx
// void listarEstudiantes(Nodo* listaEstudiantes); xxx 
// void buscarEstudiantePorNombre(Nodo* listaEstudiantes, char nombre[]); xxx
// void buscarEstudiantePorEdad(Nodo* listaEstudiantes, int edad); xxx 
// void anotarEstudianteEnMateria(Nodo* listaEstudiantes, Nodo* listaMaterias);
// void rendirMateria(Nodo* listaEstudiantes);
// void calcularEstadisticas(Nodo* listaEstudiantes, Nodo* listaMaterias);
// void calcularPromedioEstudiante(Nodo* listaEstudiantes, char nombre[]);
// void calcularPromedioMateria(Nodo* listaEstudiantes, int codigoMateria);
