#define NLEN 30
#include<stdio.h>
#include<stdlib.h>

typedef struct nd {
    char nombre[NLEN];
    char apellido[NLEN];
    int nota;
    struct nd *previous; 
    struct nd *next; 
} Nodo;

void insertFirst(char nombre[NLEN], char apellido[NLEN], Nodo** head) {
    Nodo* newNode = crearNodo(nombre,apellido);
    if(isEmpty(*head)) {
        *head = newNode;
        return;
    }
    (*head)->previous = newNode;
    newNode->next = *head;
    *head = newNode;
}

Nodo* crearNodo(char nombre[NLEN], char apellido[NLEN]){
    Nodo* newNode = (Nodo*) malloc(sizeof(Nodo));
    if(newNode == NULL) {
        printf("Error al crear nuevo nodo\n");
        exit(0);
    }
    newNode->nombre[NLEN] = nombre;
    newNode->apellido[NLEN] = apellido;
    newNode->next = NULL;
    newNode->previous = NULL;

    return newNode;
}

int isEmpty(Nodo* head) {
    return head == NULL;
}

void printAll(Nodo* head) {
    Nodo* current = head;
    int i = 1;
    while(current != NULL) {
        printf("Node %d nombre: %s\n", i, current->nombre);
        printf("Node %d apellido: %s\n", i, current->apellido);
        if(current->previous == NULL) {
            printf("Node %d previous is NULL\n", i);
        } else {
            printf("Node %d previous node data: %s\n", i, current->previous->nombre);
            printf("Node %d previous node data: %s\n", i, current->previous->apellido);
        }
        if(current->next == NULL) {
            printf("Node %d next is NULL\n", i);
        } else {
            printf("Node %d next node data: %s\n", i, current->next->nombre);
            printf("Node %d next node data: %d\n", i, current->next->apellido);
        }
        current = current->next;
        i++;
    }
}
