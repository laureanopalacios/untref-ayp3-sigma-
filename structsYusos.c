#pragma once
#define MaximoMaterias 8

typedef struct Materia {
    char nombre[50];
    int codigo;
} Materia;


typedef struct {
    char nombre[20];
    int edad;
    Materia* materias[MaximoMaterias];
    int cant_materias; 
} Alumno;

typedef struct Nodo{
    struct Nodo* next;
    void* valor;
} Nodo;


