#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structsYusos.c"

int compararNombres(void* a, void* b) {
    char* nombre1 = (char*)a;
    char* nombre2 = (char*)b;
    return strcmp(nombre1, nombre2);
}

void altaAlumno(Nodo** listaAlumnos) {
    //Reserva memoria y devuelve error en caso de estar llena
    Alumno* nuevoAlumno = (Alumno*)malloc(sizeof(Alumno));
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoAlumno == NULL || nodo == NULL) {
        printf("Memoria llena, no se pudo asignar memoria para el alumno.\n");
        free(nuevoAlumno);
        free(nodo);
        return;
    }

    //Asigna los datos al alumno
    printf("Ingrese el nombre del alumno: \n");
    scanf("%s", nuevoAlumno->nombre);

    printf("Ingrese edad del alumno: \n");
    scanf("%d", &nuevoAlumno->edad);

    nuevoAlumno->cant_materias = 0;

    
    //Asigna valores al nodo
    nodo->valor = nuevoAlumno;
    nodo->next = NULL;
    
    //Si la lista esta vacia, el nuevo nodo es el head
    if (*listaAlumnos == NULL){
        *listaAlumnos = nodo;
    } else { //Sino, el cursor se situa en el último elemento de la lista y asigna como siguiente al nuevo nodo
        Nodo* cursor = *listaAlumnos;
        while (cursor->next != NULL){
            cursor = cursor ->next;
        }
        cursor -> next = nodo;
    }
    printf("Alta realizada con éxito.\n");
}

void modificarAlumno(Nodo** listaAlumnos){
    char nombre[20];
    printf("Ingrese el nombre del alumno a modificar: \n");
    scanf("%s", nombre);
    
    Nodo* cursor = *listaAlumnos;
    while(cursor != NULL) {
        Alumno* alumno = (Alumno*)cursor->valor;
        if (strcmp(alumno->nombre,nombre)== 0){
            printf("Ingrese el nuevo nombre: ");
            scanf("%s",alumno->nombre);
            printf("Ingrese la nueva edad: ");
            scanf("%d", &alumno->edad);
            printf("Alumno modificado con éxito.\n");
            return;
        }
        cursor = cursor->next;
    }
    printf("El alumno ingresado no existe.\n");
}

void eliminarAlumno(Nodo** listaAlumnos){
    char nombre[20];
    printf("Ingrese el nombre del alumno a eliminar");
    scanf("%s", nombre);

    Nodo* cursor = *listaAlumnos;
    Nodo* anterior = NULL;
    while (cursor != NULL) {
        Alumno* alumno = (Alumno*)cursor->valor;{
            if (strcmp(alumno->nombre, nombre)== 0){
                if (anterior == NULL){
                    *listaAlumnos = cursor->next;
                } else {
                    anterior ->next = cursor->next;
                }
                free(cursor);
                printf("Alumno dado de baja.\n");
            }
            anterior = cursor;
            cursor = cursor->next;
        }
    }
    printf("El alumno ingresado no existe.\n");
}

void listarAlumnos(Nodo** listaAlumnos){
    if (listaAlumnos == NULL){
        printf("La lista está vacía.\n");
        return;
    }
    printf("Listado: \n");
    Nodo* cursor = *listaAlumnos;
    while(cursor != NULL) {
        Alumno* alumno = (Alumno*)cursor->valor;
        printf("Nombre: %s, Edad: %d",alumno->nombre, alumno->edad);
        cursor = cursor->next;
    }
}


void buscarAlumnoPorNombre(Nodo* listaAlumnos, char nombre[]) {
    while (listaAlumnos != NULL) {
        Nodo* alumno = (Nodo*)listaAlumnos->valor;
        if (strcmp(alumno->nombre, nombre) == 0) {
            printf("Nombre: %s, Edad: %d\n", alumno->nombre, alumno->edad);
            for (int i = 0; i < alumno->num_materias; i++) {
                printf("\tMateria: %s, Nota: %d, Aprobada: %s\n", alumno->materias[i]->nombre, alumno->materias[i]->nota, estudiante->materias[i]->aprobado ? "Si" : "No");
            }
            return;
        }
        listaAlumnos = listaAlumnos->next;
    }
    printf("Estudiante no encontrado.\n");
}

