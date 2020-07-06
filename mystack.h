#define MAX_SIZE 5
#define NLEN 30
#include <stdbool.h>

typedef struct nd {
  char name[NLEN];
  char lastname[NLEN];
  int grade;
  struct nd *previous; // Equivalente a left en ABB
  struct nd *next;     // Equivalente a right en ABB
} NODE;

void push(NODE **, char name[NLEN], char lastname[NLEN], int grade);
NODE *pop(NODE **);
bool isFull();
bool isEmpty(NODE **);
NODE *createNode(char[NLEN], char[NLEN], int);
void insertFirst(char[NLEN], char[NLEN], int, NODE **);
void stackPrint(NODE *);
int getStackLength(NODE **);