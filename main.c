#include <stdio.h>
#include <stdlib.h>

#include "funciones.c"
// main de funciones :)

int main() {
    Nodo* listaAlumnos = NULL;
    Nodo* listaMaterias = NULL; 

    int opcion;

    do {
        printf("\n--- MENU DE ALUMNOS ---\n");
        printf("1. Alta de alumno\n");
        printf("2. Modificar alumno\n");
        printf("3. Eliminar alumno\n");
        printf("4. Listar alumnos\n");
        printf("5. Buscar alumno por nombre\n");
        printf("6. Buscar alumno por edad\n");
        printf("7. Anotar alumno en materia\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                altaAlumno(&listaAlumnos);
                break;
            case 2:
                modificarAlumno(&listaAlumnos);
                break;
            case 3:
                eliminarAlumno(&listaAlumnos);
                break;
            case 4:
                listarAlumnos(&listaAlumnos);
                break;
            case 5:
                buscarAlumnoPorNombre(&listaAlumnos);
                break;
            case 6:
                buscarAlumnoPorEdad(&listaAlumnos);
                break;
            case 7:
                anotarAlumnoEnMateria(listaAlumnos, listaMaterias);
                break;
            case 0:
                printf("Salgo del programa.\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }

    } while (opcion != 0);

    return 0;
}