/*int comparadorPorEdad(void* a, void* b) {
    Alumno* alumno = (Alumno*)a;
    int* edadBuscada = (int*)b;
    printf("Comparando %d con %d\n", alumno->edad, *edadBuscada);    
    return alumno->edad - *edadBuscada;
}
*/


void buscarEstudiantePorEdad(Nodo* listaAlumnos, int edad) {
    int encontrado = 0;
    while (listaAlumnos != NULL) {
        Nodo* alumno = (Nodo*)listaAlumnos->valor;
        if (alumno->edad == edad) {
            printf("Nombre: %s, Edad: %d\n", alumno->nombre, alumno->edad);
            for (int i = 0; i < alumno->num_materias; i++) {
                printf("\tMateria: %s, Nota: %d, Aprobada: %s\n", estudiante->materias[i]->nombre, alumno->materias[i]->nota, estudiante->materias[i]->aprobado ? "Si" : "No");
            alumno
            encontrado = 1;
        }
        listaAlumnos = listaAlumnos->next;
    }
    if (!encontrado) {
        printf("No se encontraron estudiantes con la edad %d.\n", edad);
    }
}

void anotarAlumnoEnMateria (Nodo* listaAlumnos, Nodo* listaMaterias){
char nombreEstudiante[20];
    int codigoMateria;

    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", nombreEstudiante);
    printf("Ingrese el codigo de la materia: ");
    scanf("%d", &codigoMateria);

    Nodo* cursorAlum = listaAlumnos;
    while (cursorAlum != NULL) {
        Nodo* alumno = (Nodo*)cursor->valor;
        if (strcmp(alumno->nombre, alumno) == 0) {
            Nodo* cursorMateria = listaAlumnos;
            while (cursorMateria != NULL) {
                Materia* materia = (Materia*)cursorMateria->data;
                if (materia->codigo == codigoMateria) {
                    if (alumno->cant_materias < MaximoMaterias) {
                        Materia* copiaMateria = (Materia*)malloc(sizeof(Materia));
                        if (copiaMateria == NULL) {
                            printf("Error: No se pudo asignar memoria para la copia de la materia.\n");
                            return;
                        }
                        strcpy(copiaMateria->nombre, materia->nombre);
                        copiaMateria->codigo = materia->codigo;
                        copiaMateria->nota = -1; 
                        copiaMateria->aprobado = 0; 

                        alumno->materias[alumno->cant_materias] = copiaMateria;
                        alumno->cant_materias++;
                        printf("Estudiante %s anotado en la materia %s.\n", alumno->nombre, materia->nombre);
                    } else {
                        printf("El estudiante ya esta inscrito en el maximo de materias permitidas.\n");
                    }
                    return;
                }
                cursorMateria = cursorMateria->next;
            }
            printf("Materia no encontrada.\n");
            return;
        }
        cursorAlum = cursorAlum->next;
    }
    printf("Estudiante no encontrado.\n");
}
void rendirMateria(Nodo* listarAlumnos){
    
}

// void altaEstudiante(Nodo** listaEstudiantes); xxx
// void modificarEstudiante(Nodo* listaEstudiantes); xxx
// void eliminarEstudiante(Nodo** listaEstudiantes); xxx
// void listarEstudiantes(Nodo* listaEstudiantes); xxx 
// void buscarEstudiantePorNombre(Nodo* listaEstudiantes, char nombre[]); xxx
// void buscarEstudiantePorEdad(Nodo* listaEstudiantes, int edad); xxx 
// void anotarEstudianteEnMateria(Nodo* listaEstudiantes, Nodo* listaMaterias); xxx
// void rendirMateria(Nodo* listaEstudiantes);
// void calcularEstadisticas(Nodo* listaEstudiantes, Nodo* listaMaterias);
// void calcularPromedioEstudiante(Nodo* listaEstudiantes, char nombre[]);
// void calcularPromedioMateria(Nodo* listaEstudiantes, int codigoMateria);

