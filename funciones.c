//#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structsYusos.c"

void altaAlumno(Nodo** listaAlumnos) {
    //Reserva memoria y devuelve error en caso de estar llena
    Alumno* nuevaMateria = (Alumno*)malloc(sizeof(Alumno));
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevaMateria == NULL || nodo == NULL) {
        printf("Memoria llena, no se pudo asignar memoria para el alumno.\n");
        free(nuevaMateria);
        free(nodo);
        return;
    }

    //Asigna los datos al alumno
    printf("Ingrese el nombre del alumno: \n");
    scanf("%s", nuevaMateria->nombre);

    printf("Ingrese edad del alumno: \n");
    scanf("%d", &nuevaMateria->edad);

    nuevaMateria->cant_materias = 0;

    
    //Asigna valores al nodo
    nodo->valor = nuevaMateria;
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
        printf("Nombre: %s, Edad: %d.\n",alumno->nombre, alumno->edad);
        cursor = cursor->next;
    }
}


void buscarAlumnoPorNombre(Nodo* listaAlumnos) {
    char nombre[20];
    printf("Ingrese el nombre del Alumno.\n");
    scanf("%s", nombre);

    while (listaAlumnos != NULL) {
        Alumno* alumno = (Alumno*)listaAlumnos->valor;
        if (strcmp(alumno->nombre, nombre) == 0) {
            printf("Nombre: %s, Edad: %d\n", alumno->nombre, alumno->edad);
            for (int i = 0; i < MaximoMaterias; i++) {
                printf("\tMateria: %s, Nota: %d, Aprobada: %s\n", alumno->materias[i]->nombre, alumno->materias[i]->nota, alumno->materias[i]->aprobado ? "Si" : "No");
            }
            return;
        }
        listaAlumnos = listaAlumnos->next;
    }
    printf("alumno no encontrado.\n");
}


void buscarAlumnoPorEdad(Nodo* listaAlumnos) {
    int edad;
    printf("Ingrese la edad a buscar: \n");
    scanf("%d", &edad);
    int encontrado = 0;
    while (listaAlumnos != NULL) {
        Alumno* alumno = (Alumno*)listaAlumnos->valor;
        if (alumno->edad == edad) {
            printf("Nombre: %s, Edad: %d\n", alumno->nombre, alumno->edad);
            for (int i = 0; i < alumno->cant_materias; i++) {
                printf("\tMateria: %s, Nota: %d, Aprobada: %s\n", alumno->materias[i]->nombre, alumno->materias[i]->nota, alumno->materias[i]->aprobado ? "Si" : "No");
            }
            return;
        }
        listaAlumnos = listaAlumnos->next;  
    }
    if (!encontrado) {
        printf("No se encontraron alumnos con la edad %d.\n", edad);
    }
  }

