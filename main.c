#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.c"
#include "linkedListReal.c"


int main() {
    Nodo* listaAlumnos = NULL;
    Nodo* listaMaterias = NULL;
    
    int opcion;
    do {
        printf("\n1. Alta de alumno\n");
        printf("2. Alta de materia\n");
        printf("3. Anotar alumno en materia\n");
        printf("4. Rendir materia\n");
        printf("5. Listar alumnos\n");
        printf("6. Listar materias\n");
        printf("7. Modificar alumno\n");
        printf("8. Modificar materia\n");
        printf("9. Eliminar alumno\n");
        printf("10. Eliminar materia\n");
        printf("11. Buscar alumno por nombre\n");
        printf("12. Buscar alumno por edad\n");
        printf("13. Calcular estadisticas\n");
        printf("14. Calcular promedio de un alumno\n");
        printf("15. Calcular promedio de una materia\n");
        printf("16. Salir\n");
        printf("Seleccione una : ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                altaAlumno(&listaAlumnos);
                break;
            case 2:
                altaMateria(&listaMaterias);
                break;
            case 3:
                anotarAlumnoEnMateria(listaAlumnos, listaMaterias);
                break;
            case 4:
                buscarAlumnoPorNombre(listaAlumnos);
                break;
            case 5: 
                buscarEstudiantePorEdad(listaAlumnos);
                break;  
            case 6:
                rendirMateria(listaAlumnos);
                break;
            case 7:
                listarAlumnos(listaAlumnos);
                break;
            case 8:
                listarMaterias(listaMaterias);
                break;
            case 9:
                modificarAlumno(listaAlumnos);
                break;
            case 10:
                modificarMateria(listaMaterias);
                break;
            case 11:
                eliminarAlumno(&listaAlumnos);
                break;
            case 12:
                {
                    char nombre[20];
                    printf("Ingrese el nombre del alumno: ");
                    scanf("%s", nombre);
                    buscarEstudiantePorNombre(listaAlumnos, nombre);
                }
                break;
            case 13:
                {
                    int edad;
                    printf("Ingrese la edad del alumno: ");
                    scanf("%d", &edad);
                    buscarEstudiantePorEdad(listaAlumnos, edad);
                }
                break;
       
            // case 15:
            //     {
            //         char nombre[50];
            //         printf("Ingrese el nombre del alumno: ");
            //         scanf("%s", nombre);
            //         calcularPromedioEstudiante(listaAlumnos, nombre);
            //     }
            //     break;
            // case 16:
            //     {
            //         int codigoMateria;
            //         printf("Ingrese el codigo de la materia: ");
            //         scanf("%d", &codigoMateria);
            //         calcularPromedioMateria(listaAlumnos, codigoMateria);
            //     }
            //     break;
            case 17:
                printf("Saliendo...\n");
                break;
            default:
                printf(" invalida. Intente de nuevo.\n");
        }
    } while (opcion != 16);

    return 0;
}