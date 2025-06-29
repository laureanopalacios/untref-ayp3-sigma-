#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structsYusos.c"

int limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return c;
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
    scanf(" %[^\n]", nuevoAlumno->nombre);
    getchar(); //Para que no imprima la siguiente linea antes de tiempo

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
    scanf(" %[^\n]", nombre);
    
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
    printf("Ingrese el nombre del alumno a eliminar: \n");
    scanf(" %[^\n]", nombre);

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
    int contador = 0;
    printf("Listado: \n");
    Nodo* cursor = *listaAlumnos;
    limpiarBuffer();
    while(cursor != NULL) {
        Alumno* alumno = (Alumno*)cursor->valor;
        printf("Nombre: %s, Edad: %d.\n",alumno->nombre, alumno->edad);
        if (contador % 5 == 0 && contador !=0){
            printf("Presione ENTER para avanzar al siguiente.\n");
            getchar();
        }
        cursor = cursor->next;
        contador++;
    }
}


void buscarAlumnoPorNombre(Nodo* listaAlumnos) {
    char nombre[20];
    printf("Ingrese el nombre del Alumno.\n");
    scanf(" %[^\n]", nombre);

    while (listaAlumnos != NULL) {
        Alumno* alumno = (Alumno*)listaAlumnos->valor;
        if (strcmp(alumno->nombre, nombre) == 0) {
            printf("Nombre: %s, Edad: %d\n", alumno->nombre, alumno->edad);
            for (int i = 0; i < MaximoMaterias; i++) {
                if (alumno->materias[i] != NULL) {
                    printf("\tMateria: %s, Nota: %d, Aprobada: %s\n",
                        alumno->materias[i]->nombre,
                        alumno->materias[i]->nota, 
                        alumno->materias[i]->aprobado ? "Si" : "No");
                }
            }
            return;
        }
        listaAlumnos = listaAlumnos->next;
    }
    printf("alumno no encontrado.\n");
}

void buscarAlumnosPorEdad(Nodo* listaAlumnos) {
    int edad;
    printf("Ingrese la edad a buscar: \n");
    scanf("%d", &edad);
    int encontrado = 0;
    while (listaAlumnos != NULL) {
        Alumno* alumno = (Alumno*)listaAlumnos->valor;
        if (alumno->edad == edad) {
            encontrado = 1;
            printf("Nombre: %s, Edad: %d\n", alumno->nombre, alumno->edad);
            for (int i = 0; i < alumno->cant_materias; i++) {
                printf("\tMateria: %s, Nota: %d, Aprobada: %s\n",
                    alumno->materias[i]->nombre,
                    alumno->materias[i]->nota,
                    alumno->materias[i]->aprobado ? "Si" : "No");
                }
        }
        listaAlumnos = listaAlumnos->next;  
    }
    if (!encontrado) {
        printf("No se encontraron alumnos con la edad %d.\n", edad);
    }
  }

void buscarAlumnosPorMateria(Nodo* listaAlumnos){
    int materia;
    printf("Ingrese el codigo de la materia: \n");
    scanf("%d", &materia);

    //Recorre la lista de alumnos y cada materia que este cursando el alumno
    int encontrado = 0;
    while (listaAlumnos != NULL) {
        Alumno* alumno = (Alumno*)listaAlumnos->valor;
        for (int i = 0; i < alumno->cant_materias; i++) {
            if (alumno->materias[i]->codigo == materia){
                encontrado = 1;
                printf("Nombre: %s, Edad: %d, Aprobado:%s\n", alumno->nombre, alumno->edad, alumno->materias[i]->aprobado ? "Si" : "No");
            }
        }    
        listaAlumnos = listaAlumnos->next;  
    }
    if (!encontrado) {
        printf("No se encontraron alumnos en la materia %d", materia);
    }
}  

