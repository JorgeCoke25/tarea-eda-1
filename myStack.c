#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "./mystack.h"

//Las funciones las saque de las clases
void insertFirst(char nombre[NLEN], char apellido[NLEN], int nota, NODE **head)
{
    NODE *newNode = crearNodo(nombre, apellido, nota);
    if (isEmpty(*head))
    {
        *head = newNode;
        return;
    }
    (*head)->previous = newNode;
    newNode->next = *head;
    *head = newNode;
}

NODE *crearNodo(char nombre[NLEN], char apellido[NLEN], int nota)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode == NULL)
    {
        printf("Error al crear nuevo nodo\n");
        exit(0);
    }
    newNode->nombre[NLEN] = nombre;
    newNode->apellido[NLEN] = apellido;
    newNode->nota = nota;
    newNode->next = NULL;
    newNode->previous = NULL;

    return newNode;
}

bool isEmpty(NODE *head)
{
    return head == NULL;
}

void printAll(NODE *head)
{
    NODE *current = head;
    int i = 1;
    while (current != NULL)
    {
        printf("Node %d nombre: %s\n", i, current->nombre);
        printf("Node %d apellido: %s\n", i, current->apellido);
        printf("Node %d nota: %s\n", i, current->nota);
        if (current->previous == NULL)
        {
            printf("Node %d previous is NULL\n", i);
        }
        else
        {
            printf("Node %d previous NODE nombre: %s\n", i, current->previous->nombre);
            printf("Node %d previous NODE apellido: %s\n", i, current->previous->apellido);
            printf("Node %d previous NODE nota: %s\n", i, current->previous->nota);
        }
        if (current->next == NULL)
        {
            printf("Node %d next is NULL\n", i);
        }
        else
        {
            printf("Node %d next NODE nombre: %s\n", i, current->next->nombre);
            printf("Node %d next NODE apellido: %s\n", i, current->next->apellido);
            printf("Node %d next NODE nota: %s\n", i, current->next->nota);
        }
        current = current->next;
        i++;
    }
}
