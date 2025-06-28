#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaximoMaterias 8

typedef struct {
    char nombre[20];
    int nota;
    int aprobado;
} Materia;

typedef struct {
    char nombre[20];
    int edad;
    Materia* materias[MaximoMaterias];
    int cant_materias; 
} Alumno;