void anotarAlumnoEnMateria (Nodo* listaAlumnos, Nodo* listaMaterias){
    char nombreAlumno[20];
    int codigoMateria;

    printf("Ingrese el nombre del alumno: ");
    scanf(" %[^\n]", nombreAlumno);
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
    scanf(" %[^\n]", nombreAlumno);
    printf("Ingrese el codigo de la materia: ");
    scanf("%d", &codigoMateria);
    printf("Ingrese la nota: ");
    scanf("%d", &nota);
    if (nota > 10 || nota < 0){
        printf("Nota invalida.\n");
        return;
    }

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
    scanf(" %[^\n]", nuevaMateria->nombre);
    getchar(); //Para que no imprima la siguiente linea antes de tiempo
    int newCodigo = 0;
    printf("Ingrese el codigo de la materia: \n");
    scanf("%d", &newCodigo);

    Nodo* cursor = *listaMaterias;
    while (cursor != NULL) {
        Materia* materia = (Materia*)cursor->valor;
        if (materia->codigo == newCodigo) {
            printf("Ya existe una materia con ese código.\n");
            return;
        }
    cursor = cursor->next;
    }
    nuevaMateria->codigo = newCodigo;
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
    int contador = 0;
    printf("Listado: \n");
    Nodo* cursor = *listaMaterias;
    limpiarBuffer();
    while(cursor != NULL) {
        Materia* materia = (Materia*)cursor->valor;
        printf("Nombre: %s, Codigo: %d.\n",materia->nombre, materia->codigo);
        if (contador % 10 == 0 && contador != 0){
            printf("Presione ENTER para avanzar a la siguiente página.\n");
            getchar();
        }
        cursor = cursor->next;
        contador++;
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

void eliminarMateria(Nodo** listaMaterias) {
    int codigo;
    printf("Ingrese el codigo de la materia a eliminar: ");
    scanf("%d", &codigo);

    Nodo *cursor = *listaMaterias, *anterior = NULL;
    while (cursor != NULL) {
        Materia* materia = (Materia*)cursor->valor;
        if (materia->codigo == codigo) {
            if (anterior == NULL) {
                *listaMaterias = cursor->next;
            } else {
                anterior->next = cursor->next;
            }
            free(materia);
            free(cursor);
            printf("Materia eliminada exitosamente.\n");
            return;
        }
        anterior = cursor;
        cursor = cursor->next;
    }
    printf("Materia no encontrada.\n");
}

void calcularPromedioAlumno(Nodo** listaAlumnos){
    char nombre[20];
    printf("Ingrese el nombre del alumno: \n");
    scanf(" %[^\n]", nombre);
    float promedio = 0;
    int suma = 0;

    int encontrado = 0;
    Nodo* cursor = *listaAlumnos;
    while (cursor != NULL) {
        Alumno* alumno = (Alumno*)cursor->valor;
        if (strcmp(alumno->nombre, nombre) == 0){
            if(alumno->cant_materias == 0){
                printf("El alumno no está cursando ninguna materia.\n");
            }
            encontrado = 1;
            for (int i = 0; i < alumno->cant_materias; i++){
                suma += alumno->materias[i]->nota;
            }
            promedio = suma/(float)alumno->cant_materias;
            printf("El promedio del alumno %s es: %f",nombre, promedio);
            return;
        }
        cursor = cursor->next;
    }
    if (!encontrado){
        printf("El alumno ingresado no existe.\n");
    }
}

void calcularEstadisticasMateria(Nodo* listaAlumnos){
    int materia;
    printf("Ingrese el codigo de la materia: \n");
    scanf("%d", &materia);
    int suma = 0;
    int cantAlumnos = 0;
    //Recorre la lista de alumnos y cada materia que este cursando el alumno
    int encontrado = 0;
    while (listaAlumnos != NULL) {
        Alumno* alumno = (Alumno*)listaAlumnos->valor;
        for (int i = 0; i < alumno->cant_materias; i++) {
            if (alumno->materias[i]->codigo == materia){
                encontrado = 1;
                printf("Nombre: %s, Edad: %d, Aprobado:%s\n",
                    alumno->nombre,
                    alumno->edad,
                    alumno->materias[i]->aprobado ? "Si" : "No");
                suma += alumno->materias[i]->nota;
                cantAlumnos++;
            }
        }    
        listaAlumnos = listaAlumnos->next;  
    }
    printf("Cantidad de Alumnos:%d, Promedio general: %f.\n", cantAlumnos, (float)suma/cantAlumnos);
    if (!encontrado) {
        printf("No se encontro la materia.\n");
    }
} 

void cargarMateriasDesdeArchivo(const char* nombreArchivo, Nodo** listaMaterias) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo: %s\n", nombreArchivo);
        return;
    }

    char linea[150];
    while (fgets(linea, sizeof(linea), archivo)) {
        linea[strcspn(linea, "\n")] = 0;

        char* token = strtok(linea, ";");
        if (!token) continue;

        char nombre[50];
        strncpy(nombre, token, sizeof(nombre));
        nombre[sizeof(nombre) - 1] = '\0';

        token = strtok(NULL, ";");
        if (!token) continue;

        int codigo = atoi(token);

        Materia* nuevaMateria = (Materia*)malloc(sizeof(Materia));
        Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
        if (!nuevaMateria || !nodo) {
            printf("No hay memoria suficiente para cargar materia.\n");
            free(nuevaMateria);
            free(nodo);
            continue;
        }

        strncpy(nuevaMateria->nombre, nombre, sizeof(nuevaMateria->nombre));
        nuevaMateria->nombre[sizeof(nuevaMateria->nombre) - 1] = '\0';
        nuevaMateria->codigo = codigo;

        nuevaMateria->nota = 0;
        nuevaMateria->aprobado = 0;

        nodo->valor = nuevaMateria;
        nodo->next = NULL;


        if (*listaMaterias == NULL) {
            *listaMaterias = nodo;
        } else {
            Nodo* cursor = *listaMaterias;
            while (cursor->next != NULL) {
                cursor = cursor->next;
            }
            cursor->next = nodo;
        }
    }

    fclose(archivo);
    printf("Carga de materias desde archivo finalizada.\n");
}


