#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define COMMA ","
char Jota[1] = "j";
const char *polybius_quadrant[5][5] = {{"a", "b", "c", "d", "e"}, {"f", "g", "h", "i", "k"}, {"l", "m", "n", "o", "p"}, {"q", "r", "s", "t", "u"}, {"v", "w", "x", "y", "z"}};

char *encrypt(char *str)
{
    int studentLength = strlen(str);
    char *encrypted = (char *)malloc(sizeof(char) * studentLength * 2);
    for (int z = 0; z < studentLength; z++)
    {
        str[z] = tolower(str[z]);
        if (str[z] == Jota[0])
        {
            strcat(encrypted, "24");
        }
        for (int x = 0; x < 5; x++)
        {
            for (int y = 0; y < 5; y++)
            {
                if (*polybius_quadrant[x][y] == str[z])
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
    char *line = NULL;
    unsigned long line_length = 0;
    FILE *pfile = fopen(file, "r");

    if (pfile == NULL)
    {
        printf("ERROR\n");
        return -1;
    };

    long read;
    char *encryptedStudent[3];
    while ((read = getline(&line, &line_length, pfile)) != -1)
    {
        char *tokenized = strtok(line, COMMA);
        for (int i = 0; i < 3; i++)
        {
            char *encrypted = encrypt(tokenized);
            encryptedStudent[i] = encrypted;
            tokenized = strtok(NULL, COMMA);
        }
        encryptedStudent[2] = tokenized;
        printf("%s %s %s\n", encryptedStudent[0], encryptedStudent[1], encryptedStudent[2]);
        // lo agrego al nodo
    }

    fclose(pfile);
    if (line)
    {
        free(line);
    }
    return 0;
}