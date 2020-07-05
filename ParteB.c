#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "./mystack.h"

int main(){
    //Variables de Lectura del archivo
    char *line = NULL;
    unsigned long len = 0;
    char archivo[30];
    long read;
    //Variables de la funcion strtok()
    const char Coma[2] = ",";
    char *Alumno;
    //Variable del numero del alumno
    int NumAlumno = 1;
    //Variable de encriptacion
    const char *polybius_quadrant[5][5]={{"a","b","c","d","e"},{"f","g","h","i","k"},{"l","m","n","o","p"},{"q","r","s","t","u"},{"v","w","x","y","z"}};
    char Jota[1]="j";
    

    printf("Ingrese el nombre del archivo (con .txt incluido):\n");
    scanf("%s", &archivo);
    FILE *pfile = fopen(archivo, "r");
    if (pfile==NULL){
        printf("ERRRROR\n");
        return -1;
    }   
    
    while((read = getline(&line,&len,pfile))!=-1){//leo cada unas de las lineas archivo
        printf("\n%d.-",NumAlumno);//Indico el numero de alumno que es
        Alumno = strtok(line,Coma);//LLamo al primer "token" del string que se descompone
        for(int i=0;i<3;i++){//Itero la funcion para recorrer todos los "tokens" de la linea del archivo(que son 3, por eso i=3)
            printf(" %s ",Alumno);
            for(int z=0;z<strlen(Alumno);z++){
                Alumno[z]=tolower(Alumno[z]);//Convierto las mayusculas en minusculas
                if(Alumno[z]==Jota[0]){//Caso excepcional "j"
                    printf("24");
                }
                for(int x=0;x<5;x++){//recorre la matiz polybius_quadrant[x][y]
                    for(int y=0;y<5;y++){
                        if(*polybius_quadrant[x][y]==Alumno[z]){
                            printf("%d%d",x+1,y+1);
                        }
                    }
                }
            }
            Alumno= strtok(NULL,Coma);//se vuelve a llamar a la funcion "strtok()"" para leer el siguiente "token"
        }
        NumAlumno+=1;
    }


    //Cierro el archivo
    fclose(pfile);
    if(line){
        free(line);
    }
    return 0;  
}
//Las funciones las saque de las clases
void insertFirst(char nombre[NLEN],char apellido[NLEN],int nota, node** head) {
    node* newNode = crearNodo(nombre,apellido,nota);
    if(isEmpty(*head)) {
        *head = newNode;
        return;
    }
    (*head)->previous = newNode;
    newNode->next = *head;
    *head = newNode;
}

node* crearNodo(char nombre[NLEN] ,char apellido[NLEN],int nota) {
    node* newNode = (node*) malloc(sizeof(node));
    if(newNode == NULL) {
        printf("Error al crear nuevo nodo\n");
        exit(0);
    }
    newNode->nombre[NLEN] = nombre;
    newNode->apellido[NLEN] = apellido;
    newNode->nota= nota;
    newNode->next = NULL;
    newNode->previous = NULL;

    return newNode;
}

int isEmpty(node* head) {
    return head == NULL;
}

void printAll(node* head) {
    node* current = head;
    int i = 1;
    while(current != NULL) {
        printf("Node %d nombre: %s\n", i, current->nombre);
        printf("Node %d apellido: %s\n", i, current->apellido);
        printf("Node %d nota: %s\n", i, current->nota);
        if(current->previous == NULL) {
            printf("Node %d previous is NULL\n", i);
        } else {
            printf("Node %d previous node nombre: %s\n", i, current->previous->nombre);
            printf("Node %d previous node apellido: %s\n", i, current->previous->apellido);
            printf("Node %d previous node nota: %s\n", i, current->previous->nota);
        }
        if(current->next == NULL) {
            printf("Node %d next is NULL\n", i);
        } else {
            printf("Node %d next node nombre: %s\n", i, current->next->nombre);
            printf("Node %d next node apellido: %s\n", i, current->next->apellido);
            printf("Node %d next node nota: %s\n", i, current->next->nota);
        }
        current = current->next;
        i++;
    }
}
