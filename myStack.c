#include "./myStack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Las funciones las saque de las clases
void insertFirst(char name[NLEN], char lastname[NLEN], int grade, NODE **head)
{
  NODE *newNode = createNode(name, lastname, grade);
  if (isEmpty(*head))
  {
    *head = newNode;
    return;
  }
  (*head)->previous = newNode;
  newNode->next = *head;
  *head = newNode;
}

NODE *createNode(char name[NLEN], char lastname[NLEN], int grade)
{
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  if (newNode == NULL)
  {
    printf("Error al crear nuevo nodo\n");
    exit(0);
  }
  for (int i = 0; i < 30; i++)
  {
    newNode->name[i] = name[i];
    newNode->lastname[i] = lastname[i];
  }
  newNode->grade = grade;
  newNode->next = NULL;
  newNode->previous = NULL;

  return newNode;
}

bool isEmpty(NODE *head) { return head == NULL; }

int getStackLength(NODE *head)
{
  if (head == NULL)
  {
    return 0;
  }
  int length = 0;
  NODE *current = head;
  while (current != NULL)
  {
    length++;
    current = current->next;
  }
  return length;
}

void printAll(NODE *head)
{
  NODE *current = head;
  int i = 1;
  while (current != NULL)
  {
    printf("Node %d: Name: %s, Lastname: %s, Grade: %d\n", i, current->name, current->lastname, current->grade);
    current = current->next;
    i++;
  }
}
