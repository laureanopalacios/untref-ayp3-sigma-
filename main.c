#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.c"

void menuAlumnos(Nodo** listaAlumnos, Nodo* listaMaterias) {
    int opcion;
    do {
        printf("\n--- MENÚ ALUMNOS ---\n");
        printf("1. Alta de alumno\n");
        printf("2. Modificar alumno\n");
        printf("3. Eliminar alumno\n");
        printf("4. Buscar alumno por nombre\n");
        printf("5. Buscar alumnos por edad\n");
        printf("6. Buscar alumnos por materia\n");
        printf("7. Calcular promedio de un alumno\n");
        printf("8. Cargar alumnos desde archivo\n");
        printf("9. Listar alumnos\n");
        printf("0. Volver al menú principal\n");
        printf("Seleccione una: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: altaAlumno(listaAlumnos); break;
            case 2: modificarAlumno(listaAlumnos); break;
            case 3: eliminarAlumno(listaAlumnos); break;
            case 4: buscarAlumnoPorNombre(*listaAlumnos); break;
            case 5: buscarAlumnosPorEdad(*listaAlumnos); break;
            case 6: buscarAlumnosPorMateria(*listaAlumnos); break;
            case 7: calcularPromedioAlumno(listaAlumnos); break;
            case 8: cargarAlumnosDesdeArchivo("data/alumnos50.txt", listaAlumnos); break;
            case 9: listarAlumnos(listaAlumnos); break;
            case 0: break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 0);
}

void menuMaterias(Nodo** listaMaterias, Nodo* listaAlumnos) {
    int opcion;
    do {
        printf("\n--- MENÚ MATERIAS ---\n");
        printf("1. Alta de materia\n");
        printf("2. Modificar materia\n");
        printf("3. Eliminar materia\n");
        printf("4. Anotar alumno en materia\n");
        printf("5. Rendir materia\n");
        printf("6. Calcular estadísticas de una materia\n");
        printf("7. Cargar materias desde archivo\n");
        printf("8. Listar materias\n");
        printf("0. Volver al menú principal\n");
        printf("Seleccione una: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: altaMateria(listaMaterias); break;
            case 2: modificarMateria(listaMaterias); break;
            case 3: eliminarMateria(listaMaterias); break;
            case 4: anotarAlumnoEnMateria(listaAlumnos, *listaMaterias); break;
            case 5: rendirMateria(listaAlumnos); break;
            case 6: calcularEstadisticasMateria(listaAlumnos); break;
            case 7: cargarMateriasDesdeArchivo("data/materias.txt", listaMaterias); break;
            case 8: listarMaterias(listaMaterias); break;
            case 0: break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 0);
}

int main() {
    Nodo* listaAlumnos = NULL;
    Nodo* listaMaterias = NULL;

    int opcion;
    do {
        printf("\n===== MENÚ PRINCIPAL =====\n");
        printf("1. Gestión de alumnos\n");
        printf("2. Gestión de materias\n");
        printf("0. Salir\n");
        printf("Seleccione una: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: menuAlumnos(&listaAlumnos, listaMaterias); break;
            case 2: menuMaterias(&listaMaterias, listaAlumnos); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 0);

    return 0;
}
