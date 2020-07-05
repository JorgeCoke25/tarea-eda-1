#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define COMMA ","
char Jota[1] = "j";
const char *polybius_quadrant[5][5] = {{"a", "b", "c", "d", "e"}, {"f", "g", "h", "i", "k"}, {"l", "m", "n", "o", "p"}, {"q", "r", "s", "t", "u"}, {"v", "w", "x", "y", "z"}};

char *encrypt(char *student)
{
    printf("%s\n", student);
    int studentLength = strlen(student);
    char *encrypted = (char *)malloc(sizeof(char) * studentLength * 2);
    for (int z = 0; z < studentLength; z++)
    {
        student[z] = tolower(student[z]); //Convierto las mayusculas en minusculas
        if (student[z] == Jota[0])
        { //Caso excepcional "j"
            strcat(encrypted, "24");
        }
        for (int x = 0; x < 5; x++)
        { //recorre la matiz polybius_quadrant[x][y]
            for (int y = 0; y < 5; y++)
            {
                if (*polybius_quadrant[x][y] == student[z])
                {
                    char buffer[3];
                    sprintf(buffer, "%d%d", x + 1, y + 1);
                    strcat(encrypted, buffer);
                }
            }
        }
    }
    return encrypted;
};

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Ingrese el nombre del archivo\n");
        return 0;
    }
    char *file = argv[1];
    //Variables de Lectura del archivo
    char *line = NULL;
    unsigned long line_length = 0;
    //Variable de encriptacion
    // para el caso especial de i,j

    FILE *pfile = fopen(file, "r");
    if (pfile == NULL)
    {
        printf("ERROR\n");
        return -1;
    };

    long read;
    while ((read = getline(&line, &line_length, pfile)) != -1)
    {                                        //leo cada unas de las lineas archivo
        char *student = strtok(line, COMMA); //LLamo al primer "token" del string que se descompone
        for (int i = 0; i < 3; i++)
        { //Itero la funcion para recorrer todos los "tokens" de la linea del archivo(que son 3, por eso i=3)
            // printf("%s\n", student);
            char *encrypted = encrypt(student);
            // printf("%s\n", encrypted);
            student = strtok(NULL, COMMA); //se vuelve a llamar a la funcion "strtok()"" para leer el siguiente "token"
        }
    }

    //Cierro el archivo
    fclose(pfile);
    if (line)
    {
        free(line);
    }
    return 0;
}