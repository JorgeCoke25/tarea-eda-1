#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "./mystack.h"

int main()
{
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
    const char *polybius_quadrant[5][5] = {{"a", "b", "c", "d", "e"}, {"f", "g", "h", "i", "k"}, {"l", "m", "n", "o", "p"}, {"q", "r", "s", "t", "u"}, {"v", "w", "x", "y", "z"}};
    char Jota[1] = "j";

    printf("Ingrese el nombre del archivo (con .txt incluido):\n");
    scanf("%s", &archivo);
    FILE *pfile = fopen(archivo, "r");
    if (pfile == NULL)
    {
        printf("ERRRROAR\n");
        return -1;
    }

    while ((read = getline(&line, &len, pfile)) != -1)
    {                                //leo cada unas de las lineas archivo
        printf("\n%d.-", NumAlumno); //Indico el numero de alumno que es
        Alumno = strtok(line, Coma); //LLamo al primer "token" del string que se descompone
        for (int i = 0; i < 3; i++)
        { //Itero la funcion para recorrer todos los "tokens" de la linea del archivo(que son 3, por eso i=3)
            printf(" %s ", Alumno);
            for (int z = 0; z < strlen(Alumno); z++)
            {
                Alumno[z] = tolower(Alumno[z]); //Convierto las mayusculas en minusculas
                if (Alumno[z] == Jota[0])
                { //Caso excepcional "j"
                    printf("24");
                }
                for (int x = 0; x < 5; x++)
                { //recorre la matiz polybius_quadrant[x][y]
                    for (int y = 0; y < 5; y++)
                    {
                        if (*polybius_quadrant[x][y] == Alumno[z])
                        {
                            printf("%d%d", x + 1, y + 1);
                        }
                    }
                }
            }
            Alumno = strtok(NULL, Coma); //se vuelve a llamar a la funcion "strtok()"" para leer el siguiente "token"
        }
        NumAlumno += 1;
    }

    //Cierro el archivo
    fclose(pfile);
    if (line)
    {
        free(line);
    }
    return 0;
}
