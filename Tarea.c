#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

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
    

    printf("Ingrese el nombre del archivo (con .txt incluido):\n");
    scanf("%s", &archivo);
    FILE *pfile = fopen(archivo, "r");
    if (pfile==NULL){
        printf("ERRRROR\n");
        return -1;
    }   
    
    while((read = getline(&line,&len,pfile))!=-1){//leo cada unas de las lineas archivo
        printf("%d.-",NumAlumno);//Indico el numero de alumno que es
        Alumno = strtok(line,Coma);//LLamo al primer "token" del string que se descompone
        for(int i=0;i<2;i++){//Itero la funcion para recorrer todos los "tokens" de la linea del archivo(que son 3, por eso i=3)
            printf("%s ",Alumno);
            Alumno= strtok(NULL,Coma);//se vuelve a llamar a la funcion "strrok()"" para leer el siguiente "token"
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