void anotarAlumnoEnMateria (Nodo* listaAlumnos, Nodo* listaMaterias){
char nombreAlumno[20];
    int codigoMateria;

    printf("Ingrese el nombre del alumno: ");
    scanf("%s", nombreAlumno);
    printf("Ingrese el codigo de la materia: ");
    scanf("%d", &codigoMateria);

    Nodo* cursorAlum = listaAlumnos;
    while (cursorAlum != NULL) {
        Alumno* alumno = (Alumno*)cursorAlum->valor;
        if (strcmp(alumno->nombre, nombreAlumno) == 0) {
           Nodo* cursorMateria = listaMaterias;
            while (cursorMateria != NULL) {
                Materia* materia = (Materia*)cursorMateria->valor;
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
                        printf("alumno %s anotado en la materia %s.\n", alumno->nombre, materia->nombre);
                    } else {
                        printf("El alumno ya esta inscrito en el maximo de materias permitidas.\n");
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
    printf("alumno no encontrado.\n");
}

void rendirMateria(Nodo* listaAlumnos){
char nombreAlumno[20];
    int codigoMateria, nota;

    printf("Ingrese el nombre del alumno: ");
    scanf("%s", nombreAlumno);
    printf("Ingrese el codigo de la materia: ");
    scanf("%d", &codigoMateria);
    printf("Ingrese la nota: ");
    scanf("%d", &nota);

    Nodo* cursorAlum = listaAlumnos;
    while (cursorAlum != NULL) {
        Alumno* alumno = (Alumno*)cursorAlum->valor;
        if (strcmp(alumno->nombre, nombreAlumno) == 0) {
            for (int i = 0; i < alumno->cant_materias; i++) {
                if (alumno->materias[i]->codigo == codigoMateria) {
                    alumno->materias[i]->nota = nota;
                    alumno->materias[i]->aprobado = (nota >= 4) ? 1 : 0;
                    printf("Nota registrada para la materia %s. %s.\n", alumno->materias[i]->nombre, alumno->materias[i]->aprobado ? "Materia aprobada" : "Materia no aprobada");
                    return;
                }
            }
            printf("Materia no encontrada en la lista del alumno.\n");
            return;
        }
        cursorAlum = cursorAlum->next;
    }
    printf("alumno no encontrado.\n");
}

void altaMateria(Nodo** listaMaterias) {
    //Reserva memoria y devuelve error en caso de estar llena
    Materia* nuevaMateria = (Materia*)malloc(sizeof(Materia));
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevaMateria == NULL || nodo == NULL) {
        printf("Memoria llena, no se pudo asignar memoria para la materia.\n");
        free(nuevaMateria);
        free(nodo);
        return;
    }

    //Asigna los datos a la materia
    printf("Ingrese el nombre de la materia: \n");
    scanf("%s", nuevaMateria->nombre);

    printf("Ingrese el codigo de la materia: \n");
    scanf("%d", &nuevaMateria->codigo);

    //Asigna valores al nodo
    nodo->valor = nuevaMateria;
    nodo->next = NULL;
    
    //Si la lista esta vacia, el nuevo nodo es el head
    if (*listaMaterias == NULL){
        *listaMaterias = nodo;
    } else { //Sino, el cursor se situa en el último elemento de la lista y asigna como siguiente al nuevo nodo
        Nodo* cursor = *listaMaterias;
        while (cursor->next != NULL){
            cursor = cursor ->next;
        }
        cursor -> next = nodo;
    }
    printf("Alta realizada con éxito.\n");
}

void listarMaterias(Nodo** listaMaterias){
    if (listaMaterias == NULL){
        printf("La lista está vacía.\n");
        return;
    }
    printf("Listado: \n");
    Nodo* cursor = *listaMaterias;
    while(cursor != NULL) {
        Materia* materia = (Materia*)cursor->valor;
        printf("Nombre: %s, Codigo: %d.\n",materia->nombre, materia->codigo);
        cursor = cursor->next;
    }
}

void modificarMateria(Nodo** listaMaterias){
    int codigo;
    printf("Ingrese el codigo de la materia a modificar: \n");
    scanf("%d", &codigo);
    
    Nodo* cursor = *listaMaterias;
    while(cursor != NULL) {
        Materia* materia = (Materia*)cursor->valor;
        if (codigo==materia->codigo){
            printf("Ingrese el nuevo nombre: ");
            scanf("%s",materia->nombre);
            printf("Ingrese el nuevo codigo: ");
            scanf("%d",&materia->codigo);
            printf("Materia modificada con éxito.\n");
            return;
        }
        cursor = cursor->next;
    }
    printf("La materia ingresada no existe.\n");
}

// void altaalumno(Nodo** listaAlumnos); xxx
// void modificaralumno(Nodo* listaAlumnos); xxx
// void eliminaralumno(Nodo** listaAlumnos); xxx
// void listaralumnos(Nodo* listaAlumnos); xxx 
// void buscaralumnoPorNombre(Nodo* listaAlumnos, char nombre[]); xxx
// void buscaralumnoPorEdad(Nodo* listaAlumnos, int edad); xxx 
// void anotaralumnoEnMateria(Nodo* listaAlumnos, Nodo* listaAlumnos); xxx
// void rendirMateria(Nodo* listaAlumnos); xxx
// void calcularEstadisticas(Nodo* listaAlumnos, Nodo* listaAlumnos);
// void calcularPromedioalumno(Nodo* listaAlumnos, char nombre[]);
// void calcularPromedioMateria(Nodo* listaAlumnos, int codigoMateria);

