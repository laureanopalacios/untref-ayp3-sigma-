#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.c"



int main() {
    Nodo* listaEstudiantes = NULL;
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
                altaEstudiante(&listaEstudiantes);
                break;
            case 2:
                altaMateria(&listaMaterias);
                break;
            case 3:
                anotarEstudianteEnMateria(listaEstudiantes, listaMaterias);
                break;
            case 4:
                rendirMateria(listaEstudiantes);
                break;
            case 5:
                listarEstudiantes(listaEstudiantes);
                break;
            case 6:
                listarMaterias(listaMaterias);
                break;
            case 7:
                modificarEstudiante(listaEstudiantes);
                break;
            case 8:
                modificarMateria(listaMaterias);
                break;
            case 9:
                eliminarEstudiante(&listaEstudiantes);
                break;
            case 10:
                eliminarMateria(&listaMaterias);
                break;
            case 11:
                {
                    char nombre[50];
                    printf("Ingrese el nombre del alumno: ");
                    scanf("%s", nombre);
                    buscarEstudiantePorNombre(listaEstudiantes, nombre);
                }
                break;
            case 12:
                {
                    int edad;
                    printf("Ingrese la edad del alumno: ");
                    scanf("%d", &edad);
                    buscarEstudiantePorEdad(listaEstudiantes, edad);
                }
                break;
            case 13:
                calcularEstadisticas(listaEstudiantes, listaMaterias);
                break;
            case 14:
                {
                    char nombre[50];
                    printf("Ingrese el nombre del alumno: ");
                    scanf("%s", nombre);
                    calcularPromedioEstudiante(listaEstudiantes, nombre);
                }
                break;
            case 15:
                {
                    int codigoMateria;
                    printf("Ingrese el codigo de la materia: ");
                    scanf("%d", &codigoMateria);
                    calcularPromedioMateria(listaEstudiantes, codigoMateria);
                }
                break;
            case 16:
                printf("Saliendo...\n");
                break;
            default:
                printf(" invalida. Intente de nuevo.\n");
        }
    } while (opcion != 16);

    return 0;
}