#define MAX_SIZE = 5
#define NLEN 30
#include <stdbool.h>


typedef struct nd {
char nombre[NLEN];
char apellido[NLEN];
int nota;
struct nd *previous; // Equivalente a left en ABB
struct nd *next; // Equivalente a right en ABB
} node;

void push(int);
int pop();
bool isFull();
bool isEmpty();
node* crearNodo(char[NLEN],char[NLEN],int);
void insertFirst(char[NLEN],char[NLEN],int, node**);
void printAll(node*);