void cargarAlumnosDesdeArchivo(const char* nombreArchivo, Nodo** listaAlumnos) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo: %s\n", nombreArchivo);
        return;
    }

    char linea[100];
    while (fgets(linea, sizeof(linea), archivo)) {

        linea[strcspn(linea, "\n")] = 0;

        char* token = strtok(linea, ";");
        if (!token) continue;

        char nombre[50];
        strncpy(nombre, token, sizeof(nombre));

        token = strtok(NULL, ";");
        if (!token) continue;

        int edad = atoi(token);

        Alumno* nuevoAlumno = (Alumno*)malloc(sizeof(Alumno));
        Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
        if (!nuevoAlumno || !nodo) {
            printf("Error: No hay suficiente memoria para cargar un alumno.\n");
            free(nuevoAlumno);
            free(nodo);
            continue;
        }

        strncpy(nuevoAlumno->nombre, nombre, sizeof(nuevoAlumno->nombre));
        nuevoAlumno->edad = edad;
        nuevoAlumno->cant_materias = 0;
        for (int i = 0; i < MaximoMaterias; i++) {
            nuevoAlumno->materias[i] = NULL;
        }

        nodo->valor = nuevoAlumno;
        nodo->next = NULL;


        if (*listaAlumnos == NULL) {
            *listaAlumnos = nodo;
        } else {
            Nodo* cursor = *listaAlumnos;
            while (cursor->next != NULL) {
                cursor = cursor->next;
            }
            cursor->next = nodo;
        }
    }

    fclose(archivo);
    printf("Alumnos cargados con éxito.\n");
}
