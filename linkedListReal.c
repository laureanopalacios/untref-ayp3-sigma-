#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Nodo{
    struct Nodo* proximo;
    void* valor;
} Nodo;


Nodo* nuevoNodo(void* data) {
    //Reserva memoria en el Stack para el nuevo nodo e inicializa los atributos del nuevo nodo
    Nodo* n = malloc(sizeof(Nodo));
    n->valor = malloc(20 * sizeof(char));           // reservar espacio para un int
    strncpy((char*)n->valor, data, 19);          // copiar máximo 19 chars
    ((char*)n->valor)[19] = '\0';   
    n->proximo = NULL;
    return n;
}

void insertarAlInicio(Nodo** cabeza, void* data) {
    //Crea un nuevo nodo con el dato asignado y que apunte a la cabeza y luego lo convierte en la cabeza de la lista
    Nodo* nuevo = nuevoNodo(data);
    nuevo = nuevoNodo(data);
    nuevo->proximo = *cabeza;
    *cabeza = nuevo;
}

void insertarAlFinal (Nodo** cabeza, void* data) {
    //Si la lista esta vacia el nuevo nodo es la cabeza
    Nodo* nuevo = nuevoNodo(data);
    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {    //Recorre desde la cabeza hasta el último nodo de la lista
        Nodo* cursor = *cabeza;
        while (cursor->proximo != NULL) {
            cursor = cursor->proximo;
        }    
        //Conecta el último nodo de la lista al nuevo nodo
        cursor->proximo = nuevo;
    }
}

void eliminarNodo(Nodo** cabeza, void* data) {
    Nodo* actual = *cabeza;
    Nodo* anterior = NULL;
    
    //Si la lista esta vacía termina la ejecución
    if (actual == NULL) {
        printf("Lista vacia.\n");
        return;
    }

    //Busca el valor a eliminar y el anterior
    while (actual != NULL && *(int*)(actual->valor) != *(int*)data){
        anterior = actual;
        actual = actual->proximo;
    }
    
    //Hacemos que el anterior deje de apuntar al nodo a eliminar y que en cambio apunte al siguiente
    if (anterior == NULL) {
        *cabeza = actual->proximo;
    } else {
        anterior->proximo = actual->proximo;
    }
    
    //Libera la memoria del nodo que eliminamos
    free(actual);
    printf("Nodo eliminado.\n");
}

typedef int (*FuncionComparacion)(void*, void*);

int compararEnteros2(void* a, void* b) {
    int* ia = (int*)a;
    int* ib = (int*)b;
    if (*ia == *ib) return 0;
    else return (*ia > *ib) ? 1 : -1;
}

Nodo* buscarNodo(Nodo* cabeza, void* data, FuncionComparacion cmp) {
    while (cabeza != NULL) {
        if (cmp(cabeza->valor, data) == 0){
            return cabeza;
        }
        cabeza = cabeza->proximo;
    }
    return NULL;
}

void imprimirLista(Nodo* cabeza) {
    //Recorre la lista e imprime el valor del nodo en cada iteración
    printf("Lista: ");
    while (cabeza != NULL) {
        printf("%d -> ", *(int*)cabeza->valor);
        cabeza = cabeza->proximo;
    }
    printf("NULL\n");
}

void imprimirListaStrings(Nodo* cabeza) {
    //Recorre la lista e imprime el valor del nodo en cada iteración
    printf("Lista: ");
    while (cabeza != NULL) {
        printf("%s -> ", (char*)cabeza->valor);
        cabeza = cabeza->proximo;
    }
    printf("NULL\n");
}

void liberarLista(Nodo** cabeza) {
    //Recorre la lista liberando la memoria de cada nodo
    Nodo* actual = *cabeza;
    while (actual != NULL) {
        Nodo* siguiente = actual->proximo;
        free(actual);
        actual = siguiente;
    }
    *cabeza = NULL;
}



// Menu interactivo
int main2() {
    Nodo* lista = NULL;
    int opcion, valor;

    do {
        printf("\n1. Insertar al inicio\n2. Insertar al final\n3. Eliminar\n4. Buscar\n5. Imprimir\n6. Salir\nOpción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Valor: ");
                scanf("%d", &valor);
                insertarAlInicio(&lista, &valor);
                break;
            case 2:
                printf("Valor: ");
                scanf("%d", &valor);
                insertarAlFinal(&lista, &valor);
                break;
            case 3:
                printf("Valor a eliminar: ");
                scanf("%d", &valor);
                eliminarNodo(&lista, &valor);
                break;
            case 4:
                printf("Valor a buscar: ");
                scanf("%d", &valor);
                if (buscarNodo(lista, &valor,compararEnteros2))
                    printf("Valor encontrado.\n");
                else
                    printf("Valor no encontrado.\n");
                break;
            case 5:
                imprimirLista(lista);
                break;
            case 6:
                liberarLista(&lista);
                printf("Lista liberada.\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 6);

    return 0;
}